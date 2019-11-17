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

ll n, k, a[1000010], dpback[1000010], dpfront[1000010], dp[1000010];

void solve(){
	cin >> n >> k;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	fill(dpback, dpback + n, -1);
	fill(dpfront, dpfront + n, -1);

	for(ll i=0;i<n;i++){
		if(i == 0)
			dpback[i] = a[i];
		else if(i == 1)
			dpback[i] = a[i] + dpback[i - 1];
		else{
			dpback[i] = a[i] + max(dpback[i-1], dpback[i-2]);
		}
	}

	// for(ll i=0;i<n;i++)
	// 	cout << dpback[i] << ' ';
	// cout << "\n";

	for(ll i=n-1;i>=0;i--){
		if(i == n-1)
			dpfront[i] = dpback[i];
		else if(i == n-2)
			dpfront[i] = max(dpback[i], a[i] + dpfront[i+1]);
		else
			dpfront[i] = max(dpback[i], a[i] + max(dpfront[i+2], dpfront[i+1]));
	}

	// for(ll i=0;i<n;i++)
	// 	cout << dpfront[i] << ' ';
	// cout << "\n";

	for(ll i=n-1;i>=0;i--){
		if(i == n-1)
			dp[i] = dpback[i] - a[i];
		else if(i == n-2)
			dp[i] = max(dpback[i] - a[i], dpfront[i+1]);
		else
			dp[i] = max(dpback[i] - a[i], max(dpfront[i+1], dpfront[i+2]));
	}

	// for(ll i=0;i<n;i++)
	// 	cout << dp[i] << ' ';
	// cout << "\n";

	cout << dp[k-1] << "\n";
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