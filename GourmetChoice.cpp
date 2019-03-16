#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m;
ll a[1010][1010], ans1[5010], ans2[5010];
vector<ll> dag[5010];
ll top[5010], vis[5010], disc[5010], size;
ll disc_time, f;

void findDisc(ll x){
	cout << x << "\n";
	vis[x] = 1;
	// disc[x] = disc_time++;

	for(ll i=0;i<dag[x].size();i++)
		if(vis[dag[x][i]] == 0)
			findDisc(dag[x][i]);
		else{
			if(disc[dag[x][i]] < disc[x]){
				cout << x << " " << dag[x][i] << "\n";
				f = 0;
				return;
			}
		}
}

void dfs(ll x){
	vis[x] = 1;
	for(ll i=0;i<dag[x].size();i++)
		if(vis[dag[x][i]] == 0)
			dfs(dag[x][i]);

	top[size--] = x;
}

void te(){
	cin >> n >> m;

	for(ll i=0;i<n+m;i++)
		vis[i] = 0;

	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++){
			char ch;
			cin >> ch;
			if(ch == '>'){
				a[i][j] = 1;
				dag[i].push_back(n + j);
			}
			else if(ch == '<'){
				a[i][j] = -1;
				dag[n+j].push_back(i);
			}
			else
				a[i][j] = 0;
		}

	size = (n + m - 1);

	for(ll i=0;i<n+m;i++)
		if(vis[i] == 0)
			dfs(i);

	// for(ll i=0;i<n+m;i++)
	// 	cout << top[i] << " ";
	// cout << "\n";

	for(ll i=0;i<n+m;i++)
		disc[top[i]] = i;

	ll rank = 1;

	for(ll i=0;i<n+m;i++)
		vis[i] = 0;

	f = 1;
	disc_time = 0;

	// cout << "\n-\n";

	for(ll i=0;i<n+m;i++){
		if(vis[i] == 0)
			findDisc(i);
		// cout << "\n- ";
	}

	// cout << "-\n";

	if(f == 0){
		cout << "No\n";
		return;
	}


	if(top[0] < n)
		ans1[top[0]] = rank;
	else
		ans2[top[0] - n] = rank;

	for(ll i=1;i<n+m;i++){
		if((top[i] < n && top[i-1] < n) || (top[i] >= n && top[i-1] >= n) || (a[min(top[i], top[i-1])][max(top[i], top[i-1])-n] == 0)){
			if(top[i] < n)
				ans1[top[i]] = rank;
			else
				ans2[top[i] - n] = rank;
		}
		else{
			rank++;
			if(top[i] < n)
				ans1[top[i]] = rank;
			else
				ans2[top[i] - n] = rank;
		}
	}

	cout << "Yes\n";
	for(ll i=0;i<n;i++)
		cout << rank - ans1[i] + 1 << " ";
	cout << "\n";

	for(ll i=0;i<m;i++)
		cout << rank - ans2[i] + 1 << " ";
	cout << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}