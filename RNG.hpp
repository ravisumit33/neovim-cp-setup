#pragma once

#include <random>

class RNG {
public:
  RNG(int mn, int mx) : gen(rd()), dist(mn, mx) {}
  int generate() { return dist(gen); }

private:
  std::random_device rd;
  std::mt19937 gen;
  std::uniform_int_distribution<int> dist;
};
