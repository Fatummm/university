#include <iostream>
#include <vector>
#include <cstdint>
#include <set>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<
    std::pair<int, int>,
    null_type,
    std::less<std::pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

signed main() {
    ios::sync_with_stdio(NULL);
    ordered_set added;
    ordered_set deleted;
    int n; cin >> n;
    rep(i, n) {
        int a, t, x; cin >> a >> t >> x;
    }
}
