#include <stdio.h>
#include <stdlib.h>

int p,q,map[1000][1000]={0},book[1000][1000]={0},n,m;

int lujing[100]={0},lujing2[100] = {0};
int tail=0;
int head=0;
//struct note notee[100];
int stack2_tail=0;
int stack2_head=0;




struct note
{
    int x;
    int y;

};
struct note stack1[100];
struct note stack2[100];



void  dfs(int x ,int y,int step)
{
    //地图的大小，n行m列
   //终点
    //int booll=0;
    int next[4][2]={{0,1},
                  {1,0},
                  {0,-1},
                  {-1,0}};
    int i,tx,ty;
    //printf("%d %d <---",x,y);
    if(x==p&&y==q)
    {
        printf("\n");
        //printf("(%d %d)<--",x,y);
        //nodee[j].x=x;   // 放入栈
        //nodee[j].y=y;

        while(tail!=head)
        {
            printf("(%d,%d)<---",stack1[tail].x,stack1[tail].y);
            tail++;
        }
        tail=0;


        //j++;
        return ;
    }
    else
    {
        int i;
        for(i=0;i<4;i++)
        {
            tx = x+next[i][0];
            ty = y+next[i][1];


            if(tx<0 ||ty<0 || tx>=n ||ty>=m)
                {
                    return;
                }
            if(map[tx][ty]== 0 && book[tx][ty]==0)
            {
                book[tx][ty] = 1;
                //nodee[j].x=x;
                //nodee[j].y=y;
                //j++;

                stack1[head].x = tx;
                stack1[head].y = ty;
                head++;


                dfs(tx,ty,step+1);

                //printf("(%d %d)<---",x,y);
                book[tx][ty]=0;
                stack1[head].x=-1;
                stack1[head].y=-1;
                head--;


                //j--;
            }
            //printf("\n");
        }
        return 0;
    }



}



int main()
{   //struct note que[2501];
    int flag=0;
    //int map[51][51]={0};
    //int book[50][50]={0};
    //int head=0,tail=0;
    int i,j;
    int startx,starty;
    int next[4][2]={{0,1},
                  {1,0},
                  {0,-1},
                  {-1,0}};
    printf("请输入几行几列");
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            //printf("【%d,%d】的坐标：",i,j);
            scanf("%d",&map[i][j]);
        }
    }
    printf("请输入开始的位置:\n");
    scanf("%d %d",&startx,&starty);
    printf("请输入终点:\n");
    scanf("%d %d",&p,&q);

    dfs(startx,starty,0);



}
