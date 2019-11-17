#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, q, a[20];

void te(){
	cin >> n >> q;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	for(ll i=0;i<q;i++){
		ll l, r;
		cin >> l >> r;

		ll tot = 0;

		ll pr = 1;
		for(ll i=1;i<(1<<n);i++){
			pr = 1;
			ll x = 0;
			for(ll j=0;j<n;j++)
				if(i & (1 << j)){
					pr *= a[j];
					x ^= 1;
				}
			ll add = (r / pr) - ((l - 1) / pr);
			if(x)
				tot += add;
			else
				tot -= add;
		}

		cout << tot << "\n";
	}
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