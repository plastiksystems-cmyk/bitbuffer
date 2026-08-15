#pragma once

#include "class/bitbuffer_class.h"

namespace bitbuffer {

bool bitbuffer::read_bool() {
    return static_cast<bool>(read_uint8());
}

}