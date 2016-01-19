/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOuvrir;
    QAction *actionQuitter;
    QAction *actionAide;
    QAction *actionA_propos;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *displayIgnore;
    QLineEdit *displayPrincipal;
    QLabel *label_2;
    QPushButton *defaultIgnore;
    QPushButton *browseIgnore;
    QLineEdit *displaySeparator;
    QPushButton *defaultSeparator;
    QPushButton *browseSeparator;
    QLabel *label_3;
    QLabel *label;
    QPushButton *browsePrincipal;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QPushButton *extract;
    QProgressBar *progressBar;
    QTextEdit *textZone;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(848, 398);
        MainWindow->setMinimumSize(QSize(641, 240));
        MainWindow->setBaseSize(QSize(320, 240));
        MainWindow->setMouseTracking(false);
        actionOuvrir = new QAction(MainWindow);
        actionOuvrir->setObjectName(QStringLiteral("actionOuvrir"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionAide = new QAction(MainWindow);
        actionAide->setObjectName(QStringLiteral("actionAide"));
        actionA_propos = new QAction(MainWindow);
        actionA_propos->setObjectName(QStringLiteral("actionA_propos"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 339, 188));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        displayIgnore = new QLineEdit(layoutWidget);
        displayIgnore->setObjectName(QStringLiteral("displayIgnore"));
        displayIgnore->setReadOnly(true);

        gridLayout->addWidget(displayIgnore, 3, 0, 1, 4);

        displayPrincipal = new QLineEdit(layoutWidget);
        displayPrincipal->setObjectName(QStringLiteral("displayPrincipal"));
        displayPrincipal->setReadOnly(true);

        gridLayout->addWidget(displayPrincipal, 1, 0, 1, 4);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 2);

        defaultIgnore = new QPushButton(layoutWidget);
        defaultIgnore->setObjectName(QStringLiteral("defaultIgnore"));

        gridLayout->addWidget(defaultIgnore, 2, 3, 1, 1);

        browseIgnore = new QPushButton(layoutWidget);
        browseIgnore->setObjectName(QStringLiteral("browseIgnore"));

        gridLayout->addWidget(browseIgnore, 2, 2, 1, 1);

        displaySeparator = new QLineEdit(layoutWidget);
        displaySeparator->setObjectName(QStringLiteral("displaySeparator"));
        displaySeparator->setReadOnly(true);

        gridLayout->addWidget(displaySeparator, 6, 0, 1, 4);

        defaultSeparator = new QPushButton(layoutWidget);
        defaultSeparator->setObjectName(QStringLiteral("defaultSeparator"));

        gridLayout->addWidget(defaultSeparator, 4, 3, 1, 1);

        browseSeparator = new QPushButton(layoutWidget);
        browseSeparator->setObjectName(QStringLiteral("browseSeparator"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(browseSeparator->sizePolicy().hasHeightForWidth());
        browseSeparator->setSizePolicy(sizePolicy);

        gridLayout->addWidget(browseSeparator, 4, 2, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 2);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        browsePrincipal = new QPushButton(layoutWidget);
        browsePrincipal->setObjectName(QStringLiteral("browsePrincipal"));

        gridLayout->addWidget(browsePrincipal, 0, 2, 1, 1);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(360, 0, 421, 331));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        extract = new QPushButton(layoutWidget1);
        extract->setObjectName(QStringLiteral("extract"));
        extract->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(extract, 0, 0, 1, 1);

        progressBar = new QProgressBar(layoutWidget1);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout_2->addWidget(progressBar, 0, 1, 1, 1);

        textZone = new QTextEdit(layoutWidget1);
        textZone->setObjectName(QStringLiteral("textZone"));
        textZone->setReadOnly(true);

        gridLayout_2->addWidget(textZone, 1, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 848, 20));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menu->menuAction());
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menu->addAction(actionAide);
        menu->addAction(actionA_propos);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Nuage de Mots", 0));
        actionOuvrir->setText(QApplication::translate("MainWindow", "Ouvrir ...", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        actionAide->setText(QApplication::translate("MainWindow", "Aide", 0));
        actionA_propos->setText(QApplication::translate("MainWindow", "A propos", 0));
        displayPrincipal->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Mots \303\240 ignorer", 0));
        defaultIgnore->setText(QApplication::translate("MainWindow", "Par d\303\251faut", 0));
        browseIgnore->setText(QApplication::translate("MainWindow", "Parcourir ...", 0));
        defaultSeparator->setText(QApplication::translate("MainWindow", "Par d\303\251faut", 0));
        browseSeparator->setText(QApplication::translate("MainWindow", "Parcourir ...", 0));
        label_3->setText(QApplication::translate("MainWindow", "S\303\251parateurs", 0));
        label->setText(QApplication::translate("MainWindow", "Fichier principal", 0));
        browsePrincipal->setText(QApplication::translate("MainWindow", "Parcourir ...", 0));
        extract->setText(QApplication::translate("MainWindow", "Extraction", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menu->setTitle(QApplication::translate("MainWindow", "?", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
