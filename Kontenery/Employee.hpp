#pragma once
#include <string>


struct Employee
{
	std::string firstName;
	std::string lastName;

	Employee(const std::string& firstName, const std::string& lastName) :
		firstName(firstName),
		lastName(lastName)
	{
	}

	Employee() = delete;
};

inline bool operator==(const Employee& lhs, const Employee& rhs) {
	return lhs.firstName == rhs.firstName && lhs.lastName == rhs.lastName;
}
inline bool operator!=(const Employee& lhs, const Employee& rhs) {
	return !(lhs == rhs);
}
