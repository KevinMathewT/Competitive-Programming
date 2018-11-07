#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll s, x, n; cin >> s >> x >> n;
	vector<pair<ll, ll> > v;

	for(ll i=0;i<n;i++){
		ll a, b; cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end());

	
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