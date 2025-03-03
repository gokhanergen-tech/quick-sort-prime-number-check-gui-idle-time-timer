#include "timerbase.h"
#include <QPushButton>

TimerBase::TimerBase(QPushButton *startButton,QPushButton *stopButton,QPushButton *pauseButton,QObject *parent)
    : QObject{parent}, startButton{startButton},stopButton{stopButton}, pauseButton{pauseButton}
{
     connect(&timer, &QTimer::timeout, this, &TimerBase::onTimeout);
     connect(startButton, &QPushButton::clicked,this, &TimerBase::start);
     connect(pauseButton, &QPushButton::clicked,this, &TimerBase::pause);
     connect(stopButton, &QPushButton::clicked,this,  &TimerBase::stop);
}

void TimerBase::start() {
    if(stateProcess!="pause")
        this->reset();
    stateProcess = "start";
    this->startButton->setDisabled(true);
    timer.start(timeout);
}

void TimerBase::pause() {
    timer.stop();
    stateProcess = "pause";
    this->startButton->setDisabled(false);
}
void TimerBase::stop(bool resetDisable) {
    stateProcess = "stop";
    if(!resetDisable)
        reset();

    this->startButton->setDisabled(false);
    timer.stop();
}

void TimerBase::updateTimeout(int ms){
    timeout = ms;
}

void TimerBase::onTimeout()
{
    qDebug() << "Timeout occurred in TimerBase";
}

void TimerBase::reset()
{
    qDebug() << "Resetting timer in TimerBase";
}
