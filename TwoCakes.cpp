#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[200010], x[100010], y[100010];

void te(){
	cin >> n;
	for(ll i=0;i<2*n;i++)
		cin >> a[i];

	for(ll i=0;i<=n;i++){
		x[i] = 0;
		y[i] = 0;
	}

	for(ll i=0;i<2*n;i++){
		if(x[a[i]] == 0)
			x[a[i]] = i + 1;
		else
			y[a[i]] = i + 1;
	}

	ll p = 1, q = 1;
	ll ans = 0;

	// for(ll i=1;i<=n;i++)
	// 	cout << x[i] << " " << y[i] << "\n";

	for(ll i=1;i<=n;i++){
		// cout << x[i] << " " << y[i] << "\n";
		ans += (min(abs(x[i] - p) + abs(y[i] - q), abs(x[i] - q) + abs(y[i] - p)));
		// cout << ans << "\n";
		p = x[i];
		q = y[i];
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