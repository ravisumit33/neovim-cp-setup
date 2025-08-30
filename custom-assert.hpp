#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

template <typename T> void print_vars(const char *var_names, const T &var) {
  cerr << var_names << " = " << var << endl;
}

template <typename T, typename... Args>
void print_vars(const char *var_names, const T &var, const Args &...args) {
  const char *comma = strchr(var_names, ',');
  cerr.write(var_names, comma - var_names) << " = " << var << endl;
  print_vars(comma + 1, args...);
}

#define ASSERT_WITH_VARS(condition, ...)                                       \
  do {                                                                         \
    if (!(condition)) {                                                        \
      cerr << "Assertion failed: " #condition << endl;                         \
      print_vars(#__VA_ARGS__, __VA_ARGS__);                                   \
      abort();                                                                 \
    }                                                                          \
  } while (0)
