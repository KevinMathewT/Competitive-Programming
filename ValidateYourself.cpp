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

string s;
string t;
ll dp[20][2010], out;

void solve(){
	out = 0;
	cin >> t;

	ll i = 0, j = 0;

	while(i < s.size() && j < t.size()){
		if(s[i] == t[j]){
			i++;
			j++;
		}
		else
			j++;
	}

	if(i == s.size())
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	getline(cin, t);
	T = stoi(t);
	cin >> s;
	while(T--)
		solve();

	return 0;
}