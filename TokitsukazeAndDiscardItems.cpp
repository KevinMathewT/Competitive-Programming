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

ll n, m, k, p[100010];

void solve(){
	cin >> n >> m >> k;
	for(ll i=0;i<m;i++)
		cin >> p[i];

	ll minus = 0, curr = (p[0] - 1) / k, tot = 1, c = 0;

	for(ll i=0;i<m;i++){
		if(((p[i] - minus - 1) / k) > curr){
			tot++;
			minus += c;
			curr = ((p[i] - minus - 1) / k);
			c = 0;
		}

		c++;
		// cout << p[i] - minus << "\n";
	}

	cout << tot << "\n";
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