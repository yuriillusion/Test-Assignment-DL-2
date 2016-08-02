#include "sum_segment_tree.h"

void SumSegmentTree::Initialize(const std::vector<int>& initial_configuration) {
  size_t size = initial_configuration.size();
  tree_.resize(kMemoryCoefficient * size);
  BuildingTraversal(initial_configuration, 1, 0, size);
}

void SumSegmentTree::BuildingTraversal(const std::vector<int>& initial_configuration,
  int index, int left_border, int right_border) {
  if (left_border < right_border) {
    if (left_border == right_border - 1) {
      tree_[index].value = initial_configuration[left_border];
    } else {
      int middle = Middle(left_border, right_border);
      int son_index = index << 1;
      BuildingTraversal(initial_configuration, son_index, left_border, middle);
      BuildingTraversal(initial_configuration, son_index + 1, middle, right_border);
      tree_[index].value = tree_[son_index].value + tree_[son_index + 1].value;
    }
    tree_[index].left = left_border;
    tree_[index].right = right_border;
    tree_[index].middle = Middle(left_border, right_border);
  }
}

int SumSegmentTree::Sum(int left, int right) {
  return SummingTraversal(1, left, right);
}

int SumSegmentTree::SummingTraversal(int index, int left, int right) {
  if (tree_[index].left >= left && tree_[index].right <= right) {
    return tree_[index].value;
  } else if (tree_[index].left >= right || tree_[index].right <= left) {
    return 0;
  } else {
    int son_index = index << 1;
    return SummingTraversal(son_index, left, right) + SummingTraversal(son_index + 1, left, right);
  }
}

void SumSegmentTree::Modify(int index) {
  ModifiyngTraversal(1, index);
}

int SumSegmentTree::ModifiyngTraversal(int index, int destination) {
  if (tree_[index].left == tree_[index].right - 1) {
    if (tree_[index].value == 0) {
      ++tree_[index].value;
      return 1;
    } else {
      --tree_[index].value;
      return -1;
    }
  }
  int increment;
  if (destination >= tree_[index].left && destination < tree_[index].middle) {
    increment = ModifiyngTraversal(index << 1, destination);
  } else {
    increment = ModifiyngTraversal((index << 1) + 1, destination);
  }
  tree_[index].value += increment;
  return increment;
}

int SumSegmentTree::Middle(int left, int right) {
  return (left + right) / 2;
}