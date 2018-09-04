#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define F0(i,n) for (ll i = 0; i < n; i++)
#define F1(i,n) for (ll i = 1; i <= n; i++)
#define CL(a,x) memset(x, a, sizeof(x));
#define SZ(x) ((int)x.size())

void read(ll &x){
	cin >> x;
}
void read(ll &x,ll &y){
	cin >> x >> y;
}
void read(ll &x,ll &y,ll &z){
	cin >> x >> y >> z;
}
void read(ll &x,ll &y,ll &z,ll &w){
	cin >> x >> y >> z >> w;
}
clock_t t_start,t_end;
void start_clock(){
	t_start = clock();
}
void end_clock(){
	t_end = clock();
	ld timeis = t_end - t_start;
    printf("\n\nTime taken : %f s", ((float)timeis)/CLOCKS_PER_SEC);
}

bool IsOdd(ll n){ return n % 2 == 1; }

ll gcd(ll a,ll b){ return ((b==0)? a:gcd(b,a%b) ); }
 
 
 
 
const int N = 2e5; 
int n; 
int t[2 * N];
int d[2*N];
 
void build() {
  for (int i = n - 1; i > 0; --i)
    t[i] = max(t[i<<1], t[i<<1|1]);
}
void apply(int p, int value) { 
  t[p] += value;
  if (p < n) d[p] += value;
}
 
void buildup(int p) { 
  while (p > 1) p >>= 1, t[p] = max(t[p<<1], t[p<<1|1]) + d[p]; 
}
 
int h;
void push(int p) {
  for (int s = h; s > 0; --s) {
    int i = p >> s;
    if (d[i] != 0) {
      apply(i<<1, d[i]);
      apply(i<<1|1, d[i]);
      d[i] = 0;
    }
  }
}
 
void inc(int l, int r, ll value) {
  l += n, r += n;
  int l0 = l, r0 = r;
  for (; l <= r; l >>= 1, r >>= 1) {
    if (l&1) apply(l++, value);
    if (!(r&1)) apply(r--, value);
  }
  buildup(l0);
  buildup(r0);
}
 
int query(int l, int r) {
  l += n, r += n;
  push(l);
  push(r);
  int res = 2e9;
  for (; l <= r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, t[l++]);
    if (!(r&1)) res = max(t[r--], res);
  }
  return res;
}
 
int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output2.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);	
    ll q, i;
    cin >> n;
    F0(i, n)
    {
        cin>>t[i+n];
    }
    build();
    read(q);
    h = log(2*n)+5;
    F0(i, q)
    {
        char qr;
        cin>>qr;
        if(qr=='2')
        {
            int r;
            cin>>r;
            cout<<query(0,r-1)<<"\n";
        }
        else
        {
            int l,r;
            ll z;
            cin>>l>>r>>z;
            inc(l-1,r-1,z);
        }
 
    }
}