#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second

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
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, sum, a[100010];
unordered_map<ll, ll> m;

void solve(){
	cin >> n >> sum;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	for(ll i=0;i<n;i++){
		string s = to_string(a[i]);
		vector<ll> p(1, 0);

		// cout << s << "\n";

		for(ll i=0;i<s.size();i++){
			if(s[i] != '2' && s[i] != '5' && s[i] != '6' && s[i] != '9'){
				for(ll j=0;j<p.size();j++)
					p[j] = p[j] * 10 + (s[i] - '0');
			}
			else{
				ll sz = p.size();
				for(ll j=0;j<sz;j++)
					p.push_back(p[j]);

				if(s[i] == '2'){
					for(ll j=0;j<sz;j++)
						p[j] = p[j] * 10 + 2;
					for(ll j=sz;j<2*sz;j++)
						p[j] = p[j] * 10 + 5;
				}

				if(s[i] == '5'){
					for(ll j=0;j<sz;j++)
						p[j] = p[j] * 10 + 2;
					for(ll j=sz;j<2*sz;j++)
						p[j] = p[j] * 10 + 5;
				}

				// cout << p << "\n";
				if(s[i] == '6'){
					for(ll j=0;j<sz;j++)
						p[j] = p[j] * 10 + 6;
					for(ll j=sz;j<2*sz;j++)
						p[j] = p[j] * 10 + 9;
				}

				if(s[i] == '9'){
					for(ll j=0;j<sz;j++)
						p[j] = p[j] * 10 + 6;
					for(ll j=sz;j<2*sz;j++)
						p[j] = p[j] * 10 + 9;
				}
			}
		}

		// cout << p << "\n";

		for(ll j=0;j<p.size();j++)
			if(m.find(sum - p[j]) != m.end()){
				cout << "YES\n";
				return;
			}

		for(ll j=0;j<p.size();j++)
			m[p[j]] = 1;
	}

	cout << "NO\n";
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