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

char getSmallDgtGreaterThanZero(string num, ll n)
{
        char s_dgt = '9';
     
    for (ll i=0; i<n; i++)
        if (num[i] < s_dgt && num[i] != '0')
            s_dgt = num[i];
    return s_dgt;
}
string kthSmallestNumber(string num, ll k)
{
    ll freq[10];
    string final_num = "";
 
    memset(freq, 0, sizeof(freq));
    ll n = num.size();
    for (ll i = 0; i < n; i++)
        freq[num[i] - '0']++;
     
    char s_dgt = getSmallDgtGreaterThanZero(num, n);
    final_num += s_dgt;
    freq[s_dgt - '0']--;
    for (ll i=0; i<10; i++)
        for (ll j=1; j<=freq[i]; j++)
            final_num += (char)(i+48);
    for (ll i=1; i<k; i++)
      next_permutation(final_num.begin(), final_num.end());
    return final_num;
}
int main()
{
    string num;
    cin << num;
    ll k = 4;
    cout << kthSmallestNumber(num, k);
    return 0;
}