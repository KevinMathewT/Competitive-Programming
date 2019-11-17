#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, k, a[20];

void te(){
	cin >> n >> k;
	for(ll i=0;i<k;i++)
		cin >> a[i];

	ll tot = n, lcm, x;
	for(ll i=1;i<(1<<k);i++){
		lcm = 1;
		x = 0;
		for(ll j=0;j<k;j++)
			if(i & (1 << j)){
				lcm = (lcm * a[j]) / (__gcd(lcm, a[j]));
				x = x ^ 1;
			}

		if(x)
			tot -= (n / lcm);
		else
			tot += (n / lcm);
		// cout << tot << "\n";
	}

	cout << tot << "\n";
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