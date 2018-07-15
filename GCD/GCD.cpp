#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}


unsigned long gcd_fast(unsigned long x, unsigned long y)
{
    if(x < y)
    {
        std::swap (y, x);
    }

    unsigned long f = 1;
    while (y > 0)
    {
        f = x % y;
        x = y;
        y = f;
    }
    return x;
}

int main() {
  unsigned long a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
