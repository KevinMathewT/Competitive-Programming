#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Shubham Kumar
// Birla Institute of Technology, Mesra

ll n, m, r, s[100], b[100];

void te(){
	cin >> n >> m >> r;
	for(ll i=0;i<n;i++)
		cin >> s[i];
	for(ll i=0;i<m;i++)
		cin >> b[i];

	ll mx = r;
	for(ll i=0;i<n;i++){
		ll curr = r / s[i];
		for(ll j=0;j<m;j++)
			mx = max(mx, (r - curr * s[i]) + (b[j] * curr));
	}

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