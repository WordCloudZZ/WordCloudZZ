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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
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
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QTextEdit *textZone;
    QPushButton *extract;
    QSpinBox *nbSelect;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout;
    QPushButton *defaultSeparator;
    QPushButton *defaultIgnore;
    QLabel *label_2;
    QPushButton *browseIgnore;
    QLabel *label;
    QLineEdit *displaySeparator;
    QPushButton *browseSeparator;
    QLabel *label_3;
    QLineEdit *displayPrincipal;
    QLineEdit *displayIgnore;
    QSpacerItem *verticalSpacer;
    QPushButton *browsePrincipal;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(803, 388);
        MainWindow->setMinimumSize(QSize(803, 388));
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
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        textZone = new QTextEdit(centralWidget);
        textZone->setObjectName(QStringLiteral("textZone"));
        textZone->setReadOnly(true);

        gridLayout_2->addWidget(textZone, 8, 0, 1, 4);

        extract = new QPushButton(centralWidget);
        extract->setObjectName(QStringLiteral("extract"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(extract->sizePolicy().hasHeightForWidth());
        extract->setSizePolicy(sizePolicy);
        extract->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(extract, 0, 3, 1, 1);

        nbSelect = new QSpinBox(centralWidget);
        nbSelect->setObjectName(QStringLiteral("nbSelect"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nbSelect->sizePolicy().hasHeightForWidth());
        nbSelect->setSizePolicy(sizePolicy1);
        nbSelect->setBaseSize(QSize(0, 0));
        nbSelect->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        nbSelect->setMinimum(1);
        nbSelect->setMaximum(500);

        gridLayout_2->addWidget(nbSelect, 0, 1, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        defaultSeparator = new QPushButton(centralWidget);
        defaultSeparator->setObjectName(QStringLiteral("defaultSeparator"));

        gridLayout->addWidget(defaultSeparator, 4, 3, 1, 1);

        defaultIgnore = new QPushButton(centralWidget);
        defaultIgnore->setObjectName(QStringLiteral("defaultIgnore"));
        sizePolicy1.setHeightForWidth(defaultIgnore->sizePolicy().hasHeightForWidth());
        defaultIgnore->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(defaultIgnore, 2, 3, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 2);

        browseIgnore = new QPushButton(centralWidget);
        browseIgnore->setObjectName(QStringLiteral("browseIgnore"));

        gridLayout->addWidget(browseIgnore, 2, 2, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        displaySeparator = new QLineEdit(centralWidget);
        displaySeparator->setObjectName(QStringLiteral("displaySeparator"));
        displaySeparator->setReadOnly(true);

        gridLayout->addWidget(displaySeparator, 5, 0, 1, 4);

        browseSeparator = new QPushButton(centralWidget);
        browseSeparator->setObjectName(QStringLiteral("browseSeparator"));
        sizePolicy1.setHeightForWidth(browseSeparator->sizePolicy().hasHeightForWidth());
        browseSeparator->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(browseSeparator, 4, 2, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 2);

        displayPrincipal = new QLineEdit(centralWidget);
        displayPrincipal->setObjectName(QStringLiteral("displayPrincipal"));
        displayPrincipal->setReadOnly(true);

        gridLayout->addWidget(displayPrincipal, 1, 0, 1, 4);

        displayIgnore = new QLineEdit(centralWidget);
        displayIgnore->setObjectName(QStringLiteral("displayIgnore"));
        displayIgnore->setReadOnly(true);

        gridLayout->addWidget(displayIgnore, 3, 0, 1, 4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 4);

        browsePrincipal = new QPushButton(centralWidget);
        browsePrincipal->setObjectName(QStringLiteral("browsePrincipal"));
        browsePrincipal->setEnabled(true);
        sizePolicy1.setHeightForWidth(browsePrincipal->sizePolicy().hasHeightForWidth());
        browsePrincipal->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(browsePrincipal, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 803, 20));
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
        extract->setText(QApplication::translate("MainWindow", "Extraction", 0));
        label_4->setText(QApplication::translate("MainWindow", "Nombre de mots", 0));
        defaultSeparator->setText(QApplication::translate("MainWindow", "Par d\303\251faut", 0));
        defaultIgnore->setText(QApplication::translate("MainWindow", "Par d\303\251faut", 0));
        label_2->setText(QApplication::translate("MainWindow", "Mots \303\240 ignorer", 0));
        browseIgnore->setText(QApplication::translate("MainWindow", "Parcourir ...", 0));
        label->setText(QApplication::translate("MainWindow", "Fichier principal", 0));
        browseSeparator->setText(QApplication::translate("MainWindow", "Parcourir ...", 0));
        label_3->setText(QApplication::translate("MainWindow", "S\303\251parateurs", 0));
        displayPrincipal->setText(QString());
        browsePrincipal->setText(QApplication::translate("MainWindow", "Parcourir ...", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menu->setTitle(QApplication::translate("MainWindow", "?", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
