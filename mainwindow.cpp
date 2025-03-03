#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QIntValidator>
#include "primenumberqt.h"
#include "quicksortqt.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Quick Sort And Prime Number Check Simulation");
    primeNumberQT = new PrimeNumberQT(ui->startButton,ui->stopButton,ui->pauseButton, ui->viewProcess, ui->lineEdit, ui->progressBar);
    quickSortQT = new QuickSortQt(ui->startSorting,ui->stopSorting,ui->pauseSorting, ui->generateNumbers, ui->capacityInput, ui->timeoutQuickSort, ui->listWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete primeNumberQT;
    delete quickSortQT;
}

