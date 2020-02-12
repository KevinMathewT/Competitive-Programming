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

ll n, d, mx;
unordered_map<string, ll> m;
vector<string> s;

void solve(){
	s.clear();
	m.clear();
	cin >> n >> d;
	s = vector<string>(n, "");
	mx = LLONG_MIN;

	for(ll i=0;i<n;i++) cin >> s[i];

	ll tot = 0, p1 = 0, p2 = min(d - 1, n - 1);

	for(ll i=p1;i<=p2;i++){
		if(m.find(s[i]) == m.end() || m[s[i]] == 0) 
			tot++;
		m[s[i]]++;
	}

	mx = tot;

	while(p2 < n - 1){
		if(m[s[p1]] == 1)
			tot--;
		m[s[p1]]--;
		if(m[s[p2+1]] == 0)
			tot++;
		m[s[p2+1]]++;
		
		p1++;
		p2++;
		mx = max(mx, tot);
	}

	cout << mx << "\n";
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