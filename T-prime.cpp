#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew

void te(){
	ll size = 1e6+10;
	ll a[size];
	for(ll i=0;i<size;i++) a[i] = 1;

	for(ll i=2;i*i<=size;i++)
		if(a[i] == 1){
			a[i] = 1;
			for(ll j = i*i;j<size;j+=i)
				a[j] = 0;
		}

	a[1] = 0;
	a[0] = 0;
	// for(ll i=0;i<size;i++)
	// 	cout << i << " " << a[i] << "\n";

	ll t; cin >> t;
	while(t--){
		ll n; cin >> n;
		if((ll)sqrt(n) * (ll)sqrt(n) != n){
			cout << "NO\n";
			continue;
		}

		if(a[(ll)sqrt(n)] != 1)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	// ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}