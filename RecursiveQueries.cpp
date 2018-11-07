#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll a[(ll) 1e6 + 100];

unordered_map<ll, vector<ll> > um;

ll prodNonZeroDig(ll n){
	ll t = n;
	ll prod = 1;
	while(t > 0){
		if(t % 10 != 0)
			prod *= t % 10;
		t /= 10;
	}

	return prod;
}

ll dfs(ll n){
	// cout << n << "\n";
	if(a[n] != -1) return a[n];
	return a[n] = dfs(prodNonZeroDig(n));
}

void te(){
	ll q;
	cin >> q;

	while(q--){
		ll l, r, k;
		cin >> l >> r >> k;
		cout << upper_bound(um[k].begin(), um[k].end(), r) - lower_bound(um[k].begin(), um[k].end(), l) << "\n";
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	for(ll i=0;i<(ll)1e6 + 100;i++)
		a[i] = -1;

	for(ll i=1;i<10;i++)
		a[i] = i;

	for(ll i=10;i<(ll) 1e6 + 100;i++)
		a[i] = dfs(i);

	// cout << dfs(1000098) << "\n";

	for(ll i=1;i<(ll) 1e6 + 100;i++){
		if(a[i] >= 10)
			cout << i << " " << a[i] << "\n";
		um[a[i]].push_back(i);
	}

	// ll sum = 0;
	// for(ll i=1;i<10;i++)
	// 	sum += um[i].size();
	// cout << sum << "\n";

	// cout << "\n";

	te();

	return 0;
}