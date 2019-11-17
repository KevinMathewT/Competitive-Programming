#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, k, a, b;

void te(){
	cin >> n >> k >> a >> b;
	ll init1 = abs(k - a - b);
	ll init2 = abs(b - a);

	ll mx = LLONG_MIN, mn = LLONG_MAX;
	for(ll i=0;i<n;i++){
		ll st1 = (k * n) / __gcd((k * n), init1 + i*k);	
		mx = max(mx, st1);
		mn = min(mn, st1);
		ll st2 = (k * n) / __gcd((k * n), init2 + i*k);
		mx = max(mx, st2);
		mn = min(mn, st2);
	}

	cout << mn << " " << mx << "\n";
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