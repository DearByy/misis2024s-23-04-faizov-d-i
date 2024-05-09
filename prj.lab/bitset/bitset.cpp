#include "bitset.hpp"

BitSet::BitSet(const std::int32_t size)
{
    size_ = size;
    bits_ = std::vector<uint32_t>(size_ / 32 + 1, 0);
}

bool BitSet::operator==(const BitSet &rhs) const noexcept
{
    return bits_ == rhs.bits_;
}

bool BitSet::operator!=(const BitSet &rhs) const noexcept
{
    return !(operator==(rhs));
}

int32_t BitSet::Size() const noexcept
{
    return size_;
}

void BitSet::Resize(const int32_t size)
{
    size_ = size;
    bits_.resize(size_ / 32 + 1);
}

bool BitSet::Get(const int32_t idx) const
{
    if (idx < size_) {
        return bits_[idx / 32] & (1 << idx % 32);   
    }
    else {
        throw std::range_error("Index out of range");
    }
}

void BitSet::Set(const int32_t idx, const bool val)
{
    if (idx < size_) {
        bits_[idx / 32] = val ? bits_[idx / 32] | (1 << idx % 32) : bits_[idx / 32] & ~(1 << idx % 32);
    }
    else {
        throw std::range_error("Index out of range");
    }
}

void BitSet::Fill(const bool val) noexcept
{
    for (uint32_t bit : bits_) {
        bit = val ? 0xFFFFFFFF : 0;
    }
}

BitSet &BitSet::operator&=(const BitSet &rhs)
{
    for (int32_t i{0}; i < bits_.size(); ++i) {
        bits_[i] &= rhs.bits_[i];
    }
    return *this;
}

BitSet &BitSet::operator|=(const BitSet &rhs)
{
    for (int32_t i{0}; i < bits_.size(); ++i) {
        bits_[i] |= rhs.bits_[i];
    }
    return *this;
}

BitSet &BitSet::operator^=(const BitSet &rhs)
{
    for (int32_t i{0}; i < bits_.size(); ++i) {
        bits_[i] ^= rhs.bits_[i];
    }
    return *this;
}

BitSet BitSet::operator~()
{
    for (uint32_t bit : bits_) {
        bit = ~(bit);
    }
    return *this;
}

BitAccessor BitSet::operator[](const int32_t idx)
{
    return BitAccessor(*this, idx);
}

bool operator&(const BitAccessor &lhs, const BitAccessor &rhs)
{
    return (lhs.bits_.Get(lhs.idx_) & (rhs.bits_.Get(rhs.idx_)));
}

bool operator|(const BitAccessor &lhs, const BitAccessor &rhs)
{
    return (lhs.bits_.Get(lhs.idx_) | (rhs.bits_.Get(rhs.idx_)));
}

bool operator^(const BitAccessor &lhs, const BitAccessor &rhs)
{
    return (lhs.bits_.Get(lhs.idx_) ^ (rhs.bits_.Get(rhs.idx_)));
}

BitSet operator&(const BitSet &lhs, const BitSet &rhs)
{
    BitSet temp(lhs);
    return (temp &= rhs);
}

BitSet operator|(const BitSet &lhs, const BitSet &rhs)
{
    BitSet temp(lhs);
    return (temp |= rhs);
}

BitSet operator^(const BitSet &lhs, const BitSet &rhs)
{
    BitSet temp(lhs);
    return (temp ^= rhs);
}

void BitAccessor::Set(const bool rhs) noexcept
{
    bits_.Set(idx_, rhs);
}

BitAccessor &BitAccessor::operator=(const bool &rhs)
{
    bits_.Set(idx_, rhs);
    return *this;
}

BitAccessor &BitAccessor::operator&=(const bool &rhs)
{
    bits_.Set(idx_, (bits_.Get(idx_) & rhs));
    return *this;
}

BitAccessor &BitAccessor::operator|=(const bool &rhs)
{
    bits_.Set(idx_, (bits_.Get(idx_) | rhs));
    return *this;
}

BitAccessor &BitAccessor::operator^=(const bool &rhs)
{
    bits_.Set(idx_, (bits_.Get(idx_) ^ rhs));
    return *this;
}

BitAccessor BitAccessor::operator~()
{
    bits_.Set(idx_, ~(bits_.Get(idx_)));
    return *this;
}

bool BitAccessor::operator==(const bool &rhs)
{
    return (bits_.Get(idx_) == rhs);
}

bool BitAccessor::operator!=(const bool &rhs)
{
    return !operator==(rhs);
}
