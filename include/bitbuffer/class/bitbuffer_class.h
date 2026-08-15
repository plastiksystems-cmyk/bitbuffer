#pragma once

#include <iostream>
#include <cstdint>
#include <stdexcept>
#include <cstdlib>

namespace bitbuffer {

class bitbuffer {
private:
	uint8_t *data = nullptr;
	size_t cursor = 0;
	size_t length = 0;
	size_t capacity = 0;

	void advance_cursor();
public:
	bitbuffer(size_t size);
	bitbuffer(const bitbuffer& buffer);
	bitbuffer(const std::string& string);

	void move_cursor(size_t position);
	size_t get_cursor() const;

	/* reading */
	uint8_t read_uint8();
	uint16_t read_uint16();
	uint32_t read_uint32();
	uint64_t read_uint64();

	int8_t read_int8();
	int16_t read_int16();
	int32_t read_int32();
	int64_t read_int64();

	float read_float();
	double read_double();

	bool read_bool();

	/* writing */
	void write_uint8(uint8_t number);
	void write_uint16(uint16_t number);
	void write_uint32(uint32_t number);
	void write_uint64(uint64_t number);

	void write_int8(int8_t number);
	void write_int16(int16_t number);
	void write_int32(int32_t number);
	void write_int64(int64_t number);

	void write_float(float number);
	void write_double(double number);

	void write_bool(bool boolean);

	/* string */
	std::string to_string();
	static std::string to_base91(std::string string);
	static std::string decode_base91(std::string encoded);
};

}