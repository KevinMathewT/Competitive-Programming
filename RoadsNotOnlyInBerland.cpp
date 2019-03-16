#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, parent[1010], ranks[1010];
vector<pair<ll, ll> > not_required;
vector<ll> leaders;
unordered_map<ll, ll> um;

void make_set(ll x){
	parent[x] = x;
	ranks[x] = 1;
}

ll find_set(ll x){
	if(parent[x] == x)
		return x;
	return parent[x] = find_set(parent[x]);
}

void union_sets(ll a, ll b){
	if(a == b)
		return;
	ll c = find_set(a);
	ll d = find_set(b);
	if(c == d){
		not_required.push_back(make_pair(a, b));
		return;
	}

	if(ranks[c] < ranks[d])
		swap(c, d);
	ranks[c] += ranks[d];
	parent[d] = c;
}

void te(){
	cin >> n;
	for(ll i=1;i<=n;i++)
		make_set(i);
	for(ll i=0;i<n-1;i++){
		ll u, v;
		cin >> u >> v;
		union_sets(u, v);
	}

	for(ll i=1;i<=n;i++)
		if(um[find_set(i)] != 1){
			leaders.push_back(find_set(i));
			um[find_set(i)] = 1;
		}

	cout << leaders.size() - 1 << "\n";
	for(ll i=0;i<leaders.size()-1;i++){
		cout << not_required[i].first << " " << not_required[i].second << " " << leaders[i] << " " << leaders[i+1] << "\n";
	}
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