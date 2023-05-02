#include<bits/stdc++.h>
using namespace std;

int findKthNumber(int m, int n, int k)
{
    int lo=0, hi=m*n;
    while (lo < hi)
    {
        int mid=(lo+hi)/2, count=0;
        for (int i=1; i<=m; i++)
            count += n < mid/i ? n : mid/i;
        if (count >= k)
            hi = mid;
        else
            lo = mid+1;
    }
    return lo;
}

int main()
{
    int N,M,K;
    cin >> N >> M >> K;

    int s = findKthNumber(N,M,K);
    cout << s << endl;
}
