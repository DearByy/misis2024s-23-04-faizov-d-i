
#ifndef STACKARRHPP
#define STACKARRHPP

#include <sstream>
#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <complex/complex.hpp>

class StackArr {
private:
	Complex* data_ = nullptr;
	std::ptrdiff_t capacity_;
	std::ptrdiff_t size_;
public:
	StackArr() 
		: size_(0), capacity_(2)
	{
		data_ = new Complex[capacity_];
	}
	StackArr(const StackArr& rhs) 
		: size_{rhs.size_}, capacity_{rhs.capacity_}, data_{new Complex[rhs.capacity_]}
	{
		std::copy(rhs.data_ , rhs.data_ + rhs.size_, data_);
	}
	StackArr(StackArr&& rhs) {
		capacity_ = rhs.capacity_;
		size_ = rhs.size_;
		Complex* tempdata_ = data_;
		data_ = rhs.data_;
		rhs.data_ = tempdata_;
	}
	~StackArr() {
		delete[] data_;
		data_ = nullptr;
	}
	StackArr& operator=(const StackArr& rhs) {
		if (this != &rhs) {
			if (rhs.size_ < capacity_) {
				std::copy(rhs.data_, rhs.data_ + rhs.size_, data_);
				size_ = rhs.size_;
				return *this;
			}
			delete[] data_;
			data_ = new Complex[rhs.size_ * 2];
			std::copy(rhs.data_, rhs.data_ + rhs.size_, data_);
			size_ = rhs.size_;
			capacity_ = rhs.size_ * 2;
		}
		return *this;
	}
	StackArr& operator=(StackArr&& rhs) {
		capacity_ = rhs.capacity_;
		size_ = rhs.size_;
		Complex* tempdata_ = data_;
		data_ = rhs.data_;
		rhs.data_ = tempdata_;
		return *this;
	}

	void Pop() noexcept;
	void Push(const Complex&) noexcept;
	bool IsEmpty() noexcept;
	Complex& Top();
	const Complex& Top() const;
};

#endif //STACKARRHPP
