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

ll n, a[100010], b[100010];
pair<ll, ll> a[100010];

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i].first;
	for(ll i=0;i<n;i++)
		cin >> a[i].second;

	sort(a, a + n);

	for(ll i=0;i<n;i++)
		b[i] = a[i].first + a[i].second;

	sort(b, b + n);

	ll sum = 0;
	for(ll i=0;i<n;i++)
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}