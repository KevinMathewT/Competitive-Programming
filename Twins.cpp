#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew

void te(){
	ll n; cin >> n;
	ll a[n]; for(ll i=0;i<n;i++) cin >> a[i];
	sort(a, a+n);
	ll sum = 0;
	for(ll i=0;i<n;i++) sum += a[i];

	ll tot = 0;
	ll count = 0;
	for(ll i=n-1;i>=0;i--){
		tot += a[i];
		count++;
		if(tot > sum-tot)
			break;
	}

	cout << count << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	// ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}