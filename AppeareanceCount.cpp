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

ll n, m, p[100010];

void solve(ll t){
	cout << "Case " << t << ":\n";
	cin >> n >> m;
	ll p1 = 1;
	for(ll i=0;i<m;i++){
		string s;
		cin >> s;

		if(n < s.size()){
			cout << 0 << "\n";
			continue;
		}

		p1 = p[n - s.size()];
		p1 = (p1 * (n - s.size() + 1)) % 1000000007;

		cout << p1 << "\n";
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	p[0] = 1;
	for(ll i=1;i<100010;i++)
		p[i] = (p[i-1] * 26) % 1000000007;
	ll T;
	cin >> T;
	for(ll i=1;i<=T;i++)
		solve(i);

	return 0;
}