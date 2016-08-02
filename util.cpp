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