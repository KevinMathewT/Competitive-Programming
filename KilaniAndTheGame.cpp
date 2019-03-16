#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, p, s[50], covered[50], grid[1010][1010], vis[1010][1010], tot_vis, added[1010][1010]; 
vector<pair<ll, ll> > v[50];

void te(){
	tot_vis = 0;
	cin >> n >> m >> p;
	for(ll i=1;i<=p;i++){
		covered[i] = 0;
		cin >> s[i];
	}
	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			vis[i][j] = 0;

	for(ll i=0;i<n;i++){
		string s;
		cin >> s;
		for(ll j=0;j<m;j++){
			if(s[j] >= '0' && s[j] <= '9'){
				covered[s[j]-'0']++;
				v[s[j]-'0'].push_back(make_pair(i, j));
				grid[i][j] = s[j]-'0';
				vis[i][j] = 1;
			}
			else if(s[j] == '#'){
				grid[i][j] = -1;
				vis[i][j] = 1;
			}
		}
	}

	while(tot_vis < (n*m)){
		ll flag = 0;
		for(ll i=1;i<=p;i++){
			queue<pair<pair<ll, ll>, ll> > q;
			for(ll j=0;j<v[i].size();j++){
				// cout << v[i][j].first << " " << v[i][j].second << "\n";
				q.push(make_pair(v[i][j], (ll)0));
			}

			// cout << "-\n";

			v[i].clear();

			while(!q.empty()){
				pair<pair<ll, ll>, ll> pp = q.front();
				q.pop();
				pair<ll, ll> point = pp.first;
				ll x = point.first;
				ll y = point.second;

				if(vis[x][y] == 0){
					tot_vis++;
					covered[i]++;
				}
				vis[x][y] = 1;

				// cout << x << " " << y << "\n";
				if(tot_vis == n*m){
					// cout << "YAY\n";
					break;
				}


				if(pp.second == s[i]){
					// cout << x << " " << y << "--\n";
					v[i].push_back(make_pair(x, y));
					continue;
				}

				if(x+1 >= 0 && x+1 < n && vis[x+1][y] == 0 && added[x+1][y] == 0){
					q.push(make_pair(make_pair(x+1, y), pp.second+1));
					added[x+1][y] = 1;
				}
				if(x-1 >= 0 && x-1 < n && vis[x-1][y] == 0 && added[x-1][y] == 0){
					q.push(make_pair(make_pair(x-1, y), pp.second+1));
					added[x-1][y] = 1;
				}
				if(y+1 >= 0 && y+1 < m && vis[x][y+1] == 0 && added[x][y+1] == 0){
					q.push(make_pair(make_pair(x, y+1), pp.second+1));
					added[x][y+1] = 1;
				}
				if(y-1 >= 0 && y-1 < m && vis[x][y-1] == 0 && added[x][y-1] == 0){
					q.push(make_pair(make_pair(x, y-1), pp.second+1));
					added[x][y-1] = 1;
				}
			}

			// cout << "-\n";
			flag = 0;
			for(ll i=1;i<=p;i++)
				if(!v[i].empty())
					flag = 1;
			if(tot_vis == n*m || flag == 0)
				break;
		}
		flag = 0;
		for(ll i=1;i<=p;i++)
			if(!v[i].empty())
				flag = 1;
		if(tot_vis == n*m || flag == 0)
			break;
	}

	for(ll i=1;i<=p;i++)
		cout << covered[i] << " ";
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