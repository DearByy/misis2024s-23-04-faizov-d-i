#pragma once
#ifndef DYNARR_DYNARR_HPP_20240103
#define DYNARR_DYNARR_HPP_20240103

#include <stdexcept>
#include <cstddef>

class DynArr {
public:
	DynArr() 
		: size_(0) 
	{
		data_ = new float[0];
	}

	DynArr(const DynArr& rhs)
		: size_(rhs.size_),
		capacity_(size_ * 2)
	{
		data_ = new float[capacity_];
		for (std::ptrdiff_t i(0); i < size_; i++) {
			data_[i] = rhs.data_[i];
		}
	}

	DynArr(const std::ptrdiff_t size)
		: size_(size), 
		capacity_(size * 2)
	{
		if (size < 0) {
			throw std::bad_alloc();
		}
		data_ = new float[capacity_];
		for (std::ptrdiff_t i(0); i < size_; i++) {
			data_[i] = 0.0;
		}
	}

	~DynArr() {
		delete[] data_;
		data_ = nullptr;
	}

	DynArr operator=(const DynArr& rhs) {
		size_ = rhs.size_;
		capacity_ = size_ * 2;
		delete[] data_;
		data_ = new float[this->capacity_];
		for (std::ptrdiff_t i(0); i < this->size_; i++) {
			data_[i] = rhs.data_[i];
		}
	}

	std::ptrdiff_t Size() const noexcept;

	std::ptrdiff_t Capacity() const noexcept;

	void Resize(const std::ptrdiff_t size);

	void PushBack(const float new_val) noexcept;

	void PopBack() noexcept;

	float& operator[](const std::ptrdiff_t idx);

	const float& operator[](const std::ptrdiff_t idx) const;

private:
	std::ptrdiff_t size_ = 0; 
	std::ptrdiff_t capacity_ = 0;
	float* data_ = nullptr;          
};
#endif
