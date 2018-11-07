#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

// ll power(ll x, ll y, ll m) 
// { 
//     if (y == 0) 
//         return 1; 
//     ll p = power(x, y/2, m) % m; 
//     p = ((p % m) * (p % m)) % m; 
  
//     return (y%2 == 0)? (p % m) : ((x % m) * (p % m)) % m; 
// }

ll power(ll x, ll y, ll m){
	// cout << x << " " << y << "\n";
	if(y == 1) return x % m;
	if(y == 0) return 1;
	if(y % 2 == 0)
		return power(((x % m) * (x % m)) % m, y / 2, m) % m;
	return (((x % m) * (power(((x % m) * (x % m)) % m, y / 2, m) % m)) % m);
}

ll modInverse(ll a, ll m) {
	// cout << a << " " << m << " " << power(a, m-2, m) << "\n";
    return power(a, m-2, m) % m; 
}

ll nCrMODp(ll n, ll r, ll p){
	if(n < r) return 0;
	if(n == r || r == 0) return 1;
	if(n-1 == r || r == 1) return (n % p);

	ll num = 1;
	for(ll i=0;i<r;i++)
		num = ((num % p) * ((n-i) % p)) % p;

	ll den = 1;
	for(ll i=1;i<=r;i++)
		den = ((den % p) * ((i) % p)) % p;

	// cout << "" << n << " " << r << " num - " << num << " den - " << den << "\n" << (((num % p) * (modInverse(den, p) % p)) % p) << "\n";
	return (((num % p) * (modInverse(den, p) % p)) % p);
}

void te(){
	ll a, b, sum;
	cin >> a;
	cin >> b;
	ll p = 1e9 + 7;

	if(b > a){
		cout << 0 << "\n";
		return;
	}
	if(a == 1 && b == 1){
		cout << 2 << "\n";
		return;
	}
	if(b == a){
		cout << 2 << "\n";
		return;
	}
	if(b == 1){
		cout << (2 * (a % p)) % p << "\n";
		return;
	}

	ll n, k;
	n = b; k = a-b+1;

	// cout << n << ' ' << k << "\n";

	// for(ll i=1;i<10;i++){
	// 	for(ll j=1;j<10;j++){
	// 		n = i;
	// 		k = j;

			// clock_t time_req;
			// time_req = clock();
			sum = 0;
			for(ll l=0;l<n;l++){
				sum = (((sum % p) + (((nCrMODp(n-1, l, (ll)1e9+7)%p) * (nCrMODp(k+l, n, (ll)1e9+7)%p))%p))%p);
			}
			// time_req = clock()- time_req;
			// cout << (float)time_req/CLOCKS_PER_SEC << " seconds" << "\n";
			cout << (2 * (sum % p)) % p << "\n";
			// cout << i << " " << j << " " << sum << "\n";
			// cout << "\\\\\\\\\\\\\\\\\\\\\n";
	// 	}
	// 	cout << "\n";
	// }
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
	// cout << T << "\n";
	while(T--)
		te();

	return 0;
}