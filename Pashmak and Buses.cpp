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

const ll N = 1010, M = 1e9 + 7;
ll n, d, k, a[N][N];

ll power(ll a, ll x) {
	if(x == 0) return 1LL;
	if(x == 1) return a;
	if(x % 2 == 0) return power((a * a), x / 2);
	return (a * power((a * a), x / 2));
}

void solve(){
	cin >> n >> k >> d;
	if(d == 1) {
		if(k < n) {
			cout << -1 << "\n";
			return;
		}
		else {
			fi(1, n) cout << i << ' ';
			return;
		}
	}

	if(n == 1) {
		fi(0, d - 1) cout << 1 << "\n";
		return;
	}

	ll mn;
	fi(1, 1000) {
		if(d >= (log2l(n) / log2l(i))) {
			mn = i;
			break;
		}
	}


	if(k < mn) {
		cout << -1 << "\n";
		return;
	}

	fi(0, n - 1) {
		string s = "";
		ll t = i;
		while(t > 0) {
			s.push_back('0' + (t % mn));
			t /= mn;
		}
		ll sz = s.size();
		fj(0, d - sz - 1) s.push_back('0');
		reverse(s.begin(), s.end());

		fj(0, s.size() - 1) {
			a[j][i] = ((s[j] - '0') + 1);
		}
	}

	fi(0, d - 1) {
		fj(0, n - 1) cout << a[i][j] << ' ';
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