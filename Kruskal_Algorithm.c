#include<stdio.h>

struct graph
{
    int u,v,w;

};

typedef struct graph GRAPH;

GRAPH array[100];

void swap(GRAPH *a,GRAPH *b)
{
    GRAPH temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int N)
{
    for(int i = 0;i <= N - 2;i++)
    {
        for(int j = 0;j <= N - 2 - i;j++)
        {
            if(array[j].w > array[j + 1].w)
            {
                swap(&array[j],&array[j + 1]);
            }
        }
    }
}

int find(int a[],int x)
{
    int g = a[x];
    return g;
}

void union_arr(int a[],int N,int u,int v)
{
    int temp = a[u];
    for(int i = 0;i < N;i++)
    {
        if(a[i] == temp)
        {
            a[i] = a[v];
        }
    }
}

int min(int N)
{
    int i,j,a[N],cost = 0;
    for(int k = 0;k < N;k++)
    {
        a[k] = k;
    }

    for(int l = 0;l < N;l++)
    {
        i = find(a,array[l].u);
        j = find(a,array[l].v);
        if(i != j)
        {
            printf("(%d %d) -> %d\n",array[l].u,array[l].v,array[l].w);
            cost = cost + array[l].w;
            union_arr(a,N,array[l].u,array[l].v);
        }
    }

    return cost;
}

int main()
{
    int N;
    printf("Enter the number of edges\n");
    scanf("%d",&N);
    printf("Enter the starting,ending and corresponding edge\n");
    for(int i = 0;i < N;i++)
    {
        scanf("%d%d%d",&array[i].u,&array[i].v,&array[i].w);
    }

    bubble_sort(N);
    printf("MST\n");
    int z = min(N);
    printf("cost of MST = %d\n",z);
}
