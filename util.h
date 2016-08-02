#pragma once

#include "sum_segment_tree.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> ReadData(std::istream& in);
std::string ReadOperation(std::istream& in);
void ApplyOperation(const std::string& operation, std::ostream& out, SumSegmentTree& tree);
void Iterate(std::istream& in, std::ostream& out, const SumSegmentTree& tree);
void MainLoop(std::istream& in, std::ostream& out);
