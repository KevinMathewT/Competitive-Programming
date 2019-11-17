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
string s[10010];

ll okay(char s){
	if(s == '\'' || s == '.' || s == ',' || s == ';' || s == ':' || s == ' ') return 0;
	return 1;
}

void solve(){
	cin >> n;
	cin.ignore(256, '\n');
	for(ll i=0;i<n;i++)
		getline(cin, s[i]);

	for(ll i=n-1;i>=0;i--){
		ll end = s[i].size()-1;
		// cout << end << "\n";
		// while(!okay(s[i][end])) end--;
		for(ll j=s[i].size()-1;j>=0;j--)
			if(s[i][j] == ' ' || j == 0){
				if(j == end)
					continue;
				for(ll k=j+(j==0?0:1);k<=end;k++)
					if(okay(s[i][k]))
						cout << s[i][k];
				end = j - 1;
				cout << ' ';
			}
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