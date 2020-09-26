#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second
#define fi(a, b) for(ll i=(a);i<=b;i++)
#define fj(a, b) for(ll j=(a);j<=b;j++)
#define fid(a, b) for(ll i=(a);i>=b;i--)
#define fjd(a, b) for(ll i=(a);i>=b;j--)

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

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// LinkedIn - https://www.linkedin.com/in/KevinMathewT/
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew

const ll N = 3000010, M = 1e9 + 7;
ll n, k;
string s;
vector<ll> l, r;
vector<ll> all[N];

void solve(){
	cin >> n >> k;
	cin >> s;

	fi(0, s.size() - 1) if(s[i] == 'L') l.push_back(i + 1); else r.push_back(i + 1);
	ll moved = 0;

	ll tot = 0, len = 0;
	vector<ll> v;

	if(r.size() == 0) {
		cout << -1 << "\n";
		return;
	}

	while(true) {
		ll t = 0;
		v.clear();

		fi(0, r.size() - 1) {
			if(r[i] < (n - (r.size() - i - 1)) && r[i + 1] != r[i] + 1) {
				t++;
				all[len].push_back(r[i]);
				r[i]++;
			}
		}

		if(t == 0) break;
		tot += t;
		len++;
	}

	if(k > tot || k < len) {
		cout << -1 << "\n";
		return;
	}

	ll extra = k - len;

	fi(0, len - 1) {
		ll cont = all[i].size() - 1;
		for(ll j=0;j<all[i].size() - 1;j++) {
			if(extra == 0) {
				cont = j;
				break;
			}

			cout << 1 << " ";
			cout << all[i][j] << "\n";
			extra--;
		}

		cout << all[i].size() - cont << ' ';
		for(ll j=cont;j<all[i].size();j++)
			cout << all[i][j] << " ";
		cout << "\n";
	}
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	// while(T--)
		solve();

	return 0;
}