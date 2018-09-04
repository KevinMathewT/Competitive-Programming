#include <bits/stdc++.h>
#define ll long long
#define ld double

using namespace std;

void te(){
	cin.ignore(256, '\n');
	string s; cin >> s;
	ll n; cin >> n;
	ll a = 0, b = 0, na = 0, nb = 0, ans = 0;
	for(ll i=0;i<s.length();i++){
		if(s[i] == 'a')
			a++;
		else
			b++;
	}
	// cout << "=================\n";
	// cout << "a = " << a << " b = " << b << "\n";
	ll rate = a-b;
	if(rate > 0){
		for(ll i=0;i<s.length();i++){
			if(s[i] == 'a') na++; else na--;

			if(na > 0){ ans += n; }
			else if(na == 0){ ans += (n-1); }
			else { ll x = (na/(0-rate)); x = (x + 1) > n ? n-1 : x; ans += n - (x + 1); }
			// cout << "ans = " << ans << "\n";
		}
	}
	if(rate < 0){
		for(ll i=0;i<s.length();i++){
			if(s[i] == 'a') na++; else na--;

			if(na <= 0){ }
			else { ll x = ceil((ld)na/(0.0-rate)); x = x > n ? n : x; ans += x; }
			// cout << "ans = " << ans << "\n";
		}
	}
	if(rate == 0){
		for(ll i=0;i<s.length();i++){
			if(s[i] == 'a') na++; else na--;
			if(na > 0) ans += n;
		}
	}
	// cout << "=================\n";
	cout << ans << "\n";
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