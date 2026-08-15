#pragma once

#include "class/bitbuffer_class.h"

namespace bitbuffer {

void bitbuffer::write_bool(bool boolean) {
    write_uint8(static_cast<uint8_t>(boolean));
}

}