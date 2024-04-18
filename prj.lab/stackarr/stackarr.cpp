
#include "stackarr.hpp"

void StackArr::Pop() noexcept {
	if (size_ != 0) {
		--size_;
	}
}

void StackArr::Push(const Complex& rhs) noexcept {
	if (size_ < capacity_) {
		data_[size_] = rhs;
		++size_;
		return;
	}
	capacity_ = (size_ + 1) * 2;
	Complex* new_data_ = new Complex[capacity_];
	for (std::ptrdiff_t i(0); i < size_; i++) {
		new_data_[i] = data_[i];
	}
	delete[] data_;
	data_ = new_data_;
	new_data_ = nullptr;
	data_[size_] = rhs;
	++size_;
}

bool StackArr::IsEmpty() noexcept{
	return (size_ == 0);
}

Complex& StackArr::Top() {
	if (size_ != 0) {
		return data_[size_ - 1];
	}
	throw std::range_error("Stack is empty");
}

const Complex& StackArr::Top() const {
	if (size_ != 0) {
		return data_[size_ - 1];
	}
	throw std::range_error("Stack is empty");
}
