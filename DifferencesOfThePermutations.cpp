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

void solve(){
	cin >> n;

	ll ans = 1;
	for(ll i=1;i<=n;i++)
		ans *= i;

	cout << (ans * (n * n - ((n * (n + 1)) / 2))) << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);		
						//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}