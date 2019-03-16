#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll h1, w1, h2, w2;

void te(){
	cin >> w1 >> h1 >> w2 >> h2;

	ll ans = 0;
	ans += 2*(h1 + h2);
	// ans += abs(w1 - w2);
	ans += 2 * (w1);
	ans += 4;

	cout << ans << "\n";
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