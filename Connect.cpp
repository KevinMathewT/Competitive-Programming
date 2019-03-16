#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, r1, c1, r2, c2, vis[100][100];
char island[100][100];
vector<pair<ll, ll> > p, q;

void dfs(ll x, ll y, ll ch){
	// cout << x << " " << y << " " << ch << " " << (island[x][y] == '1') << "\n";
	vis[x][y] = 1;
	if(ch == 1)
		p.push_back(make_pair(x, y));
	else
		q.push_back(make_pair(x, y));

	if(x + 1 < n && vis[x+1][y] != 1 && island[x+1][y] != '1'){
		// cout << "YES1\n";
		dfs(x+1, y, ch);
	}
	if(y + 1 < n && vis[x][y+1] != 1 && island[x][y+1] != '1'){
		// cout << "YES2\n";
		dfs(x, y+1, ch);
	}
	if(x - 1 >= 0 && vis[x-1][y] != 1 && island[x-1][y] != '1'){
		// cout << "YES3\n";
		dfs(x-1, y, ch);
	}
	if(y - 1 >= 0 && vis[x][y-1] != 1 && island[x][y-1] != '1'){
		// cout << "YES4\n";
		dfs(x, y-1, ch);
	}
}

void te(){
	cin >> n >> r1 >> c1 >> r2 >> c2;

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			cin >> island[i][j];

	// cout << "hjkl\n";

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			vis[i][j] = 0;

	dfs(r1-1, c1-1, 0);

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			vis[i][j] = 0;

	dfs(r2-1, c2-1, 1);

	// for(ll i=0;i<q.size();i++)
	// 	cout << q[i].F << " " << q[i].S << "\n";

	// for(ll i=0;i<p.size();i++)
	// 	cout << p[i].F << " " << p[i].S << "-\n";
	ll ans = LLONG_MAX;


	for(ll i=0;i<p.size();i++){
		if(p[i].F == r1-1 && p[i].S == c1-1){
			cout << 0 << "\n";
			return;
		}
	}

	for(ll i=0;i<p.size();i++)
		for(ll j=0;j<q.size();j++)
			ans = min(ans, (ll) (pow(p[i].F - q[j].F, 2) + pow(p[i].S - q[j].S, 2)));

	
	cout << ans << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}