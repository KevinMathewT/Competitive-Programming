#include <bits/stdc++.h>
#include <iostream>
#include <string>
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

ll getClosestK(ll *a, ll x, ll l) {

    ll low = 0;
    ll high = l - 1;

    while (low < high) {
        ll mid = (low + high) / 2;
        assert(mid < high);
        ll d1 = abs(a[mid  ] - x);
        ll d2 = abs(a[mid+1] - x);
        if (d2 <= d1)
        {
            low = mid+1;
        }
        else
        {
            high = mid;
        }
    }
    return a[high];
}

ll bs_lower_bound(ll a[], ll n, ll x) {
    ll l = 0;
    ll h = n-1;
    ll idx;
    while (l <= h) {
        ll mid = (l + h) / 2;
        if (x <= a[mid]) {
            h = mid - 1;
        } else {
        	idx = mid;
            l = mid + 1;
        }
    }
    return a[idx];
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	string s;
	ll i;
	getline(cin, s);
	char c[s.length()], d[s.length()];
	F0(i, s.length()) c[i]=s[i];
	F0(i, s.length()) d[i]=c[i];
	sort(d, d+s.length());
	map<ll, ll> m;
	F0(i, s.length()) m[(ll)c[i]]=i;
	ll n[s.length()];
	F0(i, s.length()) n[i]=(s.length()-m[d[i]])*(s.length()-m[d[i]]+1)/2;
	ll cum[s.length()+1];
	cum[0]=0;
	cum[1]=n[0];
	F0(i, s.length()-2)cum[i+2]=cum[i+1]+n[i+1];
	map<ll, ll> mcum;
	F0(i, s.length()) mcum[cum[i]]=i;

	ll g=0;
	ll q;
	read(q);
	while(q--){
		ll p, mod, z;
		read(z);
		//z = (((p % mod) * (g % mod)) % mod) + 1;
		ll u = bs_lower_bound(cum, s.length(), z);
		ll pos = m[(d[(mcum[u])])];
		float j = ceil(((sqrt(1.0 + (8.0 * (double)(z-u))) - 1.0)/2.0)) - 1;
		char ans = s[pos+(z-u-(j*(j+1)/2))-1];
		g = g + ans;
		cout << ans <<"\n";
	}

	end_clock();							//This too.
	return 0;
}