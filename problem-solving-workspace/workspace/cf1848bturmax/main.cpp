#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cout<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cout<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"]\n":"|");


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test_cases;
    cin >> test_cases;
    for( int current_test = 1; current_test <= test_cases; ++current_test)
    {
        int n, k;
        cin >> n >> k;
        //cout << "\n\nTest " << current_test << ": n("<< n <<") k("<< k <<")" << endl;
        map<int, vector<int> > color_to_position;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
          cin >> a[i];
          color_to_position[a[i]].push_back(i+1);
        }
        //va(a)
        int answer = 999999999;
        for( auto [color,positions]: color_to_position )
        {

            positions.insert(positions.begin(),0);
            positions.push_back(n+1);
            vector<int> differences;
            for(int i = 0; i < positions.size() - 1 ; ++i)
              differences.push_back(positions[i+1] - positions[i]);
            
            //cout << "\nColor: " << color << endl;
            //va(positions)
            //va(differences)
            sort(differences.rbegin(), differences.rend());
            //va(differences)
            differences.push_back(0);
            answer = min(answer, max((differences[0] + 1) / 2, differences[1]));
        }
        cout << answer - 1 << endl;
    }
    return 0;
}