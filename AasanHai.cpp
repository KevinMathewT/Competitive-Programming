#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, b[500010], vis[500010];
vector<ll> tree[500010];
vector<ll> levels[500010];

void te(){
	cin >> n;
	for(ll i=1;i<=n;i++){
		vis[i] = 0;
		char c;
		cin >> c;
		if(c == '(')
			b[i] = 0;
		else
			b[i] = 1; 
	}

	for(ll i=0;i<n-1;i++){
		ll u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}


	queue<pair<ll, ll> > q;
	q.push(make_pair(1, 0));

	while(!q.empty()){
		pair<ll, ll> p = q.front(); q.pop();
		ll u = p.first;
		ll l = p.second;
		vis[u] = 1;
		levels[l].push_back(u);

		for(ll v : tree[u]){
			if(vis[v] != 1)
				q.push(make_pair(v, l + 1));
		}
	}

	ll ans = 0;
	for(ll i=0;levels[i].size()>0;i++){
		ll l = 0, r = 0;
		for(ll j=0;j<levels[i].size();j++)
			if(b[levels[i][j]] == 0)
				l++;
			else
				r++;

		ans += (min(l, r));
	}

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