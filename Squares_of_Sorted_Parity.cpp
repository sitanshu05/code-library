#include<bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>& nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        nums[i] = nums[i] * nums[i];
    }

    sort(nums.begin(),nums.end());
    return nums;
}

int main()
{
    int N;
    cin >> N;
    vector<int>a;
    for(int i = 0; i < N; i++)
    {
        int d;
        cin >> d;
        a.push_back(d);
    }

    vector<int>s = sortedSquares(a);
    for(int i = 0; i < N; i++)
    {
        cout << s[i] << " ";
    }
}
