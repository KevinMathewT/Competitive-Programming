#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;
typedef double ld;

void te(){
	ll x1, x2, x3, v1, v2;
	cin >> x1 >> x2 >> x3 >> v1 >> v2;
	ld t1 = (x1-x3+0.0) / (v1+0.0);
	ld t2 = (x3-x2+0.0) / (v2+0.0);

	if(t1 < t2) cout << "Kefa\n";
	if(t1 > t2) cout << "Chef\n";
	if(t1 == t2) cout << "Draw\n";
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// cout << "YAY\n";

	ll T; cin >> T;
	while(T--) te();

	return 0;
}