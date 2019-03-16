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

	sort(a, a+n);
	map<ll, ll> m;

	for(ll i=0;i<n;i++)
		m[a[i]]++;

	ll mx = LLONG_MIN;

	for(ll i=0;i<n;i++)
		mx = max(mx, m[a[i]] + m[a[i]+1]);

	cout << mx << "\n";
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
	while(T--)
		te();

	return 0;
}