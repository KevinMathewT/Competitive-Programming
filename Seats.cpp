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

ll n, q, c;
set<pair<ll, pair<ll, ll> > > s1, s2, s3;
map<ll, ll> mp, rmp;

void solve(){
	c = 1;
	cin >> n >> q;
	mp[0] = 1;
	mp[n + 1] = 1;
	s1.insert({n, {-1, -n}});
	s2.insert({1, {n, n}});
	s3.insert({n, {1, n}});

	// cout << "Hello\n";

	while(q--){
		ll ty;
		cin >> ty;
		if(ty == 1){
			auto z = prev(s1.end());
			pair<ll, pair<ll, ll> > p = *z;
			// cout << p.F << " " << p.S.F << " " << p.S.S << "\n";
			// return;
			if(p.S.F == -1 && p.S.S == -n){
				s1.clear();
				s2.clear();
				s3.clear();
				s1.insert({n-1, {-2, -n}});
				s2.insert({2, {n, n-1}});
				s3.insert({n, {2, n-1}});
				mp[1] = 1;
				rmp[c++] = 1;
				cout << 1 << "\n";
				// return;
			}

			else if(p.S.F == -1){
				s1.erase(z);
				if(p.S.F != p.S.S){
					s1.insert({p.F - 1, {-2, p.S.S}});
					s2.erase(s2.lower_bound({1, {0, 0}}));
					s2.insert({2, {-p.S.S, p.F - 1}});
					s3.erase(s3.lower_bound({-p.S.S, {0, 0}}));
					s3.insert({-p.S.S, {2, p.F - 1}});
				}
				else{
					s2.erase(s2.lower_bound({1, {0, 0}}));
					s3.erase(s3.lower_bound({1, {0, 0}}));
				}
				mp[1] = 1;
				rmp[c++] = 1;
				cout << 1 << "\n";
			}

			else if(p.S.S == -n){
				// cout << "Here\n";
				// return;
				s1.erase(z);
				if(p.S.F != p.S.S){
					s1.insert({p.F - 1, {p.S.F, 1 - n}});
					s3.erase(s3.lower_bound({n, {0, 0}}));
					s3.insert({n - 1, {-p.S.F, p.F - 1}});
					s2.erase(s2.lower_bound({-p.S.F, {0, 0}}));
					s2.insert({-p.S.F, {n - 1, p.F - 1}});
				}
				else{
					s2.erase(s2.lower_bound({n, {0, 0}}));
					s3.erase(s3.lower_bound({n, {0, 0}}));
				}
				mp[n] = 1;
				rmp[c++] = n;
				cout << n << "\n";
			}

			else{
				s1.erase(z);
				ll pos = (-p.S.F-p.S.S) / 2;
				if(p.S.F == p.S.S){
					s2.erase(s2.lower_bound({-p.S.F, {0, 0}}));
					s3.erase(s3.lower_bound({-p.S.S, {0, 0}}));
				}
				else{
					s1.insert({pos + p.S.F, {p.S.F, -pos + 1}});
					s1.insert({-p.S.S - pos, {-pos-1, p.S.S}});
					s2.erase(s2.lower_bound({-p.S.F, {0, 0}}));
					s2.insert({-p.S.F, {pos-1, pos + p.S.F}});
					s2.insert({pos+1, {-p.S.S, -p.S.S - pos}});
					s3.erase(s3.lower_bound({-p.S.S, {0, 0}}));
					s3.insert({pos-1, {-p.S.F, pos + p.S.F}});
					s3.insert({-p.S.S, {pos+1, -p.S.S - pos}});
				}

				mp[pos] = 1;
				rmp[c++] = pos;
				cout << pos << "\n";
			}
		}
		if(ty == 2){
			ll banda;
			cin >> banda;
			banda = rmp[banda];
			if(mp[banda] == 0)
				continue;
			
			mp[banda] = 0;

			if(mp[banda - 1] == 1 && mp[banda + 1] == 1){
				s1.insert({1, {-banda, -banda}});
				s2.insert({banda, {banda, 1}});
				s3.insert({banda, {banda, 1}});
			}

			else if(mp[banda - 1] != 1 && mp[banda + 1] == 1){
				pair<ll, pair<ll, ll> > p = *s3.lower_bound({banda - 1, {0, 0}});
				cout << p.F << " " << p.S.F << " " << p.S.S << "\n";
				s3.erase(p);
				s1.erase(s1.lower_bound({p.S.S, {-p.S.F, -p.F}}));
				s2.erase(s2.lower_bound({p.S.F, {p.F, p.S.S}}));
				s1.insert({p.S.S + 1, {-p.S.F, -p.F - 1}});
				s2.insert({p.S.F, {p.F + 1, p.S.S + 1}});
				s3.insert({p.F + 1, {p.S.F, p.S.S + 1}});
			}

			else if(mp[banda - 1] == 1 && mp[banda + 1] != 1){
				pair<ll, pair<ll, ll> > p = *s2.lower_bound({banda + 1, {0, 0}});
				s2.erase(p);
				s1.erase(s1.lower_bound({p.S.S, {-p.F, -p.S.F}}));
				s3.erase(s3.lower_bound({p.S.F, {p.F, p.S.S}}));
				s1.insert({p.S.S + 1, {-p.F + 1, -p.S.F}});
				s2.insert({p.F - 1, {p.S.F, p.S.S + 1}});
				s3.insert({p.S.F, {p.F - 1, p.S.S + 1}});
			}

			else{
				pair<ll, pair<ll, ll> > p1 = *s3.lower_bound({banda - 1, {0, 0}});
				pair<ll, pair<ll, ll> > p2 = *s2.lower_bound({banda + 1, {0, 0}});

				// cout << p1.F << " " << p1.S.F << " " << p1.S.S << "\n";
				// cout << p2.F << " " << p2.S.F << " " << p2.S.S << "\n";
				//////////

				s3.erase(p1);
				s1.erase(s1.lower_bound({p1.S.S, {-p1.S.F, -p1.F}}));
				s2.erase(s2.lower_bound({p1.S.F, {p1.F, p1.S.S}}));

				s2.erase(p2);
				s1.erase(s1.lower_bound({p2.S.S, {-p2.F, -p2.S.F}}));
				s3.erase(s3.lower_bound({p2.S.F, {p2.F, p2.S.S}}));

				//////////

				ll l = p1.S.F, r = p2.S.F, s = p1.S.S + p2.S.S + 1;
				s1.insert({s, {-l, -r}});
				s2.insert({l, {r, s}});
				s3.insert({r, {l, s}});
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	// ios::sync_with_stdio(false);			//Not
	// cin.tie(NULL);							//this.
	// cout.tie(0);							//or this.

	solve();

	return 0;
}