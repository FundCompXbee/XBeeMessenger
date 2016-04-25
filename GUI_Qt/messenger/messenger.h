#ifndef MESSENGER_H
#define MESSENGER_H

//This file is the c++ interface for the Qt Messenger class, which inherits from QMainWindow

#include <QMainWindow>
#include <iostream>
#include <cstdlib>
#include <QThread>
#include <iostream>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QColor>
#include <QAbstractSlider>
#include <QListWidget>
#include <QListWidgetItem>

namespace Ui {
class Messenger;
}

class Messenger : public QMainWindow
{
    Q_OBJECT

public:
    explicit Messenger(QWidget *parent = 0);
    ~Messenger();
    std::string get_msgString();
    void receiveMessageFunction();

private slots:
    void on_sendButton_clicked();
    void on_channelsListWidget_clicked(const QModelIndex &index);
    void on_actionChange_Name_triggered();
    void on_actionJoin_Channel_triggered();

private:
    Ui::Messenger *ui;
    QString msgString;
    QString username;
    QString currentChannel;
};

#endif // MESSENGER_H



