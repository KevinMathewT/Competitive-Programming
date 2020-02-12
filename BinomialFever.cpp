#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second

clock_t t_start,t_end;
void start_clock(){
    t_start = clock();
}
void end_clock(){
    t_end = clock();
    ld timeis = t_end - t_start;
    printf("\n\nTime taken : %f s", ((float)timeis)/CLOCKS_PER_SEC);
}

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
NTT Code Adapted from: https://s3.amazonaws.com/codechef_shared/download/Solutions/MARCH18/Editorialist/CHEFKNN.cpp
*/

const int M = 998244353;

ll power(ll a,ll b,ll m = M){
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
    if(ans>=M) return ans%M;
    return ans;
}

// NTT helper
const int root_pw = 1 << 23;
const int root = power(3, (M - 1) / root_pw);  // g^((M-1)/root_pw)
const int root_1 = power(root, M - 2);
const int LG = 23;
const int N = 2e5 + 10;

int copyA[root_pw],rev[root_pw],invW[root_pw>>1],W[root_pw>>1];
void precompute_powers(){
    W[0] = invW[0] = 1;
    for(int i = 1;i<(root_pw>>1);i++){
        W[i] = mul(W[i-1],root);
        invW[i] = mul(invW[i-1],root_1);
    }
    int k = 0; while ((1 << k) < root_pw) ++k;
    rev[0] = 0;
    for (int i = 1; i < root_pw; i++) {
        rev[i] = rev[i >> 1] >> 1 | ((i & 1) << k - 1);
    }
}
void ntt (int* a,const int &n,const bool &invert) {
    memcpy(copyA,a,n*sizeof(int));
    int k = 0; while ((1 << k) < n) ++k;
    for (int i = 0; i < n; i++) {
        a[i] = copyA[rev[i] >> (LG - k)];
    }
    int * mkb = invert?invW:W;
    int prev_len = 1, u,v,len,i,ind,add,j;
    for (len=2; len<=n; len<<=1) {
        for (i=0; i<n; i+=len) {
            ind = 0,add = root_pw/len;
            for (j=0; j<prev_len; ++j) {
                u = a[i+j],  v = mul(a[i+j+prev_len],mkb[ind]);
                a[i+j] = u+v < M ? u+v : u+v-M;
                a[i+j+prev_len] = u-v >= 0 ? u-v : u-v+M;
                ind += add;
            }
        }
        prev_len = len;
    }
    if (invert) {
        int nrev = power(n, M-2, M);
        for (int i=0; i<n; ++i)
            a[i] = mul(a[i], nrev);
    }
}
void mul(int *a, const int &n1, int *b, const int &n2){
    int n = n1 + n2 - 1, i;
    int m = 1; while(m < n) m <<= 1;
    for(i=n1;i<m;++i) a[i] = 0;
    for(i=n2;i<m;++i) b[i] = 0;
    ntt(a, m, 0); ntt(b, m, 0);
    for(i=0;i<m;++i) a[i] = mul(a[i], b[i]);
    ntt(a,m,1);
}
// ENDS

// Combinatorics
int fact[N], inverse[N], fact_inverse[N];

void precalc(){
    fact[0] = 1;
    
    inverse[0]=1;inverse[1]=1;
    
    fact_inverse[0] = 1; fact_inverse[1] = 1;
    
    for(int i=1;i<N;i++)
        fact[i] = mul(i, fact[i-1]);
        
    for(int i=2;i<N;i++){
        inverse[i]=(M-mul(M/i, inverse[M % i]))%M;
        fact_inverse[i]=mul(inverse[i], fact_inverse[i-1]);
    }
}
 
inline int choose(const int &n, const int &r){
    return mul(fact[n],mul(fact_inverse[r],fact_inverse[n-r]));
}
// Ends

// finding (x+1)(x+2)(x+3)...(x+n) in O(nlogn)
// coefficients are stored in cur[i]
int dig[23];
int cur[root_pw];
int polyA[root_pw],polyB[root_pw];
 
void doit(int n){
    int ptr = 0;
    while(n){
        dig[ptr++] = (n&1);
        n >>= 1;
    }
    // lets represent f_n(x) = (x+1)(x+2)...(x+n)
    n = 1;  // start with (x+1)
    cur[0]=cur[1]=1;
    for(int j=ptr-2;j>=0;j--){
        
        // f_2n(x) = f_n(x) * f_n(x+n)
        // finding f_n(x+n)
        for(int i=0;i<=n;i++) polyA[i]=mul(cur[n-i],fact[n-i]);
        int pw = 1;
        for(int i=0;i<=n;i++){
            polyB[i]=mul(pw,fact_inverse[i]);   
            pw = mul(pw,n);
        }
        mul(polyB,n+1,polyA,n+1);
        for(int i=0;i<=n;i++){
            polyA[i]=mul(polyB[n-i],fact_inverse[i]);
        }
        // ends
 
        mul(cur,n+1,polyA,n+1);
 
        n<<=1; 
        
        if(dig[j]){
            // find f_(n+1)(x) given f_n(x)
            for(int i=n+1;i>0;i--) cur[i]=cur[i-1];
            cur[0]=0;
            n += 1;
            for(int i=0;i<n;i++){
                cur[i]+=mul(cur[i+1],n);
                if(cur[i]>=M) cur[i]-=M;
            }
        }
    }
}
// ends

void solve(int n, int p, int r){
    // doit(r - 1);

    if(p == 1 && r == 1){
        cout << ((n + 1) % M) << "\n";
        return;
    }

    if(p == 998244352){
        if(r == 1){
            if(n % 2 == 0) cout << 1 << "\n";
            else cout << 0 << "\n";
            return;
        }

        if(r % 2 == 0) cout << (n % 2 == 1 ? (n + 1) / 2 : n / 2) % M << "\n";
        else cout << (M - (n % 2 == 1 ? (n + 1) / 2 : n / 2)) % M << "\n";

        return;
    }

    // start_clock();
    doit(r - 1);
    // // end_clock();

    // // start_clock();

    // ll sum = 0;

    // for(ll i=0;i<r;i++){
    //     ll k = i + 1;
    //     ll k4 = (power(p, n * k + k) - 1);
    //     if(k4 < 0) k4 += M;
    //     ll k3 = (power(p, k) - 1);
    //     if(k3 < 0) k3 += M;
    //     ll k5 = (k4 * power(k3, M - 2)) % M;
    //     ll k6 = (cur[i] * k5) % M;

    //     // cout << k << ' ' << k5 << "\n";

    //     if((r - i) % 2 == 1){
    //         sum = (sum + k6);
    //         if(sum > M) sum -= M;
    //     }
    //     else{
    //         sum = (sum - k6);
    //         if(sum < 0) sum += M;
    //     }
    // }

    // sum = (sum * power(fact[r], M - 2)) % M;

    // cout << sum << "\n";
}

int main(){
    freopen("input.txt", "r", stdin);        //Comment
    freopen("output.txt", "w", stdout);      //this out.

    start_clock();

    precompute_powers();
    precalc();
    int t;
    cin >> t;
    while(t--){
        int n,p,r;
        cin >> n >> p >> r;
        solve(n,p,r);
    }

    end_clock();
}