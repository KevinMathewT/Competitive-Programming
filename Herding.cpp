#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, vis[1010][1010];
char a[1010][1010];
ll ans;

ll checkIfOut(ll a, ll b){
	if(a < 0 || b < 0 || a >= n || b >= m)
		return 1;
	return 0;
}

void dfs(ll x, ll y){
	vis[x][y] == 1;
	if(a[x][y] == 'N')
		x--;
	else if(a[x][y] == 'S')
		x++;
	else if(a[x][y] == 'E')
		y++;
	else
		y--;

	if(checkIfOut(x, y) || vis(x, y) == 1)
		ans++;
}

void te(){
	ans = 0;
	cin >> n >> m;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++){
			vis[i][j] = 0;
			cin >> a[i][j];
		}
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