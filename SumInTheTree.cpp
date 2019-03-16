#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, p[100010], val[100010], a[100010];
vector<ll> c[100010];

void dfs(ll x, ll depth){
	if(c[x].size() == 0){
		if(depth % 2 == 0){
			a[x] = 0;
		}
		return;
	}

	for(ll i=0;i<c[x].size();i++)
		dfs(c[x][i], depth+1);

	if(depth % 2 == 0){
		ll val1 = val[p[x]];
		ll val2 = LLONG_MAX;
		for(ll i=0;i<c[x].size();i++)
			val2 = min(val2, val[c[x][i]]);

		a[x] = val2 - val1;

		if(a[x] < 0){
			cout << -1 << "\n";
			exit(0);
		}

		for(ll i=0;i<c[x].size();i++)
			a[c[x][i]] = val[c[x][i]] - a[x] - val[p[x]];
	}
}

void te(){
	cin >> n;

	p[1] = -1;
	for(ll i=2;i<=n;i++){
		ll par;
		cin >> par;

		p[i] = par;
		c[par].push_back(i);
	}

	for(ll i=0;i<n;i++)
		cin >> val[i+1];

	dfs(1, 1);

	a[1] = val[1];
	ll sum = 0;
	for(ll i=1;i<=n;i++)
		sum += a[i];

	cout << sum << "\n";
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