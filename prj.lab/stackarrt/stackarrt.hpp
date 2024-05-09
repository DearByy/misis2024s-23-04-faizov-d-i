
#ifndef STACKARRTHPP09022024
#define STACKARRTHPP09022024

#include <sstream>
#include <iostream>
#include <cstddef>
#include <stdexcept>

template<typename T>
class StackArrT {
private:
	T* data_ = nullptr;
	std::ptrdiff_t capacity_;
	std::ptrdiff_t size_;
public:
	StackArrT() 
		: size_(0), capacity_(2)
	{
		data_ = new T[capacity_];
	}
	StackArrT(const StackArrT& rhs) 
		: size_{rhs.size_}, capacity_{rhs.capacity_}, data_{new T[rhs.capacity_]}
	{
		std::copy(rhs.data_ , rhs.data_ + rhs.size_, data_);
	}
	StackArrT(StackArrT&& rhs) {
		capacity_ = rhs.capacity_;
		size_ = rhs.size_;
		T* tempdata_ = data_;
		data_ = rhs.data_;
		rhs.data_ = tempdata_;
	}
	~StackArrT() {
		delete[] data_;
		data_ = nullptr;
	}
	StackArrT& operator=(const StackArrT& rhs) {
		if (this != &rhs) {
			if (rhs.size_ < capacity_) {
				std::copy(rhs.data_, rhs.data_ + rhs.size_, data_);
				size_ = rhs.size_;
				return *this;
			}
			delete[] data_;
			data_ = new T[rhs.size_ * 2];
			std::copy(rhs.data_, rhs.data_ + rhs.size_, data_);
			size_ = rhs.size_;
			capacity_ = rhs.size_ * 2;
		}
		return *this;
	}
	StackArrT& operator=(StackArrT&& rhs) {
		capacity_ = rhs.capacity_;
		size_ = rhs.size_;
		T* tempdata_ = data_;
		data_ = rhs.data_;
		rhs.data_ = tempdata_;
		return *this;
	}

	void Pop() noexcept {
		if (size_ != 0) {
			--size_;
		}
	}

	void Push(const T& rhs) noexcept {
		if (size_ < capacity_) {
			data_[size_] = rhs;
			++size_;
			return;
		}
		capacity_ = (size_ + 1) * 2;
		T* new_data_ = new T[capacity_];
		for (std::ptrdiff_t i(0); i < size_; i++) {
			new_data_[i] = data_[i];
		}
		delete[] data_;
		data_ = new_data_;
		new_data_ = nullptr;
		data_[size_] = rhs;
		++size_;
	}

	bool IsEmpty() noexcept{
		return (size_ == 0);
	}

	T& Top() {
		if (size_ != 0) {
			return data_[size_ - 1];
		}
		throw std::range_error("Stack is empty");
	}

	const T& Top() const {
		if (size_ != 0) {
			return data_[size_ - 1];
		}
		throw std::range_error("Stack is empty");
	}

	void Clear() noexcept {
		size_ = 0;
	}
};

#endif //STACKARRTHPP09022024
