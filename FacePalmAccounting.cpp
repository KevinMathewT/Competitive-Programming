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

ll n, k, a[200010], mn, ans;

void solve(){
	ans = 0;
	cin >> n >> k;
	mn = LLONG_MAX;
	for(ll i=0;i<n;i++){
		cin >> a[i];
		mn = min(mn, a[i]);
	}

	for(ll i=0;i<n;i++)
		ans += a[i];

	ll tot = 0;

	for(ll i=0;i<k;i++)
		tot += a[i];

	if(tot >= 0){
		ll v = tot + 1;
		for(ll j=k-1;j>=0;j--){
			if(a[j] - mn > 0){
				if(v > (a[j] - mn)){
					v -= a[j] - mn;
					a[j] = mn;
				}
				else{
					a[j] -= v;
					v = 0;
					break;
				}
			}
		}

		tot = -1;
	}

	ll p = 0, e = k;
	for(ll i=k;i<n;i++){
		tot -= a[p];
		tot += a[e];
		// cout << tot << "//\n";

		if(tot < 0){
			p++; e++;
			continue;
		}
		else{
			ll v = tot + 1;
			// cout << v << "///\n";
			for(ll j=e;j>p;j--){
				if((a[j] - mn) > 0){
					if(v > (a[j] - mn)){
						v -= a[i] - mn;
						a[i] = mn;
					}
					else{
						a[i] -= v;
						v = 0;
						break;
					}
				}
			}

			tot = -1;
		}

		p++; e++;
	}

	ll ans2 = 0;
	for(ll i=0;i<n;i++)
		ans2 += a[i];

	cout << ans - ans2 << "\n";
	for(ll i=0;i<n;i++)
		cout << a[i] << " ";
	cout << "\n";
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