//This file, messenger.cpp, is the c++ implementation of the Qt Messenger Class
//The functions implemented here run in response to signals from the GUI

#include "messenger.h"
#include "ui_messenger.h"

//Constructor for messenger window
Messenger::Messenger(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Messenger),
    username("conrad"),
    currentChannel("server"),
    client(username.toStdString(), 38400),
    connectedToServer(false)
{
    ui->setupUi(this);
    ui->channelsTextBrowser->textCursor().insertText("Channels: \n");

    std::string servers = client.getServers();

    bool ok;
    QString text = QInputDialog::getText(this, "Connect to Server", QString::fromStdString("Available Servers: " + serverList),
                                         QLineEdit::Normal, "", &ok);

    if (ok && !text.isEmpty()) {
        client.connectToServer(text.toStdString());
    }

    //start concurrent thread that checks for new messages on GUI startup
    extern void receiveMessageFuntion();
    QFuture<void> future = QtConcurrent::run(this, &Messenger::receiveMessageFunction);
}

//Deconstructor
Messenger::~Messenger()
{
    //leave channels
    //and disconnect from server
    delete ui;
}

//Send a message or command
void Messenger::on_sendButton_clicked()
{
    //Get the string that the user typed into the text edit box
    msgString = ui->inputText->toPlainText();

    client.sendExpression(currentChannel.toStdString(), "MSG "+ msgString.toStdString());

    //Remove the user's message from the text edit box at the bottom
    ui->inputText->clear();
}

//Check for new messages
void Messenger::receiveMessageFunction()
{
    bool isServer;
    bool isActiveChannel;
    while (true) {
        Envelope envelope = client.retrieveEnvelope();

        isServer = (envelope.getSender() == "server");
        isActiveChannel = (envelope.getDestination() == currentChannel.toStdString());

        if (isActiveChannel) {
            //Set text colors and display username followed by message
            ui->messageView->setTextColor(QColor("#73A7E2"));
            ui->messageView->textCursor().insertText(QString::fromStdString(envelope.getSender()));
            ui->messageView->textCursor().insertText(":   ");
            ui->messageView->setTextColor(QColor("#EAE2D2"));
            ui->messageView->textCursor().insertText(QString::fromStdString(envelope.getExpression()));
            ui->messageView->textCursor().insertText("\n");
        } else if (isServer) {
            ui->helpTextBrowser->textCursor().insertText(QString::fromStdString(envelope.getExpression()));
        }
        //Make sure that the message view scrolls to the bottom
        ui->messageView->ensureCursorVisible();
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
    bool ok;
    QString text = QInputDialog::getText(this, "Change Username", "User name:", QLineEdit::Normal, username, &ok);
    if (ok && !text.isEmpty()) {
        username = text;
        client.setUsername(username.toStdString());
    }
}

//Join channel command
void Messenger::on_actionJoin_Channel_triggered()
{
    bool ok;
    QString text = QInputDialog::getText(this, "Join Channel", "Join channel: ", QLineEdit::Normal, "", &ok);

    if (ok && !text.isEmpty()) {
        client.joinChannel(text.toStdString());
        ui->channelsListWidget->addItem(text);
    }
}

void Messenger::on_actionCreate_Channel_triggered()
{
    bool ok;
    QString text = QInputDialog::getText(this, "Create Channel", "Create channel: ", QLineEdit::Normal, "", &ok);

    if (ok && !text.isEmpty()) {
        client.createChannel(text.toStdString());
        ui->channelsListWidget->addItem(text);
    }
}

