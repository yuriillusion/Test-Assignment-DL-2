#pragma once

#include <vector>

class SumSegmentTree {
public:
  void Initialize(const std::vector<int>& initial_configuration);
  int Sum(int left, int right);
  void Modify(int index);
  void ApplyOperation(std::string operation, std::ostream& out);

private:
  struct Node {
    int value;
    int left;
    int right;
    int middle;
  };

  const static int kMemoryCoefficient = 4;

  std::vector<Node> tree_;

  void BuildingTraversal(const std::vector<int>& initial_configuration,
    int index, int left_border, int right_border);
  int SummingTraversal(int index, int left, int right);
  int ModifiyngTraversal(int index, int value);
  int Middle(int left, int right);
};