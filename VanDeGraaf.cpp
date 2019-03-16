#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

struct st
{
	ll red;
	ll green;
	ll blue;
};

ll arr[(ll) 1e5 + 10];
st tree[4 * ((ll) 1e5 + 10)];
ll lazy[4 * ((ll) 1e5 + 10)];

void build_tree(ll node, ll a, ll b) {
  	if(a > b) return;
  	
  	if(a == b) {
  		if(arr[a] == 0){
    		tree[node].red = 1;
    		tree[node].green = 0;
    		tree[node].blue = 0;
  		}
  		if(arr[a] == 1){
    		tree[node].red = 0;
    		tree[node].green = 1;
    		tree[node].blue = 0;
  		}
  		if(arr[a] == 2){
    		tree[node].red = 0;
    		tree[node].green = 0;
    		tree[node].blue = 1;
  		}
		return;
	}
	
	build_tree(node*2, a, (a+b)/2);
	build_tree(node*2+1, 1+(a+b)/2, b);
	
	tree[node].red = tree[node*2].red + tree[node*2+1].red;
	tree[node].green = tree[node*2].green + tree[node*2+1].green;
	tree[node].blue = tree[node*2].blue + tree[node*2+1].blue;
}

void update_tree(ll node, ll a, ll b, ll i, ll j) {
  
  	if(lazy[node] != 0) {
  		if(lazy[node] % 3 == 1){
  			ll t = tree[node].blue;
  			tree[node].blue = tree[node].green;
  			tree[node].green = tree[node].red;
  			tree[node].red = t;
   		}
  		if(lazy[node] % 3 == 2){
  			ll t = tree[node].blue;
  			tree[node].blue = tree[node].red;
  			tree[node].red = tree[node].green;
  			tree[node].green = t;
   		}

		if(a != b) {
			lazy[node*2] += lazy[node];
    		lazy[node*2+1] += lazy[node];
		}

   		lazy[node] = 0;
  	}
  
	if(a > b || a > j || b < i)
		return;
    
  	if(a >= i && b <= j) {
  		ll t = tree[node].blue;
  		tree[node].blue = tree[node].green;
  		tree[node].green = tree[node].red;
  		tree[node].red = t;

		if(a != b) {
			lazy[node*2] += 1;
			lazy[node*2+1] += 1;
		}

    		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j);
	update_tree(1+node*2, 1+(a+b)/2, b, i, j);

	tree[node].red = tree[node*2].red + tree[node*2+1].red;
	tree[node].green = tree[node*2].green + tree[node*2+1].green;
	tree[node].blue = tree[node*2].blue + tree[node*2+1].blue;
}

st query_tree(ll node, ll a, ll b, ll i, ll j) {
	st zero;
	zero.red = 0;
	zero.green = 0;
	zero.blue = 0;

	if(a > b || a > j || b < i) return zero;

	if(lazy[node] != 0) {
		if(lazy[node] % 3 == 1){
  			ll t = tree[node].blue;
  			tree[node].blue = tree[node].green;
  			tree[node].green = tree[node].red;
  			tree[node].red = t;
   		}
  		if(lazy[node] % 3 == 2){
  			ll t = tree[node].blue;
  			tree[node].blue = tree[node].red;
  			tree[node].red = tree[node].green;
  			tree[node].green = t;
   		}

		if(a != b) {
			lazy[node*2] += lazy[node];
    		lazy[node*2+1] += lazy[node];
		}

		lazy[node] = 0;
		// cout << "Hello\n";
	}

	if(a >= i && b <= j){
		st q1 = tree[node];
		// cout << node << " " << q1.red << " " << q1.green << " " << q1.blue << '\n';
		return tree[node];
	}

	st q1 = query_tree(node*2, a, (a+b)/2, i, j);
	st q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);

	// cout << node << " " << q1.red << " " << q1.green << " " << q1.blue << '\n';
	// cout << node << " " << q2.red << " " << q2.green << " " << q2.blue << '\n';

	st res;
	res.red = q1.red + q2.red;
	res.green = q1.green + q2.green;
	res.blue = q1.blue + q2.blue;
	
	return res;
}

void te(){
	ll n;
	cin >> n;

	for(ll i=0;i<n;i++)
		cin >> arr[i];

	for(ll i=0;i<4 * ((ll) 1e5 + 10);i++){
		lazy[i] = 0;
	}

	build_tree(1, 0, n-1);

	st ans = query_tree(1, 0, n-1, 0, 1);
	// cout << ans.red << " " << ans.green << " " << ans.blue << '\n';

	ll q;
	cin >> q;
	while(q--){
		ll ch;
		cin >> ch;
		if(ch == 0){
			// for(ll i=0;i<4*n;i++){
		// cout << i << " " << tree[i].red << " " << tree[i].green << " " << tree[i].blue << "\n";
			
			ll l, r, c;
			cin >> l >> r >> c;

			st ans = query_tree(1, 0, n-1, l-1, r-1);
			// cout << ans.red << " " << ans.green << " " << ans.blue << '\n';
			if(c == 0)
				cout << ans.red << "\n";
			if(c == 1)
				cout << ans.green << "\n";
			if(c == 2)
				cout << ans.blue << "\n";
		}

		if(ch == 1){
			ll l, r;
			cin >> l >> r;

			update_tree(1, 0, n-1, l-1, r-1);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);

	te();
	
	return 0;
}