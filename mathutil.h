#ifndef MATHUTIL_H
#define MATHUTIL_H
#include <QProgressBar>

class MathUtil
{
public:
    MathUtil();

    static bool canDivide(int divided, int division);
    static int* createIntegerNumbersArray(int capacity);

};

#endif // MATHUTIL_H
