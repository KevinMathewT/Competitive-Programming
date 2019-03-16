#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n;

void te(){
	cin >> n;
	ll a[n], gcdl[n], gcdr[n];

	for(ll i=0;i<n;i++){
		cin >> a[i];
		gcdl[i] = gcdr[i] = 0;
	}

	gcdl[1] = a[0];
	gcdr[n-2] = a[n-1];
	for(ll i=2;i<n;i++){
		gcdl[i] = __gcd(a[i-1], gcdl[i-1]);
		gcdr[n-i-1] = __gcd(a[n-i-1+1], gcdr[n-i-1+1]);
		// cout << a[i+1] << " " << gcdr[i+1] << "\n";
	}

	// for(ll i=0;i<n;i++)
	// 	cout << gcdl[i] << " ";
	// cout << "\n";

	// for(ll i=0;i<n;i++)
	// 	cout << gcdr[i] << " ";
	// cout << "\n";

	ll gk = a[0];
	for(ll i=1;i<n;i++)
		gk = __gcd(a[i], gk);

	if(gk > 1){
		cout << "COMPLETELY FINE!\n";
		return;
	}

	for(ll i=0;i<n;i++){
		ll g;
		if(i == 0)
			g = gcdr[i];
		else if(i == 1)
			g = __gcd(a[0], gcdr[i]);
		else if(i == n-1)
			g = gcdl[i];
		else if(i == n-2)
			g = __gcd(a[n-1], gcdl[i]);
		else
			g = __gcd(gcdl[i], gcdr[i]);

		// cout << g << " ";

		if(g != 1){
			cout << a[i] << "\n";
			return;
		}
	}
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