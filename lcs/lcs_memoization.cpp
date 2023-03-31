#include <iostream>
#include <string>
using namespace std;

int memoization[100][100];
string a,b;

int LCS(int i,int j){

    if(memoization[i][j]>0){
        return memoization[i][j];
    }else{
        if(a[i] == '\0' || b[j] == '\0') memoization[i][j] = 0;
    
    else if(a[i]==b[j]) memoization[i][j] =  1 + LCS(i +1,j+1);

    else memoization[i][j] =  max(LCS(i+1,j),LCS(i,j+1));

        return memoization[i][j];
    }

}

int main(int argc, char const *argv[])
{

    cin>>a>>b;

    for(int i=0;i<=a.length();i++){
        for(int j=0;j<=b.length();j++){
            memoization[i][j]=-1;
        }
    }


    LCS(0,0);

    for(int i=0;i<=a.length();i++){
        for(int j=0;j<=b.length();j++){
            cout<<memoization[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
