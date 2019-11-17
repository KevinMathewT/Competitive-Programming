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

ll n, a[100010];

void solve(){
	cin >> n;
	cin.ignore(256, '\n');
	for(ll i=0;i<n;i++){
		string s;
		cin >> s;
		if(s == "TRUTH")
			a[i] = 1;
		else
			a[i] = 0;
	}

	for(ll i=n-1;i>=1;i--){
		if(a[i] == 0)
			a[i - 1] = 1 - a[i - 1];
	}

	if(a[0] == 1)
		cout << "TRUTH\n";
	else
		cout << "LIE\n";
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