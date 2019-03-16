#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    new_data_set;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n;
	cin >> n;

	ll a[n], b[n];
	for(ll i=0;i<n;i++)
		cin >> a[i];
	for(ll i=0;i<n;i++)
			
		cin >> b[i];

	map<ll, ll> m;

	for(ll i=0;i<n;i++)
		m[a[i]] = i+1;
	for(ll i=0;i<n;i++)
		b[i] = m[b[i]];

	new_data_set p;
	ll c = 0;

	for(ll i=n-1;i>=0;i--){
		// cout << p.order_of_key(b[i]) << "\n";
		c += max((ll)0, (ll)p.order_of_key(b[i]));
		p.insert(b[i]);
	}

	cout << c << "\n";	
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