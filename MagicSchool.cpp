#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n, a[100000+10];

	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll f = *max_element(a, a+n);
	ll p = *min_element(a, a+n);

	// cout << f << " " << p << "\n";

	if(n == 1){
		if(f > 1 || f < 0)
			cout << -1 << "\n";
		else if(f == 0)
			cout << n - 0 << "\n";
		else
			cout << -1 << "\n";

		return;
	}

	if(f >= p+2 || f < p){
		cout << -1 << "\n";
		return;
	}

	if(f == p){
		if(f == 0)
			cout << n - 0 << "\n";
		else if(f == n-1)
			cout << 0 << "\n";
		else
			cout << -1 << "\n";

		return;
	}

	ll fail = 0, pass = 0;

	for(ll i=0;i<n;i++){
		if(a[i] == f)
			fail++;
		if(a[i] == p)
			pass++;
	}

	if(f != pass || p+1 != pass || (fail + pass != n)){
		// cout << f << " " << p << " " << fail << " " << pass << "\n";
		cout << -1 << "\n";
		return;	
	}

	cout << fail << "\n";
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