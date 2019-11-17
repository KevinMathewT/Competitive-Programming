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
unordered_map<ll, ll> um;

void solve(){
	um.clear();
	cin >> n >> m;
	ll a[n][m];

	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			cin >> a[i][j];
	
	ll mergers = 0;

	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++){
			if(um[a[i][j]] >= 2)
				mergers++;
			um[a[i][j]]++;
		}

	cout << mergers << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}