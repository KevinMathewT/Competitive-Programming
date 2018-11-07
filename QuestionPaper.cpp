#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll vis[(ll) 1e7];
ll c, n, a, b, z;

void dfs1(ll m){
	if(vis[(n*b) + m] == 1 || m < 0) return;
	// cout << m << "\n";
	vis[(n*b) + m] = 1;
	c++;
	dfs1(m - a);
	dfs1(m - a - b);
}

void dfs2(ll m){
	if(vis[(n*b) + (-m)] == 1 || m < 0) return;
	// cout << -m << "\n";
	vis[(n*b) + (-m)] = 1;
	c++;
	dfs2(m - b);
	dfs2(m - a - b);
}

void te(){
	cin >> n >> a >> b;
	for(ll i=0;i<(a + b) * n + 100;i++)
	    vis[i] = 0;
	c = 0;
	dfs1(n * a); dfs2(n * b);
	cout << c << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}