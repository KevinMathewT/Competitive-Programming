#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define F0(i,n) for (ll i = 0; i < n; i++)
#define F1(i,n) for (ll i = 1; i <= n; i++)
#define CL(a,x) memset(x, a, sizeof(x));
#define SZ(x) ((ll)x.size())

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

int main()
{
  freopen("input.txt", "r", stdin);    //Comment
  freopen("output.txt", "w", stdout);    //this
  start_clock();              //out.
  ios::sync_with_stdio(false);      //Not
  cin.tie(NULL);              //this.
  cout.tie(0);              //or this.

  string s, p;
  getline(cin, s);
  getline(cin, p);
  ll k1, k2;
  read(k1, k2);

  ll LCS[s.size()+1][p.size()+1];
  for (ll i=0; i<=s.size(); i++)
  {
    for (ll j=0; j<=p.size(); j++)
    {
      if (i == 0 || j == 0)
        LCS[i][j] = 0;
      else if (s[i-1] == p[j-1])
        LCS[i][j] = LCS[i-1][j-1] + 1;
      else
        LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
    }
  }

  ll lcs = LCS[s.size()][p.size()];
  // for (ll i=0; i<=s.size(); i++)
  // {
  //   for (ll j=0; j<=p.size(); j++)
  //   {
  //     cout << LCS[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  pair<ll, ll> arr[lcs+10];
  for(ll i=0;i<lcs+10;i++){
    arr[i].first = max(s.size(), p.size());
    arr[i].second = max(s.size(), p.size());
  }
  for(ll i=1;i<=s.size();i++){
    for(ll j=1;j<=p.size();j++){
      if(i+j <= arr[LCS[i][j]].first + arr[LCS[i][j]].second){
        arr[LCS[i][j]].first = i;
        arr[LCS[i][j]].second = j;
      }
    }
  }

  arr[0].first = 0;
  arr[0].second = 0;
  //F0(i, lcs+1)
  //cout << arr[i].first << " " << arr[i].second << "\n";
  ll f = k1+k2;
  ll t = lcs;
  for(ll i=1;i<=t;i++){
    if(f <= 0)
      break;
    ll a = arr[i].first - arr[i-1].first - 1;
    ll b = k1;
    ll c = arr[i].second - arr[i-1].second - 1;
    ll d = k2;

    ll e = min(a, c);
    //cout << "a - " << a << " c - " << c << " e - " << e << "\n";
    if(e <= f){
      f -= e;
      lcs += e;
      //cout<<"t"<<endl;
    }
    else{
      lcs += f;
      f = 0;
      //cout<<"k"<<endl;
    }
    //cout << lcs << "\n";

    // ll f = min(c, d);
    // if(e > c)
    //   e = 0;
    // if(f > a)
    //   f = 0;
    // if(e > f){
    //   lcs += e;
    //   k1 -= e;
    //   if(k1 < 0)
    //     k1 = 0;
    // }
    // else{
    //   lcs += f;
    //   k2 -= f;
    //   if(k2 < 0)
    //     k2 = 0;
    // }
  }

  cout << lcs << "\n";
  end_clock();              //This too.
  return 0;
}