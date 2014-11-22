#include<bits/stdc++.h>


using namespace std;

int main()
{

    long t;

    scanf("%ld",&t);

    for(long i=1; i<=t; i++)
    {
            long long a,b;

            vector<long long>v;

            scanf("%lld %lld",&a,&b);

            a = a-b;

            for(long long j=1; j*j <=a; j++)
            {
                    if(a%j == 0)
                    {
                        if(j > b)
                        v.push_back(j);
                        if((a/j)  >b)
                        v.push_back(a/j);
                    }
            }
            printf("Case %ld:",i);

            if(v.empty())
            printf(" impossible");
            else
            {
                sort(v.begin(),v.end());
                for(long long k=0; k<v.size();k++)
                {


                    if(k!=0)
                    {


                        if(v[k] != v[k-1]){


                                    printf(" %lld",v[k]);

                        }
                    }
                    else
                    {

                        printf(" %lld",v[k]);
                    }
                }

            }
            printf("\n");
    }

    return 0;
}
