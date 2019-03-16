#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, q, parent[500010], size[500010];

ll find_set(ll v){
	if(parent[v] == v)
		return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b){
	a = find_set(a);
	b = find_set(b);

	if(a != b){
		if(size[a] < size[b])
			swap(a, b);

		parent[b] = a;
		size[a] = max(size[a], max(size[b], (ll) (ceil((ld)size[a]/2.0) + ceil((ld)size[b]/2.0) + 1)));
	}
}

void te(){
	for(ll i=0;i<500010;i++){
		parent[i] = i;
		size[i] = 0;
	}

	cin >> n >> m >> q;

	for(ll i=0;i<m;i++){
		ll u, v;
		cin >> u >> v;
		union_sets(u, v);
	}

	while(q--){
		ll ch;
		cin >> ch;

		if(ch == 1){
			ll u;
			cin >> u;

			u = find_set(u);
			cout << size[u] << "\n";
		}

		else{
			ll u, v;
			cin >> u >> v;
			union_sets(u, v);
		}
	}
	// for(ll i=1;i<=n;i++)
	// 	cout << parent[i] << " " ;
	// cout << "\n";
	// for(ll i=1;i<=n;i++)
	// 	cout << size[i] << " " ;
	cout << "\n";
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