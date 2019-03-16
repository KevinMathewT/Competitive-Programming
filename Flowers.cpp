#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SIZE ((ll) 1e5 + 100)
#define MOD ((ll) 1e9 + 7)

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll t, k;
	cin >> t >> k;
	ll a[SIZE];

	for(ll i=0;i<k;i++)
		a[i] = 1;
	
	// for(ll i=0;i<100;i++)
	// 	cout << a[i] << " ";
	// cout << "\n";

	for(ll i=k;i<SIZE;i++)
		a[i] = (a[i-1] + a[i-k]) % MOD;

	// for(ll i=0;i<100;i++)
	// 	cout << a[i] << " ";
	// cout << "\n";

	for(ll i=1;i<SIZE;i++)
		a[i] = (a[i] + a[i-1]) % MOD;

	// for(ll i=0;i<100;i++)
	// 	cout << a[i] << " ";
	// cout << "\n";

	while(t--){
		ll l, r;
		cin >> l >> r;

		cout << ((a[r] - a[l-1] + MOD) % MOD) << "\n";
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