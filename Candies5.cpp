#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll m, n;
	cin >> m >> n;
	ll a[n];
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll low = 1, high = 1000000, ans = LLONG_MAX;

	while(low <= high){
		ll mid = (low + high) / 2;
		ll tot = 0;
		for(ll i=0;i<n;i++)
			tot += ceil((a[i]+0.0) / (mid+0.0));
		if(tot <= m){
			ans = min(ans, mid);
			high = mid - 1;
		}
		else
			low = mid + 1;
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

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}