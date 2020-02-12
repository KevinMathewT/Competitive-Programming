#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second
#define MAX 1000005
#define MOD 163577857
#define MAX 1000005
#define ll long long
#define sd(t) scanf("%d",&t)
#define pd(t) printf("%d\n",t)

using namespace std;

ll power(ll a,ll b,ll m){
	ll x=1%m; a%=m;
	while(b){
		if((1&b)) x = x * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return x;
}

int mul(const int &a,const int &b){
	ll ans = a*1LL*b;
	if(ans>=MOD) return ans%MOD;
	return ans;
}

// NTT helper
const int mod = 163577857;
const int root = 40336560;	// g^((mod-1)/root_pw)
const int root_1 = 3509831;
const int LG = 21;
const int root_pw = 1<<21;


void solve(){
	for(ll i=0;i<5;i++)
		cout << cur[i] << " ";
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