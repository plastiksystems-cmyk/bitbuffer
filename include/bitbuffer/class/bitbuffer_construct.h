#pragma once

#include "bitbuffer_class.h"

namespace bitbuffer {

bitbuffer::bitbuffer(size_t size) {
    try {
		data = new uint8_t[size];
		capacity = size;
	} catch (const std::bad_alloc& error) {
		std::cerr << "[bitbuffer]: " << error.what() << '\n';
	}
}

bitbuffer::bitbuffer(const bitbuffer& buffer) {
	try {
		data = new uint8_t[buffer.capacity];
		capacity = buffer.capacity;
	} catch (const std::bad_alloc& error) {
		std::cerr << "[bitbuffer]: " << error.what() << '\n';
	}

	std::memcpy(data, buffer.data, buffer.capacity);
}

bitbuffer::bitbuffer(const std::string& string) {
	data = new uint8_t[string.size()];

	for (char C : string) {
		uint8_t byte = static_cast<uint8_t>(C);
		write_uint8(byte);
	}
}

bitbuffer::~bitbuffer() {
	if (data != nullptr) {
		delete[] data;
	}
}

}