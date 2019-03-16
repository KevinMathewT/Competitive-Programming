#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, x, y, a[100010];

void te(){
	cin >> n >> x >> y;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll l = 0, r = 100000000000, best = LLONG_MAX, ans = 0;
	// cout << l << " " << r << "\n";

	while(l < r){
		ll mid = (l + r) / 2;

		ll profit = 0;
		for(ll i=0;i<n;i++){
			if(a[i] <= mid)
				profit -= abs(a[i] - mid) * y;
			else
				profit += abs(a[i] - mid) * x;
			// cout << profit << "\n";
		}

		cout << mid << " " << profit << "\n";
		if(profit < 0)
			l = mid + 1;
		else{
			best = min(best, profit);
			r = mid - 1;
		}
	}

	cout << best << "\n";
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