#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, q, l[100010], r[100010], pre[100010];
vector<pair<ll, pair<ll, ll> > > pairs;
vector<pair<ll, pair<ll, ll> > > dist;

void te(){
	pairs.clear();
	dist.clear();
	for(ll i=0;i<100010;i++)
		l[i] = r[i] = pre[i] = 0;
	cin >> n >> m >> q;
	// cout << n << m << q << "\n";
	for(ll i=0;i<n;i++){
		cin >> l[i] >> r[i];
		pre[l[i]]++;
		pre[r[i]+1]--;
	}
	for(ll i=2;i<=m+2;i++)
		pre[i] = pre[i-1] + pre[i];
	pre[0] = 1, pre[m+1] = 1;

	ll ns, ne;
	for(ll i=1;i<=m;i++){
		if(pre[i] == 0){
			if(pre[i-1] == 1)
				ns = i;
			if(pre[i+1] == 1){
				ne = i;
				pairs.push_back(make_pair((ne-ns+1), make_pair(ne, ns)));
			}
		}
	}

	sort(pairs.begin(), pairs.end());
	// for(ll i=0;i<pairs.size();i++)
	// 	cout << pairs[i].first << " " << pairs[i].second.first << " " << pairs[i].second.second << "\n";
	ll curr = pairs[0].first;
	dist.push_back(make_pair(curr, make_pair(pairs[0].second.first, pairs[0].second.second)));

	for(ll i=0;i<pairs.size();i++){
		if(pairs[i].first == curr)
			dist[dist.size()-1] = pairs[i];
		else{
			dist.push_back(pairs[i]);
			curr = pairs[i].first;
		}
	}

	pair<ll, pair<ll, ll> > best = dist[dist.size()-1];
	for(ll i=dist.size()-1;i>=0;i--)
		if(dist[i].second.first <= best.second.first){
			dist[i].second.first = best.second.first;
			dist[i].second.second = best.second.second;
		}
		else{
			best = dist[i];
		}


	// for(ll i=0;i<pairs.size();i++)
	// 	cout << dist[i].first << " " << dist[i].second.first << " " << dist[i].second.second << "\n";
	
	for(ll i=0;i<q;i++){
		ll inp;
		cin >> inp;
		ll low, high;
		low = 0; high = dist.size()-1; ll pos = -1;

		while(low <= high){
			ll mid = (low + high) / 2;
			if(dist[mid].first >= (inp)){
				pos = mid;
				high = mid - 1;
			}
			else
				low = mid + 1;
		}

		if(pos == -1)
			cout << "-1 -1\n";
		else
			cout << dist[pos].second.first - inp + 1 << " " << dist[pos].second.first << "\n";
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--){
		// cout << "sdf\n";
		te();
	}

	return 0;
}