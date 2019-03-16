#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll m, n, v;

void te(){
	cin >> m >> n >> v;
	ll g = __gcd(m, n);
	// cout << max(m, n) << "\n";

	if(v % g == 0 && (v <= max(m, n)))
		cout << "YES\n";
	else
		cout << "NO\n";
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