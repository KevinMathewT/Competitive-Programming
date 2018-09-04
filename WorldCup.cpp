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

int main()
{
	//freopen("input.txt", "r", stdin);		//Comment
	//freopen("output.txt", "w", stdout);		//this
	//start_clock();							//out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll n, a, b;
	read(n, a, b);
	ll c = max(a, b);
	ll d = min(a, b);

	ll l = 1, r = n, round = log2(n);
	while(l < r){
		ll mid = (l + r) / 2;
		// cout << c << " " << d << " " << mid << "\n";
		if(c <= mid && d < mid){
			round--;
			r = mid;
			continue;
		}
		if(c > mid && d > mid){
			round--;
			l = mid + 1;
			continue;
		}
		break;
	}

	if(round == log2(n)){
		cout << "Final!";
		return 0;
	}
	cout << round;

	//end_clock();							//This too.
	return 0;
}