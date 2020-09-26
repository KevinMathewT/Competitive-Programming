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

const ll N = 100, M = LLONG_MAX;
string s;

ll power(ll a, ll x, ll M){
	a %= M;
	if(x == 0) return 1LL;
	if(x == 1) return a;
	if(x % 2 == 0) return power((a * a) % M, x / 2, M);
	return (a * (power((a * a) % M, x / 2, M))) % M;
}

void solve(){
	cin >> s;
	ll i = 0;
	stack<ll> st;

	while(i < s.size()){
		if(s[i] == 'S' && s[i + 1] == 'S'){
			ll j;
			for(j=i+2;j<s.size();j++) if(s[j] == 'N') break;
			string t = s.substr(i + 2, j - (i + 2));
			i = j + 1;

			ll z = 0, p = 0;
			for(ll j=t.size() - 1;j>0;j--) z = (z + power(2, p++, LLONG_MAX) * (t[j] == 'S' ? 0 : 1));
			if(t[0] == 'T') z = -z;
			st.push(z);
			continue;
		}

		if(s[i] == 'S' && s[i + 1] == 'N' && s[i + 2] == 'S'){
			if(st.size() == 0) cout << "Invalid copy operation\n";
			else{
				ll cp = st.top();
				st.push(cp);
			}

			i += 3;
			continue;
		}

		if(s[i] == 'S' && s[i + 1] == 'N' && s[i + 2] == 'T'){
			if(st.size() < 2) cout << "Invalid swap operation\n";
			else{
				ll cp1 = st.top();
				st.pop();
				ll cp2 = st.top();
				st.pop();
				st.push(cp1);
				st.push(cp2);
			}

			i += 3;
			continue;
		}

		if(s[i] == 'S' && s[i + 1] == 'N' && s[i + 2] == 'N'){
			if(st.size() < 1) cout << "Invalid remove operation\n";
			else{
				st.pop();
			}

			i += 3;
			continue;
		}

		if(s[i] == 'T' && s[i + 1] == 'S' && s[i + 2] == 'S' && s[i + 3] == 'S'){
			if(st.size() < 2) cout << "Invalid addition operation\n";
			else{
				ll cp1 = st.top();
				st.pop();
				ll cp2 = st.top();
				st.pop();
				st.push(cp1 + cp2);
			}

			i += 4;
			continue;
		}
		
		if(s[i] == 'T' && s[i + 1] == 'S' && s[i + 2] == 'S' && s[i + 3] == 'T'){
			if(st.size() < 2) cout << "Invalid subtraction operation\n";
			else{
				ll cp1 = st.top();
				st.pop();
				ll cp2 = st.top();
				st.pop();
				st.push(cp2 - cp1);
			}

			i += 4;
			continue;
		}

		if(s[i] == 'T' && s[i + 1] == 'S' && s[i + 2] == 'S' && s[i + 3] == 'N'){
			if(st.size() < 2) cout << "Invalid multiplication operation\n";
			else{
				ll cp1 = st.top();
				st.pop();
				ll cp2 = st.top();
				st.pop();
				st.push(cp1 * cp2);
			}

			i += 4;
			continue;
		}

		if(s[i] == 'T' && s[i + 1] == 'S' && s[i + 2] == 'T' && s[i + 3] == 'S'){
			if(st.size() < 2) cout << "Invalid division operation\n";
			else{
				ll cp1 = st.top();
				st.pop();
				ll cp2 = st.top();
				st.pop();
				if(cp1 == 0){
					cout << "Division by zero\n";
					st.push(cp2);
					st.push(cp1);
					i += 4;
				}
				st.push(cp2 / cp1);
			}

			i += 4;
			continue;
		}
		

		if(s[i] == 'T' && s[i + 1] == 'N' && s[i + 2] == 'S' && s[i + 3] == 'T'){
			if(st.size() < 1) cout << "Invalid print operation\n";
			else{
				ll cp1 = st.top();
				st.pop();
				cout << cp1 << "\n";
			}

			i += 4;
			continue;
		}
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