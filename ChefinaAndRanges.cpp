#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second

clock_t t_start,t_end;
void start_clock(){
	t_start = clock();
}
void end_clock(){
	t_end = clock();
	ld timeis = t_end - t_start;
    printf("\n\nTime taken : %f s", ((float)timeis)/CLOCKS_PER_SEC);
}

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

const ll N = 5000010;
ll n, a[N], mnl, mnr, mxl, mxr, lss, rss, l[N], r[N], ls[N], rs[N], p[N], rm[N], lm[N], p1, t[N], mp[N];
set<ll> s;

ll getRs(ll x){
	if(rm[x] == 0 || lm[x] == 0)
		return 0;
	return 1;
}

ll findP(ll x){
	ll l = 0, r = p1 - 1, mid;
	while(l <= r){
		mid = (l + r) / 2;
		if(p[mid] == x)
			return mid;
		if(p[mid] > x)
			r = mid - 1;
		else l = mid + 1;
	}
}

void solve1(){


	for(ll i=0;i<n;i++)
		l[i] *= 2, r[i] *= 2;

	// cout << l << " " << r << "\n";

	p1 = 0;
	ll p2 = 0;

	for(ll i=0;i<n;i++){
		t[p2++] = l[i];
		t[p2++] = r[i];
		t[p2++] = r[i] + 1;
	}

	sort(t, t + p2);

	for(ll i=0;i<p2-1;i++)
		if(t[i] != t[i + 1])
			p[p1] = t[i], mp[t[i]] = p1++;

	p[p1] = t[p2 - 1];
	mp[t[p2 - 1]] = p1++;

	// cout << p << "\n";

	fill(a, a + p1, 0);

	for(ll i=0;i<n;i++)
		a[mp[l[i]]]++, a[mp[r[i] + 1]]--;

	// for(ll i=0;i<p.size();i++)
	// 	cout << a[i] << ' ';
	// cout << "\n";

	for(ll i=1;i<p1;i++)
		a[i] = a[i] + a[i-1];

	// for(ll i=0;i<p.size();i++)
	// 	cout << a[i] << ' ';
	// cout << "\n";

	lss = rss = 0;

	for(ll i=0;i<p1;i++)
		ls[i] = rs[i] = lm[i] = rm[i] = 0;

	for(ll i=0;i<n;i++)
		ls[lss++] = mp[l[i]];
	for(ll i=0;i<n;i++)
		rs[rss++] = mp[r[i]];

	for(ll i=0;i<lss;i++)
		if(mp[l[i]] > 0)
			lm[mp[l[i]] - 1]++;

	for(ll i=p1-2;i>=0;i--)
		lm[i] = lm[i + 1] + lm[i];

	for(ll i=0;i<rss;i++)
			rm[mp[r[i]] + 1]++;

	for(ll i=1;i<p1;i++)
		rm[i] = rm[i - 1] + rm[i];

	ll mn = LLONG_MAX, f = 0;

	for(ll i=0;i<p1;i++){
		if(a[i] < mn && getRs(i) == 1)
			mn = a[i];
	}

	if(mn == LLONG_MAX)
		cout << -1 << "\n";
	else
		cout << mn << "\n";
}

void solve(){
	cin >> n;

	ll mx = LLONG_MIN;

	for(ll i=0;i<n;i++){
		cin >> l[i] >> r[i];
		mx = max(mx, max(l[i], r[i]));
	}

	if(mx <= 1000010){
		solve1();
		return;
	}

	for(ll i=0;i<n;i++)
		l[i] *= 2, r[i] *= 2;

	// cout << l << " " << r << "\n";

	p1 = 0;

	for(ll i=0;i<n;i++){
		s.insert(l[i]);
		s.insert(r[i]);
		s.insert(r[i] + 1);
	}

	for(ll e : s)
		p[p1++] = e;

	// cout << p << "\n";

	fill(a, a + p1, 0);

	for(ll i=0;i<n;i++)
		a[findP(l[i])]++, a[findP(r[i] + 1)]--;

	// for(ll i=0;i<p.size();i++)
	// 	cout << a[i] << ' ';
	// cout << "\n";

	for(ll i=1;i<p1;i++)
		a[i] = a[i] + a[i-1];

	// for(ll i=0;i<p.size();i++)
	// 	cout << a[i] << ' ';
	// cout << "\n";

	lss = rss = 0;

	for(ll i=0;i<p1;i++)
		ls[i] = rs[i] = lm[i] = rm[i] = 0;

	for(ll i=0;i<n;i++)
		ls[lss++] = findP(l[i]);
	for(ll i=0;i<n;i++)
		rs[rss++] = findP(r[i]);

	for(ll i=0;i<lss;i++)
		if(findP(l[i]) > 0)
			lm[findP(l[i]) - 1]++;

	for(ll i=p1-2;i>=0;i--)
		lm[i] = lm[i + 1] + lm[i];

	for(ll i=0;i<rss;i++)
			rm[findP(r[i]) + 1]++;

	for(ll i=1;i<p1;i++)
		rm[i] = rm[i - 1] + rm[i];

	ll mn = LLONG_MAX, f = 0;

	for(ll i=0;i<p1;i++){
		if(a[i] < mn && getRs(i) == 1)
			mn = a[i];
	}

	if(mn == LLONG_MAX)
		cout << -1 << "\n";
	else
		cout << mn << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}