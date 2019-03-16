#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, cc;
ll um[100010], q1[100010], q2[100010], q[100010], ans[100010], parent[100010], ranks[100010];


void make_set(ll x){
	parent[x] = x;
	ranks[x] = 1;
}

ll find_set(ll x){
	if(parent[x] == x)
		return x;
	return parent[x] = find_set(parent[x]);
}

ll union_sets(ll a, ll b){
	a = find_set(a);
	b = find_set(b);
	if(a != b){
		cc--;
		if(ranks[b] > ranks[a])
			swap(a, b);
		ranks[a] += ranks[b];
		parent[b] = a;
	}
}

void te(){
	cin >> n >> m;
	cc = n;
	for(ll i=1;i<=m;i++){
		um[i] = 0;
		cin >> q1[i] >> q2[i];
	}
	for(ll i=1;i<=n;i++)
		make_set(i);
	ll qu;
	cin >> qu;
	for(ll i=1;i<=qu;i++){
		cin >> q[i];
		um[q[i]] = 1;
	}

	for(ll i=1;i<=m;i++){
		if(um[i] != 1){
			// cout << i << "\n";
			union_sets(q1[i], q2[i]);
		}
	}

	// cout << cc << "\n";

	for(ll i=qu;i>=1;i--){
		ans[i] = cc;
		union_sets(q1[q[i]], q2[q[i]]);
	}

	for(ll i=1;i<=qu;i++)
		cout << ans[i] << " ";
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