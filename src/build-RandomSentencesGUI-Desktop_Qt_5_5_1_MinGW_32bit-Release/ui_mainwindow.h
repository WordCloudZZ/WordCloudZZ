/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QSpinBox *spinBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QToolButton *toolButton;
    QLineEdit *alphabet;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QLabel *labelUnitTime;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QFrame *line;
    QLabel *labelTime;
    QLabel *labelConfidence;
    QLabel *labelVariance;
    QLabel *labelFrequency;
    QLabel *labelAverage;
    QLabel *label_6;
    QLabel *label_11;
    QLabel *labelTotal;
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QListWidget *listEch;
    QLabel *label_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setMinimumSize(QSize(800, 480));
        MainWindow->setMaximumSize(QSize(800, 480));
        QIcon icon;
        QString iconThemeName = QStringLiteral("dice.png");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QStringLiteral(""));
        MainWindow->setAnimated(true);
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 621, 201));
        groupBox->setStyleSheet(QStringLiteral(""));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 40, 471, 21));
        lineEdit->setStyleSheet(QLatin1String("background: white;\n"
"color: black;"));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(140, 80, 131, 21));
        spinBox->setMaximum(9999999);
        spinBox->setValue(10);
        spinBox->setDisplayIntegerBase(10);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 121, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 121, 21));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(140, 120, 431, 21));
        lineEdit_3->setStyleSheet(QLatin1String("background: white;\n"
"color: black;"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 120, 121, 21));
        toolButton = new QToolButton(groupBox);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(580, 120, 31, 21));
        alphabet = new QLineEdit(groupBox);
        alphabet->setObjectName(QStringLiteral("alphabet"));
        alphabet->setGeometry(QRect(10, 160, 601, 21));
        alphabet->setStyleSheet(QLatin1String("background: white;\n"
"color: black;"));
        alphabet->setReadOnly(true);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 270, 421, 191));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 20, 181, 21));
        labelUnitTime = new QLabel(groupBox_2);
        labelUnitTime->setObjectName(QStringLiteral("labelUnitTime"));
        labelUnitTime->setGeometry(QRect(240, 160, 161, 21));
        labelUnitTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 80, 131, 21));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 100, 131, 21));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 160, 131, 21));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 140, 131, 21));
        line = new QFrame(groupBox_2);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 120, 381, 21));
        line->setStyleSheet(QStringLiteral("font-weight: bold;"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        labelTime = new QLabel(groupBox_2);
        labelTime->setObjectName(QStringLiteral("labelTime"));
        labelTime->setGeometry(QRect(240, 140, 161, 21));
        labelTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelConfidence = new QLabel(groupBox_2);
        labelConfidence->setObjectName(QStringLiteral("labelConfidence"));
        labelConfidence->setGeometry(QRect(240, 100, 161, 21));
        labelConfidence->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelVariance = new QLabel(groupBox_2);
        labelVariance->setObjectName(QStringLiteral("labelVariance"));
        labelVariance->setGeometry(QRect(240, 80, 161, 21));
        labelVariance->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelFrequency = new QLabel(groupBox_2);
        labelFrequency->setObjectName(QStringLiteral("labelFrequency"));
        labelFrequency->setGeometry(QRect(240, 20, 161, 21));
        labelFrequency->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelAverage = new QLabel(groupBox_2);
        labelAverage->setObjectName(QStringLiteral("labelAverage"));
        labelAverage->setGeometry(QRect(240, 40, 161, 21));
        labelAverage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 40, 181, 21));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 60, 181, 21));
        labelTotal = new QLabel(groupBox_2);
        labelTotal->setObjectName(QStringLiteral("labelTotal"));
        labelTotal->setGeometry(QRect(240, 60, 161, 21));
        labelTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(10, 230, 461, 21));
        progressBar->setValue(0);
        progressBar->setTextVisible(true);
        progressBar->setInvertedAppearance(false);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(480, 220, 131, 41));
        pushButton->setStyleSheet(QStringLiteral("font-weight: bold;"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(480, 270, 131, 41));
        pushButton_3->setStyleSheet(QStringLiteral(""));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(480, 320, 131, 41));
        pushButton_4->setStyleSheet(QStringLiteral(""));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(480, 370, 131, 41));
        pushButton_5->setStyleSheet(QStringLiteral(""));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(480, 420, 131, 41));
        pushButton_6->setStyleSheet(QStringLiteral(""));
        listEch = new QListWidget(centralWidget);
        listEch->setObjectName(QStringLiteral("listEch"));
        listEch->setGeometry(QRect(650, 40, 141, 421));
        listEch->setStyleSheet(QStringLiteral("font-weight: bold;"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(650, 20, 151, 16));
        label_3->setStyleSheet(QStringLiteral(""));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "R\303\251glages", 0));
        spinBox->setPrefix(QString());
        label->setText(QApplication::translate("MainWindow", "Phrase \303\240 g\303\251n\303\251rer", 0));
        label_2->setText(QApplication::translate("MainWindow", "Nombre de g\303\251n\303\251rations", 0));
        label_4->setText(QApplication::translate("MainWindow", "Alphabet de g\303\251n\303\251ration", 0));
        toolButton->setText(QApplication::translate("MainWindow", "...", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "R\303\251sultats", 0));
        label_5->setText(QApplication::translate("MainWindow", "Fr\303\251quence d'apparition de la phrase", 0));
        labelUnitTime->setText(QApplication::translate("MainWindow", "0", 0));
        label_7->setText(QApplication::translate("MainWindow", "Ecart type", 0));
        label_8->setText(QApplication::translate("MainWindow", "Intervalle de confiance", 0));
        label_9->setText(QApplication::translate("MainWindow", "Temps d'ex\303\251cution unitaire", 0));
        label_10->setText(QApplication::translate("MainWindow", "Temps d'ex\303\251cution", 0));
        labelTime->setText(QApplication::translate("MainWindow", "0", 0));
        labelConfidence->setText(QApplication::translate("MainWindow", "[ 0 ; 0 ]", 0));
        labelVariance->setText(QApplication::translate("MainWindow", "0", 0));
        labelFrequency->setText(QApplication::translate("MainWindow", "0 %", 0));
        labelAverage->setText(QApplication::translate("MainWindow", "0", 0));
        label_6->setText(QApplication::translate("MainWindow", "Nombre de tirages moyen", 0));
        label_11->setText(QApplication::translate("MainWindow", "Nombre de tirages total", 0));
        labelTotal->setText(QApplication::translate("MainWindow", "0", 0));
        pushButton->setText(QApplication::translate("MainWindow", "G\303\251n\303\251rer", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Remettre \303\240 z\303\251ro", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Aide", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Exporter", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Quitter", 0));
        label_3->setText(QApplication::translate("MainWindow", "Echantillons du processus", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
