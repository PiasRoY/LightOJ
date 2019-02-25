#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;


int main()
{
    int t;
    cin>>t;

    for(int x = 1; x <= t; x++)
    {
        printf("Case %d:\n", x);

        int N, K, t = 1, count = 1;
        cin>>N>>K;

        char arr[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I','J', 'K', 'L', 'M', 'N', 'O',
                      'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

        for(int i = 0; i < N; i++) printf("%c", arr[i]);
        cout<<endl;

        while(true)
        {
            if(count == K) break;
            count++;
            //step-1
            int m1 = -1;
            for(int i = N-2; i >= 0; i--)
                if(arr[i] < arr[i+1]) {m1 = i; break;}

            if(m1 == -1) break;

            //step-2
            int m2 = -1;
            for(int i = N-1; i >= 0; i--)
                if(arr[i] > arr[m1]) {m2 = i; break;}

            //step-3
            swap(arr[m1], arr[m2]);

            //step-4
            reverse(arr+m1+1, arr+N);

            //printing array
            for(int i = 0; i < N; i++) printf("%c", arr[i]);
            cout<<endl;
        }
    }
}
