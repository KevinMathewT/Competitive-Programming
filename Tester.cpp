#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n;

void dfs(string s){
	if(s.length() == n){
		cout << n << "\n";
		cout << s << "\n";
		return;
	}

	dfs(s + ".");
	dfs(s + "#");
}

void te(){
	cin >> n;
	cout << pow(2, n) << "\n";
	dfs("");
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}