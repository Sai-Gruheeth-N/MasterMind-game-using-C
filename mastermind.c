#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
void intro();
void play();
int main()
{
    intro();
    play();
    return 0;
}
void intro()
{
    printf("\n\n\n*****   WELCOME TO MASTERMIND   *****\n\n\n");
    printf("The colors are: ['B','G','Y','O','R','P']\n");
    printf("Guess the correct sequence of the randomly generated 4-color code.\n");
    printf("\nRULES : \n");
    printf("1. Input should be in capitals.\n");
    printf("2. Input should not have spaces.\n");
    printf("3. White peg represents the correct color in the wrong position.\n");
    printf("4. Black peg represents the correct color in the correct position.\n");
    printf("\nGood Luck!\n\n");
}
void play()
{
    int x,c,attempt,left,i,j,k;
    char ch;
    srand(time(0));
    char *color[6]={"B","G","Y","O","R","P"};
    char ip[4];
    char gen[4];
    for(i=0;i<4;i++)                      
    {
        x=rand()%6;                                
        gen[i]=*color[x];
        printf("%c",gen[i]);
    }
    printf("\n");
    int again;
    for(i=0;i<7;i++)                       
    {
        attempt=i+1;
        left=7-attempt;
        printf("Attempt : %d\n",attempt);
        printf("Enter 4 colours : \n");    
        scanf("%s",ip);
        for(k=0;k<=4;k++)                        
        {
            printf("%c",ip[k]);
        }
        printf("\n");
        int bp=0,wp=0;
        c=strcmp(gen,ip);                    
        if(c==0)
        {
            bp=4;
            wp=0;
        }
        else
        {
            for(j=0;j<4;j++)
            {
                if(ip[j]==gen[j])
                {
                    bp=bp+1;
                }
                else
                {
                    for(k=0;k<4;k++)
                    {
                        if(gen[j]==ip[k] && gen[k]!=ip[k])
                        {
                            wp=wp+1;
                        }
                    }
                }
            }
        }
        if(bp==4)
        {
            printf("Correct...You are right.!!\n");
            goto end;
        }
        else
        {
            printf("Blackpegs : %d\n",bp);
            printf("Whitepegs : %d\n",wp);
            printf("Number of attempts left : %d\n\n",left);
        }
        end:if(left==0||bp==4)
        {
            printf("The colours are : ");
            for(j=0;j<4;j++)
            {
                printf("%c",gen[j]);
            }
            printf("\n");
            printf("Do you want to play again ? (y-1/n-0) :");
            scanf("%d",&again);
            printf("\n");
            if(again==1)
            {
                play();
            }
            else
            {
                printf("Thanks for playing..!!\n\n");
                exit(0);
            }
        }
    }
}