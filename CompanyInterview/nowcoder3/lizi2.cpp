#include <iostream>
#include <cstdio>

using namespace std;

int main()
    int n,ans = 0;
    cin >> n;
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            int x;
            scanf("%d", &x);
            ans += x;
        }

    }
    cout << ans <<endl;
    return 0;
}
