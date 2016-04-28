//This file, messenger.cpp, is the c++ implementation of the Qt Messenger Class
//The functions implemented here run in response to signals from the GUI

#include "messenger.h"
#include "ui_messenger.h"

//Constructor for messenger window
Messenger::Messenger(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Messenger),
    username("madeline"),
    currentChannel("server"),
    client(username.toStdString(), 38400),
    connectedToServer(false)
{
    ui->setupUi(this);
    ui->channelsTextBrowser->textCursor().insertText("Channels: \n");

    std::set<std::string> servers = client.getServers();
    ui->helpTextBrowser->textCursor().insertText("Available Servers: \n");
    for (std::string entry : servers) {
        ui->helpTextBrowser->textCursor().insertText(QString::fromStdString(entry));
        ui->helpTextBrowser->textCursor().insertText("\n");
    }
    ui->helpTextBrowser->textCursor().insertText("\nChoose a server to connect to and send its name.\n\n");


    //start concurrent thread that checks for new messages on GUI startup
    extern void receiveMessageFuntion();
    QFuture<void> future = QtConcurrent::run(this, &Messenger::receiveMessageFunction);
}

//Deconstructor
Messenger::~Messenger()
{
    delete ui;
}

//Send a message or command
void Messenger::on_sendButton_clicked()
{
    //Get the string that the user typed into the text edit box
    msgString = ui->inputText->toPlainText();

    //Check if it's a message or command

    if (connectedToServer && msgString != NULL && msgString.at(0) == '\\') {

        //send command to server

        QStringList command = msgString.split(" ");
        if (command[0] == "\\nick") {
            username = command[1];
        }
        else if (command[0] == "\\join") {
            client.sendExpression("server", "JOINCHANNEL " + command[1].toStdString() + " " + username.toStdString());
            currentChannel = command[1];
            ui->channelsListWidget->addItem(command[1]);
        }
        else if (command[0] == "\\create") {
            client.sendExpression("server", "CREATECHANNEL " + command[1].toStdString() + " " + username.toStdString());
            ui->channelsListWidget->addItem(command[1]);
        }

        ui->helpTextBrowser->clear();
    } else if (connectedToServer) {

        //Set text colors and display username followed by message
        ui->messageView->setTextColor(QColor("#73A7E2"));
        ui->messageView->textCursor().insertText(username);
        ui->messageView->textCursor().insertText(":   ");
        ui->messageView->setTextColor(QColor("#EAE2D2"));
        ui->messageView->textCursor().insertText(msgString);
        ui->messageView->textCursor().insertText("\n");

        //Make sure that the message view scrolls to the bottom
        ui->messageView->ensureCursorVisible();

        client.sendExpression(currentChannel.toStdString(), "MSG "+get_msgString());
    }

    if (!connectedToServer) {
        client.connectToServer(get_msgString());
        connectedToServer = true;
        ui->helpTextBrowser->textCursor().insertText(QString::fromStdString(client.retrieveResponse()));
    }

    //Remove the user's message from the text edit box at the bottom
    ui->inputText->clear();

    //clear the help message, in case the user was running a command
    //and not just sending a message


    //convert the QString to an std::string and send it
    //newEnvelope = envelope(get_msgString();
    //send(newEnvelope)
}

//Convert user's message from a QString to and std::string
std::string Messenger::get_msgString()
{
    return msgString.toStdString();
}

//Check for new messages
void Messenger::receiveMessageFunction()
{
    while (true) {
        //ui->messageView->textCursor().insertText("Checking for new message...\n");
        QThread::sleep(10);
        std::string displayString;
        displayString = client.retrieveResponse();
        ui->messageView->textCursor().insertText(QString::fromStdString(displayString));
    }
}


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
    ui->inputText->clear();
    ui->helpTextBrowser->clear();
    ui->inputText->textCursor().insertText("\\nick <newusername>");
    ui->helpTextBrowser->textCursor().insertText("To change your username, replace <newusername> with your desired name and click send to perform the command.");
}

//Join channel command
void Messenger::on_actionJoin_Channel_triggered()
{
    ui->inputText->clear();
    ui->helpTextBrowser->clear();
    ui->inputText->textCursor().insertText("\\join <channel>");
    ui->helpTextBrowser->textCursor().insertText("To join a channel, replace <channel> with the channel's name and click send to perform the command. Then to switch over to the channel, select it in the channel list on the left.");
}

void Messenger::on_actionCreate_Channel_triggered()
{
    ui->inputText->clear();
    ui->helpTextBrowser->clear();
    ui->inputText->textCursor().insertText("\\create <channel>");
    ui->helpTextBrowser->textCursor().insertText("To create a new channel, replace <channel> with the channel's name and click send to perform the command. Then to switch over to the new channel, select it in the channel list on the left.");
}

