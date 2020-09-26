#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
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
ll B, L, D, S[N], NB[N], T[N], M[N], SU[N];
vector<vector<ll> > ID;
unordered_map<ll, ll> m;

void solve(){
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin >> B >> L >> D;
	for(ll i=0;i<B;i++) cin >> S[i];
	ID = vector<vector<ll> >(L, vector<ll>(0));
	for(ll i=0;i<L;i++){
		cin >> NB[i] >> T[i] >> M[i];
		ID[i] = vector<ll>(NB[i]);
		for(ll j=0;j<NB[i];j++) cin >> ID[i][j];
	}

  vector<ll> permutation(L);
  for (ll i = 0; i < L; i++)
      permutation[i] = i;
  shuffle(permutation.begin(), permutation.end(), rng);

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
  		if(m.find(pr[j].S) == m.end()) m[pr[j].S] = 1, ans.push_back(pr[j].S), curr++;
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

  cout << A << "\n";
  for(ll i=0;i<A;i++){
  	cout << perm[i] << " " << currArr[i] << "\n";
  	for(ll j=0;j<ansArr[i].size();j++) cout << ansArr[i][j] << " ";
  	cout << '\n';
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