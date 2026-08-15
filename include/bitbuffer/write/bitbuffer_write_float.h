#pragma once

#include "class/bitbuffer_class.h"

namespace bitbuffer {

void bitbuffer::write_float(float number) {
    uint32_t bits;

    std::memcpy(&bits, &number, sizeof(number));

    write_uint32(bits);
}

void bitbuffer::write_double(double number) {
    uint64_t bits;

    std::memcpy(&bits, &number, sizeof(number));

    write_uint64(bits);
}

}