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

ll n, a[110];
vector<ll> one, two;

void solve(){
	one.clear(); two.clear();
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			for(ll k=0;k<n;k++)
				one.push_back(a[i] * a[j] + a[k]);

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			for(ll k=0;k<n;k++)
				if(a[i] != 0)
					two.push_back(a[i] * (a[j] + a[k]));

	sort(one.begin(), one.end());
	sort(two.begin(), two.end());

	// for(ll i=0;i<one.size();i++)
	// 	cout << one[i] << " ";
	// cout << "\n";

	// for(ll i=0;i<two.size();i++)
	// 	cout << two[i] << " ";
	// cout << "\n";
	
	ll final = 0;

	for(ll i=0;i<one.size();i++){
		ll x = one[i];
		ll l = 0, r = two.size(), ans = r, ans2 = r;
		while(l < r){
			ll mid = (l + r) / 2;
			if(two[mid] == x){
				ans = min(ans, mid);
				r = mid;
			}
			else if(two[mid] > x){
				r = mid;
			}
			else
				l = mid + 1;
		}

		l = 0, r = two.size();

		while(l < r){
			ll mid = (l + r) / 2;
			if(two[mid] > x){
				ans2 = min(ans2, mid);
				r = mid;
			}
			else
				l = mid + 1;
		}

		// cout << ans << " " << ans2 << "\n";

		final += max((ll)0, ans2 - ans);
	}

	cout << final << "\n";
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