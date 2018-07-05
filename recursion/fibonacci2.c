#include <stdio.h>

int main() {
  int d,i;
  printf("请输入想要得到的fibonacci位置的数。\n");
  scanf("%d",&i);
  d = Fib(i);
  printf("%d\n", d);
  return 0;
}
int Fib(int i) {
  if (i < 2) {
    return i == 0 ? 0 : 1;
  }
  return Fib(i-1) + Fib(i-2);
}
