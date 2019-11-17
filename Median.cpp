#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, h, w, a[1010][1010], arr[1000010];

void te(){
	cin >> n >> m >> h >> w;
	// for(ll i=0;i<n;i++)
	// 	for(ll j=0;j<m;j++)
	// 		cin >> a[i][j];

	ll c = 0;
	ll ans = LLONG_MAX;
	for(ll i=0;i+h<=n;i++){
		for(ll j=0;j+w<=m;j++){
			ll pos = 0;
			for(ll k=i;k<i+h;k++)
				for(ll l=j;l<j+w;l++)
					c++;
					// arr[pos++] = a[k][l];
			// sort(arr, arr+pos);
			// for(ll o=0;o<pos;o++)
			// 	cout << arr[o] << " ";
			// cout << "\n";
			// cout << arr[pos/2] << "\n";
			// ans = min(ans, arr[pos/2]);
		}
	}

	cout << c << "\n";

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