#pragma once

#include "bitbuffer_class.h"

namespace bitbuffer {

void bitbuffer::move_cursor(size_t position) {
    if (position >= capacity) {
        std::cerr << "[bitbuffer]: Tried to move cursor past allocated memory!\n";
        return;
    }

    cursor = position;
}

void bitbuffer::advance_cursor() {
    if (cursor >= capacity) {
        return;
    }

    cursor += 1;
}

size_t bitbuffer::get_cursor() const {
    return cursor;
}

}