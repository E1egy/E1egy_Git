#include "stdio.h"

struct Example1
{
    int i;
    float f;
    char c;
};


union Example
{
    int i;
    float f;
    char c;
};


int main()
{
    union  Example e;
    struct Example1 e1;
    int content[20] = {12, 90, 91, 23, 7};
    printf("content size = %d", sizeof(content));
    e.i = 10;
}