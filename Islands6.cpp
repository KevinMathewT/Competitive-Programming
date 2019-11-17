#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, e, a[1010];

void te(){
	cin >> n >> e;
	for(ll i=0;i<n;i++)
		a[i] = 0;
	for(ll i=0;i<e;i++){
		ll u, v;
		cin >> u >> v;
		a[u]++;
		a[v]++;
	}

	for(ll i=0;i<n-1;i++)
		if(a[i] != a[i+1]){
			cout << "no\n";
			return;
		}

	cout << "yes\n";
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