#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, size, a[2*100000], tree[8*100000], theEnd = 0;

void update(ll i, ll l, ll r, ll p, ll v, ll depth){
	// cout << i << "-\n";
	if(l == r){
		tree[i] = v;
		theEnd = depth;
		return;
	}
	ll mid = (l + r) / 2;  

	if(p <= mid)
		update(2*i, l, mid, p, v, depth+1);
	else
		update(2*i+1, mid+1, r, p, v, depth+1);

	if(depth % 2 != 0)
		if(theEnd % 2 == 0)
			tree[i] = (tree[2*i] | tree[2*i+1]);
		else
			tree[i] = (tree[2*i] ^ tree[2*i+1]);
	else
		if(theEnd % 2 == 0)
			tree[i] = (tree[2*i] ^ tree[2*i+1]);
		else
			tree[i] = (tree[2*i] | tree[2*i+1]);

	// cout << tree[i] << " " << tree[2*i] << " " << tree[2*i+1] << " " << depth << " " << theEnd << "\n";;
}

void build(ll i, ll l, ll r, ll depth){
	if(l == r){
		tree[i] = a[l];
		theEnd = depth;
		return;
	}
	ll mid = (l + r) / 2;
	
	build(2*i, l, mid, depth+1);
	build(2*i + 1, mid+1, r, depth+1);

	if(depth % 2 != 0)
		if(theEnd % 2 == 0)
			tree[i] = (tree[2*i] | tree[2*i+1]);
		else
			tree[i] = (tree[2*i] ^ tree[2*i+1]);
	else
		if(theEnd % 2 == 0)
			tree[i] = (tree[2*i] ^ tree[2*i+1]);
		else
			tree[i] = (tree[2*i] | tree[2*i+1]);

	// cout << tree[i] << " " << tree[2*i] << " " << tree[2*i+1] << " " << depth << " " << theEnd << "\n";;
}

void te(){
	cin >> n >> m;
	size = pow(2, n);

	for(ll i=0;i<size;i++){
		cin >> a[i];
	}

	build(1, 0, size-1, 0);

	// for(ll i=0;i<9;i++)
	// 	cout << i << " " << tree[i] << "\n";

	while(m--){
		ll p, v;
		cin >> p >> v;
		update(1, 0, size-1, p-1, v, 0);
		// for(ll i=0;i<9;i++)
		// 	cout << i << " " << tree[i] << "\n";
		cout << tree[1] << "\n";
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}