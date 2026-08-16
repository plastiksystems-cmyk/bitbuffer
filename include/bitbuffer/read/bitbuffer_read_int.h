#pragma once

#include "class/bitbuffer_class.h"

namespace bitbuffer {

int8_t bitbuffer::read_int8() {
    return static_cast<int8_t>(read_uint8());
}

int16_t bitbuffer::read_int16() {
    return static_cast<int16_t>(read_uint16());
}

int32_t bitbuffer::read_int32() {
    return static_cast<int32_t>(read_uint32());
}

int64_t bitbuffer::read_int64() {
    return static_cast<int64_t>(read_uint64());
}

}