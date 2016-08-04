#include "util.h"

std::vector<int> ReadData(std::istream& in) {
  size_t size;
  in >> size;
  std::vector<int> data(size);
  for (int i = 0; i < size; i++) {
    in >> data[i];
  }
  return data;
}

void ApplyOperation(std::istream& in, std::ostream& out, SumSegmentTree& tree) {
  int operation_number;
  in >> operation_number;
  switch (operation_number) {
    case 1: {
      int index = 0;
      in >> index;
      tree.Modify(index - 1);
      break;
    }
    case 2: {
      int left, right;
      in >> left >> right;
      out << tree.Sum(left - 1, right - 1) << std::endl;
      break;
    }
    default: {
      std::cerr << "Unknown operation";
    }
  }
}

void MainLoop(std::istream& in, std::ostream& out) {
  std::vector<int> initial_configuration;
  initial_configuration = ReadData(in);
  SumSegmentTree tree;
  tree.Initialize(initial_configuration);
  int number_of_operations;
  in >> number_of_operations;
  for (int i = 0; i < number_of_operations; i++) {
    ApplyOperation(in, out, tree);
  }
}
