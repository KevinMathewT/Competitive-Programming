#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n, a, b;
	cin >> n >> a >> b;

	unordered_map<ll, ll> vis;
	ll c = 0;

	for(ll i=0;i<=n;i++)
		for(ll j=0;j+i<=n;j++){
			ll m = i * a - j * b;
			if(vis[m] != 1){
				// cout << m << "\n";
				vis[m] = 1;
				c++;
			}
		}

	cout << c << "\n";
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