#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[1000010], b[1000010];
unordered_map<ll, ll> um;

void te(){
	cin >> n;
	um.clear();
	for(ll i=1;i<=n;i++)
		cin >> a[i];
	for(ll i=1;i<=n;i++)
		cin >> b[i];

	b[0] = 0;
	for(ll i=1;i<=n;i++)
		b[i] = b[i-1] + b[i];

	ll mx = -1;
	ll s = 0;
	for(ll i=1;i<=n;i++){
		if(um[a[i]] != 0)
			s = max(s, um[a[i]]);
		um[a[i]] = i;
		mx = max(mx, b[i]-b[s]);
	}

	cout << mx << "\n";
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