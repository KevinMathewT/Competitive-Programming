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

ll n;
vector<vector<ll> > v;

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++){
		v.push_back(vector<ll>(0));
		while(true){
			ll x; cin >> x; 
			if(x == -1) break;
			v[i].push_back(x);
		}
	}
	sort(v.begin(), v.end());
	for(ll i=0;i<n;i++){
		for(ll j=0;j<v[i].size();j++)
			cout << v[i][j] << ' ';
		cout << "\n";
	}
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