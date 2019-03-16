#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[1010][1010];
vector<pair<ll, ll> > graph[1010][1010];
ll vis[1010][1010];

void dfs(ll x, ll y){
	vis[x][y] = 1;
	for(ll i=0;i<graph[x][y].size();i++)
		if(vis[graph[x][y][i].first][graph[x][y][i].second] != 1)
			dfs(graph[x][y][i].first, graph[x][y][i].second);
}

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++){
			vis[i][j] = 0;
			cin >> a[i][j];
		}

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++){
			if(a[i][j] == 1){
				for(ll k=i+1;k<n;k++)
					if(a[k][j] == 1){
						// graph[k][j].push_back(make_pair(i, j));
						graph[i][j].push_back(make_pair(k, j));
						break;
					}
				for(ll k=i-1;k>=0;k--)
					if(a[k][j] == 1){
						// graph[k][j].push_back(make_pair(i, j));
						graph[i][j].push_back(make_pair(k, j));
						break;
					}
				for(ll k=j+1;k<n;k++)
					if(a[i][k] == 1){
						// graph[i][k].push_back(make_pair(i, j));
						graph[i][j].push_back(make_pair(i, k));
						break;
					}
				for(ll k=j-1;k>=0;k--)
					if(a[i][k] == 1){
						// graph[i][k].push_back(make_pair(i, j));
						graph[i][j].push_back(make_pair(i, k));
						break;
					}
			}
		}

	ll ans = 0;

	for(ll i=0;i<graph[0][0].size();i++)
		cout << graph[0][0][i].first << " " << graph[0][0][i].second << "\n";
	cout << "\n-" << graph[0][0].size() << "\n";
	cout << graph[0][1].size() << "\n";
	cout << graph[1][0].size() << "\n";
	cout << graph[1][1].size() << "\n";

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			if(a[i][j] == 1  && vis[i][j] != 1){
				ans++;
				dfs(i, j);
			}

	cout << ans << "\n";
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