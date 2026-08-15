#include "bitbuffer.h"

#include <string>

int main() {
    bitbuffer::bitbuffer buffer(15);
    buffer.write_uint8(0xFF);
    buffer.write_uint16(0xFFFF);
    buffer.write_uint32(0xFFFFFFFF);
    buffer.write_uint64(0xFFFFFFFFFFFFFFFF);

    buffer.move_cursor(0);
    uint8_t i1 = buffer.read_uint8();
    uint16_t i2 = buffer.read_uint16();
    uint32_t i3 = buffer.read_uint32();
    uint64_t i4 = buffer.read_uint64();

    std::cout << std::to_string(i1) << " " << i2 << " " << i3 << " " << i4 << " " << '\n';

    return 0;
}