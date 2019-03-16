#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, k, m;

ll power(ll x, ll a){
	ll ans = 1;

	while(a > 0){
		if(a & 1){
			ans = ((ans % M) * (x % M)) % M;
		}

		x = ((x % M) * (x % M)) % M;
		a = (a >> 1);
	}

	return ans;
}

ll getModI(ll a){
	return power(a, M-2);
}

ll mod(ll a, ll b){
	return ((a % M) * (b % M)) % M;
}

void te(){
	ll ans = 0;
	cin >> n >> k >> m;


	ans = getModI(n);
	if(m == 1){
		cout << ans << "\n";
		return;
	}

	// cout << ans << "\n";
	ans = (ans + (((n-1) * (getModI(((n) * (n + k)) % M))) % M)) % M;
	
	if(m == 2){
		cout << ans << "\n";
		return;
	}

	ans = getModI(n);

	// cout << ans << "--\n";

	m -= 3;

	// cout << n << " " << k << "\n";
	ll x = ((n + k) % k) == 0 ? k : ((n + k) % k);
	// cout << x << "-\n";

	ll l = (m / 2) + 1;

	// cout << l << "--\n";

	ll a = (((n-1) * (getModI(((n) * (x)) % M))) % M);
	ll b = (((power(((x-1) * getModI(x)) % M, l) - 1 + M) % M) * getModI(((((x-1) * getModI(x)) % M) - 1 + M) % M)) % M;
	
	// cout << a << " " << b << "--------\n";

	ll c = mod(a, b);
	// cout << c << "\n";
	ll d = 0;

	if(m % 2 == 1){
		d = mod((n-1), mod(power(((x-1) * getModI(x)) % M, l), (getModI(((n) * (x + k)) % M)) % M));
	}

	// cout << d << "\n";

	ans = (ans + (c + d) % M) % M;

	cout << ans << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// cout << mod(7, getModI(26)) << "\n";
	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}