#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll returnCost(ll a, ll b, ll c){
	if(a <= c) return c - a;
	return b + c - a;
}

void te(){
	ll n;
	cin >> n;
	ll a[n], b[n];

	for(ll i=0;i<n;i++)
		cin >> a[i];

	for(ll i=0;i<n;i++)
		cin >> b[i];

	for(ll i=0;i<n;i++)
		a[i] = a[i] % b[i];

	ll l = 0, h = 1e9 + 100, mid, mid_cost;	
	h-=1;

	// cout << h << "\n";
	ll min_cost = LLONG_MAX;

	while(l <= h){
		mid = (l + h) / 2;
		ll cost_1 = 0;
		ll cost_2 = 0;

		for(ll i=0;i<n;i++)
			cost_1 += returnCost(a[i], b[i], mid);
		for(ll i=0;i<n;i++)
			cost_2 += returnCost(a[i], b[i], mid+1);

		min_cost = min(min(min_cost, cost_1), cost_2);

		if(cost_1 < cost_2)
			h = mid - 1;
		else
			l = mid + 1;
		// cout << mid << " " << cost_1 << " " << cost_2 << "\n";
	}

	cout << min_cost << "\n";
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