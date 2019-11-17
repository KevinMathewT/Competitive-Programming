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

ll n, w[10010];

void solve(){
	cin >> n;
	ll mn = LLONG_MAX;
	for(ll i=0;i<n;i++){
		cin >> w[i];
		mn = min(mn, w[i]);
	}

	for(ll i=0;i<n;i++)
		w[i] -= mn;

	ll sum = 0;
	for(ll i=0;i<n;i++)
		sum += w[i];

	cout << sum << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}