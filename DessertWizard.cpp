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

ll n, a[1000010];

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll pre[n], suff[n], pre1[n], suff1[n];
	pre[0] = a[0];
	suff[n-1] = a[n-1];
	for(ll i=1;i<n;i++)
		pre[i] = max(a[i], pre[i - 1] + a[i]);
	for(ll i=1;i<n;i++)
		pre[i] = max(pre[i], pre[i - 1]);
	for(ll i=n-2;i>=0;i--)
		suff[i] = max(a[i], suff[i + 1] + a[i]);
	for(ll i=n-2;i>=0;i--)
		suff[i] = max(suff[i], suff[i + 1]);

	pre1[0] = a[0];
	suff1[n-1] = a[n-1];
	for(ll i=1;i<n;i++)
		pre1[i] = min(a[i], pre1[i - 1] + a[i]);
	for(ll i=1;i<n;i++)
		pre1[i] = min(pre1[i], pre1[i - 1]);
	for(ll i=n-2;i>=0;i--)
		suff1[i] = min(a[i], suff1[i + 1] + a[i]);
	for(ll i=n-2;i>=0;i--)
		suff1[i] = min(suff1[i], suff1[i + 1]);


	ll ans = LLONG_MIN;

	for(ll i=1;i<n;i++)
		ans = max(ans, max(abs(suff[i] - pre1[i-1]), abs(suff1[i] - pre[i-1])));

	cout << ans << "\n";
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