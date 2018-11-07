#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

bool comparator(const pair<ll, ll> &a, const pair<ll, ll> &b){ 
    return ((a.first + a.second) >= (b.first + b.second)); 
}

ll getManhattan(pair<ll, ll> &a, pair<ll, ll> &b){
	return abs(a.first-b.first) + abs(a.second-b.second);
}

void te(){
	ll n, m;
	cin >> n >> m;
	ll a[n][m];

	for(ll i=0;i<n;i++){
		string s;
		cin >> s;
		for(ll j=0;j<m;j++)
			a[i][j] = s[j] - '0';
	}

	vector<pair<ll, ll> > v;

	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			if(a[i][j] == 1)
				v.push_back(make_pair(i, j));

	sort(v.begin(), v.end(), comparator);

	for(ll i=0;i<v.size();i++)
		cout << v[i].first << " " << v[i].second << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}