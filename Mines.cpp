#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, m;
ll grid[100][100], grid1[100][100];

void solve(){
	cin >> n >> m;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++){
			char c;
			cin >> c;
			if(c == '*')
				grid[i][j] = -1;
			else
				grid[i][j] = 0;
		}

	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++){
			if(grid[i][j] == -1)
				grid1[i][j] = -999;
			else
				grid1[i][j] = -(grid[i+1][j] + grid[i][j+1] + grid[i+1][j+1] + grid[i+1][j-1] + grid[i-1][j+1] + grid[i-1][j-1] + grid[i-1][j] + grid[i][j-1]);
		}

	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(grid1[i][j] == -999)
				cout << "*";
			else if(grid1[i][j] == 0)
				cout << ".";
			else
				cout << grid1[i][j];
		}
		cout << "\n";
	}
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}