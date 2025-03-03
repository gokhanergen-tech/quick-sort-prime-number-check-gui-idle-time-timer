#include "primenumberqt.h"
#include <QIntValidator>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include "timerbase.h"
#include "inpututil.h"
#include "mathutil.h"

PrimeNumberQT::PrimeNumberQT(QPushButton *startButton,QPushButton *stopButton,QPushButton *pauseButton, QLabel *viewProcess, QLineEdit *lineEdit, QProgressBar *progressBar, QObject *parent)
    : TimerBase{startButton,stopButton,pauseButton, parent},viewProcess{viewProcess}, lineEdit{lineEdit}, progressBar{progressBar}
{
    int maxVal = std::numeric_limits<int>::max();
    QIntValidator *validator = new QIntValidator(2, maxVal, this);
    lineEdit->setValidator(validator);
}

void PrimeNumberQT::reset(){
    int value = InputUtil::getValueAsInt(lineEdit);
    viewProcess->setText("");
    maxProgress = value<=2?2:value/2;
    progressBar->setRange(0,maxProgress);
    progressBar->setValue(0);
    targetNumber = value;
    currentNumber = startNumber;
}

void PrimeNumberQT::displayResult(bool canDivideCurrent){
    if(canDivideCurrent){
        viewProcess->setText("This is not a prime number.");
    }else{
        viewProcess->setText("This is a prime number.");
    }
}

void PrimeNumberQT::endProcess(bool canDivideCurrent){
    this->progressBar->setValue(maxProgress);
    stop(true);
    displayResult(canDivideCurrent);
}

void PrimeNumberQT::onTimeout(){
    if(this->targetNumber==2){
        endProcess(false);
        return;
    }
    if(this->targetNumber<2){
        endProcess(true);
        return;
    }

    bool canDivideCurrent = MathUtil::canDivide(this->targetNumber, this->currentNumber);

    if(canDivideCurrent || maxProgress<=currentNumber){
        endProcess(canDivideCurrent);
    }else{
        currentNumber++;
        this->progressBar->setValue(currentNumber);
    }
}
