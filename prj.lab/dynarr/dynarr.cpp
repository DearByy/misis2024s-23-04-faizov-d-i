#include <dynarr/dynarr.h>

DYNARR_DYNARR_HPP_20240103

std::ptrdiff_t DynArr::Size() const noexcept {
	return this->size_;
}

std::ptrdiff_t DynArr::Capacity() const noexcept {
	return this->capacity_;
}

void DynArr::Resize(const std::ptrdiff_t size) {
	if (size < 0) {
		throw std::bad_alloc();
	}
	capacity_ = size * 2;
	float* new_data_ = new float[capacity_];
	for (std::ptrdiff_t i(0); i < size; i++) {
		new_data_[i] = (i < size_ ? this->data_[i] : 0);
	}
	size_ = size;
	delete[] data_;
	data_ = new_data_;
	new_data_ = nullptr;
}

void DynArr::PushBack(const float new_val) noexcept {
	if (this->size_ < this->capacity_) {
		data_[size_] = new_val;
		++size_;
		return;
	}
	capacity_ = (size_ + 1) * 2;
	float* new_data_ = new float[this->capacity_];
	for (std::ptrdiff_t i(0); i < size_; i++) {
		new_data_[i] = data_[i];
	}
	delete[] data_;
	data_ = new_data_;
	new_data_ = nullptr;
	data_[size_] = new_val;
	++size_;
}

void DynArr::PopBack() noexcept {
	--this->size_;
}

float& DynArr::operator[](const std::ptrdiff_t idx) {
	if (idx >= this->size_ || idx < -(this->size_)) {
		throw std::out_of_range("Index out of range");
	}
	return this->data_[(idx >= 0 ? idx : this->size_ + idx)];
}

const float& DynArr::operator[](const std::ptrdiff_t idx) const {
	if (idx >= this->size_ || idx < -(this->size_)) {
		throw std::out_of_range("Index out of range");
	}
	return this->data_[(idx >= 0 ? idx : this->size_ + idx)];
}
