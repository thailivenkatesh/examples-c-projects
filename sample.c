#include <stdio.h>
#include <stdlib.h>
void func(void(*fp)(float)){
    (*fp)(8.5);
    printf("In funcion 1\n");
}
void func1(float f){
    printf("%f\n",f);
}
int main(){
  printf("In main\n");
 func(func1);
}

