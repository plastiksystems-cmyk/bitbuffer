#pragma once

#include "class/bitbuffer_class.h"

namespace bitbuffer {

std::string bitbuffer::to_string() {
    std::string string;

    for (size_t i = 0; i < length; i++) {
        char C = data[i];

        string += C;
    }

    return string;
}

}