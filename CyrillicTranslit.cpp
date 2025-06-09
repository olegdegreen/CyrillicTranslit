#include "CyrillicTranslit.h"

String CyrillicTranslit::convert(const String& input) {
    String result;
    for (unsigned int i = 0; i < input.length(); i++) {
        char c = input[i];
        if ((c >= 'À' && c <= 'ß') || (c >= 'à' && c <= 'ÿ') || c == '¨' || c == '¸') {
            switch (c) {
                case 'À': case 'à': result += "a"; break;
                case 'Á': case 'á': result += "b"; break;
                case 'Â': case 'â': result += "v"; break;
                case 'Ã': case 'ã': result += "g"; break;
                case 'Ä': case 'ä': result += "d"; break;
                case 'Å': case 'å': result += "e"; break;
                case '¨': case '¸': result += "yo"; break;
                case 'Æ': case 'æ': result += "zh"; break;
                case 'Ç': case 'ç': result += "z"; break;
                case 'È': case 'è': result += "i"; break;
                case 'É': case 'é': result += "y"; break;
                case 'Ê': case 'ê': result += "k"; break;
                case 'Ë': case 'ë': result += "l"; break;
                case 'Ì': case 'ì': result += "m"; break;
                case 'Í': case 'í': result += "n"; break;
                case 'Î': case 'î': result += "o"; break;
                case 'Ï': case 'ï': result += "p"; break;
                case 'Ð': case 'ð': result += "r"; break;
                case 'Ñ': case 'ñ': result += "s"; break;
                case 'Ò': case 'ò': result += "t"; break;
                case 'Ó': case 'ó': result += "u"; break;
                case 'Ô': case 'ô': result += "f"; break;
                case 'Õ': case 'õ': result += "kh"; break;
                case 'Ö': case 'ö': result += "ts"; break;
                case '×': case '÷': result += "ch"; break;
                case 'Ø': case 'ø': result += "sh"; break;
                case 'Ù': case 'ù': result += "shch"; break;
                case 'Ú': case 'ú': result += ""; break;
                case 'Û': case 'û': result += "y"; break;
                case 'Ü': case 'ü': result += ""; break;
                case 'Ý': case 'ý': result += "e"; break;
                case 'Þ': case 'þ': result += "yu"; break;
                case 'ß': case 'ÿ': result += "ya"; break;
                default: result += c;
            }
        } else {
            result += c;
        }
    }
    return result;
}