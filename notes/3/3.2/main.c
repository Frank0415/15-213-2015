void multstore(long a, long b, long *c);

int main() {
  long d = 1;
  multstore(2, 3, &d);
  return 0;
}

long mult2(long a, long b) {
  long s = a * b;
  return s;
}