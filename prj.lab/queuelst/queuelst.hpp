#ifndef QUEUELSTHPP24022024
#define QUEUELSTHPP24022024

#include <complex/complex.hpp>
#include <iostream>

class QueueLst {
protected:
    struct Node {
        Node* next_{nullptr};
        Complex data_;

        Node() = default;
        Node(Node* const next) 
            : next_{next}
        {
        }
        Node(const Complex& data) 
            : data_{data}
        {
        }
        ~Node() = default;
    };
    Node* first_{nullptr};
    Node* last_{nullptr};
public:
    QueueLst() = default;
    ~QueueLst() {
        while (first_ != nullptr) {
            Node* temp = first_;
            first_ = temp->next_;
            delete temp;
        }
        last_ = nullptr;
    }
    QueueLst(const QueueLst& rhs) {
        Node* rhs_first = rhs.first_;
        while (rhs_first != nullptr) {
            this->Push(rhs_first->data_);
            rhs_first = rhs_first->next_;
        }
    }
    QueueLst(QueueLst&& rhs) {
        Node* tempfirst_ = first_;
        Node* templast_ = last_;
        first_ = rhs.first_;
        last_ = rhs.last_;
        rhs.first_ = tempfirst_;
        rhs.last_ = templast_;
    }
    QueueLst& operator=(const QueueLst& rhs) {
        if (this != &rhs) {
            while (first_ != nullptr) {
                Node* temp = first_;
                first_ = temp->next_;
                delete temp;
            }
            last_ = nullptr;
            Node* rhs_first = rhs.first_;
            while (rhs_first != nullptr) {
                this->Push(rhs_first->data_);
                rhs_first = rhs_first->next_;
            }
        }
        return *this;
    }
    QueueLst& operator=(QueueLst&& rhs) {
        Node* tempfirst_ = first_;
        Node* templast_ = last_;
        first_ = rhs.first_;
        last_ = rhs.last_;
        rhs.first_ = tempfirst_;
        rhs.last_ = templast_;
        return *this;
    }

    virtual void Push(const Complex&) noexcept;
    void Pop() noexcept;
    Complex& Top();
    const Complex& Top() const;
    bool IsEmpty();
    void Clear() noexcept; 
};

#endif //QUEUELSTHPP24022024
