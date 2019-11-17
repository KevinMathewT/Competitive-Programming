#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll a, b, c, d;

ll mod_inverse(ll a, ll m){
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1) 
      return 0; 
    while (a > 1){
        ll q = a / m; 
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y; 
        x = t; 
    }
    if(x < 0)
       x += m0;
    return x;
}

ll mod_pow(ll x, ll y){
	if(y == 0)
		return 1;
	if(y == 1)
		return x;
	if(y % 2 == 0)
		return mod_pow((x * x) % d, y / 2);
	return ((mod_pow((x * x) % d, y / 2) * x) % d);
}

void te(){
	cin >> a >> b >> c >> d;
	ll f = mod_pow(a, b);
	ll s = mod_inverse(c, d);

	// cout << f << " " << s << "\n";
	cout << ((f * s) % d) << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}