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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Messenger
{
public:
    QAction *actionChange_Name;
    QWidget *centralWidget;
    QTextEdit *inputText;
    QPushButton *sendButton;
    QFrame *line_1;
    QFrame *line_2;
    QTextBrowser *messageView;
    QPushButton *startButton;
    QTextBrowser *helpTextBrowser;
    QMenuBar *menuBar;
    QMenu *menuActions;

    void setupUi(QMainWindow *Messenger)
    {
        if (Messenger->objectName().isEmpty())
            Messenger->setObjectName(QStringLiteral("Messenger"));
        Messenger->resize(1050, 647);
        QPalette palette;
        QBrush brush(QColor(18, 129, 240, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(18, 17, 13, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(70, 194, 240, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush3(QColor(255, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        QBrush brush4(QColor(240, 240, 240, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush4);
        Messenger->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Utopia"));
        font.setPointSize(13);
        Messenger->setFont(font);
        Messenger->setAutoFillBackground(true);
        actionChange_Name = new QAction(Messenger);
        actionChange_Name->setObjectName(QStringLiteral("actionChange_Name"));
        centralWidget = new QWidget(Messenger);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        inputText = new QTextEdit(centralWidget);
        inputText->setObjectName(QStringLiteral("inputText"));
        inputText->setGeometry(QRect(140, 510, 651, 101));
        QPalette palette1;
        QBrush brush5(QColor(234, 226, 210, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        QBrush brush6(QColor(159, 158, 158, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        inputText->setPalette(palette1);
        inputText->setFont(font);
        inputText->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        inputText->setMouseTracking(false);
        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(800, 510, 81, 101));
        line_1 = new QFrame(centralWidget);
        line_1->setObjectName(QStringLiteral("line_1"));
        line_1->setGeometry(QRect(120, 10, 20, 601));
        line_1->setFrameShape(QFrame::VLine);
        line_1->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(890, 10, 20, 601));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        messageView = new QTextBrowser(centralWidget);
        messageView->setObjectName(QStringLiteral("messageView"));
        messageView->setGeometry(QRect(140, 10, 741, 491));
        QFont font1;
        font1.setFamily(QStringLiteral("Utopia"));
        font1.setPointSize(16);
        messageView->setFont(font1);
        messageView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(20, 20, 99, 27));
        helpTextBrowser = new QTextBrowser(centralWidget);
        helpTextBrowser->setObjectName(QStringLiteral("helpTextBrowser"));
        helpTextBrowser->setGeometry(QRect(910, 10, 121, 571));
        QPalette palette2;
        QBrush brush7(QColor(242, 241, 240, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        helpTextBrowser->setPalette(palette2);
        QFont font2;
        font2.setPointSize(11);
        helpTextBrowser->setFont(font2);
        helpTextBrowser->setFrameShape(QFrame::NoFrame);
        helpTextBrowser->setFrameShadow(QFrame::Plain);
        helpTextBrowser->setLineWidth(0);
        helpTextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        helpTextBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        helpTextBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        Messenger->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Messenger);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1050, 29));
        menuActions = new QMenu(menuBar);
        menuActions->setObjectName(QStringLiteral("menuActions"));
        Messenger->setMenuBar(menuBar);

        menuBar->addAction(menuActions->menuAction());
        menuActions->addAction(actionChange_Name);

        retranslateUi(Messenger);

        QMetaObject::connectSlotsByName(Messenger);
    } // setupUi

    void retranslateUi(QMainWindow *Messenger)
    {
        Messenger->setWindowTitle(QApplication::translate("Messenger", "Messenger", 0));
        actionChange_Name->setText(QApplication::translate("Messenger", "Change Name", 0));
        sendButton->setText(QApplication::translate("Messenger", "Send", 0));
        startButton->setText(QApplication::translate("Messenger", "Start Chat", 0));
        menuActions->setTitle(QApplication::translate("Messenger", "Actions", 0));
    } // retranslateUi

};

namespace Ui {
    class Messenger: public Ui_Messenger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSENGER_H
