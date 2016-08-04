#pragma once

#include "sum_segment_tree.h"
#include <iostream>
#include <vector>

std::vector<int> ReadData(std::istream& in);
std::string ReadOperation(std::istream& in);
void ApplyOperation(std::istream& in, std::ostream& out, const SumSegmentTree& tree);
void MainLoop(std::istream& in, std::ostream& out);
