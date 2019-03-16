#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll h, w, dp[1010][1010]; char grid[1010][1010];

ll dfs(ll x, ll y){
	// cout << x << " " << y << "\n";
	if(x >= h || y >= w) return 0;
	if(x == h-1 && y == w-1) return 1;
	if(dp[x][y] != -1)
		return dp[x][y];
	if(grid[x][y] == '#')
		return 0;

	return dp[x][y] = (dfs(x+1, y) + dfs(x, y+1)) % MOD;
}

void te(){
	cin >> h >> w;
	for(ll i=0;i<h;i++)
		for(ll j=0;j<w;j++){
			cin >> grid[i][j];
			dp[i][j] = -1;
		}

	cout << dfs(0, 0) << "\n";
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