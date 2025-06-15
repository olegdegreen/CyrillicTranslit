#include "CyrillicTranslit.h"
#include <string.h>

typedef struct {
    unsigned short cyr;
    const char* latin;
} MapEntry;

// Russian Cyrillic mapping, case-sensitive
static const MapEntry map[] = {
    {0x0410, "A"}, {0x0430, "a"}, // А а
    {0x0411, "B"}, {0x0431, "b"}, // Б б
    {0x0412, "V"}, {0x0432, "v"}, // В в
    {0x0413, "G"}, {0x0433, "g"}, // Г г
    {0x0414, "D"}, {0x0434, "d"}, // Д д
    {0x0415, "E"}, {0x0435, "e"}, // Е е
    {0x0401, "Yo"}, {0x0451, "yo"}, // Ё ё
    {0x0416, "Zh"}, {0x0436, "zh"}, // Ж ж
    {0x0417, "Z"}, {0x0437, "z"}, // З з
    {0x0418, "I"}, {0x0438, "i"}, // И и
    {0x0419, "Y"}, {0x0439, "y"}, // Й й
    {0x041A, "K"}, {0x043A, "k"}, // К к
    {0x041B, "L"}, {0x043B, "l"}, // Л л
    {0x041C, "M"}, {0x043C, "m"}, // М м
    {0x041D, "N"}, {0x043D, "n"}, // Н н
    {0x041E, "O"}, {0x043E, "o"}, // О о
    {0x041F, "P"}, {0x043F, "p"}, // П п
    {0x0420, "R"}, {0x0440, "r"}, // Р р
    {0x0421, "S"}, {0x0441, "s"}, // С с
    {0x0422, "T"}, {0x0442, "t"}, // Т т
    {0x0423, "U"}, {0x0443, "u"}, // У у
    {0x0424, "F"}, {0x0444, "f"}, // Ф ф
    {0x0425, "Kh"}, {0x0445, "kh"}, // Х х
    {0x0426, "Ts"}, {0x0446, "ts"}, // Ц ц
    {0x0427, "Ch"}, {0x0447, "ch"}, // Ч ч
    {0x0428, "Sh"}, {0x0448, "sh"}, // Ш ш
    {0x0429, "Shch"}, {0x0449, "shch"}, // Щ щ
    {0x042A, ""}, {0x044A, ""}, // Hard sign
    {0x042B, "Y"}, {0x044B, "y"}, // Ы ы
    {0x042C, ""}, {0x044C, ""}, // Soft sign
    {0x042D, "E"}, {0x044D, "e"}, // Э э
    {0x042E, "Yu"}, {0x044E, "yu"}, // Ю ю
    {0x042F, "Ya"}, {0x044F, "ya"}, // Я я
};

static size_t decode_utf8(const char* s, unsigned short* out) {
    unsigned char c = (unsigned char)s[0];
    if (c < 0x80) {
        *out = c;
        return 1;
    } else if ((c & 0xE0) == 0xC0) {
        *out = ((s[0] & 0x1F) << 6) | (s[1] & 0x3F);
        return 2;
    } else if ((c & 0xF0) == 0xE0) {
        *out = ((s[0] & 0x0F) << 12) | ((s[1] & 0x3F) << 6) | (s[2] & 0x3F);
        return 3;
    }
    *out = c;
    return 1;
}

void cyrillic_to_translit(const char* src, char* dst, size_t dst_size) {
    size_t dst_pos = 0;
    while (*src && dst_pos + 1 < dst_size) {
        unsigned short code = 0;
        size_t len = decode_utf8(src, &code);
        const char* latin = NULL;
        for (size_t i = 0; i < sizeof(map)/sizeof(map[0]); ++i) {
            if (map[i].cyr == code) {
                latin = map[i].latin;
                break;
            }
        }
        if (latin) {
            size_t l = strlen(latin);
            if (dst_pos + l >= dst_size) break;
            memcpy(dst + dst_pos, latin, l);
            dst_pos += l;
        } else {
            if (dst_pos + len >= dst_size) break;
            memcpy(dst + dst_pos, src, len);
            dst_pos += len;
        }
        src += len;
    }
    dst[dst_pos] = '\0';
}