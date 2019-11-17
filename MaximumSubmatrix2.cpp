#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, a[5010][5010];

void te(){
	cin >> n >> m;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++){
			char c; cin >> c;
			a[j][i] = c - '0';
		}

	for(ll i=0;i<n;i++)
		for(ll j=m-1;j>=0;j--)
			if(a[j][i] == 1)
				a[j][i] = a[j+1][i] + 1;

	for(ll i=0;i<m;i++)
		sort(a[i], a[i] + n);

	ll ans = -1;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			ans = max(ans, (n - i) * a[j][i]);

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