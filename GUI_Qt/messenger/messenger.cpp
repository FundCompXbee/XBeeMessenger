//This file, messenger.cpp, is the c++ implementation of the Qt Messenger Class
//The functions implemented here run in response to signals from the GUI

#include "messenger.h"
#include "ui_messenger.h"

//Constructor for messenger window
Messenger::Messenger(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Messenger)
{
    ui->setupUi(this);
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

    //Set text colors and display username followed by message
    ui->messageView->setTextColor(QColor("#619FE0"));
    ui->messageView->textCursor().insertText(username);
    ui->messageView->textCursor().insertText(":   ");
    ui->messageView->setTextColor(QColor("#EAE2D2"));
    ui->messageView->textCursor().insertText(msgString);
    ui->messageView->textCursor().insertText("\n");

    //Make sure that the message view scrolls to the bottom
    ui->messageView->ensureCursorVisible();

    //Remove the user's message from the text edit box at the bottom
    ui->inputText->clear();

    //clear the help message, in case the user was running a command
    //and not just sending a message
    ui->helpTextBrowser->clear();

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


    /*if (serialDataAvailable) {
          incomingString = serial Data
          newEnvelope = envelope(incomingString, mode = receiving);
          displayString = newEnvelope.JSONobj[string];
          ui->messageView->textCursor().insertText(displayString);
    */
    }
}

//Change name command
void Messenger::on_actionChange_Name_triggered()
{
    ui->inputText->clear();
    ui->inputText->textCursor().insertText("\\nick <newusername>");
    ui->helpTextBrowser->textCursor().insertText("To change your username, replace <newusername> with your desired name and click send to perform the command.");
}

//Start concurrent thread that checks for new incoming messages
void Messenger::on_startButton_clicked()
{
    username = "Madeline";
    extern void receiveMessageFuntion();
    QFuture<void> future = QtConcurrent::run(this, &Messenger::receiveMessageFunction);
}
