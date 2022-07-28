#include <stdio.h>
#include <stdlib.h>
void reverse_sentance(char sen)
{
    int i,j,counter=0;
    char *ptr;
    ptr=&sen;
            for( i = sizeof(sen)-2; i>=0 ; i--)
            {
                counter++;
                if(*ptr==' ')
                {
                    for( j=i+1 ; j<i+counter; j++)
                    {
                        printf("%c",sen[j]);
                    }
                    printf(" ");
                    counter=0;
                }
                else if(i==0)
                {
                    for( j=i ; j<i+counter; j++)
                    {
                        printf("%c",sen[j]);
                    }
                }
                *ptr++;
            }
}
int main()
{
    char sen[]="i like this program very much";
    int choise;
    while(1)
    {
        printf("1- reverse sentence     2-reverse word");
        scanf("%d",choise);
        switch(choise)
        {
        case 1 :
            reverse_sentance(sen);
            break;
        case 2 :
            break;
        default :
            break;
        }
    }
}
