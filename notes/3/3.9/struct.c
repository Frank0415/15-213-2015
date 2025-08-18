#include <stdlib.h>

struct example {
  int a;
  int b;
  char c;
  long d;
  char e;
};

void example_arr() {
  struct example *a;
  a = malloc(2 * sizeof(struct example));
  a[0].d = 10;
  a[0].e = 'A';
  a[1].a = 10;
  // movq	$10, 16(%rax)
  // movb	$65, 24(%rax)
  // movl	$10, 32(%rax)
}