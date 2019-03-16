#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll N, W, w[110], v[110], dp[110][100010];

void te(){
	cin >> N >> W;
	for(ll i=0;i<N;i++)
		cin >> w[i] >> v[i];

	for(ll i=0;i<=W;i++)
		if(i < w[0])
			dp[0][i] = 0;
		else
			dp[0][i] = v[0];

	for(ll i=1;i<N;i++){
		for(ll j=0;j<=W;j++){
			if(j < w[i])
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i-1][j], v[i] + dp[i-1][j-w[i]]);
		}
	}

	cout << dp[N-1][W] << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}