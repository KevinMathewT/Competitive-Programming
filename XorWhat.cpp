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

ll n, q, a[100010];

void solve(int t){
	cout << "Case #" << t << ": ";
	cin >> n >> q;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	set<ll> s;
	ll c = 0;

	for(ll i=0;i<n;i++){
		if(__builtin_popcountll(a[i]) % 2 == 1){
			s.insert(i);
			c++;
		}
	}

	ll best;

	if(__builtin_popcountll(c) % 2 == 0)
		best = n;
	else{
		best = max(*s.rbegin() + 1, n - (*s.begin() + 1));
	}

	while(q--){
		ll p, v;
		cin >> p >> v;
		if((__builtin_popcountll(v) % 2) == (__builtin_popcountll(a[p]) % 2)){
			cout << best << " ";
			continue;
		}

		if(__builtin_popcountll(v) % 2 == 0){
			s.erase(p);
			best = max(*s.rbegin() + 1, n - (*s.begin() + 1));
		}
		else{
			s.insert(p);
			best = max(*s.rbegin() + 1, n - (*s.begin() + 1));
		}

		cout << best << " ";
	}

	cout << "\n";
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
	for(ll i=1;i<=T;i++)
		solve(i);

	return 0;
}