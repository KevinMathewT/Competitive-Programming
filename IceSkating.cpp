#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew

vector<ll> v[200];
ll vis[200];

void dfs(ll n){
	vis[n] = 1;
	for(ll i=0;i<v[n].size();i++)
		if(vis[v[n][i]] == 0)
			dfs(v[n][i]);
}


void te(){
	ll n; cin >> n;
	vector<pair<ll, ll> > v1;
	vector<pair<ll, ll> > v2;
	for(ll i=0;i<200;i++) vis[i] = 0;

	for(ll i=1;i<=n;i++){
		ll x, y;
		cin >> x >> y;
		v1.push_back(make_pair(x, i));
		v2.push_back(make_pair(y, i));
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	for(ll i=1;i<v1.size();i++)
		if(v1[i].first == v1[i-1].first){
			v[v1[i-1].second].push_back(v1[i].second);
			v[v1[i].second].push_back(v1[i-1].second);
		}
	for(ll i=1;i<v2.size();i++)
		if(v2[i].first == v2[i-1].first){
			v[v2[i-1].second].push_back(v2[i].second);
			v[v2[i].second].push_back(v2[i-1].second);
		}

	// for(ll i=1;i<=n;i++){
	// 	for(ll j=0;j<v[i].size();j++)
	// 		cout << v[i][j] << " ";
	// 	cout << "\n";
	// }

	ll cc = -1;
	for(ll i=1;i<=n;i++){
		// cout << vis[i] << "-\n";
		if(vis[i] == 0){
			dfs(i);
			cc++;
		}
	}

	cout << cc << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	// ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}