#include "mathutil.h"
#include <iostream>
#include <random>
#include <QProgressBar>

MathUtil::MathUtil() {}

bool MathUtil::canDivide(int number, int number2){
    return number%number2==0;
}

/**
 * @brief Creates an array of random integers within a specified range.
 *
 * This function generates an array of integers with a specified capacity.
 * The integers are randomly generated within the range of -100000 to 100000
 * using a uniform distribution. The array is dynamically allocated and must
 * be deallocated by the caller to prevent memory leaks.
 *
 * @param capacity The number of integers to generate in the array.
 * @return A pointer to the dynamically allocated array of integers.
 *
 * @note The caller is responsible for deleting the array to avoid memory leaks.
 */
int* MathUtil::createIntegerNumbersArray(int capacity) {
    auto numbers = new int[capacity];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(-100000, 100000);

    for(int n = 0; n < capacity; ++n)
        numbers[n] = distr(gen);

    return numbers;
}
