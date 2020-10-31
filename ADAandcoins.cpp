#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i, n, q, j;
    cin >> n >> q;
    bitset<100002> ans;
    ans[0] = 1;
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        ans = ans | (ans << x);
    }

    ll s[100003];
    s[0] = ans[0];
    for (i = 1; i <=100002; i++)
        s[i] = s[i - 1] + ans[i];

    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << "\n";
    }

    return (0);
}