#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, r[510], lower, upper;

ll gcd(ll a, ll b){ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
}

ll lcm(ll a, ll b){
	// cout << gcd(a, b) << "\n";
	ll ans1 = (a / gcd(a, b));
	ll ans2 = b;

	// cout << ans1 * ans2 << "\n";

	ld fact = ((ld)upper) / ((ld)ans2);
	if(((ld)ans1) > ((ld)fact))
		return -1;

	ll ans = ans1 * ans2;
	if(ans > upper)
		return -1;
	return ans;
}

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> r[i];
	// sort(r, r+n);

	cin >> lower >> upper;
	// cout << lower << " " << upper << "\n";

	ll lc;
	if(n == 1)
		lc = r[0];
	else
		lc = lcm(r[0], r[1]);
	
	if(lc == -1){
		cout << (upper - lower + 1) << "\n";
		return;
	}

	for(ll i=2;i<n;i++){
		lc = lcm(lc, r[i]);
		if(lc == -1){
			cout << (upper - lower + 1) << "\n";
			return;
		}
	}

	// cout << lc << "-\n";
	if(lc == -1){
		cout << (upper - lower + 1) << "\n";
		return;
	}

	ll start = (lower % lc == 0) ? lower : ((lower / lc) * lc + lc);
	ll end = (upper % lc == 0) ? upper : ((upper / lc) * lc);

	// cout << start << " " << end << "\n";

	if(start > end)
		cout << (upper - lower + 1) << "\n";
	else{
		cout << (upper - lower + 1) - (((end - start) / lc + 1)) << "\n";
	}
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