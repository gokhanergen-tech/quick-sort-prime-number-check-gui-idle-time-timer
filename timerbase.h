#ifndef TIMERBASE_H
#define TIMERBASE_H

#include <QObject>
#include <QTimer>
#include <QPushButton>

/**
 * @brief The TimerBase class
 *
 * TimerBase is a base class that provides timer functionality.
 * It includes basic functions like start, stop, pause, and updating timeout.
 *
 * @note Uses Qt's `QTimer` class to manage timer operations.
 */
class TimerBase : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief TimerBase constructor
     *
     * @param startButton Start button
     * @param stopButton Stop button
     * @param pauseButton Pause button
     * @param parent Parent object (default is nullptr)
     */
    explicit TimerBase(QPushButton *startButton,
                       QPushButton *stopButton,
                       QPushButton *pauseButton,
                       QObject *parent = nullptr);

protected slots:
    /**
     * @brief Virtual function called on timeout event.
     *
     * This function is triggered when the timer expires. It can be overridden in derived classes.
     */
    virtual void onTimeout();

    /**
     * @brief Resets the timer to default states.
     *
     * This function can be overridden in derived classes to reset the timer's state.
     */
    virtual void reset();

    /**
     * @brief Starts the timer.
     *
     * If the process is not in "pause" state, it will reset the timer and start it.
     */
    virtual void start();

    /**
     * @brief Pauses the timer.
     *
     * Stops the timer and changes the process state to "pause".
     */
    void pause();

    /**
     * @brief Stops the timer.
     *
     * @param resetDisable If false, the timer will be reset.
     *
     * This function can be overridden in derived classes.
     */
    virtual void stop(bool resetDisable);

    /**
     * @brief Updates the timeout value of the timer.
     *
     * @param ms The new timeout value in milliseconds.
     */
    void updateTimeout(int ms);

private:
    QTimer timer;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *pauseButton;
    std::string stateProcess = "stop";
    int timeout = 0;
};


#endif // TIMERBASE_H
