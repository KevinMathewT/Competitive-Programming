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

ll n, k, a[100010][25], zero[100010][20], one[100010][25];

void solve(){
	cin >> n >> k;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<k;j++)
			cin >> a[i][j];

	for(ll i=0;i<n;i++)
		for(ll j=0;j<k;j++){
			if(a[i][j] == 0)
				zero[i][j] = 1;
			if(a[i][j] == 1)
				zero[i][j] = 0;
		}
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