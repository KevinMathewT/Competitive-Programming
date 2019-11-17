#define _CRT_SECURE_NO_WARNINGS
#define REL

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string>
#include <set>
#include <bitset>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <random>
#include <cassert>
#include <complex>

using namespace std;

typedef int64_t i64;
typedef long long LL;
typedef long double LD;
typedef unsigned int uint;
typedef complex <LD> cld;
typedef complex <double> cd;
typedef unsigned long long ULL;

#define endl "\n"
#define dendl "\n\n"
#define mp make_pair
#define pb push_back
#define size(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

/////////////////////////////////////////////////////////////////////

template <typename T>
int sign(T a) {
	if (a == 0)
		return 0;
	return (a > 0 ? 1 : -1);
}

template <typename T1, typename T2>
T2 mod(T1 x, T2 MOD) {
	if (x < 0)
		x += MOD;
	if (x >= MOD)
		x -= MOD;
	return x;
}

template <typename T>
T sqr(T a) {
	return a * a;
}

template <typename T>
bool uax(T& a, const T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template <typename T>
bool uin(T& a, const T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
	in >> p.first >> p.second;
	return in;
}

template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& p) {
	out << '(' << p.first << ' ' << p.second << ')';
	return out;
}

mt19937_64 gen_rand;

const int N = (int)3e5 + 7;
const int LOG = 31;
const int N_ = (int)5007;
const int MAXN = (int)8e5 + 7;
const int MOD = (int)1e9 + 7;
const int INF = (int)2e9 + 7;
const int CONST = 5000;
const LL LINF = (i64)1e18 + 10;
const LD PI = 3.1415926535897932384626433832795;
const LD EPS = 5e-1;

/////////////////////////////////////////////////////////////////////

LL a[21];

LL power(int a, int p) {
	ULL res = 1;
	for (int i = 0; i < p; i++)
		res *= a;
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	a[0] = 0;
	for (int i = 1; i <= 20; i++)
		a[i] = (power(7, i) - power(2, i)) / 5;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << a[n] * 7 + power(2, n) << endl;
	}
}

