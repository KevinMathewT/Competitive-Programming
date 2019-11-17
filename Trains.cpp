#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, dp[110][10010], p[110], cash[110][110], best_way[110][110];

void te(){
	cin >> n >> m;
	for(ll i=0;i<n;i++){
		cin >> p[i];
		for(ll j=0;j<p[i];j++){
			best_way[i][j] = 0;
			cin >> cash[i][j];
		}
	}

	for(ll i=0;i<n;i++){
		best_way[i][0] = 0;
		best_way[i][p[i]] = accumulate(cash[i], cash[i] + p[i], 0);
		for(ll j=1;j<p[i];j++){
			ll prev = 0;
			ll curr = 0;
			ll next = 0;
			ll k;
			for(k=0;k<j;k++)
				curr += cash[i][k];
			ll t = k;
			for(;k<p[i];k++)
				next += cash[i][k];
			best_way[i][p[i]-j] = prev + next;
			for(;t<p[i];t++){
				prev += cash[i][t-j];
				curr -= cash[i][t-j];
				curr += cash[i][t];
				next -= cash[i][t];
				best_way[i][p[i]-j] = max(best_way[i][p[i]-j], prev + next);
			}
		}
		// cout << "\n";
	}

	// for(ll i=0;i<n;i++){
	// 	for(ll j=0;j<=p[i];j++)
	// 		cout << best_way[i][j] << " ";
	// 		cout << "\n";
	// }

	for(ll i=0;i<=n;i++){
		dp[i][0] = 0;
	}
	for(ll i=0;i<=m;i++){
		dp[0][i] = 0;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			dp[i][j] = best_way[i-1][j];
			for(ll k=0;k<=j;k++)
				dp[i][j] = max(dp[i][j], dp[i-1][k] + best_way[i-1][j-k]);
			// cout << dp[i][j] << " ";
		}
		// cout << "\n";
	}

	cout << dp[n][m] << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}