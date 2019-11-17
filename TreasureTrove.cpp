#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    os << "]";
	return os;
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n;
char a[1010][1010], b[1010][1010];

void left(ll &x, ll &y, ll k){
	x -= k;
}

void right(ll &x, ll &y, ll k){
	x += k;
}

void up(ll &x, ll &y, ll k){
	y -= k;
}

void down(ll &x, ll &y, ll k){
	y += k;
}

void rotP(ll x, ll y, ll k){
	ll layer = min(i, min(j, min(n - i - 1, n - j - 1)));

	
}

void solve(){
	cin >> n;

	vector<pair<ll, ll> > x;

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++){
			cin >> a[i][j];
			if(a[i][j] == 'X')
				x.push_back({i, j});
		}

	vector<ll> l(n / 2, LLONG_MAX);

	for(ll i=0;i<x.size();i++){
		ll layer = min(x[i].F, min(x[i].S, min(n - x[i].F - 1, n - x[i].S - 1)));

		cout << x[i].F << ' ' << x[i].S << " " << layer << "\n";
		if(x[i].F == layer){
			ll rot = x[i].S - layer;
			cout << rot << "\n";
			if(rot <= abs(l[layer]))
				l[layer] = rot;
		}
		else if((n - x[i].S - 1) == layer){
			ll rot = x[i].F - layer + n - 2 * layer - 1;
			cout << rot << "\n";
			if(rot <= abs(l[layer]))
				l[layer] = rot;	
		}
		else if(x[i].S == layer){
			ll rot = x[i].F - layer;
			cout << rot << "\n";
			if(rot < abs(l[layer]))
				l[layer] = -rot;
		}
		else if((n - x[i].F - 1) == layer){
			ll rot = x[i].S - layer + n - 2 * layer - 1;
			cout << rot << "\n";
			if(rot < abs(l[layer]))
				l[layer] = -rot;	
		}
	}

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++){
			ll layer = min(i, min(j, min(n - i - 1, n - j - 1)));
			ll sz = n - 2 * (layer);
			ll movx, movy;
			ll x = i, y = j;

			if(x == layer){
				if(l[layer] > 0)
					if(l[layer] < layer)
						right(i, j, l[layer]);
					else
						down(i, j, layer - 1), down(i, j, -l[layer] - layer + 1);

				else if(l[layer] < 0)
					if(-l[layer] < layer)
						down(i, j, -l[layer]);
					else
						right(i, j, layer - 1), down(i, j, -l[layer] - layer + 1);
			}
			else if((n - y - 1) == layer){
				if(l[layer] > 0)
					if(l[layer] < layer)
						down(i, j, l[layer]);
					else
						left(i, j, layer - 1), down(i, j, -l[layer] - layer + 1);

				else if(l[layer] < 0)
					if(-l[layer] < layer)
						down(i, j, -l[layer]);
					else
						right(i, j, layer - 1), down(i, j, -l[layer] - layer + 1);
			}
			else if(y == layer){
				if(l[layer] > 0)
					if(l[layer] < layer)
						right(i, j, l[layer]);
					else
						down(i, j, layer - 1), down(i, j, -l[layer] - layer + 1);

				else if(l[layer] < 0)
					if(-l[layer] < layer)
						down(i, j, -l[layer]);
					else
						right(i, j, layer - 1), down(i, j, -l[layer] - layer + 1);
			}
			else if((n - x - 1) == layer){
				if(l[layer] > 0)
					if(l[layer] < layer)
						right(i, j, l[layer]);
					else
						down(i, j, layer - 1), down(i, j, -l[layer] - layer + 1);

				else if(l[layer] < 0)
					if(-l[layer] < layer)
						down(i, j, -l[layer]);
					else
						right(i, j, layer - 1), down(i, j, -l[layer] - layer + 1);
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

	solve();

	return 0;
}