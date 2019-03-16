#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

vector<ll> v;
vector<ll> adj[100000];

ll dist(ll a, ll b){
	ll diff = 0;
	while(a > 0 && b > 0){
		if((a % 10) != (b % 10))
			diff++;
		a /= 10;
		b /= 10;
	}

	return diff;
}

void te(){
	ll a, b;
	cin >> a >> b;
	ll vis[100000];
	for(ll i=0;i<v.size();i++)
		vis[v[i]] = 0;

	queue<pair<ll, ll> > q;
	q.push(make_pair(a, 0));

	while(!q.empty()){
		pair<ll, ll> curr = q.front();
		q.pop();

		vis[curr.first] = 1;

		if(curr.first == b){
			cout << curr.second << "\n";
			return;
		}

		for(ll i=0;i<adj[curr.first].size();i++)
			if(v[adj[curr.first][i]] != 1)
				q.push(make_pair(adj[curr.first][i], curr.second+1));
	}

	cout << "Impossible\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	for(ll i=0;i<v.size();i++){
		vector<ll> a(0);
		adj[v[i]] = a;
	}

	for(ll i=1000;i<=9999;i++){
		ll factors = 0;
		for(ll j=1;j*j<=i;j++)
			if(i % j == 0)
				factors++;

		if(factors == 1)
			v.push_back(i);
	}

	for(ll i=0;i<v.size()-1;i++)
		for(ll j=i+1;j<v.size();j++)
			if(dist(v[i], v[j]) == 1){
				adj[v[i]].push_back(v[j]);
				adj[v[j]].push_back(v[i]);
			}

	// for(ll i=0;i<v.size();i++){
	// 	cout << v[i] << " - ";
	// 	for(ll j=0;j<adj[v[i]].size();j++)
	// 		cout << adj[v[i]][j] << " ";
	// 	cout << "\n";
	// }

	// cout << v.size() << "\n";

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}