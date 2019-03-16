#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll seive[(ll) 1e6 + 100];
ll semi[(ll) 1e6 + 100];
ll final[(ll) 1e6 + 100];
vector<ll> primes;

void te(){
	ll l, r;
	cin >> l >> r;
	cout << l << " " << r << "\n";

	cout << final[r] - final[l-1] << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	seive[0] = 0;
	seive[1] = 0;
	semi[0] = 0;
	semi[1] = 0;
	final[0] = 0;
	final[1] = 0;

	ll c = 0;
	for(ll i=2;i<(ll) 1e6 + 100;i++){
		seive[i] = 1;
		semi[i] = 0;
		final[i] = 0;
	}
	for(ll i=2;i<(ll) 1e6 + 100;i++)
		if(seive[i] == 1){
			// cout << i << "\n";
			// c++;
			primes.push_back(i);
			for(ll j=i*i;j<(ll) 1e6 + 100;j+=i)
				seive[j] = 0;
		}

		// cout << c << "\n";

	for(ll i=0;i<primes.size();i++)
		for(ll j=0;j<=i;j++){
			if(primes[i]*primes[j] > (ll) 1e6 + 100)
				break;
			semi[primes[i]*primes[j]] = 1;
		}

	for(ll i=2;i<(ll) 1e6 + 100 - 2;i++)
		if(seive[i] == 1 && (seive[i+2] == 1 || semi[i+2] == 1))
			final[i] = 1;

	// for(ll i=1;i<100;i++)
	// 	cout << i << " " << final[i] << '\n';

	for(ll i=1;i<(ll) 1e6 + 100;i++)
		final[i] = final[i] + final[i-1];

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}