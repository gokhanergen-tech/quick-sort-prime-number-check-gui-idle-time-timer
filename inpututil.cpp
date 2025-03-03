#include "inpututil.h"

InputUtil::InputUtil() {}

/**
 * @brief InputUtil::getValueAsInt
 *
 * Parse the input as integer number
 *
 * @param input, it can take as QLineEdit type
 * @return the integer value of input data
 */
int InputUtil::getValueAsInt(QLineEdit *input){
    if (input == nullptr) {
        return 0;
    }

    QString STRING_NUM = input->text();

    if (STRING_NUM.isEmpty()) {
        return 0;
    }

    int value = STRING_NUM.toInt();


    if (STRING_NUM != QString::number(value)) {
        return 0;
    }

    return value;
}
