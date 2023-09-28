#include <assert.h>
#include <iostream>

#include "Array.h"

Array &Array::operator=(const Array& other)
{
	if (this == &other) {
		return *this;
	}

	if (m_size != other.m_size) {
		m_size = other.m_size;
		delete[] m_array;
		m_array = new int[m_size];
	}

	for (int i = 0; i < m_size; ++i) {
		m_array[i] = other.m_array[i];
	}

	return *this;
}

int Array::size() const
{
	return m_size;
}

Array::~Array()
{
	delete[] m_array;
}

Array::Array(const Array& other)
	: m_size(other.m_size)
{
	m_array = new int[m_size];

	for (int i = 0; i < m_size; ++i) {
		m_array[i] = other.m_array[i];
	}
}

void Array::print() const
{
	std::cout << '[';
	for (int i = 0; i < m_size - 1; ++i) {
		std::cout << m_array[i] << ", ";
	}
	std::cout << m_array[m_size - 1] << "]\n";
}

const int& Array::operator[](const int index) const
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

int& Array::operator[](const int index)
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

Array::Array(const int size, const int value)
{
	if (size < 0) {
		std::cerr << "Array::Array: размер отрицательный, инвертируйте...\n";
		m_size = -size;
	}
	else {
		m_size = size;
	}

	m_array = new int[m_size];

	for (int i = 0; i < m_size; ++i) {
		m_array[i] = value;
	}
}