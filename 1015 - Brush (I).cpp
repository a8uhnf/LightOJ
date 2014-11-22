#include<bits/stdc++.h>

using namespace std;

int main()
{

    long t;

    scanf("%ld",&t);

    for(long i=1;i<=t;i++)
    {

                long n;
                scanf("%ld",&n);

                long a;
                long ans=0;

                for(long j=1;j<=n;j++)
                {
                    scanf("%ld",&a);

                    if(a<0)
                    continue;

                    ans = ans+a;
                }
                printf("Case %ld: %ld\n",i,ans);

    }

    return 0;
}
