typedef long long ll;
struct node {
    ll add = 0;
    ll value = 0;
    node() {}
};

ll add(ll a, ll b) {
    static ll mod = (ll)(1e9 +7);
    return (a + b) % mod;
}

class Segtree {
    public:
    vector<node> arr;
    void init(int n1) { arr = vector<node>(n1 * 4, node());}

    pair<ll, ll> update(int a, int b, int l, int r, int i, int d1, int d2) {
        if (l > r) return {0, 0};
        auto& cur = arr[i];
        if (l > b || r < a) {
            cur.value = add((r - l + 1) * d2 , cur.value)  ;
            cur.add += d2;
            return {0, cur.value};
        }
        if (l >= a && r <= b) {
            cur.value += (r - l + 1) * (d1 + d2);
            cur.add += d1 + d2;
            return {cur.value, cur.value};
        }
        int m = (r + l) / 2;
        auto vl = update(a, b, l, m, i* 2 + 1, d1, cur.add + d2);
        auto vr = update(a, b, m + 1, r, i * 2 + 2, d1, cur.add + d2);
        cur.add = 0;
        cur.value = add(vl.second, vr.second);
        return {vl.first + vr.first, vl.second + vr.second};
    } 

};

class Solution {
public:
    int n;
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        unordered_map<int, int> mp;
        ll ans = 0;
        ll cur = 0;

        Segtree t;
        t.init(n);
        for (int i = 0; i < n; i++) {
            int v = nums[i];
            int prev = mp.count(v) > 0 ? mp[v] : -1;
            auto [a, b] = t.update(prev + 1, i, 0, n - 1, 0, 1, 0);
            cur = cur + a * 2 - (i - prev);
            ans = add(cur, ans);
            mp[v] = i;
        }
        return ans;
    }
};