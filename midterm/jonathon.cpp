#include <iostream>
using namespace std;

bool check (int n) {
  int i = 2, k = 0, r = 0;
  while (n > 1) { 
    if (n % i == 0) {
      while (n % i == 0) {
        n = n / i;
        ++r;
      }
      ++k; 
    }
    ++i;
  }
  if (k == 2 and r <= 2 or k == 1 and (r == 3 or r == 2)) return 1;
  return false; 
}

int main() {
  int n;
  cin >>n;
  int cnt = 0;

  for (int i = 4; i <= n; ++i) {
    if (check(i)) {
      cout << i << endl;
      ++cnt;
    }
  } 
  cout << cnt << endl;
}