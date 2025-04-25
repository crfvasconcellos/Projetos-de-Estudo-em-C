#include <stdio.h>

void mostrarpont(int * lista, int * listacomE, int * valor1 )
{
    printf("%d %d  %d ",*lista,listacomE,valor1);

}

int main()
{
    int nums[3];
nums[0] = 10;
nums[1] = 20;
nums[2] = 30;

mostrarpont(nums,&nums,&nums[0]);
}