#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ld a1, a2, b1, b2, c1, c2;

void te(){
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

	ld x = ((b2*a1) - (b1*a2)) / (b2-b1);

	// cout << x << "\n";

	ld dist = ((((x - (a1*a1)) - c1) / b1) - (((x - (a2*a2)) - c2) / b2));
	

	cout << dist << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.
	cout << setprecision(6) << fixed;

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}