#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int N,M,A[3000][3000],a[3000][3000],dist[3000],visited[3000],max = 999999;

int findmin()
{
    int min = max,index = -1;
    for(int i = 0;i < N;i++)
    {
        if(visited[i] == 0){
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
        if(visited[i] == 0){
        if(A[u][i] == 1 && dist[i] > dist[u] + a[u][i])
        {
            dist[i] = dist[u] + a[u][i];
        }

        }
    }
}

void dijkstra(int source)
{
    dist[source] = 0;
    while(1){
    int t = findmin();
    if(t == -1)
        return;
    visited[t] = 1;
    filldist(t);
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
    scanf("%d%d",&N,&M);
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < N;j++)
        {
            A[i][j] = 0;
            a[i][j] = max;
        }
    }

    int k,l,m;
    for(int i = 0;i < M;i++)
    {
        scanf("%d%d%d",&k,&l,&m);
        A[k - 1][l - 1] = 1;
        A[l - 1][k - 1] = 1;
        if(a[k - 1][l - 1] > m){
        a[k - 1][l - 1] = m;
        a[l - 1][k - 1] = m;
        }
    }

    for(int i = 0;i < N;i++)
    {
        visited[i] = 0;
        dist[i] = max;
    }
    int source;
    scanf("%d",&source);
    dijkstra(source - 1);
    for(int i = 0;i < N;i++)
    {
        if(i != source - 1)
        {
            if(dist[i] == max)
                printf("-1 ");
            else
                printf("%d ",dist[i]);
        }
    }

    printf("\n");
}

}
