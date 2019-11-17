#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, q, t[4 * 1000010], a[1000010];

void build(ll v, ll tl, ll tr) {
    if (tl == tr) {
    	if(a[tl] > 0)
    		t[v] = 1;
    	else if (a[tl] < 0)
    		t[v] = -1;
    	else
    		t[v] = 0;
    } else {
        ll tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = t[v*2] * t[v*2+1];
    }
}

ll product(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return 1;
    if (l == tl && r == tr) {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return product(v*2, tl, tm, l, min(r, tm)) * product(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
    	if(new_val > 0)
    		t[v] = 1;
    	else if (new_val < 0)
    		t[v] = -1;
    	else
    		t[v] = 0;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = t[v * 2] * t[v * 2 + 1];
    }
}

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	build(1, 0, n - 1);

	cin >> q;

	while(q--){
		ll t, a, b;
		cin >> t >> a >> b;

		if(t == 1)
			update(1, 0, n-1, a-1, b);
		if(t == 2){
			ll ans = product(1, 0, n-1, a-1, b-1);
			if(ans == -1)
				cout << "NEGATIVE\n";
			else if(ans == 1)
				cout << "POSITIVE\n";
			else
				cout << "ZERO\n";
		}
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
		solve();

	return 0;
}