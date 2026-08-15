#pragma once

#include "class/bitbuffer_class.h"

namespace bitbuffer {

float bitbuffer::read_float() {
    uint32_t bits = read_uint32();
    float number;

    std::memcpy(&number, &bits, sizeof(number));

    return number;
}

double bitbuffer::read_double() {
    uint64_t bits = read_uint64();
    double number;

    std::memcpy(&number, &bits, sizeof(number));

    return number;
}

}