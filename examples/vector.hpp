#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

template <typename T>
class vector_t
{
private:
	T * elements_;
	size_t size_;
	size_t capacity_;
public:
	vector_t();
	vector_t(vector_t const & other);
	vector_t & operator =(vector_t const & other);
	~vector_t();

	T & at(size_t index) const;

	size_t size() const;
	size_t capacity() const;

	void push_back(T value);
	void pop_back();

	T & operator [](size_t index);
	T operator [](size_t index) const;

	bool operator ==(vector_t const & other) const;
};
template<typename T>
bool operator !=(vector_t<T> const & lhs, vector_t<T> const & rhs);

template <typename T>
T & vector_t<T>::at(size_t index) const
{
	if (index >= capacity_) {
		throw "Index out of range!";
	}
	return elements_[index];
}

template <typename T>
vector_t<T>::vector_t()
{
	elements_ = nullptr;
	size_ = 0;
	capacity_ = 0;
}

template <typename T>
vector_t<T>::vector_t(vector_t const & other)
{
	elements_ = new T[other.capacity()];
	for (size_t i = 0; i < other.size(); ++i) {
		elements_[i] = other.elements_[i];
	}
	size_ = other.size();
	capacity_ = other.capacity();
}

template <typename T>
vector_t<T> & vector_t<T>::operator =(vector_t const & other)
{
	if (this == &other) return *this;
	else {
		if (elements_ != nullptr) delete[] elements_;
		elements_ = new T[other.capacity()];
		for (size_t i = 0; i < other.size(); ++i) {
			elements_[i] = other.elements_[i];
		}
		size_ = other.size();
		capacity_ = other.capacity();
		return *this;
	}
}

template <typename T>
bool vector_t<T>::operator ==(vector_t const & other) const
{
	if (size_ != other.size() || capacity_ != other.capacity()) {
		return false;
	}
	for (size_t i = 0; i < capacity_; i++) {
		if (elements_[i] != other.elements_[i]) return false;
	}
	return true;
}

template <typename T>
vector_t<T>::~vector_t()
{
	if (elements_ != nullptr) {
		delete[] elements_;
	}
}

template <typename T>
size_t vector_t<T>::size() const
{
	return size_;
}

template <typename T>
size_t vector_t<T>::capacity() const
{
	return capacity_;
}

template <typename T>
void vector_t<T>::push_back(T value)
{
	if (!elements_) {
		size_ = 1;
		capacity_ = 1;
		elements_ = new T[capacity_];
		elements_[0] = value;
	}
	else {
		if (size_<capacity_) {
			size_++;
			elements_[size_ - 1] = value;
		}
		else if (size_ == capacity_) {
			capacity_ *= 2;
			size_++;
			T *tmp = new T[size_ - 1];
			for (size_t i = 0; i < size_ - 1; ++i) {
				tmp[i] = elements_[i];
			}
			delete[] elements_;
			elements_ = new T[capacity_];
			for (size_t i = 0; i < size_; ++i) {
				if (i != size_ - 1) elements_[i] = tmp[i];
				else elements_[i] = value;
			}
			delete[] tmp;
		}
	}
}

template <typename T>
void vector_t<T>::pop_back()
{
	if (size_ == 0) {
		return;
	}
	size_--;
	if (size_ <= (capacity_ / 4)) {
		capacity_ = capacity_ / 2;
		T *elements = new T[capacity_];
		for (int i; i<size_; i++) {
			elements[i] = elements_[i];
		}

		if (elements_ != nullptr) {
			delete[] elements_;
		}
		elements_ = elements;
	}
}

template <typename T>
T & vector_t<T>::operator [](size_t index)
{
	return elements_[index];
}

template <typename T>
T vector_t<T>::operator [](size_t index) const
{
	return elements_[index];
}

template <typename T>
bool operator !=(vector_t<T> const & lhs, vector_t<T> const & rhs)
{
	bool result = false;
	if (rhs.size() != lhs.size()) {
		return true;
	}

	if (!(lhs == rhs)) {
		result = true;
		return result;
	}
	return result;
}
