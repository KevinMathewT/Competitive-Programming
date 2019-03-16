#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[10010];

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll gcd = a[0];
	for(ll i=1;i<n;i++)
		gcd = __gcd(gcd, a[i]);

	if(gcd == 1){
		cout << -1 << "\n";
		return;
	}

	ll ans = 0;
	for(ll i=1;i*i<=gcd;i++){
		if(gcd % i == 0){
			ll cnt = 0;
			for(ll j=2;j*j<=i;j++){
				if(i % j == 0)
					cnt++;
			}

			if(cnt == 0 && i != 1)
				ans++;
			// cout << i << "\n";

			ll k = (gcd / i);
			if(k == i)
				continue;

			cnt = 0;
			for(ll j=2;j*j<=k;j++){
				if(k % j == 0)
					cnt++;
			}

			if(cnt == 0)
				ans++;
			// cout << k << "\n";
		}
	}

	cout << ans << "\n";
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