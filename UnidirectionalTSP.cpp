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

ll n, m;
void solve(){
	cin >> m;
	ll a[n + 1][m + 1];

	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			cin >> a[i][j];

	ll dp[n + 1][m + 1];

	for(ll i=0;i<n;i++)
		dp[i][m-1] = a[i][m-1];

	for(ll i=m-2;i>=0;i--)
		for(ll j=0;j<n;j++)
			dp[j][i] = min(a[j][i] + dp[(j) % n][i+1], min(a[j][i] + dp[(j-1+n) % n][i+1], a[j][i] + dp[(j+1+n) % n][i+1]));

	vector<ll> path(0);
	ll mn = LLONG_MAX, pos;

	for(ll i=0;i<n;i++)
		if(dp[i][0] < mn){
			mn = dp[i][0];
			pos = i;
		}

	path.push_back(pos);
	for(ll i=0;i<m-1;i++){
		pair<ll, ll> p[3];
		p[0].second = (pos-1+n) % n;
		p[1].second = pos;
		p[2].second = (pos+1+n) % n;

		p[0].first = a[pos][i] + dp[p[0].second][i + 1];
		p[1].first = a[pos][i] + dp[p[1].second][i + 1];
		p[2].first = a[pos][i] + dp[p[2].second][i + 1];

		sort(p, p + 3);
		pos = p[0].second;
		path.push_back(pos);
	}

	for(ll i=0;i<path.size();i++)
		cout << path[i] + 1 << " ";
	cout << "\n";

	cout << mn << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	while(cin >> n)
		solve();

	return 0;
}