/********************************************************************************
** Form generated from reading UI file 'messenger.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSENGER_H
#define UI_MESSENGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Messenger
{
public:
    QWidget *centralWidget;
    QTextEdit *inputText;
    QPushButton *sendButton;
    QFrame *line_1;
    QFrame *line_2;
    QPlainTextEdit *messageView;
    QPushButton *changeNameButton;
    QLabel *actionsLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Messenger)
    {
        if (Messenger->objectName().isEmpty())
            Messenger->setObjectName(QStringLiteral("Messenger"));
        Messenger->resize(1050, 647);
        centralWidget = new QWidget(Messenger);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        inputText = new QTextEdit(centralWidget);
        inputText->setObjectName(QStringLiteral("inputText"));
        inputText->setGeometry(QRect(140, 530, 651, 51));
        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(800, 530, 81, 51));
        line_1 = new QFrame(centralWidget);
        line_1->setObjectName(QStringLiteral("line_1"));
        line_1->setGeometry(QRect(120, -30, 20, 641));
        line_1->setFrameShape(QFrame::VLine);
        line_1->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(890, 0, 20, 611));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        messageView = new QPlainTextEdit(centralWidget);
        messageView->setObjectName(QStringLiteral("messageView"));
        messageView->setGeometry(QRect(140, 9, 741, 511));
        changeNameButton = new QPushButton(centralWidget);
        changeNameButton->setObjectName(QStringLiteral("changeNameButton"));
        changeNameButton->setGeometry(QRect(10, 40, 111, 25));
        actionsLabel = new QLabel(centralWidget);
        actionsLabel->setObjectName(QStringLiteral("actionsLabel"));
        actionsLabel->setGeometry(QRect(10, 10, 111, 21));
        Messenger->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Messenger);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1050, 22));
        Messenger->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Messenger);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Messenger->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Messenger);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Messenger->setStatusBar(statusBar);

        retranslateUi(Messenger);

        QMetaObject::connectSlotsByName(Messenger);
    } // setupUi

    void retranslateUi(QMainWindow *Messenger)
    {
        Messenger->setWindowTitle(QApplication::translate("Messenger", "Messenger", 0));
        sendButton->setText(QApplication::translate("Messenger", "Send", 0));
        changeNameButton->setText(QApplication::translate("Messenger", "Change Name", 0));
        actionsLabel->setText(QApplication::translate("Messenger", " Actions:", 0));
    } // retranslateUi

};

namespace Ui {
    class Messenger: public Ui_Messenger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSENGER_H
