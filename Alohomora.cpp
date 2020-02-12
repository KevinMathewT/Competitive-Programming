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

const ld eps = 1e-8;
const int mod=1e9+7;
const ll N = 2e5 + 5;
const ll MAXN = 1 << 20;

inline int add(int a,int b){a+=b;if(a>=mod)a-=mod;return a;}
inline int sub(int a,int b){a-=b;if(a<0)a+=mod;return a;}
inline int mul(int a,int b){return (a*1ll*b)%mod;}
inline int power(int a,int b){int rt=1;while(b>0){if(b&1)rt=mul(rt,a);a=mul(a,a);b>>=1;}return rt;}
inline int inv(int a){return power(a,mod-2);}

struct base {
	typedef double T;
	T re, im;
	base() :re(0), im(0) {}
	base(T re) :re(re), im(0) {}
	base(T re, T im) :re(re), im(im) {}
	base operator + (const base& o) const {
		return base(re + o.re, im + o.im);
	}
	base operator - (const base& o) const {
		return base(re - o.re, im - o.im);
	}
	base operator * (const base& o) const {
		return base(re * o.re - im * o.im, re * o.im + im * o.re);
	}
	base operator * (ld k) const {return base(re * k, im * k) ;}
	base conj() const { return base(re, -im);}
};

base w[MAXN];
base f1[MAXN];

ll rev[MAXN];

void build_rev(ll k) {
	static ll rk = -1;
	if( k == rk )return ;
	rk = k;
	for(ll i=1; i<=(1<<k); i++) {
		ll j = rev[i-1], t = k-1;
		while( t >= 0 && ((j>>t)&1) ) {j ^= 1 << t;--t;}
		if( t >= 0 ) { j ^= 1 << t; --t;}
		rev[i] = j;
	}
}

void fft(base *a, ll k) {
	build_rev(k);
	ll n = 1 << k;
	for(ll i=0; i<n; i++) if( rev[i] > i ) swap(a[i], a[rev[i]]);
	for(ll l = 2, llo = 1; l <= n; l += l, llo += llo) {
		if( w[llo].re == 0 && w[llo].im == 0 ) {
			ld angle = M_PI / llo;
			base ww( cosl(angle), sinl(angle) );
			if( llo > 1 ) for(ll j = 0; j < llo; ++j) {
					if( j & 1 ) w[llo + j] = w[(llo+j)/2] * ww;
					else w[llo + j] = w[(llo+j)/2];
				}
			else w[llo] = base(1, 0);
		}
		for(ll i = 0; i < n; i += l) {
			for(ll j=0; j<llo; j++) {
				base v = a[i + j], u = a[i + j + llo] * w[llo + j];
				a[i + j] = v + u;
				a[i + j + llo] = v - u;
			}
		}
	}
}

vector<ll> Multiply(vector<ll>& a, vector<ll>& b) {
	ll k = 1;
	while( (1<<k) < (a.size() + b.size()) ) ++k;
	ll n = (1<<k);
	for(ll i=0; i<n; i++) f1[i] = base(0,0);
	for(ll i=0; i<a.size(); i++) f1[i] = f1[i] + base(a[i], 0);
	for(ll i=0; i<b.size(); i++) f1[i] = f1[i] + base(0, b[i]);
	fft(f1, k);
	for(ll i=0; i<1+n/2; i++) {
		base p = f1[i] + f1[(n-i)%n].conj();
		base _q = f1[(n-i)%n] - f1[i].conj();
		base q(_q.im, _q.re);
		f1[i] = (p * q) * 0.25;
		if( i > 0 ) f1[(n - i)] = f1[i].conj();
	}
	for(ll i=0; i<n; i++) f1[i] = f1[i].conj();
	fft(f1, k);
	vector<ll> res(a.size() + b.size());
	for(ll i=0; i<res.size(); i++) {
		if(fabs(f1[i].re) < eps) res[i]=0;
		else res[i] = f1[i].re / fabs(f1[i].re) * ll (abs(f1[i].re / n) + 0.5);
	}
	return res;
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll n,m;cin>>n>>m;
	string s,t;
	cin>>s>>t;
	ll a1[10],b1[10];
	for(ll i=0;i<10;i++)cin>>a1[i];
	for(ll j=0;j<10;j++)cin>>b1[j];
	ll mn[10][10];
	for(ll i=0;i<10;i++)
	{
		for(ll j=0;j<10;j++)
		{
			if(i==j){mn[i][j]=0;continue;}
			ll cur=1e9;
			for(ll k=0;k<10;k++)
			{
				ll a = 0, b = 0;
				ll i1 = i, j1 = j;
				while(i1 != k) a += a1[i1], i1=(i1+1) % 10;
				while(j1 != k) b += b1[j1], j1=(j1+1) % 10;
				cur = min(cur, a + b);
			}
			mn[i][j] = cur;
		}
	}

	for(ll i=0;i<10;i++){
		for(ll j=0;j<10;j++)
			cout << mn[i][j] << '\t';
		cout << "\n";
	}

	vector<ll> answer(n + m);
	for(ll i=0;i<10;i++)
	{
		vector<ll> v1(n),v2(m);
		for(ll j=0;j<m;j++)
			v2[m-1-j]=((t[j]-'0') == i);
		for(ll j=0;j<n;j++)
			v1[j] = mn[s[j]-'0'][i];
		cout << v1 << '\n' << v2 << "\n";
		vector<ll> v3 = Multiply(v1,v2);
		cout << v3 << "\n";
		for(ll j=0;j<=n-m;j++)
			answer[j] += v3[j+m-1];
	}
	ll cur = 1e18;
	for(ll i=0;i<=n-m;i++)
		cur = min(cur, answer[i]);
	cout << cur << endl;
}