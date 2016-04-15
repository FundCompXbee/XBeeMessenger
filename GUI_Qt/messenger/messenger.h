#ifndef MESSENGER_H
#define MESSENGER_H

#include <QMainWindow>

namespace Ui {
class Messenger;
}

class Messenger : public QMainWindow
{
    Q_OBJECT

public:
    explicit Messenger(QWidget *parent = 0);
    ~Messenger();

    void keyPressEvent(QKeyEvent* e);

    std::string get_msgString();

private slots:
    void on_sendButton_clicked();



private:
    Ui::Messenger *ui;
    QString msgString;
};

#endif // MESSENGER_H
