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

ll a, b;

void solve(){
	cin >> a >> b;
	// cout << log(5) << " " << log(2) << "\n";

	if(a == b){
		cout << a + 1 << "\n";
		return;
	}

	if(a < b){
		ll out = a;
		b -= a;

		out += ceil((ld)log10(5) * (ld)b);
		
		cout << out << "\n";
		return;
	}

	if(a > b){
		swap(a, b);
		ll out = a;
		b -= a;

		out += ceil((ld)log10(2) * (ld)b);

		cout << out << "\n";
		return;
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