#include<bits/stdc++.h>

using namespace std;

vector<long>prime;

long co[105];

long sieve()
{

    prime.push_back(2);
    prime.push_back(3);
    prime.push_back(5);
    prime.push_back(7);
    prime.push_back(11);
    prime.push_back(13);

}

void fact(long a)
{


    long j,k;

    for(j = 2 ; j<=a; j++)
    {

        long temp = j ;

        for(k = 0; prime[k]*prime[k] <= temp; k++)
        {
            if(temp % prime[k] == 0)
            {
                while(temp % prime[k] == 0)
                {
                    temp = temp /prime[k];
                    co[prime[k]]++;
                }
            }
        }
        if(temp>1)
        {
            co[temp]++;
        }
    }


}

int main()
{
    sieve();


    long t;

    scanf("%ld",&t);

    for(long i=1; i<=t; i++)
    {
        memset(co,0,sizeof(co));

        long n;

        scanf("%ld",&n);



        fact(n);

        printf("Case %ld: %ld = ",i,n);

        long c=0;

        if(co[2] != 0)
        {

            printf("2 (%ld)",co[2]);
            c=1;
        }



        for(long m=3; m<=n ; m=m+2)
        {

            c=1;

            if(co[m] != 0)
                    {

                        if(c!=0)printf(" * ");

                        printf("%ld (%ld)",m,co[m]);
                    }

        }
        cout<<endl;

    }

    return 0;
}
