#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 20
#define Ture 1
#define False 0
typedef struct
{
    char data[MAXSIZE];
    int top;
}Stack;

typedef struct
{
    int data[MAXSIZE];
    int top;
}NumStack;

int InitStack(Stack *S)
{
    int i;
    for(i=0 ; i<MAXSIZE ; i++)
    {
        S->data[i]=0;
        S->top = -1;
        return Ture;
    }
}

int CreateStack(Stack *S , int n)
{
    if(n > MAXSIZE || n < 1)
    {
        printf("Lenth error");
        return False;
    }
    int i;
    for(i = 0; i < n; i++)
    {
        S->data[i]=rand()%100+1;
    }
    S->top = n-1;
    return Ture;
}

int Push(Stack *S , char e)
{
    if(MAXSIZE-1 == S->top)
    {
        printf("Stack already full!");
        return False;
    }
    ++(S->top);
    S->data[S->top] = e;
    return Ture;
}

int Pop(Stack *S, char *e)
{
    if(S->top == -1)
    {
        printf("Stack empty!");
        return False;
    }
    *e=S->data[S->top];
    --(S->top);
    return Ture;
}
void MidtoFin(char *Mid , char *Fin)
{
    char e;
    Stack S;
    if(InitStack(&S) != Ture)
    {
        printf("Init Error");

    }
    while(*Mid)
    {
        if(*Mid>='0' && *Mid<='9')
        {
            *(Fin++)=*(Mid++);
            *(Fin++)=',';
            continue;
        }
        else if(*Mid=='+'||*Mid=='-'||*Mid=='*'||*Mid=='/'||*Mid=='('||*Mid==')')
        {
            if(S.top == -1 || *Mid == '(')
           {
               Push(&S,*(Mid++));
                continue;
           }
           if(*Mid == ')')
           {
                Pop(&S,&e);

                *(Fin++)=e;
                while(Pop(&S,&e) && e!='(')
                {
                     *(Fin++) = e;
                }

                Mid++;
                continue;
           }//if
        }//elseif
         Pop(&S,&e);
         if('+'==*Mid || '-'==*Mid)
         {
             if(e == '(')
             {
                Push(&S,'(');
                Push(&S,*(Mid++));
                continue;
             }
             else
             {
                 *(Fin++) = e;
                 Push(&S,*(Mid++));
                 continue;
             }
         }
         else if('*'==*Mid || '/'==*Mid)
         {
             if(e == '*' || e == '/')
             {
                 *(Fin++)= e;
                 Push(&S,*(Mid++));
                 continue;
             }
             else
             {
                 Push(&S,e);
                 Push(&S,*(Mid++));
                 continue;
             }
         }
    }//while
    while(S.top != -1)
    {
        Pop(&S,&e);
        *(Fin++) = e;
    }
    *Fin = '\0';
}

int operation(int number_1 , char op , int number_2)
{

    switch(op)
    {
        case '+':return number_1 + number_2;
        case '-':return number_1 - number_2;
        case '*':return number_1 * number_2;
        case '/':return number_1 / number_2;
    }
}
int IsNumber(char x)
{
    switch(x)
    {
        case '0':return 1;
        case '1':return 1;
        case '2':return 1;
        case '3':return 1;
        case '4':return 1;
        case '5':return 1;
        case '6':return 1;
        case '7':return 1;
        case '8':return 1;
        case '9':return 1;

        default:
            return(0);
    }
}
int IsOperate(char x)
{
	switch(x)
	{
		case '+':return 1;
		case '-':return 1;
		case '*':return 1;
		case '/':return 1;
		case ',':return 2;
	}
}
int SumOfFin(char *Fin)
{

    NumStack Num;
    Num.top = -1;
    int i=0;
    int number_2;
    int number_1;
    int lastnum;
    int y;
    while(Fin[i] != '\0')
    {
        if(IsNumber(Fin[i]))
        {

             Num.data[++Num.top] = atoi(&Fin[i]) ;
        }


        else
        {
        	y=IsOperate(Fin[i]);
        	switch(y)
        	{
        		case 1:{
	        			number_2=Num.data[Num.top--];
			            number_1=Num.data[Num.top--];
			            lastnum = operation(number_1,Fin[i],number_2);
			            Num.data[++Num.top] = lastnum;
						break;
						}
				case 2:break;
			}

        }

        i++;

    }
    return Num.data[Num.top];

}
int main(void)
{
	char Mid[256];
	char Fin[]="";
	int y;
	printf("input:\n");
	gets(Mid);
	MidtoFin(Mid , Fin);
	//printf("%s\n",Fin);
	y=SumOfFin(Fin);
    printf("The result is :%d",y);
	return 0;
}

