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

string sw;
ll m;
unordered_map<ll, ll> um, um1;

void solve(){
	um.clear();
	um1.clear();
	cin >> sw >> m;
	// cout << sw << ' ' << m << "\n";

	for(ll i=0;i<sw.size();i++){
		um[sw[i] - '0'] = um1[sw[i] - '0'] = 1;
	}

	if(m == 1000){
		if(um[0] != 1){
			cout << "0\n";
		}
		ll c = 0;
		for(ll i=1;i<10;i++){
			c += um[i];
		}

		cout << c << "\n";
		return;
	}

	ll ans = 0;

	for(ll i=1;i<=1000;i++){
		ll n = (i * m);
		string s = to_string(n);
		// cout << s << "\n";

		ll flag = 1;
		for(ll j=0;j<s.size();j++){
			// cout << (s[j]);
			if(um[s[j] - '0'] != 1)
				flag = 0;
		}
		// cout << "\n";

		// cout << n << ' ' << flag << "\n";

		if(flag == 0)
			continue;

		if(um1[s[0] - '0'] == 1){
			ans++;
			um1[s[0] - '0'] = 0;
		}
	}

	cout << ans << "\n";
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