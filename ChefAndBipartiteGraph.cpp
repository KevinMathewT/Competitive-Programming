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

ll n, m, a, b;

void solve(){
	cin >> n >> m >> a >> b;

	if(m > (n * n) || m < 0){
		cout << -1 << "\n";
		return;
	}

	if(m < ((n) * a) || m > ((n) * b)){
		cout << -1 << "\n";
		return;
	}

	if(a > n){
		cout << -1 << "\n";
		return;
	}

	ll tot = 0;

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++){
			if(tot >= m)
				return;
			tot++;

			cout << (j + 1) << " " << ((j + i) % n + 1) << "\n";
		}
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