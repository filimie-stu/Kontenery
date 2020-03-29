#pragma once
#include <list>

template<class T>
class SortedList {
	std::list<T> list_;

public:
	void insert(const T& number) {

		auto v = list_.begin();
		auto vEnd = list_.end();
		if (list_.size())
			while (v != vEnd && *v < number)
				v++;

		list_.insert(v, number);
	}

	void erase(typename std::list<T>::iterator pos) {
		list_.erase(pos);
	}

	typename std::list<T>::iterator begin() {
		return list_.begin();
	}

	typename std::list<T>::iterator end() {
		return list_.end();
	}

	T& operator[](std::size_t idx) {
		auto v = list_.begin();
		std::advance(v, idx);
		return *v;
	}
};