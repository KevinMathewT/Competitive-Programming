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

ll x, y, k, n, p[100010], c[100010];

void solve(){
	cin >> x >> y >> k >> n;
	for(ll i=0;i<n;i++)
		cin >> p[i] >> c[i];

	x = x - y;

	for(ll i=0;i<n;i++)
		if(c[i] <= k && p[i] >= x){
			cout << "LuckyChef\n";
			return;
		}

	cout << "UnluckyChef\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}