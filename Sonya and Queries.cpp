// Kevin Mathew T
// Birla Institute of Technology, Mesra
// LinkedIn - https://www.linkedin.com/in/KevinMathewT/
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second
#define fi(a, b) for(ll i=(a);i<=b;i++)
#define fj(a, b) for(ll j=(a);j<=b;j++)
#define fid(a, b) for(ll i=(a);i>=b;i--)
#define fjd(a, b) for(ll j=(a);j>=b;j--)

// #include <ext/pb_ds/assoc_container.hpp> // Common file 
// #include <ext/pb_ds/tree_policy.hpp> 
// #include <functional> // for less 
// #include <iostream> 
// using namespace __gnu_pbds; 
// using namespace std; 
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// find_by_order(k) : Value at kth index in sorted array. 
// order_of_key(k) : Index of the value k.

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    os << "]";
	return os;
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator<<(ostream &os, multiset<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, unordered_map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}


const ll N = 100010, M = 1e9 + 7;
ll n;
set<pair<ll, ll> > s1;
set<pair<string, ll> > s2;

void solve(){
	cin >> n;

	fi(0, n - 1) {
		char c;
		cin >> c;

		// cout << s1 << '\n';
		// cout << s2 << '\n';

		if(c == '+') {
			ll x; cin >> x;
			if(s1.lower_bound({x, 0}) == s1.end() || (*s1.lower_bound({x, 0})).F != x) {
				s1.insert({x, 1});

				string ns = to_string(x);
				fi(1, 18 - ns.size)
				fi(0, ns.size() - 1) if((ns[i] - '0') % 2 == 0) ns[i] = '0'; else ns[i] = '1';

				fi(0, ns.size() - 1) {
					string s = ns.substr(i, ns.size() - i);
					if(s2.lower_bound({s, 0}) == s2.end() || (*s2.lower_bound({s, 0})).F != s) {
						s2.insert({s, 1});
					} else {
						pair<string, ll> p1 = *s2.lower_bound({s, 0});
						p1.S++;
						s2.erase(s2.lower_bound({s, 0}));
						s2.insert(p1);
					}
				}
			} else {
				pair<ll, ll> p = *s1.lower_bound({x, 0});
				s1.erase(s1.lower_bound(p));
				p.S++;
				s1.insert(p);


				string ns = to_string(x);
				fi(0, ns.size() - 1) if((ns[i] - '0') % 2 == 0) ns[i] = '0'; else ns[i] = '1';

				fi(0, ns.size() - 1) {
					string s = ns.substr(i, ns.size() - i);
					if(s2.lower_bound({s, 0}) == s2.end() || (*s2.lower_bound({s, 0})).F != s) {
						s2.insert({s, 1});
					} else {
						pair<string, ll> p1 = *s2.lower_bound({s, 0});
						p1.S++;
						s2.erase(s2.lower_bound({s, 0}));
						s2.insert(p1);
					}
				}				
			}
		} else if(c == '-') {
			ll x; cin >> x;
			pair<ll, ll> p = *s1.lower_bound({x, 0});
			p.S--;
			s1.erase(s1.lower_bound({x, 0}));
			if(p.S > 0) s1.insert(p);

			string ns = to_string(x);
			fi(0, ns.size() - 1) if((ns[i] - '0') % 2 == 0) ns[i] = '0'; else ns[i] = '1';
			fi(0, ns.size() - 1) {
				string s = ns.substr(i, ns.size() - i);

				pair<string, ll> p1 = *s2.lower_bound({s, 0});
				p1.S--;
				s2.erase(s2.lower_bound({s, 0}));
				if(p1.S > 0) s2.insert(p1);
			}
		} else {
			string s;	cin >> s;
			ll st = s.size() - 1;
			fi(0, s.size() - 1) if(s[i] != '0') { st = i; break; }
			s = s.substr(st, s.size() - st);
			if(s.compare("") == 0) s.push_back('0');
			cout << s << "-\n";
			if(s2.lower_bound({s, 0}) == s2.end() || (*s2.lower_bound({s, 0})).F != s) {
				cout << 0 << "\n";
			} else {
				cout << (*s2.lower_bound({s, 0})).S << "\n";
			}
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	// while(T--)
		solve();

	return 0;
}