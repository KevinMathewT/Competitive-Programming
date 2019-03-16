#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, k;
ll a[2000010], pre[2000010];

ll power(ll x, ll a){
	ll ans = 1;
	// cout << a << " ";
	// cout << x << " ";
 	while(a > 0){
		if(a & 1)
			ans = ((ans%M) * (x%M)) % M;
		x = ((x%M) * (x%M)) % M;
		a /= 2;
	}
	// cout << "-" << ans << "\n";
	return ans;
}

void te(){
	cin >> n >> k;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll s[k];
	for(ll i=0;i<k;i++){
		if(i == 0)
			pre[0] = a[0];
		else
			pre[i] = a[i] + pre[i-1];
		s[i] = 0;
	}

	for(ll i=0;i<n;i++){
		ll t = 0;
		for(ll j=i;j<n;j++){
			t = (t + a[j]) % M;
			// cout << t << "-";
			for(ll i=0;i<k;i++){
				s[i] = (s[i] + power(t, i+1)) % M;
			}
		}
		// cout << "\n";
	}

	for(ll i=0;i<k;i++)
		cout << s[i] << " ";
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