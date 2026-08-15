#include "bitbuffer.h"

#include <string>

int main() {
    bitbuffer::bitbuffer buffer(12);
    buffer.write_float(1.1256356f);
    buffer.write_double(1.125653727672);

    buffer.move_cursor(0);
    float f1 = buffer.read_float();
    double f2 = buffer.read_double();

    std::string bufstring = buffer.to_string();
    std::string basestring = bitbuffer::bitbuffer::to_base91(bufstring);

    std::cout << bufstring << "   " << basestring << '\n';
    std::cout << f1 << ' ' << f2 << '\n';

    return 0;
}

