#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n, m;
	cin >> n >> m;

	ll p[n], c[n];
	for(ll i=0;i<n;i++)
		cin >> p[i] >> c[i];
	ll lv = 0;

	priority_queue<pair<ll, pair<ll, ll> > > pq;

	vector<ll> v[m+1];
	ll votes[m+1];

	for(ll i=0;i<=m;i++)
		votes[i] = 0;

	for(ll i=0;i<n;i++){
		if(p[i] == 1){
			lv++;
			continue;
		}

		votes[p[i]]++;
		v[p[i]].push_back(c[i]);
	}

	for(ll i=2;i<=m;i++){
		if(v[i].size() == 0) continue;
		sort(v[i].begin(), v[i].end());
	}

	for(ll i=2;i<=m;i++){
		if(v[i].size() == 0) continue;

		pq.push(make_pair(votes[i], make_pair(-v[i][0], i)));
	}

	ll pointer[m+1];
	for(ll i=0;i<=m;i++)
		pointer[i] = 0;

	ll tot = 0;

	while(!pq.empty()){
		pair<ll, pair<ll, ll> > pp = pq.top();
		pq.pop();

		if(lv > pp.first)
			break;

		cout << lv << " " << pp.first << " " << -pp.second.first << " " << pp.second.second << "\n";

		lv++;
		tot += -pp.second.first;
		pp.first = pp.first - 1;
		if(pointer[pp.second.second] == v[pp.second.second].size())
			continue;
		pp.second.first = -v[pp.second.second][pointer[pp.second.second]++];

		pq.push(pp);
	}

	cout << tot << "\n";
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