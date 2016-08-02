#pragma once

#include <vector>

class SumSegmentTree {
public:
  void Initialize(const std::vector<int>& initial_configuration);
  int Sum(int left, int right);
  // Changes 1 to 0 and vice versa
  void Modify(int index);
  void ApplyOperation(std::string operation, std::ostream& out);

private:
  // Contains sum of elements x[i] of initial set, where i is in [left, right)
  struct Node {
    int value;
    int left;
    int right;
    int middle;
  };

  // Segment tree on n elements can be placed in 4n memory units
  const static int kMemoryCoefficient = 4;
  const static int kRootIndex = 1;

  std::vector<Node> tree_;

  void BuildingTraversal(const std::vector<int>& initial_configuration,
    int index, int left_border, int right_border);
  int SummingTraversal(int index, int left, int right);
  int ModifiyngTraversal(int index, int value);
  int Middle(int left, int right);
};