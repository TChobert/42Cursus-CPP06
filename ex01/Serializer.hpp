#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer {

	private:

	Serializer(void);

	public:

	static uintptr_t serialize(Data *ptr);
	static  Data  * deserialize(uintptr_t raw);
};
