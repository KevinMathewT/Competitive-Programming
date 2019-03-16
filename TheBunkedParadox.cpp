#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[100010];
unordered_map<ll, ll> um;
unordered_map<ll, ll> vis;

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	for(ll i=0;i<n;i++)
		um[a[i]]++;

	ll ans = 0;

	for(ll i=0;i<n;i++)
		if(vis[a[i]] != 1 && a[i] != 0){
			ans += um[a[i]] * um[-a[i]];
			vis[a[i]] = 1;
			vis[-a[i]] = 1;
		}

	cout << ans << "\n";
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