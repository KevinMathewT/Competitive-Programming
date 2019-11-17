#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, k;

ll gcd(ll a, ll b, ll &x, ll &y){
    if (a == 0){
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void te(){
	cin >> n >> m >> k;
	
	if(n % m == 0){
		cout << 0 << "\n";
		return;
	}
	if(k == 0){
		cout << -1 << "\n";
	}

	ll x, y, g;
	bool sol = find_any_solution(k, m, n, x, y, g);
	if(!sol){
		cout << -1 << "\n";
		return;
	}

	ll l = 0, r = 10000000;
	ll ans = 1000000000000;
	while(l < r){
		ll mid = (l + r) / 2;
		ll s = x + mid * (m / g);
		cout << mid << " " << s << "\n";
		if(s < 0)
			l = (mid + 1);
		else{
			ans = min(ans, mid);
			r = mid - 1;
		}
	}

	cout << ans << "\n";
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