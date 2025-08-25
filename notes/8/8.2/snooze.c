#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

unsigned int snooze(unsigned int secs) {
  unsigned int sleep_time = sleep(secs);
  printf("Slept for %d of %d secs.", secs - sleep_time, secs);
  return sleep_time;
}

int main() {
  snooze(2);
  return 0;
}