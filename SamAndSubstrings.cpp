#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

ll recurse(ll n){
	if(to_string(n).length() == 1)
		return n;

	ll sum = n;

	return sum = sum + recurse(stoi(to_string(n).substr(1))) + recurse(n/10);
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);

	ll mod = 1e9 + 7;
	string n;
	cin >> n;
	ll sum = 0;
	for(ll i=0;i<n.length();i++){
		for(ll j=1;i+j<=n.length();j++)
			sum = (sum%mod + stoll(n.substr(i, j))%mod)%mod;
	}

	cout << sum << "\n";
}