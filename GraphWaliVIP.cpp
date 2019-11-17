#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, vis[100010];

void te(){
	cin >> n;
	for(ll i=0;i<100010;i++)
		vis[i] = 0;
	if(n == 1){
		cout << 0 << "\n";
		return;
	}
	if(n == 2){
		cout << 1 << "\n";
		return;
	}

	vis[2] = 1;

	for(ll i=2;i*2<=n;i++)
		for(ll j=i;j<=n;j+=i)
			vis[j] = 1;

	ll ans = 0;
	for(ll i=2;i<=n;i++)
		ans += 1 - vis[i];

	cout << ans + 1 << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}