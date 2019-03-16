#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n;
ll a[20][20];
ll dp[20][20];

void te(){
	ll n;
	cin >> n;

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			cin >> a[i][j];

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			for(ll x=i-2;x<=i+2;x++)
				for(ll y=j-2;y<=j+2;j++){
					if(x < i && y < j || )
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