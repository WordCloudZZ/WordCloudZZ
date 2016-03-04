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
    QObject::connect(ui->pushButton_6, SIGNAL(clicked()), qApp, SLOT(quit()));
    wg = NULL;
    mThread = NULL;
    graine = "Le hasard ne fait pas de phrase.";
    setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "/dice.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
    if(NULL!=wg)
        delete wg;
    if(NULL!=mThread)
        delete mThread;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1) {
    phrase = arg1.toLatin1().toStdString();
}

void MainWindow::on_spinBox_valueChanged(int arg1) {
    iterations = arg1;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->pushButton->text()=="Générer") {
        std::string alpha;
        if(this->ui->lineEdit_3->text().isEmpty() || !QFile::exists(this->ui->lineEdit_3->text())) {
            alpha = "alphabet.az";
        } else {
            alpha = ui->lineEdit_3->text().toStdString();
        }
        if(!QFile::exists(this->ui->lineEdit_3->text())) {
            QMessageBox::warning(this, "Fichier inexistant", "Le fichier renseigné n'existe pas, le fichier par défaut va donc être utilisé.");
        }

        /// on bloque les boutons
        this->ui->pushButton->setText("Annuler");
        this->ui->pushButton_3->setDisabled(true);
        this->ui->pushButton_4->setDisabled(true);
        this->ui->pushButton_5->setDisabled(true);
        this->ui->pushButton_6->setDisabled(true);
        this->ui->toolButton->setDisabled(true);
        ui->lineEdit->setDisabled(true);
        ui->lineEdit_3->setDisabled(true);
        ui->spinBox->setDisabled(true);
        ui->progressBar->setValue(0);
        update();

        /// raz results
        resetResults();

        /// on verifie les entrees
        iterations = iterations < 1 ? 1 : iterations;

        /// on cree le traitement
        wg = new WordsGenerator(graine, alpha.c_str());
        sortie << "";
        mThread = new ComputingThread(wg, phrase, iterations, sortie);
        QObject::connect(mThread, SIGNAL(computingEnded(Stats)), this, SLOT(changeStats(Stats)));
        QObject::connect(mThread, SIGNAL(computingProgressed(double)), this, SLOT(computingProgressed(double)));
        mThread->start(QThread::TimeCriticalPriority);

    } else if(ui->pushButton->text()=="Annuler") {
        mThread->getProgThread().exit(0);
        mThread->getProgThread().requestInterruption();
        mThread->getProgThread().terminate();
        mThread->getProgThread().requestInterruption();
        mThread->exit(0);
        mThread->requestInterruption();
        mThread->terminate();
        mThread->requestInterruption();
        changeStats(Stats());
        computingTerminated();
    }

}

void MainWindow::changeStats(Stats stats) {
    unsigned long long rayon = stats.radius();
    ui->labelFrequency->setText(QString::number(100/stats.average())+"%");
    ui->labelAverage->setText(QString::number((unsigned long long)stats.average()));
    ui->labelTotal->setText(QString::number((unsigned long long)stats.total()));
    ui->labelVariance->setText(QString::number((unsigned long long)sqrt(stats.variance())));
    ui->labelTime->setText(QString::number(stats.time()));
    ui->labelUnitTime->setText(QString::number(stats.time()/stats.number()));
    ui->labelConfidence->setText("[ "+QString::number((unsigned long long)((stats.average()-rayon)<0?0:stats.average()-rayon))+" ; "+QString::number((unsigned long long)(stats.average()+rayon))+" ]");

    for(double val : stats.samples()) {
        QListWidgetItem * qlwi = new QListWidgetItem(QString::number((unsigned long long)val));
        unsigned couleur = 150 * (val-stats.min()) / (stats.max()-stats.min());
        qlwi->setBackgroundColor(QColor(50 + couleur, 200 - couleur, 0, 200));
        qlwi->setTextColor(QColor(255,255,255));
        qlwi->setTextAlignment(Qt::AlignRight);
        ui->listEch->addItem(qlwi);
    }

    this->ui->pushButton->setText("Générer");
    this->ui->pushButton_3->setDisabled(false);
    this->ui->pushButton_4->setDisabled(false);
    this->ui->pushButton_5->setDisabled(false);
    this->ui->pushButton_6->setDisabled(false);
    this->ui->toolButton->setDisabled(false);
    ui->lineEdit->setDisabled(false);
    ui->lineEdit_3->setDisabled(false);
    ui->spinBox->setDisabled(false);
    ui->progressBar->setValue(100);
}

void MainWindow::computingTerminated() {
    /// on libere les ressources
    delete mThread;
    mThread = NULL;
    delete wg;
    wg = NULL;
    ui->progressBar->setValue(100);
}

void MainWindow::on_pushButton_3_clicked() {
    resetResults();

    ui->lineEdit->setText("");
    ui->lineEdit_3->setText("");
    ui->spinBox->setValue(10);
    ui->progressBar->setValue(0);
    ui->alphabet->setText("");
}

void MainWindow::resetResults() {
    ui->listEch->clear();
    ui->labelFrequency->setText("0%");
    ui->labelAverage->setText("0");
    ui->labelTotal->setText("0");
    ui->labelVariance->setText("0");
    ui->labelTime->setText("0");
    ui->labelUnitTime->setText("0");
    ui->labelConfidence->setText("[ 0 ; 0 ]");
}

void MainWindow::on_pushButton_4_clicked() {    // Aide
    QMessageBox::question(this, "Aide", "Voici les quelques étapes permettant d'utiliser au mieux ce programme :\n\t1- Entrez la phrase que vous souhaitez étudier ;\n\t2- Choisissez le nombre de générations à effectuer ;\n\t3- Choisissez une chaîne de caractères qui sera votre graine d'aléa ;\n\t4- Sélectionnez le fichier correpondant à votre alphabet de génération ;\n\t5- Cliquez sur générer.\nVous aurez alors l'ensemble des résultats affiché dans le cadre inférieur de la fenêtre et que vous pourrez exporter au format texte.",
            QMessageBox::Ok);
}

void MainWindow::computingProgressed(double percent) {
    ui->progressBar->setValue(percent*100);
}

void MainWindow::on_toolButton_clicked() {
    /// Open file selection window
    QString fichier = QFileDialog::getOpenFileName(this, "Choix du fichier principal", QString(), "Formats supportés (*.txt *.html *.az);;Autre (*)");
    if(fichier.length() != 0) { /// Test if a file is selected
        ui->lineEdit_3->setText(fichier);
        QFile f(fichier);
        if(f.open(QFile::ReadOnly)) {
            QTextStream flux(&f);
            ui->alphabet->setText(flux.readLine());
            f.close();
        }
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Enregistrez vos résultats", QString(), "Formats supportés (*.txt *.html);;Autre (*)");
    QFile f(filename);
    if(f.open(QFile::WriteOnly)) {
        f.write(sortie.str().c_str());
        f.close();
    }
}
