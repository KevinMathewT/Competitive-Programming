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

ll x, n, a[10000010];

void solve(){
	cin >> n >> x;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll l = 0, r = 0, b = LLONG_MAX;
	ll t = a[0];

	while(r < n){
		// cout << l << ' ' << r << " " << t << "\n";
		if(t >= x){
			b = min(b, r - l + 1);
			t-=a[l];
			l++;
			continue;
		}
		r++;
		t+=a[r];
	}

	if(b == LLONG_MAX)
		cout << -1 << "\n";
	else
		cout << b << "\n";
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
