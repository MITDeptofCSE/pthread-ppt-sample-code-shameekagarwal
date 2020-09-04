#include<stdio.h>
#include <pthread.h>
#include<stdlib.h>
int sum;
void runner(char * param);
int main(int argc, char* argv[]) {
  pthread_t tid;
  pthread_attr_t attr;
  if (argc != 2) {
    fprintf(stderr, "usage: a.out <integer value>\n");
    return -1;
  }
  if (atoi(argv[1]) < 0) {
    fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
    return -1;
  }
  printf("Sum = %d\n", sum);
}
void runner(char *param) {
  int i, upper = atoi(param);
  sum = 0;
  for (i = 1; i <= upper; i++) {
    sum += i;
  }
  pthread_exit(0);//this line shows error i dont know
}