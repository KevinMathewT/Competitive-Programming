#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n, q;
	cin >> n >> q;
	ll size = (ll)10*(1e6)+10;
	ll x[n], y[n], r[n], d[size];
	for(ll i=0;i<n;i++)
		cin >> x[i] >> y[i] >> r[i];
	for(ll i=0;i<size;i++)
		d[i] = 0;

	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			ld a = ((ld)(x[j]-x[i]));
			ld b = ((ld)(y[j]-y[i]));
			ld c = sqrt((a*a) + (b*b));
			// cout << a << " " << b << " " << c << "\n";
			ll left, right;
			if(c + r[j] < r[i] || c + r[i] < r[j]){
				ll y = min(r[i], r[j]);
				ll z = max(r[i], r[j]);
				left = (ll) ceil(z - (c + y));
				right = (ll) floor(z + (c + y));
			}
			else{
				left = (ll) ceil(max(0.0, c-(r[i]+r[j])));
				right = (ll) floor(c+(r[i]+r[j]));
			}
			// cout << left << " " << right << "\n";
			// ll l = (ll)ceil(max(0.0, sqrt(((ld)(x[j]-x[i]))*((ld)(x[j]-x[i])) + ((ld)(y[j]-y[i]))*((ld)(y[j]-y[i]))) - (r[i] + r[j])));
			// ll r = (ll)floor(sqrt(((ld)(x[j]-x[i]))*((ld)(x[j]-x[i])) + ((ld)(y[j]-y[i]))*((ld)(y[j]-y[i]))) + (r[i] + r[j]) + min(0, sqrt(((ld)(x[j]-x[i]))*((ld)(x[j]-x[i])) + ((ld)(y[j]-y[i]))*((ld)(y[j]-y[i]))) - (r[i] + r[j])));
			d[left]++; d[right+1]--;
		}
	}

	for(ll i=1;i<size;i++)
		d[i] = d[i] + d[i-1];

	// for(ll i=0;i<25;i++)
	// 	cout << d[i] << " ";
	// cout << "\n";

	while(q--){
		ll k;
		cin >> k;
		cout << d[k] << "\n";
	}

}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}