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

const ll N = 1010, M = (24 * 60) + 10;
ll n, flag, ans[N], sat[2], final[N], c[M];
vector<pair<pair<ll, ll>, ll> > v;

void exchange(vector<pair<pair<ll, ll>, ll> > &vec){
	fi(0, vec.size() - 1) swap(vec[i].F.F, vec[i].F.S);
}

ll intersect(pair<ll, ll> p1, pair<ll, ll> p2){
	if(p2.F < p1.S) return 1;
	return 0;
}

void solve(ll cs){
	flag = 0;
	cin >> n;
	v = vector<pair<pair<ll, ll>, ll> >(n, {{0LL, 0LL}, 0LL});
	fi(0, n - 1) cin >> v[i].F.F >> v[i].F.S, v[i].S = i;

	exchange(v);
	sort(v.begin(), v.end());
	exchange(v);

	fill(c, c + M, 0LL);
	fi(0, n - 1) c[v[i].F.F]++, c[v[i].F.S]--;
	fi(1, M - 1) c[i] += c[i - 1];
	fi(0, M - 1) if(c[i] > 2) flag = 1;

	ans[0] = 0;
	fi(1, n - 1)
		if(v[i - 1].F.S > v[i].F.F) ans[i] = 1 - ans[i - 1];
		else ans[i] = ans[i - 1];

	if(flag) cout << "Case #" << cs << ": " << "IMPOSSIBLE" << "\n";
	else {
		cout << "Case #" << cs << ": ";
		fi(0, n - 1) final[v[i].S] = ans[i];
		fi(0, n - 1) if(final[i] == 0) cout << 'C'; else cout << 'J';
		cout << "\n";
	}
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	fi(1, T)
		solve(i);

	return 0;
}