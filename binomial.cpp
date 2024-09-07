namespace binomial {

int ncr(int n, int r) {
  double res = 1;
  for (int i = 1; i <= r; ++i)
    res = res * (n - r + i) / i;
  return (int)(res + 0.01);
}

namespace pascal {

const int MAXN = 1e3;
int C[MAXN + 1][MAXN + 1];
void precompute() {
  C[0][0] = 1;
  for (int n = 1; n <= MAXN; ++n) {
    C[n][0] = C[n][n] = 1;
    for (int k = 1; k < n; ++k)
      C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
  }
}

} // namespace pascal

} // namespace binomial
