// Copyright 2022 UNN-IASR
#include <math.h>
#include <ctype.h>

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;

    while (*str != '\0') {
        if (isspace(*str)) {
            if (inWord && !hasDigit) {
                count++;
            }
            inWord = false;
            hasDigit = false;
        } else {
            if (!inWord) {
                inWord = true;
            }
            if (isdigit(*str)) {
                hasDigit = true;
            }
        }
        str++;
    }

    if (inWord && !hasDigit) {
        count++;
    }

    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool startsWithUpper = false;
    bool onlyLowercase = true;

    while (*str != '\0') {
        if (isspace(*str)) {
            if (inWord && startsWithUpper && onlyLowercase) {
                count++;
            }
            inWord = false;
            startsWithUpper = false;
            onlyLowercase = true;
        } else {
            if (!inWord) {
                inWord = true;
                startsWithUpper = isupper(*str);
            }
            if (!islower(*str) && !startsWithUpper) {
                onlyLowercase = false;
            }
        }
        str++;
    }

    if (inWord && startsWithUpper && onlyLowercase) {
        count++;
    }

    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int sum = 0;
    unsigned int count = 0;
    unsigned int len = 0;

    while (*str != '\0') {
        if (isspace(*str)) {
            if (len > 0) {
                sum += len;
                count++;
                len = 0;
            }
        } else {
            len++;
        }
        str++;
    }

    if (len > 0) {
        sum += len;
        count++;
    }

    if (count == 0) {
        return 0;
    }

    return (unsigned int) (sum / count + 0.5);
}
