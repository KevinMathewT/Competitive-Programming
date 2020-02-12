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

ll n, k;
string s;

ll add1(vector<ll> &b){
	ll carry = 0;
	for(ll i=k-1;i>=0;i--){
		carry = (b[i] + 1) / 10;
		b[i] = (b[i] + 1) % 10;

		if(carry == 0) break;
	}
}

void solve(){
	cin >> n >> k;
	cin >> s;

	vector<ll> a(s.size(), 0), b(s.size(), 0);
	for(ll i=0;i<s.size();i++) a[i] = b[i] = s[i] - '0';

	for(ll i=k;i<b.size();i++)
		b[i] = b[i - k];

	ll tight = 1;
	for(ll i=0;i<n;i++){
		if(b[i] > a[i]) break;
		if(a[i] > b[i]) {
			add1(b);
			break;
		}
	}

	for(ll i=k;i<b.size();i++)
		b[i] = b[i - k];

	cout << b.size() << '\n';
	for(ll i=0;i<n;i++)
		cout << b[i];
	cout << "\n";
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