#pragma once
#ifndef QUEUEARRHPP27022024
#define QUEUEARRHPP27022024

#include <complex/complex.hpp>
#include <cstddef>
#include <stdexcept>

class QueueArr {
private:
    std::ptrdiff_t head_{0};
    std::ptrdiff_t capacity_{0};
    std::ptrdiff_t size_{0};
    Complex* data_{nullptr};
public:
    QueueArr() = default;
    ~QueueArr() {
        if (data_ != nullptr) {
            delete[] data_;
        }
        data_ = nullptr;
    }
    QueueArr(const QueueArr& rhs)
        : size_{rhs.size_}, capacity_{rhs.size_ * 2}
    {   
        if (capacity_ != 0) {
            data_ = new Complex[capacity_];
        }
        std::ptrdiff_t idx{0};
        while(idx < rhs.size_) {
            data_[idx] = rhs.data_[(rhs.head_ + idx) % capacity_];
            ++idx;
        }
    }
    QueueArr(QueueArr&& rhs) {
        head_ = rhs.head_;
        capacity_ = rhs.capacity_;
        size_ = rhs.size_;
        Complex* tempdata_ = data_;
        data_ = rhs.data_;
        rhs.data_ = tempdata_;
    }
    QueueArr operator=(const QueueArr& rhs) {
        if (this != &rhs) {
            if (capacity_ >= rhs.size_) {
                std::ptrdiff_t idx{0};
                while(idx < rhs.size_) {
                    data_[idx] = rhs.data_[(rhs.head_ + idx) % capacity_];
                    ++idx;
                }
                size_ = rhs.size_;
                head_ = 0;
                return *this;
            }
            if (data_ != nullptr) {
                delete[] data_;   
            }
            size_ = rhs.size_;
            capacity_ = size_ * 2;
            data_ = new Complex[capacity_];
            std::ptrdiff_t idx{0};
            while(idx < rhs.size_) {
                data_[idx] = rhs.data_[(rhs.head_ + idx) % capacity_];
                ++idx;
            }
            head_ = 0;
        }
        return *this;
    }
    QueueArr& operator=(QueueArr&& rhs) {
        head_ = rhs.head_;
        capacity_ = rhs.capacity_;
        size_ = rhs.size_;
        Complex* tempdata_ = data_;
        data_ = rhs.data_;
        rhs.data_ = tempdata_;
        return *this;
    }

    void Push(const Complex&) noexcept;
    void Pop() noexcept;
    Complex& Top();
    const Complex& Top() const;
    Complex& Tail();
    const Complex& Tail() const;
    bool IsEmpty() noexcept;
    void Clear() noexcept;
};

#endif //QUEUEARRHPP27022024
