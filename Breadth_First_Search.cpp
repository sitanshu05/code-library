#include<stdio.h>
int max = 999999;
int N,M;
int matrix[3000][3000],A[3000][3000],visited[3000],dist[3000];
int minelement()
{
    int min = max,index = -1;
    for(int i = 0;i < N;i++)
    {
        if(visited[i] == 0)
        {
            if(dist[i] < min)
            {
                min = dist[i];
                index = i;
            }
        }
    }

    return index;
}

void filldist(int u)
{
    for(int i = 0;i < N;i++)
    {
        if(visited[i] == 0)
        {
            if(A[u][i] == 1 && dist[i] > dist[u] + matrix[u][i])
            {
                dist[i] = dist[u] + matrix[u][i];
            }
        }
    }
}

void dijkstra(int source)
{
    dist[source] = 0;
    while(1){
    int u = minelement();
    if(u == -1)
        return;
    visited[u] = 1;
    filldist(u);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
    int k,l;
    scanf("%d%d",&N,&M);
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < N;j++)
        {
            A[i][j] = 0;
            matrix[i][j] = max;
        }
    }

    for(int i = 0;i < M;i++)
    {
        scanf("%d%d",&k,&l);
        A[k - 1][l - 1] = 1;
        A[l - 1][k - 1] = 1;
        matrix[k - 1][l - 1] = 6;
        matrix[l - 1][k - 1] = 6;
    }
    int source;
    scanf("%d",&source);
    for(int i = 0;i < N;i++)
    {
        visited[i] = 0;
        dist[i] = max;
    }
    dijkstra(source - 1);

    for(int i = 0;i < N;i++)
    {
        if(i != source - 1)
        {
            if(dist[i] >= max)
            {
                printf("-1 ");
            }

            else{
            printf("%d ",dist[i]);
            }
        }
    }

    printf("\n");
}
}
