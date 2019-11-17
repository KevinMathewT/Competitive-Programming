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

ll n, m, a[1000010];

void solve(){
	cin >> m;
	for(ll i=0;i<m;i++)
		cin >> a[i];

	ll tot = 0;

	for(ll i=1;i<(1<<m);i++){

		ll pr = 1, flag = 0, p = 0;
		vector<ll> v(0);
		for(ll j=0;j<m;j++){
			if(i & (1<<j)){
				p ^= 1;
				pr *= a[j];
			}
			if(pr > n){
				flag = 1;
				break;
			}
		}

		cout << pr << "--\n";

		if(flag) continue;

		if(p & 1)
			tot += (n / pr);
		else
			tot -= (n / pr);
	}

	cout << (n - tot) << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	while(cin >> n)
		solve();

	return 0;
}