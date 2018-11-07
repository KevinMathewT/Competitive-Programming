#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll a[(ll)1e5 + 100];
ll tree[(ll)(4 * 1e5 + 100)];
ll lazy_start[(ll)(4 * 1e5 + 100)];
ll lazy_dist[(ll)(4 * 1e5 + 100)];

void updateSegTree(ll i, ll a, ll b, ll l, ll r, ll s){
	if(lazy_start[i] != 0){
		tree[i] = ((lazy_start[i]*(lazy_start[i]-1)) / 2) - (((lazy_start[i] - lazy_dist[i])*((lazy_start[i] - lazy_dist[i])-1)) / 2);
		if(l != r){
			ll mid = (a + b) >> 1;
			lazy_start[i << 1] = lazy_start[i];
			lazy_start[i << 1 + 1] = lazy_start[i] - mid + l - 1;
			lazy_dist[i << 1] = min(lazy_dist[i], mid - l + 1);
			lazy_dist[i << 1 + 1] = min(lazy_dist[i], r - mid);
		}
		lazy_start[i] = 0;
		lazy_dist[i] = 0;
	}

	if(r > l || a > r || b < l)
		return;

	if(a >= l && b <= r){
		ll start = s - (a - l);
		ll dist = b - a;
		tree[i] = ((start * (start-1)) / 2) - (((start - dist - 1) * ((start - dist - 2)) / 2);
		if(l != r){
			ll mid = (a + b) >> 1;
			lazy_start[i << 1] = s - (a - l);
			lazy_start[(i << 1) + 1] = s - (mid + 1 - l);
			lazy_dist[i << 1] = min(r - l, mid - l + 1);x
			lazy_dist[(i << 1) + 1] = min(0, r - mid);
		}
	}
}

void buildSegTree(ll i, ll l, ll r){
	if(l == r){
		tree[i] = a[l];
		return;
	}
	ll mid = (l + r) >> 1;
	buildSegTree(i << 1, l, mid);
	buildSegTree((i << 1) + 1, mid + 1, r);

	tree[i] = tree[i << 1] + tree[i << 1 + 1];
}

void te(){
	ll n, q;
	cin >> n >> q;
	ll a[n];
	for(ll i=0;i<n;i++)
		cin >> a[i];

	buildSegTree(1, 0, n-1);

	while(q--){
		ll ch, a, b;
		cin >> ch >> a >> b;
	}

	cout << "YES\n";
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