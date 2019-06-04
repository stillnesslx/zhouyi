#include <stdio.h>
#include <stdlib.h>
#include "time.h"

#include <assert.h>


//rxl 2016
unsigned int randint(unsigned int l, unsigned int u)
{
    return l + (RAND_MAX * rand() + rand()) % (u-l);
}
/*unsigned int randint(unsigned int l, unsigned int u)
{
    return l + rand() % (u-l);
}*/
//char pos = ”––”  
int main()
{
    char pos[4] = "---";
    char neg[4] = "- -";
    char pna[4][4] = {"- -","---","- -","---"};
    char cpna[4][4] = {"---","---","- -","- -"};
    printf("%s:%s:%s:%s",pna[0],pna[1],pna[2],pna[3]);

    unsigned int i,j;
    unsigned int sen,sky,earth,people;
    unsigned int es[6];
    srand((unsigned int)time(NULL));
    people = 1;
    //for(i=0;i<100;i++)
    //{
        //printf("%d:",randint(0,5));
    //}
    printf("\r\n");
    for(i=0;i<6;i++)
    {
        sen = 49;
        for(j=0;j<3;j++)
        {
            sky = randint(1,sen-1);
            //printf("sky:%d\r\n",sky);
            earth = sen - sky - 1;
            //printf("%d",sky);
            //(0 == randint(0,2)) ? (sky = sky -1) : (earth = earth - 1);
            sky = (sky % 4 == 0) ? (4) : (sky % 4);
            earth = (earth % 4 == 0) ? (4) : (earth % 4);
            sen = sen - sky - earth - people;
            //printf("i=%d,j=%d,sky:%d,earth:%d,sen%d\r\n",i,j,sky,earth,sen);
        }
        assert(0 == (es[i] % 4));
        es[i] = sen / 4;
       // printf("sen:%d,es[%d]:%d\r\n",sen,i,es[i]);
       // printf("es:%d\r\n",es[i]);
    }

    for(i=0;i<6;i++)
    {
        printf("\r\n %d: %s  %s",es[5-i],pna[es[5-i]-6],cpna[es[5-i]-6]);
    }
    printf("\r\n");
    return 0;
}
