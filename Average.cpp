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

ll n, a[10010];
set<ll> s;

ll nC2(ll x){
	return (x * (x - 1)) / 2;
}

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];
	sort(a, a + n);
	ll c = 0;

	for(ll i=0;i<n;i++){
		ll l = i - 1, r = i + 1;
		ll count = 0;

		while(l >= 0 && (a[l] == a[i]))
			count++, l--;
		while(r < n && (a[r] == a[i]))
			count++, r++;

		c += (count > 0);
		if(count > 0)
			continue;

		// cout << i << ' ' << c << ' ' << count << "\n";

		while(l >= 0 && r < n){
			if((a[l] + a[r]) == (a[i] + a[i])){
				c++;
				break;
			}
			else if((a[l] + a[r]) > (a[i] + a[i]))
				l--;
			else
				r++;
		}

		// cout << i << ' ' << c << "\n";
	}

	cout << c << "\n";
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