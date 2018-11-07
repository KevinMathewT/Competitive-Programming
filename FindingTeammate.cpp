#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll power(ll x, ll y, ll m){
	// cout << x << " " << y << "\n";
	if(y == 1) return x % m;
	if(y == 0) return 1;
	if(y % 2 == 0)
		return power(((x % m) * (x % m)) % m, y / 2, m) % m;
	return (((x % m) * (power(((x % m) * (x % m)) % m, y / 2, m) % m)) % m);
}

ll modInverse(ll a, ll m){
	// cout << a << " " << m << " " << power(a, m-2, m) << "\n";
    return power(a, m-2, m) % m; 
}

void te(){
	ll n;
	cin >> n;
	cout << n << "-\n";
	ll s[n];
	for(ll i=0;i<n;i++){
		cin >> s[i];
		cout << s[i] << "--\n";
	}

	sort(s, s+n);

	vector<ll> v;

	ll c = 1;
	for(ll i=n-2;i>=0;i--)
		if(s[i] != s[i+1]){
			v.push_back(c);
			c = 1;
		}
		else
			c++;
	v.push_back(c);

	ll p = (ll) 1e9 + 7;

	for(ll i=0;i<v.size();i++)
		cout << v[i] << "\n";

	// ll tot = 0;
	// for(ll i=0;i<v.size();i++){
	// 	if(v[i] % 2 == 0)
	// 		tot += ((((v[i] % p) * ((v[i]-1) % p)) % p) * (modInverse(2, p) % p)) % p;
	// 	else{
	// 		tot += ((((v[i] % p) * (v[i+1] % p)) % p) * (((((v[i]-1) % p) * ((v[i]-2) % p)) % p) * (modInverse(2, p) % p))) % p;
	// 		v[i+1]--;
	// 	}
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
	cout << T << "\n";
	while(T--)
		te();

	return 0;
}