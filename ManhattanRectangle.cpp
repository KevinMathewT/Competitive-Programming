#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll x = (ll) 1000000000;

void te(){
	ll dist1, dist2, dist3, xl, yl, xh, yh;
	
	cout << "Q " << 0 << " " << 0 << "\n";
	cout << flush;
	cin >> dist1;

	cout << "Q " << 0 << " " << x << "\n";
	cout << flush;
	cin >> dist2;

	cout << "Q " << x << " " << 0 << "\n";
	cout << flush;
	cin >> dist3;

	cout << "Q " << 0 << " " << ((dist1 - dist2 + x) / 2) << "\n";
	cout << flush;
	cin >> xl;

	yl = dist1 - xl;
	yh = xl - dist2 + x;
	xh = (x) + yl - dist3;

	cout << "A " << xl << " " << yl << " " << xh << " " << yh << "\n";
	cout << flush;
	ll yes;
	cin >> yes;
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