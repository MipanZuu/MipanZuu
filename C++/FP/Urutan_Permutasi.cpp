//
//  main.cpp
//  FINAL PROJECT
//
//  Created by Denta Bramasta Hidayat on 14/06/21.
//



#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mod 1000000007
using namespace __gnu_pbds;
vector<long long int> vec;

int main()
{
    long long int ans=1;
    ordered_set OrderSet;
    int n;
    
    cin >> n;
    
    int j = n-1;
    long long int fact[n+5];
    fact[0]=1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = (fact[i-1] * i) % mod;
        //cout << fact[i] << " ";
    }
    for (int j = 0; j < n; j++)
      {
          long long int in;
          cin >> in;
          OrderSet.insert(in);
          vec.push_back(in);
    }
    for (int k = 0; k < n; k++)
    {
        long long int order = OrderSet.order_of_key(vec[k]);
        ans += (order * fact[j]);
        ans = ans % mod;
        j--;
        OrderSet.erase(vec[k]);
    }
    cout << ans << endl;
    return 0;
}



