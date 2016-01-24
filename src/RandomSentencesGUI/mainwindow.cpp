#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Générateur de phrases aléatoires");
    iterations = ui->spinBox->value();
    qRegisterMetaType<Stats>("Stats");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete wg;
    delete mThread;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    phrase = arg1.toStdString();
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    iterations = arg1;
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    graine = arg1.toStdString();
}

void MainWindow::on_pushButton_clicked()
{
    /// declaration
    //std::ostringstream flux;
    //std::string result;

    /// on bloque les boutons
    this->ui->pushButton->setDisabled(true);
    this->ui->pushButton_3->setDisabled(true);
    this->ui->pushButton_4->setDisabled(true);
    this->ui->pushButton_5->setDisabled(true);
    this->ui->pushButton_6->setDisabled(true);
    update();

    /// on verifie les entrees
    iterations = iterations < 1 ? 1 : iterations;

    /// on cree le traitement
    wg = new WordsGenerator(graine);
    mThread = new ComputingThread(wg, phrase, iterations);
    QObject::connect(mThread, SIGNAL(computingEnded(Stats)), this, SLOT(changeStats(Stats)));
    QObject::connect(mThread, SIGNAL(terminated()), this, SLOT(computingTerminated()));
    mThread->start(QThread::TimeCriticalPriority);

/*
    result = flux.str();
    std::cout << result;*/

}

void MainWindow::changeStats(Stats stats) {
    unsigned long long rayon = stats.radius();
    ui->labelAverage->setText(QString::number((unsigned long long)stats.average()));
    ui->labelVariance->setText(QString::number((unsigned long long)stats.variance()));
    ui->labelTime->setText(QString::number(stats.time()));
    ui->labelUnitTime->setText(QString::number(stats.time()/stats.number()));
    ui->labelConfidence->setText("[ "+QString::number((unsigned long long)(stats.average()-rayon))+" ; "+QString::number((unsigned long long)(stats.average()+rayon))+" ]");

    this->ui->pushButton->setDisabled(false);
    this->ui->pushButton_3->setDisabled(false);
    this->ui->pushButton_4->setDisabled(false);
    this->ui->pushButton_5->setDisabled(false);
    this->ui->pushButton_6->setDisabled(false);
}

void MainWindow::computingTerminated() {
    delete mThread;
}

void MainWindow::on_pushButton_3_clicked() {
    ui->labelAverage->setText("0");
    ui->labelVariance->setText("0");
    ui->labelTime->setText("0");
    ui->labelUnitTime->setText("0");
    ui->labelConfidence->setText("[ 0 ; 0 ]");

    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->spinBox->setValue(10);
}
