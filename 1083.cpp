#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test_cases;
    scanf("%d", &test_cases);
    for(int t = 1; t <= test_cases; t++) {
        int N, max = 0;
        scanf("%d", &N);
        int histogram[N];
        for(int i = 0; i < N; i++) scanf("%d", &histogram[i]);
        // Processing
        for(int i = 0; i < N; i++) {
            int count = 0;
            //Position To Left
            for(int j = i; j >= 0; j--) {
                if(histogram[j] >=  histogram[i]) count++;
                else break;
            }
            //Position To Right
            for(int j = i+1; j < N; j++) {
                if(histogram[j] >=  histogram[i]) count++;
                else break;
            }
            count *= histogram[i];
            if(count > max) max = count;
        }
        printf("Case %d: %d\n", t, max);
    }
}
