#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, tr, tg, tu, ans, vis[300010], a[300010], red[300010], green[300010], cless[300010];
vector<ll> tree[300010];

void dfs(ll x){
	vis[x] = 1;
	for(ll i=0;i<tree[x].size();i++)
		if(vis[tree[x][i]] != 1)
			dfs(tree[x][i]);

	ll r = 0, g = 0, uc = 0;

	for(ll i=0;i<tree[x].size();i++){
		r += red[tree[x][i]];
		g += green[tree[x][i]];
		uc += cless[tree[x][i]];
	}

	red[x] = r;
	green[x] = g;
	cless[x] = uc;

	if(a[x-1] == 0){
		tu++;
		cless[x]++;
	}
	if(a[x-1] == 1){
		tr++;
		red[x]++;
	}
	if(a[x-1] == 2){
		tg++;
		green[x]++;
	}
}

void findEdges(ll x){
	vis[x] = 1;

	for(ll i=0;i<tree[x].size();i++){
		if(vis[tree[x][i]] != 1){
			if((green[tree[x][i]] == tg && red[tree[x][i]] == 0) || (green[tree[x][i]] == 0 && red[tree[x][i]] == tr)){
				// cout << x << " " << tree[x][i] << "\n"; 
				ans++;
			}

			findEdges(tree[x][i]);
		}
	}
}

void te(){
	cin >> n;
	for(ll i=0;i<n;i++){
		cin >> a[i];
		vis[i] = red[i] = green[i] = cless[i] = 0;
	}

	for(ll i=0;i<n-1;i++){
		ll u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	tu = tg = tr = ans = 0;

	dfs(1);

	for(ll i=0;i<=n;i++){
		vis[i] = 0;
	}

	// cout << tr << " " << tg << " " << tu << "\n";

	// for(ll i=1;i<=n;i++)
	// 	cout << red[i] << " ";
	// cout << "\n";

	// for(ll i=1;i<=n;i++)
	// 	cout << green[i] << " ";
	// cout << "\n";

	// for(ll i=1;i<=n;i++)
	// 	cout << cless[i] << " ";
	// cout << "\n";

	findEdges(1);

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