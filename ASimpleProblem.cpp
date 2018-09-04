#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll size = 1e3+100;

void te(){
	ll n; cin >> n;
	ll a[n]; for(ll i=0;i<n;i++) cin >> a[i];

	ll fact[size];
	for(ll i=0;i<size;i++) fact[i] = i;

	for(ll i=2;i*i<size;i++){
		if(fact[i] == i)
			for(ll j=i*i;j<size;j+=i)
				fact[j] = i;
	}

	// for(ll i=0;i<size;i++) cout << i << " " << fact[i] << "\n";

	ll cum[n];
	map<ll, ll> m;

	for(ll i=0;i<n;i++)
		m[i] = 1;

	for(ll i=0;i<n;i++){
		ll count = 0;
		ll t = a[i];
		while(true){
			if(m.find(t) != m.end())
				count++;
			if(fact[t] == t)
				break;
			else
				t /= fact[t];
			cout << a[i] << " " << t << "\n";
		}
		cum[i] = count;
		cout << count << "-\n";
	}
	cout << "\n";

	for(ll i=1;i<n;i++)
		cum[i] = cum[i] + cum[i-1];

	ll q;
	cin >> q;
	while(q--){
		ll l, r;
		cin >> l >> r;
		if(l != 0)
			cout << cum[r] - cum[l] << "\n";
		else
			cout << cum[r] << "\n";
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