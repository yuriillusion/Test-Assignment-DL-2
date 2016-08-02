#include "sum_segment_tree.h"
#include "util.h"
#include <fstream>

int main() {
  std::ifstream in("input.txt");
  std::ofstream out("output.txt");
  MainLoop(in, out);
  in.close();
  out.close();

  return 0;
}