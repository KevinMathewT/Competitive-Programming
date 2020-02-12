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
NTT Code Adapted from: https://s3.amazonaws.com/codechef_shared/download/Solutions/MARCH18/Setter/CHEFKNN.cpp
*/

const ll M = 998244353, G = 3, MAXN = 1 << 23;
 
ll gpow[30], invgpow[30];
ll fact[MAXN], invfact[MAXN];
ll inv[MAXN];
 
ll power(ll number, ll exponent) {
    ll answer = 1;
    while (exponent) {
        if (exponent & 1) {
            answer = (long long)answer * number % M;
        }
        number = (long long)number * number % M;
        exponent >>= 1;
    }
    return answer;
}
 
void init() {
    fact[0] = 1;
    for (ll i = 1; i < MAXN; i++) {
        fact[i] = (long long)fact[i - 1] * i % M;
    }
    invfact[MAXN - 1] = power(fact[MAXN - 1], M - 2);
    for (ll i = MAXN - 2; i >= 0; i--) {
        invfact[i] = (long long)invfact[i + 1] * (i + 1) % M;
    }
    inv[1] = 1;
    for (ll i = 2; i < MAXN; i++) {
        inv[i] = (long long)(M - M / i) * inv[M % i] % M;
    }
 
    ll where = (M - 1) / 2, invg = power(G, M - 2);
    ll idx = 0;
    while (where % 2 == 0) {
        idx++;
        gpow[idx] = power(G, where);
        invgpow[idx] = power(invg, where);
        where /= 2;
    }
}
 
void ntt(ll *a, ll n, ll sign) {
    for (ll i = n >> 1, j = 1; j < n; j++) {
        if (i < j) swap(a[i], a[j]);
        ll k = n >> 1;
        while (k & i) {
            i ^= k;
            k >>= 1;
        }
        i ^= k;
    }
    for (ll l = 2, idx = 1; l <= n; l <<= 1, idx++) {
        ll omega = (sign == 1) ? gpow[idx] : invgpow[idx];
        for (ll i = 0; i < n; i += l) {
            ll value = 1;
            for (ll j = i; j < i + (l>>1); j++) {
                ll u = a[j], v = (long long)a[j + (l>>1)] * value % M;
                a[j] = (u + v); a[j] = (a[j] >= M) ? a[j] - M : a[j];
                a[j + (l>>1)] = (u - v); a[j + (l>>1)] = (a[j + (l>>1)] < 0) ? a[j + (l>>1)] + M : a[j + (l>>1)];
                value = (long long)value * omega % M;
            }
        }
    }
    if (sign == -1) {
        const ll x = power(n, M - 2);
        for (ll i = 0; i < n; i++) {
            a[i] = (long long)a[i] * x % M;
        }
    }
}
 
void multiply(ll* a, ll na, ll* b, ll nb) {
    na++; nb++;
    ll n = 1; while (n < na + nb - 1) n <<= 1;
    for (ll i = na; i < n; i++) {
        a[i] = 0;
    }
    for (ll i = nb; i < n; i++) {
        b[i] = 0;
    }
 
    ntt(a, n, +1); ntt(b, n, +1);
    for (ll i = 0; i < n; i++) {
        a[i] = (long long)a[i] * b[i] % M;
    }
    ntt(a, n, -1);
    for (ll i = na + nb - 1; i < n; i++) {
        a[i] = 0;
    }
}
 
ll stirling[MAXN], shstr[MAXN];
ll aux[MAXN];
 
void shiftStirling(ll n) {
    for (ll i = 0; i <= n; i++) {
        shstr[i] = (long long)fact[i] * stirling[i] % M;
    }
    for (ll i = 0, val = 1; i <= n; i++, val = (long long)val * n % M) {
        aux[n - i] = (long long)val * invfact[i] % M;
    }
    multiply(shstr, n, aux, n);
    for (ll i = 0; i <= n; i++) {
        shstr[i] = (long long)shstr[i + n] * invfact[i] % M;
    }
}
 
void compute(ll n) {
    if (n == 1) {
        stirling[0] = 1;
        stirling[1] = 1;
        return;
    }
 
    compute(n >> 1);
    shiftStirling(n >> 1);
    if (n & 1) {
        for (ll i = 0; i <= (n >> 1) + 1; i++) aux[i] = 0;
        for (ll i = 0; i <= (n >> 1); i++) {
            aux[i] = (aux[i] + (long long)shstr[i] * n) % M;
            aux[i+1] = (aux[i+1] + shstr[i]);
            aux[i+1] = (aux[i+1] >= M) ? aux[i+1] - M : aux[i+1];
        }
        for (ll i = 0; i <= (n >> 1) + 1; i++) {
            shstr[i] = aux[i];
        }
    }
 
    multiply(stirling, n >> 1, shstr, (n + 1) >> 1);
}
 
int main() {
    freopen("input.txt", "r", stdin);        //Comment
    freopen("output.txt", "w", stdout);      //this out.
    ios::sync_with_stdio(false);            //Not
    cin.tie(NULL);                          //this.
    cout.tie(0);                            //or this.
    init();
    
    ll T; 
    cin >> T;
    while(T--){
        ll n, p, r; 
        cin >> n >> p >> r;

        if(p == 1 && r == 1){
            cout << ((n + 1) % M) << "\n";
            continue;
        }

        if(p == 998244352){
            if(r == 1){
                if(n % 2 == 0) cout << 1 << "\n";
                else cout << 0 << "\n";
                continue;
            }

            if(r % 2 == 0) cout << (n % 2 == 1 ? (n + 1) / 2 : n / 2) % M << "\n";
            else cout << (M - (n % 2 == 1 ? (n + 1) / 2 : n / 2)) % M << "\n";

            continue;
        }

        start_clock();
        compute(r - 1);
        end_clock();

        start_clock();

        ll sum = 0;

        for(ll i=0;i<r;i++){
            ll k = i + 1;
            ll k4 = (power(p, n * k + k) - 1);
            if(k4 < 0) k4 += M;
            ll k3 = (power(p, k) - 1);
            if(k3 < 0) k3 += M;
            ll k5 = (k4 * power(k3, M - 2)) % M;
            ll k6 = (stirling[i] * k5) % M;

            // cout << k << ' ' << k5 << "\n";

            if((r - i) % 2 == 1){
                sum = (sum + k6);
                if(sum > M) sum -= M;
            }
            else{
                sum = (sum - k6);
                if(sum < 0) sum += M;
            }
        }

        sum = (sum * power(fact[r], M - 2)) % M;

        cout << sum << "\n";

        end_clock();
    }
 
    return 0;
}