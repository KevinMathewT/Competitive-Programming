#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n, m;
	cin >> n >> m;
	ll chess[n][m];
	string s;
	for(ll i=0;i<n;i++){
		cin >> s;
		for(ll j=0;j<m;j++)
			chess[i][j] = s[j]-'0';
	}

	ll w = min(n, m);
	ll x = n;
	ll y = m;
	ll z = 2;
	ll dp[w][x][y][z];
	
	for(ll i=0;i<w;i++)
		for(ll j=0;j<x;j++)
			for(ll k=0;k<y;k++)
				for(ll l=0;l<z;l++)
					dp[i][j][k][l] = 0;

	// ll count = 0;
	for(ll i=0;i<w;i++)
		for(ll j=0;j<x;j++){
			if(j + i >= n) break;
			for(ll k=0;k<y;k++){
				if(k + i >= m) break;
				if(i == 0){
					if(chess[j][k] == 1)
						dp[i][j][k][0] = 1;
					else
						dp[i][j][k][1] = 1;
					// cout << chess[j][k] << " " << i << " " << j << " " << k << " " << dp[i][j][k][0] << " " << dp[i][j][k][1] << "\n";
					continue;
				}
				// if(i == 0) cout << "376473547635248752384";
				// if(((ll)((i+1)/2)) % 2 == 0){
				if(i % 2 == 1)
					if(((ll)((i+1)/2)) % 2 == 0){
						dp[i][j][k][0] = dp[i/2][j][k][0] + dp[i/2][j+(i/2)+1][k][0] + dp[i/2][j][k+(i/2)+1][0] + dp[i/2][j+(i/2)+1][k+(i/2)+1][0];
						dp[i][j][k][1] = dp[i/2][j][k][1] + dp[i/2][j+(i/2)+1][k][1] + dp[i/2][j][k+(i/2)+1][1] + dp[i/2][j+(i/2)+1][k+(i/2)+1][1];
					}
					else{
						dp[i][j][k][0] = dp[i/2][j][k][0] + dp[i/2][j+(i/2)+1][k][1] + dp[i/2][j][k+(i/2)+1][1] + dp[i/2][j+(i/2)+1][k+(i/2)+1][0];
						dp[i][j][k][1] = dp[i/2][j][k][1] + dp[i/2][j+(i/2)+1][k][0] + dp[i/2][j][k+(i/2)+1][0] + dp[i/2][j+(i/2)+1][k+(i/2)+1][1];
					}
				else{
					if(((ll)((i+1)/2)) % 2 == 1){
						dp[i][j][k][0] = dp[i/2][j][k][0] + dp[i/2-1][j+(i/2)+1][k][0] + dp[i/2-1][j][k+(i/2)+1][0] + dp[i/2][j+(i/2)][k+(i/2)][0];
						dp[i][j][k][1] = dp[i/2][j][k][1] + dp[i/2-1][j+(i/2)+1][k][1] + dp[i/2-1][j][k+(i/2)+1][1] + dp[i/2][j+(i/2)][k+(i/2)][1];
						if(chess[j+(i/2)][k+(i/2)] == 1)
							dp[i][j][k][0]--;
						else
							dp[i][j][k][1]--;

					}
					else{
						dp[i][j][k][0] = dp[i/2][j][k][0] + dp[i/2-1][j+(i/2)+1][k][1] + dp[i/2-1][j][k+(i/2)+1][1] + dp[i/2][j+(i/2)][k+(i/2)][0];
						dp[i][j][k][1] = dp[i/2][j][k][1] + dp[i/2-1][j+(i/2)+1][k][0] + dp[i/2-1][j][k+(i/2)+1][0] + dp[i/2][j+(i/2)][k+(i/2)][1];
						if(chess[j+(i/2)][k+(i/2)] == 1)
							dp[i][j][k][0]--;
						else
							dp[i][j][k][1]--;
					}
					// count++;
					// cout << count << "\n";
				}
			}
		}

	// cout << "////////////\n";
	ll size = 210*210;
	ll ans[size];

	for(ll i=0;i<size;i++)
		ans[i] = 0;

	for(ll i=0;i<w;i++)
		for(ll j=0;j<x;j++){
			if(j + i >= n) break;
			for(ll k=0;k<y;k++){
				if(k + i >= m) break;
				for(ll l=0;l<z;l++){
					// cout << i << " " << j << " " << k << " " << l << " " << dp[i][j][k][l] << "\n";
					ans[dp[i][j][k][l]] = max(ans[dp[i][j][k][l]], i+1);
				}
			}
		}

	for(ll i=1;i<size;i++){
		ans[i] = max(ans[i-1], ans[i]);
		// cout << ans[i] << " ";
	}
	// cout << "\n";

	ll q;
	cin >> q;
	while(q--){
		ll query;
		cin >> query;
		if(query > (n * m))
			cout << ans[size-1] << "\n";
		else
			cout << ans[query] << "\n";
	}
	// cout << dp[4][0][0][0] << "-\n";
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