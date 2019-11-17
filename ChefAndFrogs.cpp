#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, k, p;
pair<ll, ll> a[100010];
ll parent[100010];

void solve(){
	fill(parent, parent + 100010, 0);
	cin >> n >> k >> p;
	for(ll i=0;i<n;i++){
		ll z;
		cin >> z;
		a[i] = {z, i};
	}

	sort(a, a + n);
	ll curr = 1;

	parent[a[0].S + 1] = curr;

	for(ll i=1;i<n;i++)
		if((a[i].F - a[i-1].F) <= k)
			parent[a[i].S + 1] = curr;
		else
			parent[a[i].S + 1] = ++curr;

	while(p--){
		ll u, v;
		cin >> u >> v;
		if(parent[u] == parent[v])
			cout << "Yes\n";
		else
			cout << "No\n";
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