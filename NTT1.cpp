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

const int mod = 998244353;

int power(int a, int x){
    if(x == 0) return 1;
    if(x == 1) return (a % mod);
    if(x % 2 == 0) return power((a * a) % mod, x / 2);
    return (a * (power((a * a) % mod, x / 2))) % mod;
}

int inverse(int a){ return power(a, mod - 2); }


// p                   | deg | g
// 469762049             26    3
// 998244353             23    3
// 1107296257            24    10
// 10000093151233        26    5
// 1000000523862017      26    3
// 1000000000949747713   26    2

const int g = 3;
const int root_pw = 1 << 23;
const int root = power(g, (mod - 1) / root_pw);
const int root_1 = inverse(root);

void fft(vector<int> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = inverse(n);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}

vector<int> multiply(vector<int> a, vector<int> const& b) {
    cout << a << "\n";
    fft(a, false);
    cout << a << "\n";
    return a;
}

void solve(){
    cout << (((ld) mod - 1.0) / (root_pw + 0.0)) << "\n";
	vector<int> a, b;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(3);
    b.push_back(2);
    b.push_back(3);
    b.push_back(4);
    b.push_back(3);

    cout << a << " " << b << "\n";
    cout << multiply(a, b) << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}