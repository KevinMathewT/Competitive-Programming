#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, k, reached;
ll jainx, jainy, riyax, riyay;
unordered_map<ll, unordered_map<ll, ll> > grid;
unordered_map<ll, unordered_map<ll, ll> > vis;

void dfs(ll x, ll y){
	// cout << x << " " << y << "\n";
	vis[x][y] = 1;
	if(x == riyax && y == riyay)
		reached = 1;

	if(x + 1 < n && grid[x+1][y] == 1 && vis[x+1][y] != 1)
		dfs(x+1, y);

	if(y + 1 < m && grid[x][y+1] == 1 && vis[x]	+1] != 1)
		dfs(x, y+1);
}

void te(){
	grid.clear();
	vis.clear();
	reached = 0;
	cin >> n >> m;

	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			cin >> grid[i][j];

	cin >> jainx >> jainy >> riyax >> riyay;
	jainx--;
	jainy--;
	riyax--;
	riyay--;
	cin >> k;

	if(jainx > riyax || jainy > riyay || ((riyax-jainx)+(riyay-jainy)) % k != 0 || grid[jainx][jainy] == 0 || grid[riyax][riyay] == 0){
		cout << "NO\n";
		return;
	}

	dfs(jainx, jainy);

	if(reached == 1)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}