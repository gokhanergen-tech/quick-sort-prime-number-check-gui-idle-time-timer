#ifndef PRIMENUMBERQT_H
#define PRIMENUMBERQT_H

#include <QObject>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <string>
#include "timerbase.h"

/**
 * @brief The PrimeNumberQT class
 *
 * This class is responsible for performing the prime number checking process.
 * It inherits from the TimerBase class, enabling timer functionality to control
 * the process and its states. The class includes functionality to start, stop,
 * pause, and reset the process of checking prime numbers.
 */
class PrimeNumberQT : public TimerBase
{
    Q_OBJECT
public:
    /**
     * @brief PrimeNumberQT constructor
     *
     * Initializes the PrimeNumberQT with the provided buttons, label, and other UI elements.
     *
     * @param startButton Start button to begin the prime number check
     * @param stopButton Stop button to stop the process
     * @param pauseButton Pause button to pause the process
     * @param viewProcess QLabel to display the current process state
     * @param lineEdit QLineEdit to input the target number
     * @param progressBar QProgressBar to visually represent the process progress
     * @param parent Parent QObject (default is nullptr)
     */
    explicit PrimeNumberQT(QPushButton *startButton,
                           QPushButton *stopButton,
                           QPushButton *pauseButton,
                           QLabel *viewProcess,
                           QLineEdit *lineEdit,
                           QProgressBar *progressBar,
                           QObject *parent = nullptr);

private slots:
    void reset() override;
    void displayResult(bool canDivideCurrent);
    void endProcess(bool canDivideCurrent);
    void onTimeout() override;



private:
    QLabel *viewProcess;
    QLineEdit *lineEdit;
    QProgressBar *progressBar;
    QTimer timer;

    int startNumber = 2;
    int currentNumber = 2;
    int targetNumber = 0;
    int maxProgress = 2;
    bool hasDividedNumber = false;
    std::string stateProcess = "stop";
};

#endif // PRIMENUMBERQT_H
