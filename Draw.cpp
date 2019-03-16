#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n;

void te(){
	cin >> n;
	ll a = 0, ans = 0;

	for(ll i=0;i<n;i++){
		// cout << ans << "\n";
		ll x, y;
		cin >> x >> y;

		// cout << a << " " << min(x, y) - a + 1 << "--\n";
		ans += max((ll)0, min(x, y) - a + 1);
		if(x == y)
			a = x + 1;
		else
			a = max(x, y);
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