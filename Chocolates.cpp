#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[200010];

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll last = LLONG_MAX;
	ll ans = 0;

	for(ll i=n-1;i>=0;i--){
		ll tem = min(last, a[i]);
		// cout << tem << "\n";
		ans += max((ll)0, min(last, a[i]));
		last = tem - 1;
	}

	cout << ans << "\n";
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