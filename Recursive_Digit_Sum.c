#include<stdio.h>

int recursive(long long int sum)
{
    int x = 0;
    if(sum < 10)
        return sum;

    else
    {
        while(sum)
        {
            int m = sum % 10;
            x = x + m;
            sum = sum / 10;
        }
    }

    return recursive(x);
}

int main()
{
    int k;
    long long N,sum = 0;
    scanf("%lld%d",&N,&k);
    printf("%lld %d",N,k);
    long long j = N,a[100],m = 0,l = 0;
    while(j)
    {
        a[m++] = j % 10;
        j = j / 10;
    }

    int ll = m;
    while(ll--)
    {
        if(l != m)
            sum = sum + a[l++];
    }

    sum = sum * k;

    printf("%lld ",sum);

    printf("%d ",recursive(sum));
}
