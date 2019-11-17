#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll k;
vector<ll> v[100010], pre[100010];
map<pair<ll, ll>, ll> dp;

void solve(){
	cin >> k;
	for(ll i=0;i<k;i++){
		ll s;
		cin >> s;
		for(ll j=0;j<s;j++){
			ll x;
			cin >> x;
			v[i].push_back(x);
		}
		sort(v[i].begin(), v[i].end());
		pre[i].push_back(v[i][0]);

		for(ll j=1;j<v[i].size();j++)
			pre[i].push_back(pre[i][pre[i].size() - 1] + v[i][j]);
	}

	ll q;
	cin >> q;
	while(q--){
		ll p, q; cin >> p >> q;
		p--; q--;
		if(v[q].size() < v[p].size())
			swap(p, q);

		if(dp.find({p, q}) != dp.end()){
			cout << dp[{p, q}] << "\n";
			continue;
		}


		ll tot = 0;
		for(ll i=0;i<v[p].size();i++){
			ll pos = lower_bound(v[q].begin(), v[q].end(), v[p][i]) - v[q].begin() - 1;
			if(pos >= 0)
				tot -= pre[q][pos];
			tot += (pos + 1) * v[p][i];
			tot += pre[q][pre[q].size() - 1] - (pos >= 0 ? pre[q][pos] : 0);
			tot -= (v[q].size() - pos - 1) * v[p][i];
		}

		dp[{p, q}] = tot;
		dp[{q, p}] = tot;

		cout << tot << "\n";
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