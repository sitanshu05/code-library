#include<iostream>
#include<string>
using namespace std;
int memo[100][100];
string a,b;


int LCS(int i,int j){
    if(memo[i][j]>=0){
        return memo[i][j];
    }

    if(a[i-1]==b[i-1]){
        memo[i][j] = 1 + LCS(i-1,j-1);
    }else memo[i][j] = max(LCS(i-1,j),LCS(i,j-1));

    return memo[i][j];
}

int main(int argc, char const *argv[])
{

    cin>>a>>b;

    for (int i = 0; i <= a.length(); i++)
    {
        for (int j = 0; j <= b.length(); j++)
        {
            if(!i || !j) memo[i][j] = 0;
            else memo[i][j]=-1;
        }
        
    }

    LCS(1,1);

    for (int i = 0; i <= a.length(); i++)
    {
        for (int j = 0; j <= b.length(); j++)
        {
            cout<<memo[i][j]<<" ";
        }
        cout<<endl;
        
    }


    
    
    return 0;
}
