#pragma once

#include "class/bitbuffer_class.h"

namespace bitbuffer {

void bitbuffer::write_uint8(uint8_t number) {
    data[cursor] = number;
    length++;
    advance_cursor();
}

void bitbuffer::write_uint16(uint16_t number) {
    uint8_t high = static_cast<uint8_t>(number >> 8);
    uint8_t low = static_cast<uint8_t>(number & 0xFF);

    write_uint8(high);
    write_uint8(low);
}

void bitbuffer::write_uint32(uint32_t number) {
    uint16_t high = static_cast<uint16_t>(number >> 16);
    uint16_t low = static_cast<uint16_t>(number & 0xFFFF);

    write_uint16(high);
    write_uint16(low);
}

void bitbuffer::write_uint64(uint64_t number) {
    uint32_t high = static_cast<uint32_t>(number >> 32);
    uint32_t low = static_cast<uint32_t>(number & 0xFFFFFFFF);

    write_uint32(high);
    write_uint32(low);
}

}