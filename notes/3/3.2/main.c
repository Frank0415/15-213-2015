#include <stdio.h>

void multstore(long a, long b, long *c) { *c = a * b; }

int main() {
  long d = 1;
  multstore(2, 3, &d);
  printf("2 * 3 --> %ld\n", d);
  return 0;
}

long mult2(long a, long b) {
  long s = a * b;
  return s;
}