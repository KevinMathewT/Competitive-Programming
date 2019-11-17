#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?
 
ll n, x[100010], y[100010], s, bord, angle[100010];
vector<pair<ld, ld> > v;
pair<ld, ld> center;

bool lessFun(pair<ld, ld> a, pair<ld, ld> b)
{
    if (a.F - center.F >= 0 && b.F - center.F < 0)
        return true;
    if (a.F - center.F < 0 && b.F - center.F >= 0)
        return false;
    if (a.F - center.F == 0 && b.F - center.F == 0) {
        if (a.S - center.S >= 0 || b.S - center.S >= 0)
            return a.S > b.S;
        return b.S > a.S;
    }

    ll det = (a.F - center.F) * (b.S - center.S) - (b.F - center.F) * (a.S - center.S);
    if (det < 0)
        return true;
    if (det > 0)
        return false;
    ll d1 = (a.F - center.F) * (a.F - center.F) + (a.S - center.S) * (a.S - center.S);
    ll d2 = (b.F - center.F) * (b.F - center.F) + (b.S - center.S) * (b.S - center.S);
    return d1 > d2;
}

ll gcd(ll a,ll b){
	a = abs(a);
	b = abs(b);		
	while (a && b) a > b ? a -= b : b -= a;
	return a + b;
}
 
void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		v.push_back({0, 0});
	for(ll i=0;i<n;i++)
		cin >> v[i].F >> v[i].S;

	center.F = 0;
	center.S = 0;
	for(ll i=0;i<n;i++)
		center.F += v[i].F, center.S = v[i].S;

	center.F /= n;
	center.S /= n;

	sort(v.begin(), v.end(), lessFun);

	for(ll i=0;i<n;i++)
		x[i] = v[i].F, y[i] = v[i].S;

	ll mnx = 0, mny = 0;
	for(ll i=0;i<n;i++)
		mnx = min(mnx, x[i]), mny = min(mny, y[i]);
	for(ll i=0;i<n;i++){
		// cout << x[i] << ' ' << y[i] << " ";
		x[i] -= mnx, y[i] -= mny;
		// cout << x[i] << ' ' << y[i] << "\n";
	}

	x[n] = x[0];
	y[n] = y[0];

	for(ll i=0;i<n;i++)
		s += 1ll * x[i+1] * y[i] - 1ll * x[i] * y[i+1];
	for(ll i=0;i<n;i++)
		bord += gcd(y[i+1] - y[i], x[i+1] - x[i]);
	 
	cout << (s + 2 - bord) / 2 << endl;
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}