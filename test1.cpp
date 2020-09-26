#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fun(int* a,int n){
	int i,j;
  	vector<int> v[n+1];
  	vector<vector<int>> ans;
  	for(i=0;i<n;i++){
    	v[a[i]].push_back(i);
  	}
  	for(i=1;i<=n;i++){
      vector<int>temp;
    	for(j=0;j<v[i].size();j++){
        	if(temp.size()==i){
            	ans.push_back(temp);
              	temp.clear();
            }
          	temp.push_back(v[i][j]);
        }
      	if(temp.size()==i)ans.push_back(temp);
    }
  	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.

  int a[7] = {2, 1, 3, 3, 3, 2};
  int n=7;
  cout << fun(a,n) << "\n";
}