const ll N = 100010, M = 1e9 + 7;

class SegmentTree {
public:
	struct node {

	};
	node null_node;
	vector<node> T;
	vector<ll> arr;
	ll n;

	SegmentTree(vector<ll> _a) {
		arr = _a;
		n = _a.size();
		T = vector<node>(4 * n);
	}

	// Check if two nodes are equal
	bool isEqual(node a, node b) {
		// Logic
		return true;
	}

	// Merge two nodes
	node merge(node a, node b) {
		if (isEqual(a, null_node)) return b;
		if (isEqual(b, null_node)) return a;
		node ret;

		// Logic

		return ret;
	}

	void initNullNode() {
		// Random Values for null node
	}

	void build(ll i, ll l, ll r) {
		if (l == r) {
			// Logic for arr[l]

			return;
		}

		ll m = (l + r) / 2;
		build(2 * i, l, m);
		build((2 * i) + 1, m + 1, r);
		T[i] = merge(
			T[2 * i], 
			T[2 * i + 1]
		);
	}

	node query(ll i, ll l, ll r, ll a, ll b) {
		if (r < a || l > b) return null_node;
		if (l >= a and r <= b) return T[i];

		ll m = (l + r) / 2;
		return merge(
			query(2 * i, l, m, a, b),
			query(2 * i + 1, m + 1, r, a, b)
		);
	}

	void update(ll i, ll l, ll r, ll p, ll x) {
		if (l == r) {
			// Logic for a[l]

			return;
		}

		ll m = (l + r) / 2;
		if (p <= m) update(2 * i, l, m, p, x);
		else update(2 * i + 1, m + 1, r, p, x);
		T[i] = merge(T[2 * i], T[2 * i + 1]);
	}

	void init() {
		initNullNode();
		build(1, 0, n - 1);
	}
};

ll n, q;
vector<ll> a;

void solve() {
	cin >> n >> q;
	a = vector<ll> (n, 0);
	fi (0, n - 1) cin >> a[i];

	SegmentTree S(a);
	S.init();
}