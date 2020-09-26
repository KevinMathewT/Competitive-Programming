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

const ll N = 2, M = 1e9 + 7;
ll n, p, q, x;

vector<ll> removeDuplicates(vector<ll> &p){
	vector<ll> ret;
	unordered_map<ll, ll> m;
	for(ll i=0;i<p.size();i++)
		if(m.find(p[i]) == m.end())
			ret.push_back(p[i]), m[p[i]] = 1;

	return ret;
}

void solve(){
	cin >> n;
	if(n == 0){
		cin >> x;
		cout << "No\n";
		return;
	}

	if(n == 1){
		cin >> p;
		cin >> x;

		string s = to_string(x);
		char z = to_string(p)[0];

		for(ll i=0;i<s.size();i++) if(s[i] != z){
			cout << "No\n";
			return;
		}

		cout << "Yes\n";
		cout << s.size() << "\n";
	}

	if(n == 2){
		cin >> p >> q;
		cin >> x;

		if(p == q){

			string s = to_string(x);
			char z = to_string(p)[0];

			for(ll i=0;i<s.size();i++) if(s[i] != z){
				cout << "No\n";
				return;
			}

			cout << "Yes\n";
			cout << s.size() << "\n";
			return;
		}

		string s = to_string(x);
		char y = to_string(p)[0];
		char z = to_string(q)[0];

		for(ll i=0;i<s.size();i++) if(s[i] != y && s[i] != z){
			cout << "No\n";
			return;
		}

		vector<ll> poss(0, 0);

		for(ll i=1;i<=10;i++){
			for(ll j=0;j<(1LL << i);j++){
				string t = "";
				for(ll k=0;k<i;k++)
					if((j & (1LL << k))) t.push_back(y);
					else t.push_back(z);
        poss.push_back(stoll(t));
      }
		}

		sort(poss.begin(), poss.end());

		poss = removeDuplicates(poss);

		cout << "Yes\n";
		for(ll i=0;i<poss.size();i++) if(poss[i] == x) {
			cout << i + 1 << "\n";
			return;
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	// while(T--)
		solve();

	return 0;
}