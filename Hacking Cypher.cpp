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

const ll N = 1000010, M = 1e9 + 7;
ll n, a, b, arr[N];
string s;

ll power(ll a, ll x, ll m) {
	a = a % m;
	if (x == 0) return 1;
	if (x == 1) return a;
	if (x % 2 == 0) return power((a * a) % m, x / 2, m);
	return (a * power((a * a) % m, x / 2, m)) % m;
}

void solve(){
	cin >> s;
	n = s.size();
	cin >> a >> b;

	ll p = 1;

	arr[n - 1] = (s[n - 1] - '0') % b;
	fid(n - 2, 0) arr[i] = ((((s[i] - '0') * power(10 % b, p++, b)) % b) + arr[i + 1]) % b;

	// fi(0, n - 1) cout << arr[i] << ' ';
	// cout << "\n";

	ll tot = 0;
	fi(0, n - 2) {
		tot = (tot * 10) % a;
		tot = (tot + s[i] - '0') % a;
		if(tot == 0 && arr[i + 1] == 0) {
			if(s[i + 1] == '0') continue;
			cout << "YES\n";
			fj(0, i) cout << s[j];
			cout << '\n';
			fj(i + 1, n - 1) cout << s[j];
			cout << "\n";
			return;
		}
	}

	cout << "NO\n";
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