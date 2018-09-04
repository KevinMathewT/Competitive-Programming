#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	string s;
	cin >> s;

	ll a[10], orig[10];
	for(ll i=0;i<10;i++){
		a[i] = s[i] - '0';
		orig[i] = s[i] - '0';
	}

	ll k;
	cin >> k;
	k = k % 62;
	// cout << k << "--\n";
	if(k == 0)
		k = 62;

	// cout << k << "\n";
	ll i = 0;
	for(ll i=0;i<k;i++){
		ll l = 0, r;
		for(ll j=0;j<10;j++){
			r = j == 9 ? 0 : a[j+1];
			ll t = a[j];
			a[j] = l ^ r;
			l = t;
		}
		// for(ll i=0;i<10;i++)
		// 	cout << a[i] << "";
		// cout << "\n";
		// ll flag = 1;
		// for(ll i=0;i<10;i++)
		// 	if(a[i] != orig[i])
		// 		flag = 0;
		// if(flag == 1)
		// 	break;
		// i++;
	}

	// cout << i << "-\n";

	for(ll i=0;i<10;i++)
		cout << a[i] << "";
	cout << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	// ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
	te();

	return 0;
}