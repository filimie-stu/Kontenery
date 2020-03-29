#pragma once
#include <random>
#include <chrono>

template<class NumberType>
class RandomNumberGenerator
{
	static std::mt19937 engine_;
	const std::uniform_int_distribution<NumberType> distribution_;
	
public:
	RandomNumberGenerator(NumberType min, NumberType max) : distribution_(min, max)
	{
	}

	NumberType getNext() const {
		return distribution_(engine_);
	}
};

template<class NumberType>
std::mt19937 RandomNumberGenerator<NumberType>::engine_{ static_cast<unsigned>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) };
