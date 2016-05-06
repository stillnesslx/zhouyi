#include <stdio.h>
#include <stdlib.h>
#include "time.h"

//rxl
unsigned int randint(unsigned int l, unsigned int u)
{
    return l + (RAND_MAX * rand() + rand()) % (u-l);
}
/*unsigned int randint(unsigned int l, unsigned int u)
{
    return l + rand() % (u-l);
}*/
int main()
{
    unsigned int i,j;
    unsigned int sen,sky,earth,people;
    unsigned int es[6];
    srand((unsigned int)time(NULL));
    people = 1;
    for(i=0;i<6;i++)
    {
        sen = 49;
        for(j=0;j<3;j++)
        {
            sky = randint(4-i,sen-4+i);
            //printf("%d\r\n",sky);
            earth = sen - sky;
            //printf("%d",sky);
            (0 == randint(0,1)) ? (sky = sky -1) : (earth = earth - 1);
            sky = (sky % 4 == 0) ? (4) : (sky % 4);
            earth = (earth % 4 == 0) ? (4) : (earth % 4);
            sen = sen - sky - earth - people;
            //printf("sky:%d,earth:%d,sen%d\r\n",sky,earth,sen);
        }
        es[i] = sen / 4;
        //printf("sen:%d,es[%d]:%d\r\n",sen,i,es[i]);
        printf("es:%d\r\n",es[i]);
    }
    return 0;
}
