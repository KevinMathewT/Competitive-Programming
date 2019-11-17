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

ll a, b, x[3], p, q, r;

void solve(){
	cin >> a >> b >> x[0] >> x[1] >> x[2];

	if(a < b)
		swap(a, b);

	for(ll i=0;i<3;i++)
		for(ll j=0;j<3;j++)
			for(ll k=0;k<3;k++){
				if(i == j || j == k || k == i)
					continue;

				p = x[i];
				q = x[j];
				r = x[k];

				if( ((p + r + p + q + p) <= a) && ((q + r) <= b) ){
					cout << "POSSIBLE\n";
					return;
				}

				if((p + r + p + r) <= a && (r + q + r) <= b){
					cout << "POSSIBLE\n";
					return;
				}
			}

	cout << "IMPOSSIBLE\n";
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