#pragma once

template<class Indexable, class TargetElementType>
void printIndexable(const Indexable& indexable) {
	for (size_t i = 0; i < indexable.size(); i++)
		std::cout << static_cast<TargetElementType>(indexable[i]) << "\t";
	std::cout << std::endl;
}