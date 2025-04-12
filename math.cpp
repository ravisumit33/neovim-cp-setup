#include <cmath>

namespace squareRoot {

int isqrt(int x) {
  int sq = sqrt(x) + 2;
  while (sq > x / sq) {
    --sq;
  }
  return sq;
}

int64_t isqrtl(int64_t x) {
  int64_t sq = sqrtl(x) + 2;
  while (sq > x / sq) {
    --sq;
  }
  return sq;
}

} // namespace squareRoot
