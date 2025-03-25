#pragma once

#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <stdexcept>

template<class Ttype>
class MineVectorRealisation
{
private:
	Ttype* data = nullptr;
	size_t SIZE;

	void expandMas()
	{
		try {
			Ttype* temp = new Ttype[SIZE + 1];
			if (data) {
				std::copy(data, data + SIZE, temp);
				delete[] data;
			}
			data = temp;
			SIZE++;
		}
		catch (const std::bad_alloc& e) {
			std::cerr << "Memory allocation error -- " << e.what() << std::endl;
		}

	}

	void AddSomething(const Ttype& thing)
	{
		expandMas();
		data[SIZE - 1] = thing;

	}
	void AddSomething(Ttype&& thing)
	{
		expandMas();
		data[SIZE - 1] = std::move(thing);
	}
public:

	MineVectorRealisation(std::initializer_list<Ttype> vec) : SIZE(vec.size())
	{
		if (SIZE > 0) {
			data = new Ttype[SIZE];
			std::copy(vec.begin(), vec.end(), data);
		}

	}

	MineVectorRealisation(int num) : SIZE(num)
	{
		if (num > 0) {
			data = new Ttype[SIZE]();
		}
	}

	~MineVectorRealisation()
	{
		delete[] data;
	}

	Ttype& operator[](size_t index) {
		if (index > SIZE) throw std::out_of_range("index out of range");
		return data[index];
	}

	const Ttype& operator[](size_t index) const {
		if (index > SIZE) throw std::out_of_range("index out of range");
		return data[index];
	}

	bool empty() const { return SIZE == 0; }
	void clear() { delete[] data; data = nullptr; SIZE = 0; }
	void push_back(const Ttype& value) { AddSomething(value); }
	void push_back(Ttype&& value) { AddSomething(std::move(value)); }

	Ttype* begin() { return data; }
	const Ttype* begin() const { return data; }
	Ttype* end() { return data + SIZE; }
	const Ttype* end() const { return data + SIZE; }


	size_t getSize() const { return SIZE; }

	void getMas() const
	{
		for (size_t i = 0; i < SIZE; i++) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}


};

template<typename Otype>
void masInfo(const MineVectorRealisation<Otype>& vec)
{
	const int ELEMENTS_IN_ROW = 16;
	const size_t VEC_SIZE = vec.getSize();
	std::cout << "Size -- " << VEC_SIZE << std::endl;
	std::cout << "Elements -- ";

	for (size_t i = 0; i < VEC_SIZE; ++i) {
		std::cout << vec[i] << " ";

		if ((i + 1) % ELEMENTS_IN_ROW == 0) {
			std::cout << std::endl << "            ";
		}
	}
	if (VEC_SIZE % ELEMENTS_IN_ROW != 0) {
		std::cout << std::endl;
	}
}