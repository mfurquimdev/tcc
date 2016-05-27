#include <iostream>
#include <string>
#include <bitset>
#include <type_traits>

int main()
{
	unsigned int counter = 0;
	for (size_t n = 0; n < 0x7c01; n++)
	{
		std::bitset<15> b(n);
		if (b.count() == 5)
		{
			b ^= 0xffff;
			std::cout << counter << ": " << b.to_string() << std::endl;
			counter++;
		}
	}
}
