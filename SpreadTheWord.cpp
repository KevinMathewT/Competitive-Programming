#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n;
	cin >> n;
	ll a[n];
	for(ll i=0;i<n;i++) cin >> a[i];
	ll cum[n];
	cum[0] = a[0];
	for(ll i=1;i<n;i++) cum[i] = cum[i-1]+a[i];

	ll i = 0, jumps = 0;
	while(i < n-1){
		jumps++;
		// cout << i << "-\n";
		i += cum[i];
	}

	cout << jumps << "\n";
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
	while(T--)
		te();

	return 0;
}