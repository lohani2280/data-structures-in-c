#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist
{
        char emp;
        int time1;
        int time2;
        struct linkedlist *add;
}node;

void CREATE(node **head,char c,int t1, int t2);
void TRAVERSE(node **head,int total);

int main(void)
{
    node *head = NULL;
    char e[7]={'A','B','C','D','E','F','G'};
    int t[7]={4,5,5,3,1,2,4};
    char in;
    printf("Enter the employee name which will start first.\n");
    //getchar();
    in=getchar();
    printf("%c\n",in);
    int total=0,i,f=0,a=0,x;
    for(i=0;i<7;i++)
    {
        if(in==e[i])
        {
            f=1;
            break;
        }
    }
    if(f==1)
    {
    while(total!=24)
    {
        if(t[i]>0)
        {
            if(t[i]>=2)
            {
                x=total;
                total=total+2;
                t[i]-=2;
                CREATE(&head,in,x,total);

            }
            else if(t[i]==1)
            {
                x=total;
                total+=1;
                t[i]-=1;
                CREATE(&head,in,x,total);

            }
            else
                a++;
        }
        printf("|%d||%c||%d||%d| ",x,e[i],total,t[i]);
        i=(i+1)%7;
        in=e[i];

    }
    CREATE(&head,'Q',-1,-1);
    TRAVERSE(&head,total);
    }
    else
        printf("Wrong Input.\n");
    return 0;
}


void CREATE(node **head,char c,int t1,int t2)
{
    node *current;
    if(*head==NULL)
    {
        (*head)=(node*)malloc(sizeof(node));
        (*head)->emp=c;
        (*head)->time1=t1;
        (*head)->time2=t2;
        (*head)->add=NULL;
    }
    else
    {
        current=(*head);
        while(current->add!=NULL)
        {
            current=current->add;
        }
        current->add=(node*)malloc(sizeof(node));
        current->add->emp=c;
        current->add->time1=t1;
        current->add->time2=t2;
        current->add->add=NULL;
	}
}

void TRAVERSE(node **head,int total)
{
    int i,j,st,et,c,sh;
    char e[7]={'A','B','C','D','E','F','G'};
    node *cur;
    cur=(*head);
    for(i=0;i<7;i++)
    {
        c=0;
        while(cur->emp!='Q')
        {
            if((cur->emp==e[i])&&c==0)
            {
                st=cur->time1;
                printf("The starting time of %c is %d\n",e[i],st);
                c=1;
            }
            if((cur->emp==e[i]))
            {
                et=cur->time2;
            }
            if(cur->add!=NULL)
                cur=cur->add;
        }
        printf("The end time of %c is %d\n",e[i],et);
        sh=et-st;
        printf("The time for which %c shares the platform is %d\n\n",e[i],sh);
        cur=(*head);
    }
}
