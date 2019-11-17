#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

string s1, s2;
ll x, y, x2, y2, vis[9][9];

void te(){
	cin >> s1 >> s2;

	x = (ll)(s1[0] - 'a' + 1);
	y = (ll)(s1[1] - '0');

	x2 = (ll)(s2[0] - 'a' + 1);
	y2 = (ll)(s2[1] - '0');

	queue<pair<pair<ll, ll>, ll> > q;
	q.push(make_pair(make_pair(x, y), 0));

	for(ll i=1;i<=8;i++)
		for(ll j=1;j<=8;j++)
			vis[i][j] = 0;

	while(!q.empty()){
		pair<pair<ll, ll>, ll> a = q.front(); q.pop();
		if(a.first.first == x2 && a.first.second == y2){
			cout << a.second << "\n";
			return;
		}

		for(ll i=0;i<2;i++)
			for(ll j=0;j<2;j++)
				for(ll k=0;k<2;k++){
					ll add1 = 1;
					ll add2 = 2;
					ll pow1 = 1;
					ll pow2 = 1;
					if(i == 0)
						swap(add1, add2);
					if(j == 0)
						pow1 = -1;
					if(k == 0)
						pow2 = -1;

					ll new_x = a.first.first + (add1 * pow1);
					ll new_y = a.first.second + (add2 * pow2);
					if(new_x >= 1 && new_x <= 8 && new_y >= 1 && new_y <= 8 && vis[new_x][new_y] == 0)
						q.push(make_pair(make_pair(new_x, new_y), a.second + 1));
				}
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
		te();

	return 0;
}