#include <stdio.h>
#include <string.h>

void x (){
  char str [100];
  printf("Enter a string: \n");
  fgets(str, sizeof(str), stdin);
  // scanf("%s", str);
  printf("%s", str);
}

void main (){
  x();
  // return 0;
}
