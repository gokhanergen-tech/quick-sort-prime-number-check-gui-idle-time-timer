#ifndef QUICKSORTQT_H
#define QUICKSORTQT_H

#include <QObject>
#include <QListWidget>
#include <QLineEdit>
#include "timerbase.h"
#include <stack>

/**
 * @brief The QuickSortQt class
 *
 * This class is responsible for implementing the Quick Sort algorithm with a graphical interface.
 * It inherits from TimerBase, allowing it to use a timer for controlling the sorting process.
 * The class handles starting, stopping, pausing, and resetting the sorting process,
 * along with generating numbers and updating the display.
 */
class QuickSortQt : public TimerBase
{
    Q_OBJECT
public:
    /**
     * @brief QuickSortQt constructor
     *
     * Initializes the QuickSortQt with the provided buttons, inputs, and other UI elements.
     *
     * @param startButton Button to start the sorting process
     * @param stopButton Button to stop the sorting process
     * @param pauseButton Button to pause the sorting process
     * @param generateNumbersButton Button to generate the random numbers
     * @param capacityInput QLineEdit to input the number of elements to be sorted
     * @param timeoutInput QLineEdit to input the timeout for the sorting process
     * @param listNumbers QListWidget to display the numbers being sorted
     * @param parent Parent QObject (default is nullptr)
     */
private slots:
    void generateNumbers();
    void updateList();
    void processNextOrder();

    void reset() override;
    void start() override;
    void stop(bool disableReset) override;
    void onTimeout() override;

private:
    QListWidget *listNumbers;
    QPushButton *generateNumbersButton;
    QLineEdit *capacityInput;
    QLineEdit *timeoutInput;

    int *arr;
    std::stack<std::pair<int, int>> stack;
    bool isSorted = false;
    int capacity=-1;
};

#endif // QUICKSORTQT_H
