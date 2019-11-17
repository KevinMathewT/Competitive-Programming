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

map<ll, ll> parent, ranks, encountered;
ll n, q, s;

void make_set(ll v) {
    parent[v] = v;
}

ll find_set(ll v) {
	// cout << v << "----\n";
    if (parent[v] == v || (v > 1 && encountered[v] == 0) || (v == 1 && parent[v] == -1))
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b){
    a = find_set(a);
    // cout << "----------\n";
    b = find_set(b);
    // cout << "----------\n";
    // cout << a << " " << b << "\n";
    // cout << parent[a] << " " << parent[b] << "\n";
    if (a != b)
        parent[a] = b;

    // cout << a << " " << b << "\n";
    // cout << parent[a] << " " << parent[b] << "////\n";
}

void solve(){
	cin >> n >> q;
	parent.clear();
	ranks.clear();
	encountered.clear();
	parent[1] = -1;
	s = 0;

	while(q--){
		ll t;
		cin >> t;

		if(t == 1){
			ll y;
			cin >> y;
			// cout << y << "//////////////////////\n";
			ll x = (y + s);
			if(encountered[x] == 0){
				make_set(x);
				encountered[x] = 1;
			}
			if(encountered[x-1] == 0){
				make_set(x-1);
				encountered[x-1] = 1;
			}

			union_sets(x, x - 1);
		}

		if(t == 2){
			ll p, q;
			cin >> p >> q;

			p = (p + s);
			q = (q + s);
			// cout << p << " " << q << "-\n";

			if(encountered[q] == 0){
				// cout << "YES\n";
				s = (s + q) % n;
				cout << q << "\n";
			}
			else{
				ll par = find_set(q);
				// cout << par << "--\n";
				if(par < p){
					cout << 0 << "\n";
					continue;
				}
				else{
					cout << par << "\n";
					s = (s + par) % n;
				}
			}
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