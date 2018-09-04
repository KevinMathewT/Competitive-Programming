#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void te(){
	ll n; cin >> n;
	ll a[n]; for(ll i=0;i<n;i++) cin >> a[i];

	ll h = 0, cost = 0, energy = 0;
	for(ll i=0;i<n;i++){
		if((energy+h)-a[i] < 0){
			cost += abs((energy+h)-a[i]);
			energy = 0;
		}
		else
			energy += (h-a[i]);
		h = a[i];
	}
	cout << cost << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this
	// ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(NULL);							//or this.

	te();

	return 0;
}