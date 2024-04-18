
#ifndef STACKLSTHPP
#define STACKLSTHPP

#include <sstream>
#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <complex/complex.hpp>

class StackLst {
private:
	struct Node {
		Node() = default;
		Node(const Complex& data) 
			: data_{data}
		{
		}
		Complex data_{0};
		Node* prev_{nullptr};
	};
	Node* head_{nullptr};
public:
	StackLst() = default;
	~StackLst(){
		while (head_ != nullptr) {
			Node* previ = head_->prev_;
			delete head_;
			head_ = previ;
		}
	}
	StackLst(const StackLst& rhs) 
	{
		if (rhs.head_ == nullptr) {
			return;
		}
		Node* rhs_head = rhs.head_;
		head_ = new Node();
		Node* this_head = head_;
		while (rhs_head != nullptr) {
			this_head->data_ = rhs_head->data_;
			if (rhs_head->prev_ != nullptr) {
				Node* previ = this_head;
				this_head = new Node();
				previ->prev_ = this_head;
			}
			rhs_head = rhs_head->prev_;
		}
	}
	StackLst(StackLst&& rhs) {
		Node* temphead_ = head_;
		head_ = rhs.head_;
		rhs.head_ = temphead_;
	}
	StackLst& operator=(const StackLst& rhs) {
		if (this != &rhs) {
			if (rhs.head_ == nullptr) {
				while (head_ != nullptr) {
					Node* previ = head_->prev_;
					delete head_;
					head_ = previ;
				}
				return *this;
			}
			if (head_ == nullptr) {
				head_ = new Node();
			}
			Node* rhs_head = rhs.head_;
			Node* this_head = head_;
			while (rhs_head != nullptr) {
				if (this_head->prev_ != nullptr) {
					this_head->data_ = rhs_head->data_;
					if (rhs_head->prev_ != nullptr) {
						this_head = this_head->prev_;
					}
				}
				else {
					this_head->data_ = rhs_head->data_;
					if (rhs_head->prev_ != nullptr) {
						Node* previ = this_head;
						this_head = new Node();
						previ->prev_ = this_head;
					}
				}
				rhs_head = rhs_head->prev_;
			}
			Node* temp = this_head;
			this_head = temp->prev_;
			temp->prev_ = nullptr; 
			while (this_head != nullptr) {
				temp = this_head;
				this_head = temp->prev_;
				delete temp;
			}
		}
		return *this;
	}
	StackLst& operator=(StackLst&& rhs) {
		Node* temphead_ = head_;
		head_ = rhs.head_;
		rhs.head_ = temphead_;
		return *this;
	}

	void Pop() noexcept;
	void Push(const Complex&) noexcept;
	bool IsEmpty() noexcept;
	Complex& Top();
	const Complex& Top() const;
};

#endif //STACKLSTHPP
