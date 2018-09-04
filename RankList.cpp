#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew

void te(){
	ll n, k; cin >> n >> k;
	vector<pair<ll, ll> > v;

	for(ll i=0;i<n;i++){
		ll a, b; cin >> a >> b;
		v.push_back(make_pair(-a, b));
	}

	sort(v.begin(), v.end());

	ll cfor = 0, cback = 0;
	for(ll i=k;i<n;i++)
		if(v[i].first == v[k-1].first && v[i].second == v[k-1].second)
			cfor++;
		else
			break;

	for(ll i=k-2;i>=0;i--)
		if(v[i].first == v[k-1].first && v[i].second == v[k-1].second)
			cback++;
		else
			break;

	cout << cfor+cback+1 << "\n";
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