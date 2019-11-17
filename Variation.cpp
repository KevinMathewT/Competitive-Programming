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

ll n, k, a[65010];

void solve(){
	cin >> n >> k;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	sort(a, a + n);
	ll ans = 0;

	for(ll i=0;i<n;i++){
		ll l = 0, r = n - 1, pos = n;
		ll mid;

		while(l <= r){
			mid = (l + r) / 2;

			if(a[mid] < a[i] + k)
				l = mid + 1;
			else{
				pos = min(pos, mid);
				r = mid - 1;
			}
		}

		ans += max((ll)0, (n - pos));
	}

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