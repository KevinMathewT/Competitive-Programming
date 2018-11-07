#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n, m;
	cin >> n >> m;

	ll a[n][m];
	string s;

	for(ll i=0;i<n;i++){
		cin >> s;
		for(ll j=0;j<m;j++)
			a[i][j] = s[j] - '0';
	}

	// for(ll i=0;i<n;i++){
	// 	for(ll j=0;j<m;j++)
	// 		cout << a[i][j] << " ";
	// 	cout << "\n" ;
	// }
	// cout << "\n\n";

	ll ans[n+m-1];
	for(ll i=0;i<n+m-1;i++)
		ans[i] = 0;

	for(ll i=1;i<=n+m-2;i++){
		for(ll j=0;j<n;j++){
			for(ll k=0;k<m;k++){
				if(a[j][k] == 1){
					for(ll l=0;l<=i;l++){
						ll t = ans[i];
						if(j+l < n && j+l >= 0 && k+i-l < m && k+i-l >= 0)
							ans[i] += a[j+l][k+i-l];
						if(j-l < n && j-l >= 0 && k+i-l < m && k+i-l >= 0 && l != 0 && (i - l) != 0)
							ans[i] += a[j-l][k+i-l];
						if(j+l < n && j+l >= 0 && k-i+l < m && k-i+l >= 0)
							ans[i] += a[j+l][k-i+l];
						if(j-l < n && j-l >= 0 && k-i+l < m && k-i+l >= 0 && (i - l) != 0 && l != 0)
							ans[i] += a[j-l][k-i+l];
						if(ans[i] != t){
							// cout << a[j+l][k+i-l] << " " << a[j-l][k+i-l] << " " << a[j+l][k-i+l] << " " << a[j-l][k-i+l] << "\n";
							// cout << j << ' ' << k << " " << i << " " << l << " " << t << " " << ans[i] << "\n";
						}
					}
				}
			}
		}
	}

	for(ll i=1;i<=n+m-2;i++)
		cout << ans[i] / 2 << " ";

	cout << "\n";
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