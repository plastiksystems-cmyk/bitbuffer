#pragma once

#include "class/bitbuffer_class.h"

namespace bitbuffer {

void bitbuffer::write_int8(int8_t number) {
    write_uint8(static_cast<uint8_t>(number));
}

void bitbuffer::write_int16(int16_t number) {
    write_uint16(static_cast<uint16_t>(number));
}

void bitbuffer::write_int32(int32_t number) {
    write_uint32(static_cast<uint32_t>(number));
}

void bitbuffer::write_int64(int64_t number) {
    write_uint64(static_cast<uint64_t>(number));
}

}