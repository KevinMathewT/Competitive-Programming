#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n;
ld okay[100], x[100], y[100];

ld dist(ld x1, ld y1, ld x2, ld y2){
	return sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));
}

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> x[i] >> y[i];

	ll c = 0;

	for(ll i=2;i<n;i++){
		ld ang = (x[i] - x[i-1]) * (x[i-1] * x[i-2]) + (y[i] - y[i-1]) * (y[i-1] * y[i-2]);
		ang /= dist(x[i], y[i], x[i-1], y[i-1]) * dist(x[i-2], y[i-2], x[i-1], y[i-1]);
		if(ang >= sqrt(2) && ang <= 1)
			okay[i-2] = 1;
		else
			okay[i-2] = 0, c++;
	}

	if(c == 0){
		cout << "yes yes\n";
		return;
	}

	if(c > 3){
		cout << "no no\n";
		return;
	}

	if(c == 1){
		cout << "no yes\n";
		return;
	}

	if(c == 2){
		for(ll i=0;i<n-3;i++)
			if(okay[i] == 0 && oka)
	}

	if(c == 3){

	}
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}