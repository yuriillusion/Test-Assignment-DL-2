#pragma once

#include <vector>

class SumSegmentTree {
public:
  void Initialize(const std::vector<int>& initial_configuration);
  int Sum(int left, int right);
  // Changes 1 to 0 and vice versa
  void Modify(int index);

private:
  // Segment tree on n elements can be placed in 4n memory units
  const static int kMemoryCoefficient = 4;
  const static int kRootIndex = 1;

  std::vector<int> tree_;
  int lower_level_index_;

  bool IsOdd(const int number);
  int UpperIntegerLog2(int number);
};
