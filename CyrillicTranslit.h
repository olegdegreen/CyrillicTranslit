#ifndef CYRILLIC_TRANSLIT_H
#define CYRILLIC_TRANSLIT_H

#include <Arduino.h>

class CyrillicTranslit {
public:
    static String convert(const String& input);
};

#endif
