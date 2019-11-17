#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, x, y, a[100010], b[100010];
pair<ll, pair<ll, ll> > d[100010];

void solve(){
	cin >> n >> x >> y;
	for(ll i=0;i<n;i++)
		cin >> a[i];
	for(ll i=0;i<n;i++)
		cin >> b[i];
	for(ll i=0;i<n;i++)
		d[i] = { abs(a[i] - b[i]), { a[i], b[i] } };
	sort(d, d + n);
	ll tot = 0, andy = 0, bob = 0;

	for(ll i=n-1;i>=0;i--){
		if((bob >= y) || (d[i].S.F > d[i].S.S && andy < x)){
			tot += d[i].S.F;
			andy++;
		}
		else{
			tot += d[i].S.S;
			bob++;
		}
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

	solve();

	return 0;
}