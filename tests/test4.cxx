#include "bitbuffer.h"

int main() {
    bitbuffer::bitbuffer buffer(14);

    std::string TestString = "Hello, world!";
    size_t TestStringSize = TestString.size();

    buffer.write_string(TestString, TestStringSize);

    buffer.move_cursor(0);

    std::cout << buffer.read_string(TestStringSize) << '\n';
}