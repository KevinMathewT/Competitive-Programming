#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, x, y;

ll numberOfNonSeeable(ll a, ll b){
	ll tot = (n * m) - (n - 1) - (m - 1) - 1;
	// cout << tot << "\n";
	tot -= min(a-1, b-1);
	tot -= min(a-1, m-b);
	tot -= min(n-a, b-1);
	tot -= min(n-a, m-b);
	// cout << tot << "\n";

	if(abs(x-a) == abs(y-b)){
		if(x-a < 0 && y-b < 0)
			tot += min(a-1, b-1) - abs(x-a);
		if(x-a < 0 && y-b > 0)
			tot += min(a-1, m-b) - abs(x-a);
		if(x-a > 0 && y-b < 0)
			tot += min(n-a, b-1) - abs(x-a);
		if(x-a > 0 && y-b > 0)
			tot += min(n-a, m-b) - abs(x-a);
	// cout << tot << "\n";
	}
	else if(x == a){
		if(y > b)
			tot += m - y;
		else
			tot += y - 1;
	// cout << tot << "\n";
	}	
	else if(y == b){
		if(x > a)
			tot += n - x;
		else
			tot += x - 1;
	// cout << tot << "\n";
	}
	else{
		tot -= 1;
	// cout << tot << "\n";
	}
	// cout << tot << "\n";
	// cout << "\n";

	return tot;
}

void te(){
	cin >> n >> m >> x >> y;

	ll tot = 0;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
			if((i == x && j == y))
				continue;
			else{
				// cout << i << " " << j << " " << numberOfNonSeeable(i, j) << "\n";
				tot += numberOfNonSeeable(i, j);
			}

	cout << tot << "\n";
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