#pragma once

#include "class/bitbuffer_class.h"

namespace bitbuffer {

void bitbuffer::write_int8(int8_t number) {
    data[cursor] = number;
    length++;
    advance_cursor();
}

void bitbuffer::write_int16(int16_t number) {
    int8_t high = static_cast<int8_t>(number >> 8);
    int8_t low = static_cast<int8_t>(number & 0xFF);

    write_int8(high);
    write_int8(low);
}

void bitbuffer::write_int32(int32_t number) {
    int16_t high = static_cast<int16_t>(number >> 16);
    int16_t low = static_cast<int16_t>(number & 0xFFFF);

    write_int16(high);
    write_int16(low);
}

void bitbuffer::write_int64(int64_t number) {
    int32_t high = static_cast<int32_t>(number >> 32);
    int32_t low = static_cast<int32_t>(number & 0xFFFFFFFF);

    write_int32(high);
    write_int32(low);
}

}