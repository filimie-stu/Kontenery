
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <unordered_set>
#include <set>
#include "IPv4.hpp"
#include "Functions.hpp"
#include "Employee.hpp"
#include "RandomNumberGenerator.hpp"
#include "SortedList.hpp"

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

void zadanie3()
{
	RandomNumberGenerator<int> generator(-100, 100);
	std::vector<int> randoms(10000);

	for (auto& element : randoms)
		element = generator.getNext();

	std::priority_queue<int, std::deque<int>> dequeQueue;
	std::priority_queue<int, std::vector<int>> vectorQueue;

	auto t1 = sysclock_t::now();
	for (auto element : randoms)
		vectorQueue.emplace(element);

	auto t2 = sysclock_t::now();
	for (auto element : randoms)
		dequeQueue.emplace(element);

	auto t3 = sysclock_t::now();

	std::cout << "\nvectorQueue time:\t\t\t" << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << std::endl;
	std::cout << "\ndequeQueue time:\t\t" << std::chrono::duration_cast<std::chrono::microseconds>(t3 - t2).count() << std::endl;

	// Dodawanie elementów do std::deque jest widocznie wolniejsze ni¿ dodawanie elementow do std::vector,
	// co rzutuje na równie¿ na czas pracy kolejki priorytetowej. 
	// Taki stan rzeczy mo¿na uzasadniæ faktem, ¿e std::vector gwarantuje ci¹g³oœæ wykorzystywanej pamiêci,
	// podczas gdy std::deque korzysta z wielu statycznych tablic. Dostêp do elementu std::deque oznacza wiêc
	// dwie operacje dereferencji - nie jedn¹, jak w przypadku wektora.

}

void zadanie4()
{

	RandomNumberGenerator<int> rng(0, 19);
	std::vector<int> liczbyLosowe(15);

	for (auto& liczba : liczbyLosowe)
		liczba = rng.getNext();

	std::cout << "Nieposortowane:" << std::endl;
	for (auto liczba : liczbyLosowe)
		std::cout << liczba << "\t";
	std::cout << std::endl;

	std::unordered_set<int> liczbyLosoweBezPowtorzen(liczbyLosowe.begin(), liczbyLosowe.end());
	std::cout << "Nieposortowane bez powtorzen:" << std::endl;

	for (auto liczba : liczbyLosoweBezPowtorzen)
		std::cout << liczba << "\t";
	std::cout << std::endl;

	std::set<int> liczbyPosortowaneBezPowtorzen(liczbyLosowe.begin(), liczbyLosowe.end());
	std::cout << "Posortowane:" << std::endl;

	for (auto liczba : liczbyPosortowaneBezPowtorzen)
		std::cout << liczba << "\t";
	std::cout << std::endl;
}

void zadanie5()
{
	SortedList<double> dubs;
	dubs.insert(5);
	dubs.insert(5.22);
	dubs.insert(5.1);
	dubs.insert(-51.1);
	dubs.insert(0.04);
	dubs.insert(10);

	for (const auto el : dubs)
		std::cout << el << "\t";
	std::cout << std::endl;

	dubs.insert(100);
	auto fivePointOne = std::find(dubs.begin(), dubs.end(), 5.1);
	dubs.erase(fivePointOne);

	for (const auto el : dubs)
		std::cout << el << "\t";
	std::cout << std::endl;
}

int main()
{

	return 0;
}



