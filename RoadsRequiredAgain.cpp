#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

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

string s, t;
unordered_map<ll, ll> m;

void solve(){
    m.clear();
    cin >> s >> t;
    ll flag = 0;
    ll freq[26] = {0};

    for(ll i=0;i<s.size();i++)
        freq[s[i] - 'a'] = 1;

    for(ll i=0;i<t.size();i++){
        if(freq[t[i] - 'a'] == 1)
            m[t[i] - 'a'] = 1;
    }

    for(ll i=0;i<s.size();i++)
        if(m[s[i] - 'a'] != 1){
            flag = 1;
            cout << s[i];
        }
    for(ll i=0;i<t.size();i++)
        if(m[t[i] - 'a'] != 1){
            flag = 1;
            cout << t[i];
        }

    if(flag == 0)
        cout << -1 << "\n";

    cout << "\n";
}

int main()
{
    // freopen("input.txt", "r", stdin);       //Comment
    // freopen("output.txt", "w", stdout);     //this out.
    ios::sync_with_stdio(false);            //Not
    cin.tie(NULL);                          //this.
    cout.tie(0);                            //or this.

    ll T;
    cin >> T;
    while(T--)
     solve();

    return 0;
}