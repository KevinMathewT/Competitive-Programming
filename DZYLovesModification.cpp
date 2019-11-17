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

ll n, m, k, p, a[1010][1010], sum[2010], moves[2010];

void solve(){
	cin >> n >> m >> k >> p;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			cin >> a[i][j];

	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			sum[i] += a[i][j];
			sum[n + j] += a[i][j];
		}
	}

	ll tot = 0;

	for(ll i=0;i<n+m;i++){
		sort(sum, sum + n);
		sort(sum + n, sum + n + m);

		if(sum[n-1] >= sum[n+m-1]){
			moves[i] = sum[n-1];
			sum[n-1] -= m * p;
			for(ll j=n;j<n+m;j++)
				sum[j] -= p;
		}
		else{
			moves[i] = sum[n+m-1];
			sum[n+m-1] -= n * p;
			for(ll j=0;j<n;j++)
				sum[j] -= p;
		}
	}

	for(ll i=1;i<n+m;i++)
		moves[i] = moves[i] + moves[i-1];

	cout << ((k / (n + m)) * moves[n+m-1] + moves[(k % (n + m)) - 1]) << "\n";
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