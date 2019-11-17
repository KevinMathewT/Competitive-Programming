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

ll n, k, a[100010];

void solve(){
	cin >> n >> k;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll curr = 0, ans = LLONG_MAX;

	ll j = 0;

	for(ll i=0;i<n;i++){
		ans = min(ans, abs(k - curr));
		curr += a[i];

		while(curr > k && j < i)
			curr -= a[j++];
	}

	ans = min(ans, abs(k - curr));

	cout << ans << "\n";
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