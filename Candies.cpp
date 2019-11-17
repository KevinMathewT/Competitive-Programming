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

ll tree[100010][20];
ll n, arr[100010];

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> arr[i];
	build(1, 0, n-1);

	for(ll i=0;(1<<i)<=n;i++){
		for(ll j=0;j<n;j+=(1<<i)){
			if(i == 0)
		}
	}
}

ll main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}