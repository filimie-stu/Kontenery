
#include <iostream>
#include "IPv4.hpp"
#include "Functions.hpp"

int main()
{
	auto localhost = IPv4({ 127, 0, 0, 1 });
	auto randomAddress = IPv4({ 158, 10, 161, 3 });
	auto maskClassA = IPv4({ 255, 0, 0, 0 });
	auto maskClassB = IPv4({ 255, 255, 0, 0 });
	auto maskClassC = IPv4({ 255, 255, 255, 0 });

	printIndexable<IPv4, int>(localhost.maskWith(maskClassB));
	printIndexable<IPv4, int>(randomAddress.maskWith(maskClassC));
	printIndexable<IPv4, int>(randomAddress.changeEndianess().maskWith(maskClassA));



	return 0;
}