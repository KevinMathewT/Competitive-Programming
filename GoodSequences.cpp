#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[100010], dp[100010], fact[100010];

void te(){
	for(ll i=0;i<100010;i++)
		fact[i] = 0;
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	dp[0] = 1;
	for(ll i=1;i*i<=a[0];i++)
		if(a[0] % i == 0){
			if(i != 1)
				fact[i] = dp[0];
			fact[a[0]/i] = dp[0];
		}

	ll mx = LLONG_MIN;
	for(ll i=1;i<n;i++){
		mx = 0;
		for(ll j=1;j*j<=a[i];j++){
			if(a[i] % j == 0){
				if(j != 1)
					mx = max(fact[j], mx);
					mx = max(fact[a[i]/j], mx);
			}
		}

		mx++;
		// cout << mx << "\n";
		dp[i] = mx;
		for(ll j=1;j*j<=a[i];j++){
			if(a[i] % j == 0){
				if(j != 1)
					fact[j] = max(fact[j], mx);
					fact[a[i]/j] = max(fact[a[i]/j], mx);
			}
		}
	}

	mx = 1;

	for(ll i=0;i<n;i++)
		mx = max(mx, dp[i]);

	cout << mx << "\n";
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