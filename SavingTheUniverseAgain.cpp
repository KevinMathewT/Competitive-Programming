#include <bits/stdc++.h>
#define ll long long
#define ld double

using namespace std;

ll test = 1;

void te(){
	ll n; string s;
	cin >> n >> s;
	ll a[s.length()];
	ll c = 0, st = 1;
	for(ll i=0;i<s.length();i++){
		if(s[i] == 'C')
			st *= 2;
		if(s[i] == 'S'){
			a[c++] = st;
			st = 1;
		}
	}
	ll tot = 0; for(ll i=0;i<c;i++) tot += a[i];
	ll hacks = 0;

	while(tot > n){
		
	}

	cout << "Case #" << (test++) << ": " << hacks << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll T;
	cin >> T;
	for(ll i=0;i<T;i++) te();
	return 0;
}