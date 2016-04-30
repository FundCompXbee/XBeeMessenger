//This file, messenger.cpp, is the c++ implementation of the Qt Messenger Class
//The functions implemented here run in response to signals from the GUI

#include "messenger.h"
#include "ui_messenger.h"

//Constructor for messenger window
Messenger::Messenger(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Messenger),
    username("default"),
    currentChannel("server"),
    client(username.toStdString(), 38400)
{
    //First initialize ui
    ui->setupUi(this);

    //display title for list of channels
    ui->channelsTextBrowser->textCursor().insertText("Channels: \n");

    //ping for available servers
    std::string servers;
    bool badmessage = true;

    while(badmessage) {
        try {
            servers = client.getServers();
            badmessage = false;
        } catch(...) {
            std::cout << "caught failed getServers() call" << std::endl;
            continue;
        }
    }

    //display a dialog box asking user to choose a server
    bool ok;
    QString text = QInputDialog::getText(this, "Connect to Server", QString::fromStdString("Available Servers: " + servers),
                                         QLineEdit::Normal, "", &ok);
    badmessage = true;
    if (ok && !text.isEmpty()) {
        while(badmessage) {
            try {
                client.connectServer(text.toStdString());
                badmessage = false;
            } catch(...) {
                std::cout << "caught failed connectServers() call" << std::endl;
                continue;
            }
        }
    }

    //"connected" must be true for the separate thread initialized below to recieve messages
    connected = true;

    //start concurrent thread that checks for new messages
    extern void receiveMessageFuntion();
    QFuture<void> future = QtConcurrent::run(this, &Messenger::receiveMessageFunction);
}

//Deconstructor
Messenger::~Messenger()
{
    std::cout << "destructing GUI" << std::endl;

    //leave channels
    //and disconnect from server
    client.disconnectServer();

    //set "connected" to false so that the separate thread stops running
    connected = false;

    //finally actually destroy the GUI
    delete ui;
}

//Send a message or command
void Messenger::on_sendButton_clicked()
{
    //Get the string that the user typed into the text edit box
    msgString = ui->inputText->toPlainText();

    //send the string to server with destination:currentChannel
    client.sendExpression(currentChannel.toStdString(), "MSG "+ msgString.toStdString());

    //Remove the user's message from the text edit box at the bottom
    ui->inputText->clear();
}

//Check for new messages
void Messenger::receiveMessageFunction()
{
    bool isServer;
    bool isActiveChannel;

    //Runs forever until "connected" becomes false, which doesn't happen until deconstruction of the GUI
    while (connected) {
        //instantiate an envelope object in which to recieve the message or transmission
        Envelope envelope;

        try {
            envelope = client.retrieveEnvelope();
        } catch(...) {
            continue;
        }

        //filter envelops based on destination and sender.
        isServer = (envelope.getSender() == "server");
        isActiveChannel = (envelope.getDestination() == currentChannel.toStdString());

        //only display messages in the message window that are intended for the active channel, "currentChannel"
        if (isActiveChannel) {
            //Set text colors and display username followed by message
            ui->messageView->setTextColor(QColor("#73A7E2"));
            ui->messageView->textCursor().insertText(QString::fromStdString(envelope.getSender()));
            ui->messageView->textCursor().insertText(":   ");
            ui->messageView->setTextColor(QColor("#EAE2D2"));
            ui->messageView->textCursor().insertText(QString::fromStdString(envelope.getExpression()));
            ui->messageView->textCursor().insertText("\n");            
        }
        //if messages are from the server, then display them in an informational panel on the right side of the window
        else if (isServer) {
            ui->helpTextBrowser->textCursor().insertText(QString::fromStdString(envelope.getExpression()));
            ui->helpTextBrowser->textCursor().insertText("\n\n");
        }

        //Make sure that the message view scrolls to the bottom
        ui->messageView->ensureCursorVisible();
    }

    std::cout << "End of concurrent thread" << std::endl;
}

//Change the active channel, when a channel is selected from the list on the left
void Messenger::on_channelsListWidget_clicked(const QModelIndex &index)
{
    currentChannel = ui->channelsListWidget->selectedItems()[0]->text();
    ui->messageView->setTextColor(QColor("#DB92DD"));
    ui->messageView->textCursor().insertText("____________________________________________________________________\n");
    ui->messageView->textCursor().insertText("Channel: ");
    ui->messageView->textCursor().insertText(currentChannel);
    ui->messageView->textCursor().insertText("\n\n");
    //Make sure that the message view scrolls to the bottom
    ui->messageView->ensureCursorVisible();
}

//Change name command
void Messenger::on_actionChange_Name_triggered()
{
    //display a dialog box to ask the user for a username
    bool ok;
    QString text = QInputDialog::getText(this, "Change Username", "User name:", QLineEdit::Normal, username, &ok);

    if (ok && !text.isEmpty()) {
        //call function which sends request to the server to change username
        client.setUsername(text.toStdString());
        QThread::sleep(1);
        username = text;
    }
}

//Join channel command
void Messenger::on_actionJoin_Channel_triggered()
{
    //display dialog box to ask user for name of channel to join
    bool ok;
    QString text = QInputDialog::getText(this, "Join Channel", "Join channel: ", QLineEdit::Normal, "", &ok);

    if (ok && !text.isEmpty()) {
        //call function that sends JOINCHANNEL command to the server
        client.joinChannel(text.toStdString());
        ui->channelsListWidget->addItem(text);
    }
}

//Create channel command
void Messenger::on_actionCreate_Channel_triggered()
{
    //display dialog box to ask user for name of channel to create
    bool ok;
    QString text = QInputDialog::getText(this, "Create Channel", "Create channel: ", QLineEdit::Normal, "", &ok);

    if (ok && !text.isEmpty()) {
        //call function that sends CREATECHANNEL command
        client.createChannel(text.toStdString());
        ui->channelsListWidget->addItem(text);
    }
}

