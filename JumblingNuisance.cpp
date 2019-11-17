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

ll n, f[1000], M = 1e9 + 7;

ll rec(ll x){
	if(x == 1) return 0;
	return ((((x * rec(x - 1)) % M) + ((ll)pow(-1, x)) + M) % M);
}

void solve(){
	cin >> n;
	if(n == 0)
		cout << 0 << "\n";
	else
		cout << rec(n) << "\n";
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