#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n;
char a[510][510];

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			cin >> a[i][j];

	// cout << "HEY\n";
	ll ans = 0;
	for(ll i=1;i<n-1;i++)
		for(ll j=1;j<n-1;j++)
			if(a[i][j] == 'X' && a[i+1][j-1] == 'X' && a[i-1][j+1] == 'X' && a[i+1][j+1] == 'X' && a[i-1][j-1] == 'X')
				ans++;

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