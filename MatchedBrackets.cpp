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

ll n, arr[100010];

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> arr[i];

	ll a = n, b = 0, c = 0, d = 0, length = 0, depth = 0, start = 0;

	stack<ll> s;

	for(ll i=0;i<n;i++){
		if(arr[i] == 1){
			s.push(1);
			depth++;
		}

		if(arr[i] == 2){
			s.pop();
			depth--;
		}

		if(depth > b){
			b = depth;
			a = i + 1;
		}

		if(depth == 0){
			length = i + 1 - start;
			if(length > c){
				c = length;
				d = start;
			}
			start = i + 1;
		}
	}

	cout << b << " " << a << " " << c << " " << d + 1 << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}