#include<bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    int sizeofs1=s1.size();
    int sizeofs2=s2.size();

    if(sizeofs1>sizeofs2)  return false;

    vector<int>check1(26,0);
    vector<int>check2(26,0);

    for(int i=0; i<sizeofs1; i++)
    {
        check1[s1[i] - 'a']++;
        check2[s2[i] - 'a']++;
    }
    if(check1==check2)
    {
        return true;
    }

    for(int i=sizeofs1; i<sizeofs2; i++)
    {
        check2[s2[i-sizeofs1] - 'a']--;
        check2[s2[i] - 'a']++;
        if(check1==check2) return true;
    }
    return false;
}

int main()
{
    string a,b;
    cin >> a >> b;
    bool k = checkInclusion(a,b);
    cout << k << endl;
}
