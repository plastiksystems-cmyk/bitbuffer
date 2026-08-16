#include "bitbuffer.h"

int main() {
    bitbuffer::bitbuffer buffer(1);

    buffer.write_uint8(65);
    buffer.move_cursor(0);

    std::cout << static_cast<char>(buffer.read_char8()) << '\n';
}