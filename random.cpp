#include <random>

using namespace std;

namespace RNG {

class RNG {
public:
  RNG(int mn, int mx) : gen(rd()), dist(mn, mx) {}
  int generate() { return dist(gen); }

private:
  random_device rd;
  mt19937 gen;
  uniform_int_distribution<int> dist;
};

} // namespace RNG
