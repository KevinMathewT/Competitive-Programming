#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, a[200010], cum[200010];

void te(){
	cin >> n >> m;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	cum[0] = a[0];
	for(ll i=1;i<n;i++)
		cum[i] = a[i] + cum[i-1];

	sort(a, a + n);
	for(ll i=0;i<n/2;i++){
		ll t = a[i];
		a[i] = a[n-1-i];
		a[n-1-i] = t;
	}

	ll tot = accumulate(a, a+n, 0);

	ll best = LLONG_MAX;

	if(m > tot){
		cout << -1 << "\n";
		return;
	}

	ll l = 1, r = n + 1;
	
	while(l <= r){
		ll mid = (l + r) / 2;

		ll tot = 0;
		ll minus = -1;

		// cout << mid << "-------------\n";
		for(ll i=0;i<n;i++){
			if(i % mid == 0)
				minus++;

			// cout << minus << "-\n";
			tot += max((ll) 0, a[i] - minus);
			// cout << i << "^" << tot << " ";
		}
		// cout << "\n";
		// cout << mid << " " << tot << "\n";

		if(tot >= m){
			// cout << mid << "--------\n";
			best = min(best, mid);
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}

	cout << best << "\n";
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