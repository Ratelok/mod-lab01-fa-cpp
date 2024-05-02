// Copyright 2022 UNN-IASR
#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>

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

unsigned int faStr2(const char* str) {
    unsigned int count = 0;
    bool inWord = false;
    for (; *str; ++str) {
        if (std::isspace(*str)) {
            inWord = false;
        }
        else if (!inWord) {
            inWord = true;
            bool startsWithUppercase = std::isupper(*str);
            bool onlyLowercase = true;
            for (const char* p = str + 1; !std::isspace(*p) && *p; ++p) {
                if (!std::islower(*p)) {
                    onlyLowercase = false;
                    break;
                }
            }
            if (startsWithUppercase && onlyLowercase) {
                ++count;
            }
        }
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
