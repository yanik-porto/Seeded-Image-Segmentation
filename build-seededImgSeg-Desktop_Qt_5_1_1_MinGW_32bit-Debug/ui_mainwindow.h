/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "imglabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    imgLabel *label_image;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_load;
    QPushButton *pushButton_draw;
    QPushButton *pushButton_extract;
    QLabel *label_drawing;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(779, 542);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 10, 721, 481));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_image = new imgLabel(widget);
        label_image->setObjectName(QStringLiteral("label_image"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_image->sizePolicy().hasHeightForWidth());
        label_image->setSizePolicy(sizePolicy);
        label_image->setFrameShape(QFrame::Box);
        label_image->setFrameShadow(QFrame::Plain);
        label_image->setScaledContents(false);
        label_image->setWordWrap(false);

        horizontalLayout->addWidget(label_image);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        pushButton_load = new QPushButton(widget);
        pushButton_load->setObjectName(QStringLiteral("pushButton_load"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_load->sizePolicy().hasHeightForWidth());
        pushButton_load->setSizePolicy(sizePolicy1);
        pushButton_load->setMinimumSize(QSize(210, 50));
        QIcon icon;
        icon.addFile(QStringLiteral(":/MyIcons/png/photos13.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_load->setIcon(icon);

        verticalLayout->addWidget(pushButton_load);

        pushButton_draw = new QPushButton(widget);
        pushButton_draw->setObjectName(QStringLiteral("pushButton_draw"));
        pushButton_draw->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_draw->sizePolicy().hasHeightForWidth());
        pushButton_draw->setSizePolicy(sizePolicy1);
        pushButton_draw->setMinimumSize(QSize(210, 50));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/MyIcons/png/paint86.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_draw->setIcon(icon1);
        pushButton_draw->setCheckable(true);

        verticalLayout->addWidget(pushButton_draw);

        pushButton_extract = new QPushButton(widget);
        pushButton_extract->setObjectName(QStringLiteral("pushButton_extract"));
        sizePolicy1.setHeightForWidth(pushButton_extract->sizePolicy().hasHeightForWidth());
        pushButton_extract->setSizePolicy(sizePolicy1);
        pushButton_extract->setMinimumSize(QSize(210, 50));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/MyIcons/png/photo24.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_extract->setIcon(icon2);

        verticalLayout->addWidget(pushButton_extract);


        horizontalLayout->addLayout(verticalLayout);

        label_drawing = new QLabel(widget);
        label_drawing->setObjectName(QStringLiteral("label_drawing"));
        sizePolicy.setHeightForWidth(label_drawing->sizePolicy().hasHeightForWidth());
        label_drawing->setSizePolicy(sizePolicy);
        label_drawing->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(label_drawing);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 779, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_image->setText(QString());
        pushButton_load->setText(QApplication::translate("MainWindow", "Load", 0));
        pushButton_draw->setText(QApplication::translate("MainWindow", "Draw", 0));
        pushButton_extract->setText(QApplication::translate("MainWindow", "extract", 0));
        label_drawing->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
