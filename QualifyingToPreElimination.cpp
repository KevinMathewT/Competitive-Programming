#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n, k;
	cin >> n >> k;
	vector<ll> v;
	for(ll i=0;i<n;i++){
		ll a; cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	// for(ll i=0;i<n;i++)
	// 	cout << v[i] << " ";
	// cout << "\n";

	cout << v.end() - lower_bound(v.begin(), v.end(), v[n-k]) << "\n";
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