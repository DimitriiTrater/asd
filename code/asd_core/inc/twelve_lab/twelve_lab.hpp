#pragma once
#include "tenth_lab/tenth_lab.hpp"
#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <istream>
#include <limits>
#include <queue>
#include <string>
#include <vector>

struct MinHeapNode {
  int element;
  int index;
};

struct Comp {
  bool operator()(const MinHeapNode &left, const MinHeapNode &right) const {
    return left.element > right.element;
  }
};

std::fstream open_file(const std::string &file_name,
                       std::ios_base::openmode mode);

void merge_files(const std::string &output_file, int n, int k);

void create_initial_files(const std::string &input_file, int run_size,
                          int num_ways);

void start_tw();
