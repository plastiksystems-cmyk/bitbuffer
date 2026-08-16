#pragma once

#include "class/bitbuffer_class.h"

namespace bitbuffer {

void bitbuffer::write_char8(char8_t character) {
    write_uint8(static_cast<uint8_t>(character));
}

void bitbuffer::write_char16(char16_t character) {
    write_uint16(static_cast<uint16_t>(character));
}

void bitbuffer::write_char32(char32_t character) {
    write_uint32(static_cast<uint32_t>(character));
}

}