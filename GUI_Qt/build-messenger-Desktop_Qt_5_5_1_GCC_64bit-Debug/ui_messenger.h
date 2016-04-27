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
#include <QtWidgets/QListWidget>
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
    QAction *actionJoin_Channel;
    QAction *actionCreate_Channel;
    QWidget *centralWidget;
    QTextEdit *inputText;
    QPushButton *sendButton;
    QFrame *line_1;
    QFrame *line_2;
    QTextBrowser *messageView;
    QTextBrowser *helpTextBrowser;
    QTextBrowser *channelsTextBrowser;
    QListWidget *channelsListWidget;
    QMenuBar *menuBar;
    QMenu *menuActions;

    void setupUi(QMainWindow *Messenger)
    {
        if (Messenger->objectName().isEmpty())
            Messenger->setObjectName(QStringLiteral("Messenger"));
        Messenger->resize(1097, 647);
        QPalette palette;
        QBrush brush(QColor(76, 76, 76, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(96, 167, 163, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        QBrush brush2(QColor(234, 226, 210, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush2);
        QBrush brush3(QColor(248, 44, 44, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        QBrush brush4(QColor(18, 17, 13, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette.setBrush(QPalette::Active, QPalette::Window, brush4);
        QBrush brush5(QColor(122, 173, 119, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush5);
        QBrush brush6(QColor(220, 226, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        QBrush brush7(QColor(159, 158, 158, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        QBrush brush8(QColor(240, 240, 240, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        Messenger->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Utopia"));
        font.setPointSize(13);
        Messenger->setFont(font);
        Messenger->setAutoFillBackground(true);
        actionChange_Name = new QAction(Messenger);
        actionChange_Name->setObjectName(QStringLiteral("actionChange_Name"));
        actionJoin_Channel = new QAction(Messenger);
        actionJoin_Channel->setObjectName(QStringLiteral("actionJoin_Channel"));
        actionCreate_Channel = new QAction(Messenger);
        actionCreate_Channel->setObjectName(QStringLiteral("actionCreate_Channel"));
        centralWidget = new QWidget(Messenger);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        inputText = new QTextEdit(centralWidget);
        inputText->setObjectName(QStringLiteral("inputText"));
        inputText->setGeometry(QRect(180, 510, 651, 101));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        inputText->setPalette(palette1);
        inputText->setFont(font);
        inputText->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        inputText->setMouseTracking(false);
        inputText->setLineWidth(2);
        inputText->setMidLineWidth(2);
        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setEnabled(true);
        sendButton->setGeometry(QRect(840, 510, 81, 101));
        sendButton->setAutoFillBackground(true);
        sendButton->setCheckable(false);
        sendButton->setAutoDefault(false);
        sendButton->setFlat(true);
        line_1 = new QFrame(centralWidget);
        line_1->setObjectName(QStringLiteral("line_1"));
        line_1->setGeometry(QRect(160, 10, 20, 601));
        line_1->setFrameShape(QFrame::VLine);
        line_1->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(930, 10, 20, 601));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        messageView = new QTextBrowser(centralWidget);
        messageView->setObjectName(QStringLiteral("messageView"));
        messageView->setGeometry(QRect(180, 10, 741, 491));
        QFont font1;
        font1.setFamily(QStringLiteral("Utopia"));
        font1.setPointSize(16);
        messageView->setFont(font1);
        messageView->setLineWidth(2);
        messageView->setMidLineWidth(2);
        messageView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        messageView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        helpTextBrowser = new QTextBrowser(centralWidget);
        helpTextBrowser->setObjectName(QStringLiteral("helpTextBrowser"));
        helpTextBrowser->setGeometry(QRect(960, 10, 121, 571));
        QFont font2;
        font2.setPointSize(11);
        helpTextBrowser->setFont(font2);
        helpTextBrowser->setFrameShape(QFrame::NoFrame);
        helpTextBrowser->setFrameShadow(QFrame::Plain);
        helpTextBrowser->setLineWidth(0);
        helpTextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        helpTextBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        helpTextBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        channelsTextBrowser = new QTextBrowser(centralWidget);
        channelsTextBrowser->setObjectName(QStringLiteral("channelsTextBrowser"));
        channelsTextBrowser->setGeometry(QRect(10, 10, 141, 581));
        channelsTextBrowser->setFont(font2);
        channelsTextBrowser->setFrameShape(QFrame::NoFrame);
        channelsTextBrowser->setFrameShadow(QFrame::Plain);
        channelsTextBrowser->setLineWidth(0);
        channelsTextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        channelsTextBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        channelsTextBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        channelsListWidget = new QListWidget(centralWidget);
        channelsListWidget->setObjectName(QStringLiteral("channelsListWidget"));
        channelsListWidget->setGeometry(QRect(10, 40, 151, 192));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush4);
        QBrush brush9(QColor(97, 159, 224, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush4);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        channelsListWidget->setPalette(palette2);
        QFont font3;
        font3.setKerning(true);
        channelsListWidget->setFont(font3);
        channelsListWidget->setAutoFillBackground(true);
        channelsListWidget->setFrameShape(QFrame::NoFrame);
        channelsListWidget->setAlternatingRowColors(true);
        channelsListWidget->setWordWrap(true);
        Messenger->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Messenger);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1097, 29));
        menuActions = new QMenu(menuBar);
        menuActions->setObjectName(QStringLiteral("menuActions"));
        Messenger->setMenuBar(menuBar);

        menuBar->addAction(menuActions->menuAction());
        menuActions->addAction(actionChange_Name);
        menuActions->addAction(actionJoin_Channel);
        menuActions->addAction(actionCreate_Channel);

        retranslateUi(Messenger);

        sendButton->setDefault(false);


        QMetaObject::connectSlotsByName(Messenger);
    } // setupUi

    void retranslateUi(QMainWindow *Messenger)
    {
        Messenger->setWindowTitle(QApplication::translate("Messenger", "Messenger", 0));
        actionChange_Name->setText(QApplication::translate("Messenger", "Change Name", 0));
        actionJoin_Channel->setText(QApplication::translate("Messenger", "Join Channel", 0));
        actionCreate_Channel->setText(QApplication::translate("Messenger", "Create Channel", 0));
        sendButton->setText(QApplication::translate("Messenger", "Send", 0));
        menuActions->setTitle(QApplication::translate("Messenger", "Actions", 0));
    } // retranslateUi

};

namespace Ui {
    class Messenger: public Ui_Messenger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSENGER_H
