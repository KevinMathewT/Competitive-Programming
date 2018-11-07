#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll a, b, n;
	cin >> a >> b >> n;

	map<ll, map<ll, ll> > m;
	ll ca = 0, cb = 0;
	ll t = a;
	while(t > 0){
		if(t & 1 != 0)
			ca++;
		t >>= 1;
	}
		
	t = b;
	while(t > 0){
		if(t & 1 != 0)
			cb++;
		t >>= 1;
	}

	ll c = 0;

	// cout << ca << " " << cb << "\n";

	for(ll i=0;i<=n;i++){
		ll c1 = 0, c2 = 0;
		t = i;
    	c1 = __builtin_popcount(t);
		
		t = n-i;
		c2 = __builtin_popcount(t);

		// if(c1 == 5 && c2 == 5)
		// 	cout << i << " " << c1 << " " << n-i << " " << c2 << "\n";
		if(c1 == ca && c2 == cb)
			c++;
	}

	cout << c << "\n";
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