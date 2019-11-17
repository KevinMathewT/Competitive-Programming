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

ll n, pos;
unordered_map<string, pair<ll, ll> > mp;
string st[100010];

void solve(){
	pos = 0;
	cin >> n;
	cin.ignore(256, '\n');
	for(ll i=0;i<n;i++){
		string s;
		cin >> s;
		pair<ll, ll> 
		if(mp[s] == 0)
			st[pos++] = s;

	}

	ll tot = 0;

	for(ll i=0;i<pos;i++){
		cout << st[i] << "\n";
		if(!(mp[st[i]] == -1))
			tot++;
	}

	cout << tot << "\n";
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