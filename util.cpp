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

std::string ReadOperation(std::istream& in) {
  std::string operation;
  std::getline(in, operation);
  return operation;
}

void ApplyOperation(const std::string& operation, std::ostream& out, SumSegmentTree& tree) {
  std::stringstream parser;
  parser << operation;
  int operation_number = 0;
  parser >> operation_number;
  switch (operation_number) {
    case 1: {
      int index = 0;
      parser >> index;
      tree.Modify(index - 1);
      break;
    }
    case 2: {
      int left, right;
      parser >> left >> right;
      out << tree.Sum(left - 1, right) << std::endl;
      break;
    }
    default: {
      std::cerr << "Unknown operation";
    }
  }
}

void Iterate(std::istream& in, std::ostream& out, SumSegmentTree& tree) {
  std::string operation = ReadOperation(in);
  ApplyOperation(operation, out, tree);
}

void MainLoop(std::istream& in, std::ostream& out) {
  std::vector<int> initial_configuration;
  initial_configuration = ReadData(in);
  SumSegmentTree tree;
  tree.Initialize(initial_configuration);
  int number_of_operations;
  in >> number_of_operations;
  in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  for (int i = 0; i < number_of_operations; i++) {
    Iterate(in, out, tree);
  }
}