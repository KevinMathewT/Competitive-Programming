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

ll a, b, c, d;

void solve(){
	cin >> a >> b >> c >> d;

	if(a != c && b != d){
		cout << "sad\n";
		return;
	}

	if(a != c){
		if(a > c)
			cout << "left\n";
		else
			cout << "right\n";
			return;
	}

	if(b != d){
		if(b > d)
			cout << "down\n";
		else
			cout << "up\n";
			return;
	}
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