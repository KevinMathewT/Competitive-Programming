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
string s;

void solve(){
	cin >> n >> s;

	if(n % 2 != 0){
		cout << 1 << "\n" << s << "\n";
		return;
	}

	ll z = 0, o = 0;

	for(ll i=0;i<s.size();i++){
		if(s[i] == '0')
			z++;
		else
			o++;
	}

	if(z != (n / 2)){
		cout << 1 << "\n" << s << "\n";
		return;
	}

	ll k = 0, l = 0;

	for(ll i=0;i<s.size();i++){
		if(s[i] == '0')
			k++;
		else
			l++;
		if(k != l && (z - k) != (o - l)){
			cout << 2 << "\n";
			cout << s.substr(0, i + 1) << " ";
			cout << s.substr(i + 1) << "\n";
			return;
		}
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