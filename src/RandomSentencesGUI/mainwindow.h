#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <string>
#include <sstream>
#include "WordsGenerator.h"
#include "ComputingThread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_clicked();

    void changeStats(Stats stats);

    void computingTerminated();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void computingProgressed(double percent);

    void on_toolButton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow    * ui;
    WordsGenerator    * wg;
    std::string         phrase,
                        graine;
    int                 iterations;
    ComputingThread   * mThread;
    std::ostringstream  sortie;
};

#endif // MAINWINDOW_H
