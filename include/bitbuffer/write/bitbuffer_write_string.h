#include "class/bitbuffer_class.h"

namespace bitbuffer {

void bitbuffer::write_string(const std::string& string, size_t size) {
    size = std::min(size, string.size());

    for (size_t i = 0; i < size; i++) {
        write_char8(string[i]);
    }
}

}