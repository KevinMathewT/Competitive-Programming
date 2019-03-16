#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

map<string, ll> mp;
vector<ll> v[50];
ll n, q;

void te(){
	mp.clear();
	for(ll i=0;i<50;i++)
		v[i].clear();

	cin >> n;

	cin.ignore(256, '\n');
	for(ll i=0;i<n;i++){
		string s;
		getline(cin, s);
		// cout << s << "\n";
		mp[s] = i;
	}

	cin >> q;
	cin.ignore(256, '\n');
	for(ll i=0;i<q;i++){
		string s;
		getline(cin, s);

		v[mp[s]].push_back(i);
		// cout << mp[h] << "\n";
	}

	ll last = 0;
	ll cost = 0;
	ll last_p = -1;

	// for(ll i=0;i<n;i++){
	// 	cout << i << " - ";
	// 	for(ll j=0;j<v[i].size();j++)
	// 		cout << v[i][j] << " " ;
	// 	cout << "\n";
	// }

	while(true){
		ll h = 0;
		for(ll i=0;i<n;i++){
			if(i == last_p)
				continue;
			if(upper_bound(v[i].begin(), v[i].end(), last) == v[i].end()){
				cout << cost << "\n";
				return;
			}
			if(*lower_bound(v[i].begin(), v[i].end(), last) > h){
				h = max(h, *lower_bound(v[i].begin(), v[i].end(), last));
				last_p = i;
			}
		}

		cost++;
		last = h;

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
	// cout << T << "\n";
	while(T--)
		te();

	return 0;
}