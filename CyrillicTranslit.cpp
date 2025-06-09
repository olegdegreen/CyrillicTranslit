#include "CyrillicTranslit.h"

String CyrillicTranslit::convert(const String& input) {
    String result;
    for (unsigned int i = 0; i < input.length(); i++) {
        char c = input[i];
        if ((c >= '�' && c <= '�') || (c >= '�' && c <= '�') || c == '�' || c == '�') {
            switch (c) {
                case '�': case '�': result += "a"; break;
                case '�': case '�': result += "b"; break;
                case '�': case '�': result += "v"; break;
                case '�': case '�': result += "g"; break;
                case '�': case '�': result += "d"; break;
                case '�': case '�': result += "e"; break;
                case '�': case '�': result += "yo"; break;
                case '�': case '�': result += "zh"; break;
                case '�': case '�': result += "z"; break;
                case '�': case '�': result += "i"; break;
                case '�': case '�': result += "y"; break;
                case '�': case '�': result += "k"; break;
                case '�': case '�': result += "l"; break;
                case '�': case '�': result += "m"; break;
                case '�': case '�': result += "n"; break;
                case '�': case '�': result += "o"; break;
                case '�': case '�': result += "p"; break;
                case '�': case '�': result += "r"; break;
                case '�': case '�': result += "s"; break;
                case '�': case '�': result += "t"; break;
                case '�': case '�': result += "u"; break;
                case '�': case '�': result += "f"; break;
                case '�': case '�': result += "kh"; break;
                case '�': case '�': result += "ts"; break;
                case '�': case '�': result += "ch"; break;
                case '�': case '�': result += "sh"; break;
                case '�': case '�': result += "shch"; break;
                case '�': case '�': result += ""; break;
                case '�': case '�': result += "y"; break;
                case '�': case '�': result += ""; break;
                case '�': case '�': result += "e"; break;
                case '�': case '�': result += "yu"; break;
                case '�': case '�': result += "ya"; break;
                default: result += c;
            }
        } else {
            result += c;
        }
    }
    return result;
}