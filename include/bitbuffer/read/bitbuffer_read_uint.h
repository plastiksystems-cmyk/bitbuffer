#pragma once

#include "class/bitbuffer_class.h"

namespace bitbuffer {

uint8_t bitbuffer::read_uint8() {
    uint8_t number = data[cursor];
    advance_cursor();

    return number;
}

uint16_t bitbuffer::read_uint16() {
    uint8_t high = read_uint8();
    uint8_t low = read_uint8();

    return (static_cast<uint16_t>(high) << 8) | low;
}

uint32_t bitbuffer::read_uint32() {
    uint16_t high = read_uint16();
    uint16_t low = read_uint16();

    return (static_cast<uint32_t>(high) << 16) | low;
}

uint64_t bitbuffer::read_uint64() {
    uint32_t high = read_uint32();
    uint32_t low = read_uint32();

    return (static_cast<uint64_t>(high) << 32) | low;
}

}