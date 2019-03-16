#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m;
vector<ll> par[3010];
ll grandPar[3010][3010];

void te(){
	for(ll i=0;i<3010;i++)
		for(ll j=0;j<3010;j++)
			grandPar[i][j] = 0;	

	cin >> n >> m;

	for(ll i=0;i<m;i++){
		ll a, b;
		cin >> a >> b;

		par[b].push_back(a);
	}

	for(ll i=1;i<=n;i++){
		for(ll j=0;j<par[i].size();j++){
			for(ll k=0;k<par[par[i][j]].size();k++){
				grandPar[i][par[par[i][j]][k]]++;
			}
		}
	}

	ll ans = 0;

	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			if(i != j)
				ans += ((grandPar[i][j]) * (grandPar[i][j] - 1)) / 2;

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