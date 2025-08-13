#include <stdbool.h>
int cmp_more(int a, int b) { return a < b; }

bool cmp_more_1(int a, int b) { return a < b; }

int cmp_more_2(int a, int b) {
  if (a > b) {
    return 114;
  } else {
    return 514;
  }
}