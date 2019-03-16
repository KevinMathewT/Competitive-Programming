#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SIZE 20

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

struct bit
{
	ll bits[SIZE][2];
	ll sum;
};

bit zero;

ll n, m, a[100010], lazy[400010];
bit tree[400010];

void update(ll i, ll l, ll r, ll a, ll b, ll v){
	if(lazy[i] != 0){
		ll s = 0;
		for(ll j=0;j<SIZE;j++){
			if((1 << j) & lazy[i]){
				s -= (1 << j) * tree[i].bits[j][1];
				s += (1 << j) * tree[i].bits[j][0];
				swap(tree[i].bits[j][0], tree[i].bits[j][1]);
			}
		}

		if(l != r){
			lazy[2*i] ^= lazy[i];
			lazy[2*i+1] ^= lazy[i];
		}

		lazy[i] = 0;
		tree[i].sum += s;
	}

	if(r < a || l > b || r < l)
		return;

	if(l >= a && r <= b){
		ll s = 0;
		for(ll j=0;j<SIZE;j++){
			if((1 << j) & v){
				s -= (1 << j) * tree[i].bits[j][1];
				s += (1 << j) * tree[i].bits[j][0];
				swap(tree[i].bits[j][0], tree[i].bits[j][1]);
			}
		}

		tree[i].sum += s;
		if(l != r){
			lazy[2*i] ^= v;
			lazy[2*i+1] ^= v;
		}
		return;
	}

	ll mid = (l + r) / 2;
	update(2*i, l, mid, a, b, v);
	update(2*i+1, mid+1, r, a, b, v);

	tree[i].sum = tree[2*i].sum + tree[2*i+1].sum;

	for(ll j=0;j<SIZE;j++){
		tree[i].bits[j][0] = tree[2*i].bits[j][0] + tree[2*i+1].bits[j][0];
		tree[i].bits[j][1] = tree[2*i].bits[j][1] + tree[2*i+1].bits[j][1];
	}
}

ll query(ll i, ll l, ll r, ll a, ll b){
	// cout << i << " " << lazy[i] << "\n";
	if(lazy[i] != 0){
		ll s = 0;
		for(ll j=0;j<SIZE;j++){
			if((1 << j) & lazy[i]){
				s -= (1 << j) * tree[i].bits[j][1];
				s += (1 << j) * tree[i].bits[j][0];
				swap(tree[i].bits[j][0], tree[i].bits[j][1]);
			}
		}

		if(l != r){
			lazy[2*i] ^= lazy[i];
			lazy[2*i+1] ^= lazy[i];
		}

		lazy[i] = 0;
		tree[i].sum += s;
	}

	if(r < a || l > b || r < l)
		return 0;

	if(l >= a && r <= b){
		return tree[i].sum;
	}

	ll s1, s2;
	ll mid = (l + r) / 2;
	s1 = query(2*i, l, mid, a, b);
	s2 = query(2*i+1, mid+1, r, a, b);
	// cout << i << " " << s1 << " " << s2 << "--\n";

	return (s1 + s2);
}

void build(ll i, ll l, ll r){
	if(l == r){
		tree[i].sum = a[l];
		for(ll j=0;j<SIZE;j++){
			// cout << ((1<<j) & a[l]) << "\n";
			if(((1<<j) & a[l]) == 0){
				tree[i].bits[j][0] = 1;
				tree[i].bits[j][1] = 0;
			}
			else{
				tree[i].bits[j][0] = 0;
				tree[i].bits[j][1] = 1;
			}
		}

		// cout << tree[i].sum << "\n";
		// for(ll j=0;j<SIZE;j++)
		// 	cout << tree[i].bits[j][0] << " ";
		// cout << "\n";

		// for(ll j=0;j<SIZE;j++)
		// 	cout << tree[i].bits[j][1] << " ";
		// cout << "\n";

		// cout << "----------------\n";

		return;
	}

	ll mid = (l + r) / 2;

	build(2*i, l, mid);
	build(2*i+1, mid+1, r);

	tree[i].sum = tree[2*i].sum + tree[2*i+1].sum;

	for(ll j=0;j<SIZE;j++){
		tree[i].bits[j][0] = tree[2*i].bits[j][0] + tree[2*i+1].bits[j][0];
		tree[i].bits[j][1] = tree[2*i].bits[j][1] + tree[2*i+1].bits[j][1];
	}
}

void te(){
	for(ll i=0;i<400010;i++)
		lazy[i] = 0;
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	build(1, 0, n-1);

	cin >> m;
	ll t = m;
	while(m--){
		// cout << "------------\n" << t-m << "\n";
		ll ch;
		cin >> ch;

		if(ch == 1){
			ll l, r;
			cin >> l >> r;
			cout << query(1, 0, n-1, l-1, r-1) << "\n";
		}
		else{
			ll l, r, v;
			cin >> l >> r >> v;
			update(1, 0, n-1, l-1, r-1, v);
		}
		
		// for(ll i=0;i<n;i++)
		// 	cout << query(1, 0, n-1, i, i) << " " ;
		// cout << "\n";
		// for(ll i=0;i<10;i++)
		// 	cout << i << "\t";
		// cout << "\n";
		// for(ll i=0;i<10;i++)
		// 	cout << tree[i].sum << "\t";
		// cout << "\n";
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