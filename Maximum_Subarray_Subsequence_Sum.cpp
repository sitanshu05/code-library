#include<stdio.h>

int max(int a,int b)
{
    if(a > b)
        return a;

    else
        return b;
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
    int N;
    scanf("%d",&N);
    int a[N];
    for(int i = 0;i < N;i++)
    {
        scanf("%d",&a[i]);
    }

    //int max = 0;
    //quicksort(a,0,N - 1);

    /*for(int i = 0;i < N;i++)
    {
        printf("%d ",a[i]);
    }

    printf("\n");*/
    int maxsofar = a[0];
    int maxsumendinghere = a[0];
    for(int i = 1;i < N;i++)
    {
        maxsumendinghere = max(maxsumendinghere + a[i],a[i]);
        if(maxsofar < maxsumendinghere)
            maxsofar = maxsumendinghere;
    }

    int sum1 = 0;
    for(int i = 0;i < N;i++)
    {
        if(a[i] > 0 || N == 1)
        {
            sum1 = sum1 + a[i];
        }
    }

    int max1 = maxsofar;
    if(max1 == 0 && sum1 == 0)
        printf("-1 -1\n");

    else if(max1 == 0)
        printf("-1 %d\n",sum1);

    else if(sum1 == 0)
        printf("%d -1\n",max1);

    else
        printf("%d %d\n",max1,sum1);
    }

}
