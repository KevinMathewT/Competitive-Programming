#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, a[1010][1010], vis[1010][1010];

ll dfs(ll x, ll y){
	vis[x][y] = 1;
	ll sum;
	if(a[x][y] == 2)
		sum = 0;
	else
		sum = 1;

	if(x+1 < n && vis[x+1][y] != 1 && a[x+1][y] != 0)
		sum += dfs(x + 1, y);
	if(x-1 >= 0 && vis[x-1][y] != 1 && a[x-1][y] != 0)
		sum += dfs(x - 1, y);
	if(y+1 < m && vis[x][y+1] != 1 && a[x][y+1] != 0)
		sum += dfs(x, y + 1);
	if(y-1 >= 0 && vis[x][y-1] != 1 && a[x][y-1] != 0)
		sum += dfs(x, y - 1);

	return sum;
}

void te(){
	cin >> n >> m;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			cin >> a[i][j];

	ll ans = 1;

	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			vis[i][j] = 0;

	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			if(vis[i][j] != 1 && a[i][j] == 1)
				ans = max(ans, dfs(i, j));

	cout << ans << "\n";
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