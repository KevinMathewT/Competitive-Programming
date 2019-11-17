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

vector<ll> a(0);
ll n, dp[100][10010];

void solve(){
	ll x;

	while(cin >> x)
		a.push_back(x);
	n = a.size();
	// cout << n << "\n";

	ll sum = accumulate(a.begin(), a.end(), (ll) 0);

    ll dp[n+1][sum+1];
    for(ll i=0;i<=n;i++)
        dp[i][0] = 1;
    for(ll i=1;i<=sum;i++)
        dp[0][i] = 0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=sum;j++){
            dp[i][j] = dp[i-1][j];
            if(a[i-1] <= j)
                dp[i][j] |= dp[i-1][j-a[i-1]];
        }
    }
    ll diff = LLONG_MAX;
    for (ll j=sum/2;j>=0;j--){
        if (dp[n][j] == true){
            diff = sum-2*j;
            break;
        }
    }

    ld b = (accumulate(a.begin(), a.end(), (ll)0) / 2.0);
    ld c = diff / 2.0;

    cout << ((ll)(b + c)) << "\n";
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