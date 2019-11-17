#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRanking - https://www.hackerranking.com/KevinMathew?

ll n, q, parent[100010], ranking[100010];

void make_set(ll x){
	parent[x] = x;
	ranking[x] = 1;
}

ll find_set(ll x){
	if(parent[x] == x)
		return x;
	return parent[x] = find_set(parent[x]);
}

void union_set(ll x, ll y){
	x = find_set(x);
	y = find_set(y);

	if(ranking[x] > ranking[y])
		swap(x, y);

	parent[y] = x;
	ranking[x] += ranking[y];
}

void solve(){
	cin >> n >> q;

	for(ll i=1;i<=n;i++)
		make_set(i);

	while(q--){
		ll t, x, y;
		cin >> t >> x >> y;

		if(t == 0)
			union_set(x, y);
		if(t == 1){
			if(find_set(x) == find_set(y))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}