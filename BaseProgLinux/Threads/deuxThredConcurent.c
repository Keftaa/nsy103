#include <pthread.h>
#include <stdio.h>
extern unsigned long x;
unsigned long x = 2;
void *pa(void *p) {
  x = x + 1;
}

void *pb(void *p) {
  x = x * 3;
}

void lanceThread() {
  pthread_t ta, tb;
  pthread_create(&ta, 0, pa, 0);
  pthread_create(&tb, 0, pb, 0);

  pthread_join(tb, 0);
  pthread_join(ta, 0);
 
}
int main() {
  x = 2;
  lanceThread();
  printf("x=%lu\n", x);
}