#ifndef BITSET_BITSET_HPP_20240318
#define BITSET_BITSET_HPP_20240318

#include <cstdint>
#include <iosfwd>
#include <vector>
#include <stdexcept>

class BitAccessor;

class BitSet {
public:
  BitSet() = default;

  BitSet(const BitSet&) = default;

  BitSet(BitSet&&) = default;

  BitSet(const std::int32_t size);

  BitSet& operator=(const BitSet&) = default;

  BitSet& operator=(BitSet&&) = default;

  ~BitSet() = default;

  [[nodiscard]] bool operator==(const BitSet& rhs) const noexcept;

  [[nodiscard]] bool operator!=(const BitSet& rhs) const noexcept;

  int32_t Size() const noexcept;

  void Resize(const int32_t size); // 0 < size

  [[nodiscard]] bool Get(const int32_t idx) const;

  void Set(const int32_t idx, const bool val);

  void Fill(const bool val) noexcept;

  [[nodiscard]] BitSet& operator&=(const BitSet& rhs);

  [[nodiscard]] BitSet& operator|=(const BitSet& rhs);

  [[nodiscard]] BitSet& operator^=(const BitSet& rhs);

  [[nodiscard]] BitSet operator~();

  BitAccessor operator[](const int32_t);
  
  // std::ostream& WriteTxt(std::ostream&);
  // std::ostream& WriteBinary(std::ostream&);
  // std::istream& ReadTxt(std::istream&);
  // std::istream& ReadBinary(std::istream&);
private:
  std::int32_t size_ = 0;
  std::vector<uint32_t> bits_;
};

// std::ostream& operaror<<(std::ostream&, const BitSet&);
// std::istream& operaror>>(std::istream&, BitSet&);

[[nodiscard]] BitSet operator&(const BitSet& lhs, const BitSet& rhs);

[[nodiscard]] BitSet operator|(const BitSet& lhs, const BitSet& rhs);

[[nodiscard]] BitSet operator^(const BitSet& lhs, const BitSet& rhs);

class BitAccessor {
  public:
    BitAccessor() = default;

    BitAccessor(const BitAccessor&) = default;

    BitAccessor(BitAccessor&&) = default;

    BitAccessor(const BitSet bits, int32_t idx)
      : bits_{bits}, idx_{idx}
    {
    }

    ~BitAccessor() = default;

    [[nodiscard]] BitAccessor& operator=(const BitAccessor&) = default;

    [[nodiscard]] BitAccessor& operator=(BitAccessor&&) = default;

    void Set(const bool) noexcept;

    [[nodiscard]] BitAccessor& operator=(const bool& rhs);
    
    [[nodiscard]] BitAccessor& operator&=(const bool& rhs);

    [[nodiscard]] BitAccessor& operator|=(const bool& rhs);

    [[nodiscard]] BitAccessor& operator^=(const bool& rhs);

    [[nodiscard]] BitAccessor operator~();

    friend bool operator&(const BitAccessor& lhs, const BitAccessor& rhs);

    friend bool operator|(const BitAccessor& lhs, const BitAccessor& rhs);
    
    friend bool operator^(const BitAccessor& lhs, const BitAccessor& rhs);

    bool operator==(const bool& rhs);

    bool operator!=(const bool& rhs);

  private: 
    BitSet bits_;
    const int32_t idx_; 
};

[[nodiscard]] bool operator&(const BitAccessor& lhs, const BitAccessor& rhs);

[[nodiscard]] bool operator|(const BitAccessor& lhs, const BitAccessor& rhs);

[[nodiscard]] bool operator^(const BitAccessor& lhs, const BitAccessor& rhs);


#endif
