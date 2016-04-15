#include "messenger.h"
#include "ui_messenger.h"

Messenger::Messenger(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Messenger)
{
    ui->setupUi(this);
}

Messenger::~Messenger()
{
    delete ui;
}

void Messenger::on_sendButton_clicked()
{
    msgString = ui->inputText->toPlainText();
    ui->messageView->textCursor().insertText(msgString);
    ui->inputText->clear();

    //wrapper send string

}

void Messenger::keyPressEvent(QKeyEvent *e)
{
    if( e->key() == Qt::Key_Return )
        on_sendButton_clicked();
}

std::string Messenger::get_msgString()
{
    return msgString.toStdString();
}
