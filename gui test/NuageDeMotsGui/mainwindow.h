#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QFileDialog>

#include <iostream>
#include <string>

#include "FileReader.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

private :
    IFileReader * fr;
    std::string buff[3];
    std::string buff0;
    std::string buff1;
    std::string buff2;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setDefaultFiles(const std::string &, const std::string &, const std::string &);

private slots:
    void on_actionQuitter_triggered();

    void on_browsePrincipal_clicked();

    void on_browseIgnore_clicked();

    void on_browseSeparator_clicked();

    void on_extract_clicked();

    void on_defaultIgnore_clicked();

    void on_defaultSeparator_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
