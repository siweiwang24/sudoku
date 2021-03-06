/*
Copyright 2020. Siwei Wang.
*/
#include "square.h"

using std::bitset;
using std::nullopt;
using std::ostream;
using std::vector;

Square::Square() noexcept
    : m_row(0), m_column(0), m_number(0), m_possible_values(nullopt) {}

vector<unsigned char> Square::possible() const {
  // Get reference to the underlying bitset.
  const auto& bs = m_possible_values.value();
  // Make the vector and reserve the right amount of space.
  vector<unsigned char> v;
  v.reserve(bs.count());
  // Iterate through and push for those that are set.
  for (unsigned char i = 0; i < bs.size(); ++i)
    if (bs[i]) v.emplace_back(static_cast<unsigned char>(i + 1));
  return v;
}
