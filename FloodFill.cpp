#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, c[5010], temp[5010], numCon[5010], pre[5010];
unordered_map<ll, ll> mp;
unordered_map<ll, vector<ll>> pos;

void te(){
	cin >> n;
	for(ll i=0;i<n;i++){
		cin >> c[i];
		temp[i] = c[i];
	}

	sort(temp, temp+n);
	ll assn = 0;

	for(ll i=0;i<n;i++){
		if(mp[temp[i]] == 0){
			mp[temp[i]] = assn++;
		}
	}

	for(ll i=0;i<n;i++){
		c[i] = mp[c[i]];
	}

	for(ll i=0;i<n;i++)
		cout << c[i] << " ";
	cout << "\n";

	vector<ll> vec;
	vec.push_back(c[0]);
	for(ll i=1;i<n;i++)
		if(c[i] != c[i-1])
			vec.push_back(c[i]);

	ll mx = 0;
	ll ans = 0;

	for(ll i=0;i<vec.size();i++){
		cout << vec[i] << " ";
		pre[i] = 0;
	}

	cout << "\n";

	for(ll i=0;i<vec.size();i++){
		pos[vec[i]].push_back(i);
	}

	for(ll i=0;i<assn;i++){
		for(ll j=0;j<pos[i].size()/2;j++){
			pre[pos[i][j]+1]++;
			pre[pos[i][pos[i].size()-(j+1)]]--;
		}
	}

	for(ll i=1;i<vec.size();i++){
		pre[i] = pre[i] + pre[i-1];
		mx = max(mx, pre[i]);
	}

	for(ll i=0;i<vec.size();i++)
		cout << pre[i] << " ";
	cout << "\n";

	cout << vec.size() - 1 - mx << "\n";
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