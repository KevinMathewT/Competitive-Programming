#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, a[200010], b[200010], mn;
ll x[100010], y[100010];

void te(){
	cin >> n >> m;
	for(ll i=0;i<m;i++)
		cin >> a[i] >> b[i];

	ll mx = 0;

	for(ll i=0;i<m;i++){
		x[a[i]-1]++;
		y[b[i]-1]++;
	}

	ll mx_pos = -1;

	for(ll i=0;i<n;i++){
		if(x[i] > mx){
			mx = max(mx, x[i]);
			mx_pos = i;
		}
	}

	for(ll i=0;i<n;i++){
		ll ans = mx * n - 1;
		if(x[i] == mx)
			cout << ans << "\n";
		else
			cout << ans + 1 << "\n";
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