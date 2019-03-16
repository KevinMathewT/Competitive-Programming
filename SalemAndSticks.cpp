#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[1010], ans = LLONG_MAX, z;

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	for(ll i=1;i<=101;i++){
		ll cost = 0;
		for(ll j=0;j<n;j++){
			if(i == a[j])
				cost += 0;
			else
				cost += abs(a[j]-i)-1;
		}

		if(cost < ans){
			ans = cost;
			z = i;
		}
	}

	cout << z << " " << ans << "\n";
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