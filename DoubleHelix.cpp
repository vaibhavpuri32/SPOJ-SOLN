#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18
int main()
{

    ll i, j, t;

    while (true)
    {
        ll n, m;
        cin >> n;
        if (n == 0)
        {
            exit(0);
        }
        ll a[n + 3];
        for (i = 1; i <= n; i++)
            cin >> a[i];

        cin >> m;
        ll b[m + 3];
        for (i = 1; i <= m; i++)
            cin >> b[i];

        a[0] = -inf;
        b[0] = -inf;
        b[m + 1] = 0;
        a[n + 1] = 0;
        map<ll, ll> M;
        for (i = 1; i <= n + 1; i++)
        {
            M[a[i]]++;
        }
        for (i = 1; i <= m + 1; i++)
        {
            M[b[i]]--;
        }

        ll pref1[n + 2];
        ll pref2[m + 2];
        pref1[0] = 0;
        pref2[0] = 0;
        for (i = 1; i <= n + 1; i++)
        {
            pref1[i] = pref1[i - 1] + a[i];
        }
        for (i = 1; i <= m + 1; i++)
        {
            pref2[i] = pref2[i - 1] + b[i];
        }
        /*
        for (i = 0; i <= n + 1; i++)
        {
            //pref1[i] = pref1[i - 1] + a[i];
            cout << pref1[i] << " ";
        }
        cout << "\n";
        for (i = 0; i <= m + 1; i++)
        {
            //pref2[i] = pref2[i - 1] + b[i];
            cout << pref2[i] << " ";
        }
        cout << "\n";
*/
        ll ans = 0;
        ll prev = 0;
        vector<ll> v1, v2;
        for (i = 1; i <= n + 1; i++)
        {
            if (M[a[i]] == 0)
            {
                v1.push_back(pref1[i] - pref1[prev]);
                prev = i;
            }
        }
        prev = 0;
        for (i = 1; i <= m + 1; i++)
        {
            if (M[b[i]] == 0)
            {
                v2.push_back(pref2[i] - pref2[prev]);
                prev = i;
            }
        }

        for (i = 0; i < v1.size(); i++)
        {
            ans = ans + max(v1[i], v2[i]);
            //cout<<max(v1[i],v2[i])<<" ";
        }
        if (ans == 0)
            ans = max(pref1[n], pref2[n]);
        cout << ans << "\n";
    }

    return (0);
}