
#include <iostream>
#include <vector>
#include "IPv4.hpp"
#include "Functions.hpp"
#include "Employee.hpp"

void zadanie1() {
	auto localhost = IPv4({ 127, 0, 0, 1 });
	auto randomAddress = IPv4({ 158, 10, 161, 3 });
	auto maskClassA = IPv4({ 255, 0, 0, 0 });
	auto maskClassB = IPv4({ 255, 255, 0, 0 });
	auto maskClassC = IPv4({ 255, 255, 255, 0 });

	printIndexable<IPv4, int>(localhost.maskWith(maskClassB));
	printIndexable<IPv4, int>(randomAddress.maskWith(maskClassC));
	printIndexable<IPv4, int>(randomAddress.changeEndianess().maskWith(maskClassA));
}

void zadanie2() {
	std::vector<Employee> pracownicy{
		{ "Anna", "Pierwsza" },
		{ "Daniel", "Drugi" },
		{ "Cecylia", "Trzecia" }
	};

	std::cout << "\nPierwsza iteracja:\n";
	for (const auto& pracownik : pracownicy)
		std::cout << pracownik.firstName << "\t\t" << pracownik.lastName << std::endl;

	// a
	pracownicy.insert(pracownicy.begin(), Employee("Pawel", "Nowy"));
	pracownicy.insert(pracownicy.begin() + 1, Employee("Blazej", "Blazejski"));
	pracownicy.insert(pracownicy.begin() + 2, Employee("Cezary", "Cezarski"));
	pracownicy.insert(pracownicy.begin() + 3, Employee("Damian", "Damianski"));
	pracownicy.insert(pracownicy.begin() + 4, Employee("Ewa", "Ewowska"));

	// b
	auto third = pracownicy.begin() + 2;
	pracownicy.erase(third);

	auto last = pracownicy.end();
	std::advance(last, -1);
	pracownicy.erase(last);

	// c
	auto pawelNowy = std::find(pracownicy.begin(), pracownicy.end(), Employee("Pawel", "Nowy"));
	pracownicy.erase(pawelNowy);

	// d
	std::cout << "\nDruga iteracja:\n";
	std::for_each(pracownicy.begin(), pracownicy.end(),
		[](const Employee& pracownik) {
			std::cout << pracownik.firstName << "\t\t" << pracownik.lastName << std::endl;
		});

}

int main()
{
	zadanie1();
	zadanie2();


	return 0;
}



