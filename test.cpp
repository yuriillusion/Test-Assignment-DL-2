#include "sum_segment_tree.h"
#include <vector>
#include <iostream>

int main() {
  SumSegmentTree stree;
  std::vector<int> a = { 1, 0, 1 };
  stree.Initialize(a);
  stree.Modify(1);
  stree.Modify(2);
  std::cout << stree.Sum(0, 2);

  return 0;
}