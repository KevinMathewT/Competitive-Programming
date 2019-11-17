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

ll n, s, t, k, g[100][100], p[100][100];

struct Node{
	ll v, vis, vis2, paths;
	Node(ll u){
		v = u;
		vis = vis2 = 0;
		paths = 0;
	}
};

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			cin >> a[i][j];
	cin >> s >> t >> k;

	queue<Node>	q;
	q.push()

	while(!q.empty()){
		Node p = q.front();
	}
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