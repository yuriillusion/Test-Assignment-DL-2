#include "sum_segment_tree.h"

void SumSegmentTree::Initialize(const std::vector<int>& initial_configuration) {
  int size = initial_configuration.size();
  tree_.resize(kMemoryCoefficient * size);
  int height = GetPowerOf2(size);
  lower_level_index_ = 1 << height;
  for (int i = 0; i < size; i++) {
    tree_[lower_level_index_ + i] = initial_configuration[i];
  }
  int level_index = lower_level_index_ >> 1;
  while (level_index > 0) {
    int last_index = level_index << 1;
    for (int i = level_index; i < last_index; i++) {
      tree_[i] = tree_[(i << 1)] + tree_[(i << 1) + 1];
    }
    level_index >>= 1;
  }
}

int SumSegmentTree::Sum(int left, int right) {
  int sum = 0;
  left += lower_level_index_;
  right += lower_level_index_;
  while (left < right) {
    if (IsOdd(left)) {
      sum += tree_[left];
      ++left;
    }
    if (!IsOdd(right)) {
      sum += tree_[right];
      --right;
    }
    left >>= 1;
    right >>= 1;
  }
  if (left == right) {
    sum += tree_[left];
  }
  return sum;
}

void SumSegmentTree::Modify(int index) {
  int increment;
  if (tree_[lower_level_index_ + index] == 0) {
    tree_[lower_level_index_ + index] = 1;
    increment = 1;
  } else {
    tree_[lower_level_index_ + index] = 0;
    increment = -1;
  }
  int current_index = (lower_level_index_ + index) >> 1;
  while (current_index > 0) {
    tree_[current_index] += increment;
    current_index >>= 1;
  }
}

bool SumSegmentTree::IsOdd(const int number) {
  return (number & 1) == 1;
}

int SumSegmentTree::GetPowerOf2(int number) {
  int power = 0;
  number -= 1;
  while (number) {
    number >>= 1;
    power += 1;
  }
  return power;
}