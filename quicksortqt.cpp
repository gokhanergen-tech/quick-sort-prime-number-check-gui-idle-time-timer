#include "quicksortqt.h";
#include <QListWidget>
#include <QPushButton>
#include "timerbase.h"
#include "mathutil.h"
#include "inpututil.h"

QuickSortQt::QuickSortQt(QPushButton *startButton,QPushButton *stopButton,QPushButton *pauseButton, QPushButton *generateNumbersButton, QLineEdit *capacityInput,QLineEdit *timeoutInput, QListWidget *listNumbers, QObject *parent)
    : TimerBase{startButton,stopButton,pauseButton, parent},generateNumbersButton{generateNumbersButton},capacityInput{capacityInput},timeoutInput{timeoutInput}, listNumbers{listNumbers}
{
    connect(generateNumbersButton, &QPushButton::clicked,this,&QuickSortQt::generateNumbers);
}

/**
 * @brief QuickSortQt::generateNumbers
 *
 * When clicked generate button, the function will be triggered.
 * It produces an integer array with values between -100,000 and 100,000, with the size specified.
 *
 */
void QuickSortQt::generateNumbers(){
    capacity = InputUtil::getValueAsInt(capacityInput);
    if(capacity > 1){
        int *numbers = MathUtil::createIntegerNumbersArray(capacity);
        listNumbers->setFlow(QListWidget::LeftToRight);
        listNumbers->setWrapping(true); // Satır sonunda bir sonraki satıra geçme
        listNumbers->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        this->arr = numbers;
        reset();
        isSorted = false;
        listNumbers->clear();
        stack.push({0, capacity - 1});
        updateList();
    }
}

void QuickSortQt::updateList(){
    int showCount = capacity < 250?capacity:250;
    if(listNumbers->count()!=showCount){
        for(int i=0;i<showCount;i++){
            listNumbers->addItem(QString::number(arr[i]));
        }
    }else{
        for(int i=0;i<showCount;i++){
            listNumbers->item(i)->setText(QString::number(arr[i]));
        }
    }
}

void QuickSortQt::reset(){
    if(capacity>=2){
        while(!stack.empty()){
            stack.pop();
        }
        stack.push({0, capacity - 1});
    }
}

void QuickSortQt::start(){
    if(capacity <= 1) return;
    updateTimeout(InputUtil::getValueAsInt(timeoutInput));
    TimerBase::start();
}

void QuickSortQt::stop(bool disableReset){
    TimerBase::stop(disableReset);
    listNumbers->clear();
}

/**
 * @brief PrimeNumberQT::onTimeout
 *
 * Timer trigger function
 *
 */
void QuickSortQt::onTimeout(){
    if (stack.empty()) {
        isSorted = true;
        TimerBase::stop(false);
    }else{
        processNextOrder();
        updateList();
    }
}

/**
 * @brief QuickSortQt::processNextOrder
 *
 * The function provides to go next process step. In case of timeout, It is called
 *
 */
void QuickSortQt::processNextOrder(){
    auto [l, h] = stack.top();
    stack.pop();

    if (l >= 0 && l<h){
        int pivot = arr[(l+h)/2];

        int lt = l;
        int eq = l;
        int gt = h;

        while(eq<=gt){
            if (arr[eq] < pivot){
                std::swap(arr[eq], arr[lt]);
                lt++;
                eq++;
            }else if(arr[eq]>pivot){
                std::swap(arr[eq], arr[gt]);
                gt--;
            }else{
                eq++;
            }
        }
        stack.push({l, lt-1});
        stack.push({gt + 1, h});
    }
}
