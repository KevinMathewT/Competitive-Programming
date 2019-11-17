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

ll n, k, a[100010], pre[100010];

void solve(){
	cin >> n >> k;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	sort(a, a + n);

	pre[0] = a[0];
	suff[n-1] = a[n-1];

	for(ll i=1;i<n;i++)
		pre[i] = pre[i - 1] + a[i];
	for(ll i=n-2;i>=0;i--)
		suff[i] = suff[i + 1] + a[i];

	// for(ll i=0;i<n;i++)
	// 	cout << a[i] << " ";
	// cout << "\n";

	// for(ll i=0;i<n;i++)
	// 	cout << pre[i] << " ";
	// cout << "\n";

	ll best = a[n-1] - a[0];

	for(ll i=0;i<n;i++){
		ll l = a[i], r = a[n-1];

		while(l <= r){
			ll m = (l + r) / 2;
			ll mid = lower_bound(a, a + n, m) - a;

			// cout << i << " " << m << " " << mid << " " << (((i + 1) * a[i]) - pre[i] + pre[n-1] - (mid >= 1 ? pre[mid - 1] : 0) - ((n - mid) * m)) << " ";

			if((((i + 1) * a[i]) - pre[i] + pre[n-1] - (mid >= 1 ? pre[mid - 1] : 0) - ((n - mid) * m)) <= k){
				best = min(best, m - a[i]);
				r = m - 1;
			}
			else
				l = m + 1;

			// cout << best << "\n";
		}
	}

	for(ll i=n-1;i>=0;i--){
		ll l = a[0], r = a[i];

		while(l <= r){
			ll m = (l + r) / 2;
			ll mid = upper_bound(a, a + n, m) - a - 1;
			
			if((((mid + 1) * a[mid]) - pre[mid] + pre[n-1] - (i >= 1 ? pre[i - 1] : 0) - ((n - i) * m)) <= k){
				best = min(best, a[i] - m);
				l = m + 1;
			}
			else
				r = m - 1;
		}
	}

	cout << best << "\n";
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