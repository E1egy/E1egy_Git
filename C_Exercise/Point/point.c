#include "stdio.h"
int main()
{
    int *p;
    int a = 5;
    int b = 10;
    p = &a; // 指针p存储a的地址
    *p = b; // 指针先指向一个地址，然后将a的值给p指向的地址所对应的变量
    printf("p = %d\na = %d\nb = %d", *p, a, b);
}
                            











