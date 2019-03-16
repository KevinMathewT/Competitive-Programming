#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll l, r, a = 0, b = 0, x = -1, dp[70];

void te(){
	cin >> l >> r;
	ll p = ((ll)1 << (ll)log2(r));

	if(l == r){
		cout << 0 << "\n";
		return;
	}

	while(p){
		if(r & p){
			a += p;
			b = a-1;

			if(a >= l && a <= r && b >= l && b <= r)
				x = max(x, a ^ b);
		}

		p /= 2;
	}

	cout << x << "\n";
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