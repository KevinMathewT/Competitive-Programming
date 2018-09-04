#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew

void te(){
	ll a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a+3);
	ll tot = 0;
	tot += a[0];
	a[1] -= a[0];
	a[2] -= a[0];
	tot += min(a[1], a[2]/2);
	ll x = a[1] - min(a[1], a[2]/2);
	ll y = a[2] - 2 * min(a[1], a[2]/2);	

	// cout << x << " " << y << "\n";
	tot += min(y, x/2);

	cout << tot << "\n";
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