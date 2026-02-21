#include<stdio.h>
int main(){
int read_arr[6];
int power=12345;
        read_arr[0] = power/10000%10+48;
        read_arr[1] = power/1000%10+48;
        read_arr[2] = power/100%10+48;
        read_arr[3] = power/10%10+48;
        read_arr[4] = power/1%10+48;
        for(int i=0;i<5;i++)
        printf("%d\n",read_arr[i]);
        return 0;

}