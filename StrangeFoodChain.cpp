#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, k, parent[50010], d[50010];

void make_set(ll x){
	parent[x] = x;
	d[x] = 0;
}

pair<ll, ll> find_set(ll x){
	if(parent[x] == x)
		return make_pair(parent[x], d[x]);
	pair<ll, ll> rec = find_set(parent[x]);
	parent[x] = rec.first;
	d[x] += rec.second;

	return make_pair(parent[x], d[x]);
}

void te(){
	cin >> n >> k;
	for(ll i=1;i<=n;i++)
		make_set(i);
	ll ans = 0;
	for(ll i=0;i<k;i++){
		ll t, x, y;
		cin >> t >> x >> y;

		if(x > n || y > n){
			ans++;
			continue;
		}

		pair<ll, ll> a = find_set(x);
		pair<ll, ll> b = find_set(y);

		if(a.first == b.first){
			if(((((d[x]-d[y]) % 3) + 3) % 3) != (t-1)){
				ans++;
				continue;
			}
		}

		ll dist = (t - 1 - d[x] + d[y]) % 3;
		parent[a.first] = b.first;
		d[a.first] = dist;
	}

	cout << ans << "\n";
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