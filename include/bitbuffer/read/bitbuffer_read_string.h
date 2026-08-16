#pragma once

#include "class/bitbuffer_class.h"

namespace bitbuffer {

std::string bitbuffer::read_string(size_t size) {
    std::string string;
    string.reserve(size);

    for (size_t i = 0; i < size; i++) {
        string += read_char8();
    }

    return string;
}

}