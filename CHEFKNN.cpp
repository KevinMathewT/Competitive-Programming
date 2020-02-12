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
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> M) {
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
 
/*
NTT Code Adapted from: https://www.codechef.com/viewsolution/18397100
*/

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

typedef long long ll;

const int N=2e6+5,M=998244353;

int pwr(int x,int y) {
	int z=1;
	for(;y;y>>=1,x=(ll)x*x%M)
		if (y&1) z=(ll)z*x%M;
	return z;
}

int n,p,ty;

ll W[2][N],fac[N],inv[N];

void init(int b){
	for(int i=1;i<(1<<b);i<<=1){
		ll wn=pwr(3,(M-1)/(i<<1));
		for(int j=0;j<i;++j) W[1][i+j]=(j?wn*W[1][i+j-1]%M:1);
		wn=pwr(3,M-1-(M-1)/(i<<1));
		for(int j=0;j<i;++j) W[0][i+j]=(j?wn*W[0][i+j-1]%M:1);
	}
}

void pre(int N) {
	fac[0]=1;fo(i,1,N) fac[i]=fac[i-1]*i%M;
	inv[N]=pwr(fac[N],M-2);fd(i,N-1,0) inv[i]=inv[i+1]*(i+1)%M;
}

ll C(int p,int n) {return fac[p]*inv[n]%M*inv[p-n]%M;}

void DFT(ll *a,int len,int flag) {
	if (flag==-1) flag=0;
	for(int i=0,j=0;i<len;++i){
		if(i<j) swap(a[i],a[j]);
		for(int k=len>>1;(j^=k)<k;k>>=1);
	}
	for(int i=1;i<len;i<<=1)
		for(int j=0;j<len;j+=(i<<1))
			for(int k=0;k<i;++k) {
				ll x=a[j+k],y=a[j+k+i]*W[flag][i+k]%M;
				a[j+k]=(x+y)%M;
				a[j+k+i]=(x-y)%M;
			}
	ll Inv=pwr(len,M-2);
	if (!flag) for(int i=0;i<len;i++) a[i]=a[i]*Inv%M;
}

ll F[N],G[N],H[N];

void solve(int n) {
	if (n==1) {
		F[0]=2;F[1]=1;
		return;
	}
	int nn;solve(nn=n>>1);
	int len=1;for(;len<=n;len<<=1);

	fo(i,nn+1,len-1) F[i]=0;fo(i,0,len-1) G[i]=0;

	ll pw=1;fo(i,0,nn) G[i]=inv[i]*pw%M,pw=pw*nn%M;
	fo(i,0,nn) F[i]=F[i]*fac[i]%M;
	reverse(F,F+nn+1);

	DFT(F,len,1);DFT(G,len,1);
	fo(i,0,len-1) G[i]=G[i]*F[i]%M;
	DFT(G,len,-1);DFT(F,len,-1);

	reverse(F,F+nn+1);reverse(G,G+nn+1);

	fo(i,0,nn) {
		F[i]=F[i]*inv[i]%M;
		G[i]=G[i]*inv[i]%M;
	}
	fo(i,nn+1,len-1) F[i]=G[i]=0;
	
	DFT(F,len,1);DFT(G,len,1);
	fo(i,0,len-1) F[i]=F[i]*G[i]%M;
	DFT(F,len,-1);

	if (n&1) 
		fd(i,n,0) {
			F[i]=F[i]*(n+1)%M;
			if (i) (F[i]+=F[i-1])%=M;
		}
}

int main() {
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	// ios::sync_with_stdio(false);			//Not

	// cout.tie(0);							//or this.
	// cin.tie(NULL);							//this.
	init(20);pre(1e6+5);
	for(scanf("%d",&ty);ty;ty--) {
		scanf("%d%d",&n,&p);p++;
		if (n==1) {
			puts("1");
			continue;
		}

		solve(n-1);

        // for(ll i=n-2;i>=0;i--){
        //     F[i] = (F[i] - F[i+1] + M);
        //     if(F[i] > M) F[i] -= M;
        // }


		for(ll i=0;i<n;i++)
			cout << F[i] << " ";
		cout << "\n";
		ll ans=0;
		fo(i,1,min(n,p)) (ans+=F[n-i]*C(p-1,i-1)%M)%=M;
		printf("%lld\n",(ans+M)%M);
	}
	return 0;
}