import <iostream>
import <vector>
using namespace std;

vector<vector<int>> generate(int n){

    vector<vector<int>> triangle;

    vector<int> tmp;

    for(int i=0;i<n;i++){

        if(i==0)
        {
            tmp.push_back(1);
        }
        else if(i==1)
        {
            tmp.push_back(1);
            tmp.push_back(1);
        }
        else
        {
            tmp.push_back(1);
            for(int j =0;j<triangle.size()-1;j++){
                tmp.push_back(triangle[i-1][j] + triangle[i-1][j+1]);
            }

            tmp.push_back(1);
        }

        triangle.push_back(tmp);

        tmp.clear();
    }

    return triangle;
};

int main(){
  
  vector<vector<int>> ans; 
  
  ans = generate(5);
  
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
  
}
