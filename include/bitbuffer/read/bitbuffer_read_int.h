#pragma once

#include "class/bitbuffer_class.h"

namespace bitbuffer {

int8_t bitbuffer::read_int8() {
    int8_t number = data[cursor];
    advance_cursor();

    return number;
}

int16_t bitbuffer::read_int16() {
    int8_t high = read_int8();
    int8_t low = read_int8();

    return (static_cast<int16_t>(high) << 8) | low;
}

int32_t bitbuffer::read_int32() {
    int16_t high = read_int16();
    int16_t low = read_int16();

    return (static_cast<int32_t>(high) << 16) | low;
}

int64_t bitbuffer::read_int64() {
    int32_t high = read_int32();
    int32_t low = read_int32();

    return (static_cast<int64_t>(high) << 32) | low;
}

}