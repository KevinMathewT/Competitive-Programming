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

ll n, dp[1000010][2];

ll DP(vector<ll> v){
	for(ll i=0;i<1000010;i++)
		dp[i][0] = dp[i][1] = 0;

	dp[0][0] = 0;
	dp[0][1] = v[0];
	for(ll i=1;i<v.size();i++){
		dp[i][0] = dp[i-1][1];
		dp[i][1] = v[i] + min(dp[i-1][1], dp[i-1][0]);
	}

	return min(dp[v.size() - 1][0], dp[v.size() - 1][1]);
}

void solve(){
	cin >> n;
	vector<ll> v(0, 0);
	for(ll t, i=0;i<n;i++){
		cin >> t;
		v.push_back(t);
	}

	vector<ll> v1 = vector<ll>(v.begin() + 1, v.end());
	vector<ll> v2 = vector<ll>(v.begin(), v.end() - 1);

	cout << min((v[0] + DP(v1)), (v[n - 1] + DP(v2))) << "\n";
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