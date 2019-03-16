#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[100010], safe[100010];
unordered_map<ll, ll> um;

void te(){
	cin >> n;
	for(ll i=0;i<n;i++){
		safe[i] = 1;
		cin >> a[i];
	}

	for(ll i=0;i<n;i++)
		um[a[i]] = 1;

	for(ll i=0;i<n;i++)
		if(um[-a[i]] == 1)
			safe[i] = 0;

	vector<ll> v;
	for(ll i=0;i<n;i++)
		if(safe[i] == 1)
			v.push_back(a[i]);

	sort(v.begin(), v.end());

	ll ans = 0;
	for(ll i=0;i<n;i++){
		if(a[i] > 0 && v.end() - upper_bound(v.begin(), v.end(), a[i]) >= 3)
			ans = (ans + a[i]) % 1000000007;
	}

	cout << ans << "\n";
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