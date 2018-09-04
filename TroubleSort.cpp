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
ll test = 1;

void bucketSort(ld arr[], ll n)
{
    vector<ld> b[n];
    for (ll i=0; i<n; i++)
    {
       ll bi = n*arr[i]; 
       b[bi].push_back(arr[i]);
    }
    for (ll i=0; i<n; i++)
       sort(b[i].begin(), b[i].end());
    ll index = 0;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < b[i].size(); j++)
          arr[index++] = b[i][j];
}

void te(){
	ll n; cin >> n;
	ll a = 0, b = 0;
	ld x[n], o[(ll)(ceil(n/2.0))], e[n/2]; 
	for(ll i=0;i<n;i++){ 
		cin >> x[i];
		if(i % 2 == 0)
			o[a++] = x[i];
		else
			e[b++] = x[i];
	}
	for(ll i=0;i<o.size();i++)
		cout << o[i] << " ";
	cout << "\n" << a << "\n";
	for(ll i=0;i<e.size();i++)
		cout << e[i] << " ";
	cout << "\n" << b << "\n";
	bucketSort(o, a); bucketSort(e, b);
	// for(ll i=0;i<n;i++){
	// 	if(i%2 == 0){
	// 		if(i/2 > b-1) continue;
	// 		if(o[i/2] > e[i/2]){
	// 			cout << "Case #" << (test++) << ": " << i << "\n";
	// 			return;
	// 		}
	// 	}
	// 	else{
	// 		if(((i/2)+1) > a-1) continue;
	// 		if(e[i/2] > o[(i/2)+1]){
	// 			cout << "Case #" << (test++) << ": " << i << "\n";
	// 			return;
	// 		}
	// 	}
	// }

	cout << "Case #" << (test++) << ": OK\n";
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T; cin >> T;
	while(T--) te();

	return 0;
}