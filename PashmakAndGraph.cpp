#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, dp[300010], temp[300010];
vector<pair<ll, ll> > graph[300010];

void te(){
	cin >> n >> m;
	for(ll i=0;i<300010;i++){
		dp[i] = 0;
		temp[i] = 0;
		graph[i].clear();
	}

	for(ll i=0;i<m;i++){
		ll u, v, w;
		cin >> u >> v >> w;

		graph[w].push_back(make_pair(u, v));
	}

	for(ll i=0;i<300010;i++){
		for(ll j=0;j<graph[i].size();j++){
			temp[graph[i][j].second] = max(temp[graph[i][j].second], 1 + dp[graph[i][j].first]);
		}
		for(ll j=0;j<graph[i].size();j++){
			dp[graph[i][j].second] = max(temp[graph[i][j].second], temp[graph[i][j].second]);
		}
	}

	ll max_ans = 1;
	for(ll i=1;i<=n;i++)
		max_ans = max(max_ans, dp[i]);

	cout << max_ans << "\n";
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