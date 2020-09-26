#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
typedef long long ll;
typedef long long ld;
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

const ll N = 100010;
ll B, L, D, SCORE_LIM;
ld S[N], NB[N], T[N], M[N], SU[N], SCORE[N], SCORE1[N], SCORE2[N];
vector<vector<ll> > ID;
unordered_map<ll, ll> m;

ld pow(ld a, ld x){
  ld ret = 1;
  for(ll i=1;i<=x;i++) ret *= a;
  return ret;
}

ll solve(ll a, ll b, ll c, ll d){
  m.clear();
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  vector<ll> permutation(L);
  for (ll i = 0; i < L; i++)
      permutation[i] = i;

  vector<pair<ll, ll>> SC(L);
  for(ll i=0;i<L;i++){
    pair<ll, ll> pll = {0, 0};
    pll.S = i;
    pll.F = ((pow(SCORE1[i], a)) * pow(NB[i], c)) / (pow(T[i], d) * (pow(SCORE[i], b)));
    SC[i] = pll;
  }

  ll tot1 = 0;

  sort(SC.begin(), SC.end());
  reverse(SC.begin(), SC.end());
  for(ll i=0;i<SC.size();i++) permutation[i] = SC[i].S;

  for(ll i=0;i<L;i++) SU[i] = T[permutation[i]];

  ll tot = 0, A = L;
  for(ll i=0;i<L;i++){
  	tot += SU[i];
  	if(tot >= D){
  		tot -= SU[i];
  		A = i;
  		break;
  	}
  }

  for(ll i=0;i<A/4;i++)
    swap(permutation[i], permutation[(A / 2) - i]);

  vector<ll> perm(0), currArr(0);
  vector<vector<ll> > ansArr(0);

  ll temp = A;

  ll left = D;
  for(ll i=0;i<temp;i++){

  	left -= SU[i];
  	vector<pair<ll, ll> > pr;
  	for(ll j=0;j<ID[permutation[i]].size();j++)
  		pr.push_back({S[ID[permutation[i]][j]], ID[permutation[i]][j]});
  	sort(pr.begin(), pr.end());
  	reverse(pr.begin(), pr.end());

  	ll allow = M[permutation[i]] * left;

  	vector<ll> ans;
  	ll curr = 0;
  	for(ll j=0;j<pr.size();j++){
  		if(m.find(pr[j].S) == m.end()) m[pr[j].S] = 1, ans.push_back(pr[j].S), curr++, tot1 += S[pr[j].S];
  		if(curr >= allow) break;
  	}

  	if(curr == 0){
  		A--;
  		continue;
  	}

  	// cout << permutation[i] << " ";
  	// cout << curr << "\n";
  	// for(ll j=0;j<ans.size();j++) cout << ans[j] << ' ';
  	// cout << "\n";

  	perm.push_back(permutation[i]);
  	currArr.push_back(curr);
  	ansArr.push_back(ans);
  	// ansArr.push_back(vector<ll>(0));
  	// for(ll j=0;j<ans.size();j++)
  	// 	ansArr[ansArr.size() - 1].push_back(ans[j]);
  }

  // cout << A << " " << perm.size() << "\n";

  // cout << tot1 << "\n";

  // if(a == 2 && b == 0 && c == 0 && d == 2){
  //   cout << A << "\n";
  //   for(ll i=0;i<A;i++){
  //   	cout << perm[i] << " " << currArr[i] << "\n";
  //   	for(ll j=0;j<ansArr[i].size();j++) cout << ansArr[i][j] << " ";
  //   	cout << '\n';
  //   }
  // }

  return tot1;
}

void calc(){
  cin >> B >> L >> D;
  for(ll i=0;i<B;i++) cin >> S[i], SCORE_LIM += S[i];
  ID = vector<vector<ll> >(L, vector<ll>(0));
  for(ll i=0;i<L;i++){
    cin >> NB[i] >> T[i] >> M[i];
    SCORE[i] = 0;
    SCORE2[i] = 0;
    ID[i] = vector<ll>(NB[i]);
    for(ll j=0;j<NB[i];j++) cin >> ID[i][j], SCORE[i]++, SCORE1[i] += S[ID[i][j]], SCORE2[i] = max(SCORE2[i], S[ID[i][j]]);
  }

  ll mx = 0;

  ll lim1 = -2, lim2 = 2;

  for(ll j=lim1;j<=lim2;j++)
    for(ll k=lim1;k<=lim2;k++)
      for(ll l=lim1;l<=lim2;l++)
        for(ll m=lim1;m<=lim2;m++){
          ll temp = solve(j, k, l, m);
          cout << j << ' ' << k << ' ' << l << ' ' << m << " " << temp << "\n";
          mx = max(mx, temp);
        }

  cout << mx << " " << SCORE_LIM << "\n";
}

int main(){
	freopen("input1.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	// while(T--)
		calc();

	return 0;
}