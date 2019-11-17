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

string s, t;

void solve(){
	getline(cin, s);
	t = "";

	for(ll i=0;i<s.size();i++){
		// cout << "Hello\n";
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
			t.push_back(s[i]);
			t.push_back('p');
		}

		t.push_back(s[i]);
	}

	cout << t << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	string s;
	ll T;
	getline(cin, s);
	T = stoll(s);
	while(T--)
		solve();

	return 0;
}