#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, v;

void te(){
	cin >> n >> v;

	ll tot = 0;
	ll tank = 0;

	for(ll i=1;i<=n;i++){
		// cout << (v - tank) << " " << i << " " << tank << " " << n-i << "\n";
		if(tank < (n - i)){
			ll add = (min(v, (n - i)) - tank);
			tank += (min(v, (n - i)) - tank);
			tot += add * i;
		}

		tank--;
		// cout << tank << " " << tot << "\n";
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