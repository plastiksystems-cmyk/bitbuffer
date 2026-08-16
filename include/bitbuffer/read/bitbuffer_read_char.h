#pragma once

#include "class/bitbuffer_class.h"

namespace bitbuffer {

#if BITBUFFER_CXX_STANDARD >= 20
char8_t bitbuffer::read_char8() {
    return static_cast<char8_t>(read_uint8());
}
#endif

char16_t bitbuffer::read_char16() {
    return static_cast<char16_t>(read_uint16());
}

char32_t bitbuffer::read_char32() {
    return static_cast<char32_t>(read_uint32());
}

}