#include<stdio.h>

int main()
{
    int n,k,q;
    scanf("%d%d%d",&n,&k,&q);
    int a[n],queries[q],b[n];
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
        b[i] = a[i];
    }

    for(int i = 0;i < q;i++)
    {
        scanf("%d",&queries[i]);
    }

    for(int i = 0; i < q; i++)
    {
        printf("%d\n",a[queries[i] >= k ?
               ((queries[i] - k) - (((queries[i] - k)/n) * n)) % n:
        (((queries[i] - k) - (((queries[i] - k)/n) * n)) + n) % n
              ]);
    }

}
