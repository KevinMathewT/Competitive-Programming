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

ll n, dp[1000010][20];
string s[20];
vector<pair<string, ll> > v;
unodered_map<ll, unordered_map<string, ll> > um;

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> s[i];
	for(ll i=0;i<n;i++){
		for(ll j=1;j<(1<<s[i].size());j++){
			string st = "";
			for(ll k=0;k<s[i].size();k++)
				if((j & (1<<k)))
					st.push_back(s[i][k]);
			cout << st << "\n";
			if(um[i][st] != 1)
				v.push_back({st, i});
			um[i][st] = 1;
		}
	}

	for(ll i=n-1;i>=0;i--){
		if(i == n-1)
			for(ll j=v.size()-1;j>=0;j--)

	}
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