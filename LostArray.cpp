#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n;
	cin >> n;
	ll a[n];
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll diff[n];
	diff[0] = a[0];
	for(ll i=1;i<n;i++)
		diff[i] = a[i] - a[i-1];

	ll l = 1;
	vector<ll> v;

	for(ll l=1;l<=n;l++){
		ll flag = 1;
		for(ll d=0;(d+l) < n;d++)
			if(diff[d] != diff[d+l])
				flag = 0;

		if(flag == 1)
			v.push_back(l);
	}

	sort(v.begin(), v.end());

	cout << v.size() << "\n";
	for(ll i=0;i<v.size();i++)
		cout << v[i] << " " ;

	cout << "\n";
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