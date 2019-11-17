#include <bits/stdc++.h>
using namespace std;
typedef ll ll;
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

ll n, a, b, c, d, e;

void matmult(ll a[][2], ll b[][2], ll c[][2]) //multiply matrix a and b. put result in c
{
  int i, j, k;
  for (i = 0; i & lt; 2; i++)
  {
    for (j = 0; j & lt; 2; j++)
    {
      c[i][j] = 0;
      for (k = 0; k & lt; 2; k++)
      {
        c[i][j] += (a[i][k] * b[k][j]);
        c[i][j] = c[i][j];
      }
    }
  }
}

void matpow(ll Z[][2], int n, ll ans[][2])
//find ( Z^n ) and return result in ans
{
  ll temp[2][2];
  //assign ans= the identity matrix
  ans[0][0] = 1;
  ans[1][0] = 0;
  ans[0][1] = 0;
  ans[1][1] = 1;
  int i, j;
  while (n & gt; 0)
  {
    if (n & amp; 1)
    
      matmult(ans, Z, temp);
      for (i = 0; i & lt; 2; i++)
        for (j = 0; j & lt; 2; j++)
          ans[i][j] = temp[i][j];
    
    matmult(Z, Z, temp);
    for (i = 0; i & lt; 2; i++)
      for (j = 0; j & lt; 2; j++)
        Z[i][j] = temp[i][j];
    n = n / 2;
	}
  
  return;
}

ll findFibonacci(ll n) {
  ll fib;
  if (n & gt; 2)
  {
    ll int Z[2][2] = {{1, 1},{1,0}}, result[2][2]; //modify matrix a[][] for other recurrence relations
    matpow(Z, n - 2, result);
    fib = result[0][0] * 1 + result[0][1] * 0; //final multiplication of Z^(n-2) with the initial terms of the series
  } else
    fib = n - 1;
  return fib;
}

void solve(){
	cin >> n >> a >> b >> c >> d >> e;
	cout << findFibonacci(n) << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}