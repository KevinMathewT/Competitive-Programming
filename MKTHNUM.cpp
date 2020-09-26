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

struct node {
	node *left, *right;
	ll v;

	node(ll v) : left(nullptr), right(nullptr), v(v){}
	node(node *l, node *r) : left(l), right(r) {
		v = l->v + r->v;
	}
};

const ll N = 100010, M = 1e9 + 7;
ll n, o, A[N], S[N], T[2 * N], ind;
node *roots[N], *roots0;
unordered_map<ll, ll> m, r;
vector<ll> cp;

node* build(ll l, ll r) {
	if(l == r)
		return new node(0);
	ll m = (l + r) / 2;
	return new node(build(l, m), build(m + 1, r));
}

node* upgrade(node* p, ll l, ll r, ll v) {
	if(l == r) return new node(p->v + 1);
	ll m = (l + r) / 2;

	if(v <= m) return new node(upgrade(p->left, l, m, v), p->right);
	else return new node(p->left, upgrade(p->right, m + 1, r, v));
}

ll query(node* s, node* e, ll l, ll r, ll k) {
	if(l == r) return l;
	ll m = (l + r) / 2;
	if(k <= e->left->v - s->left->v) return query(s->left, e->left, l, m, k);
	else return query(s->right, e->right, m + 1, r, k - (e->left->v - s->left->v));
}

void print(node* p, ll l, ll r){
	if(l == r) {
		cout << p->v << " ";
		return;
	}

	ll m = (l + r) / 2;
	print(p->left, l, m);
	print(p->right, m + 1, r);
}

void solve(){
	cin >> n >> o;
	fi(0, n - 1) cin >> A[i];
	fi(0, n - 1) cp.push_back(A[i]);
	sort(cp.begin(), cp.end());
	ind = 0;
	fi(0, n - 1) if(m.find(cp[i]) == m.end()) m[cp[i]] = ind, r[ind++] = cp[i];
	fi(0, n - 1) A[i] = m[A[i]];
	fi(0, n - 1) S[i] = 0LL;

	roots0 = build(0, n - 1);
	fi(0, n - 1) roots[i] = upgrade(i == 0 ? roots0 : roots[i - 1], 0, n - 1, A[i]);

	fi(0, o - 1) {
		ll p, q, k;
		cin >> p >> q >> k;
		p--; q--;
		cout << r[query(p == 0 ? roots0 : roots[p - 1], roots[q], 0, n - 1, k)] << "\n";
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