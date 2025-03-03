#ifndef INPUTUTIL_H
#define INPUTUTIL_H

#include <QLineEdit>

class InputUtil
{
public:
    InputUtil();

    static int getValueAsInt(QLineEdit *input);
};

#endif // INPUTUTIL_H
