#ifndef CYRILLIC_TRANSLIT_H
#define CYRILLIC_TRANSLIT_H

#include <stddef.h>
void cyrillic_to_translit(const char* src, char* dst, size_t dst_size);
#endif // CYRILLIC_TRANSLIT_H