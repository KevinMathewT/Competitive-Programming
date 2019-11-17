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

ld a, b;
vector<ll> ans;
map<ll, ll> mp;

void solve(){
	ans.clear(); mp.clear();
	cin >> a >> b;

	while(a > 0){
		if(b == 1){
			if(a == 1){
				cout << "YES 1\n1\n";
				return;
			}
			else{
				cout << "NO\n";
				return;
			}
		}

		ll p = (ll)(log(a) / log(b));
		// cout << p << "-\n";
		if(mp[p] == 1){
			cout << "NO\n";
			return;
		}
		ans.push_back(p);
		mp[p] = 1;
		a = a - pow(b, p);
	}

	sort(ans.begin(), ans.end());
	cout << "YES " << ans.size() << "\n";
	for(ll i=0;i<ans.size();i++)
		cout << ans[i] << " ";
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
	while(T--)
		solve();

	return 0;
}