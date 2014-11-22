#include<bits/stdc++.h>

using namespace std;

#define mx 1000000

unsigned long long phi[5*mx+5];
//long ans[mx*5+5];


bool prime[5*mx+5];

void sieve()
{
       long x,y;

       for(x=4; x<= 5*mx; x=x+2)
       prime[x]=1;

       for(x=3; x * x <= 5*mx; x=x+2)
       {
           if(prime[x] == 0)
           {
               for(y = x*2; y<=5*mx; y=x+y)
               prime[y]=1;
           }
       }

       //cout<<prime[17]<<" "<<prime[21]<<" "<<prime[33]<<" "<<prime[41]<<endl;

}


int main()
{
    sieve();
long l;

    for(l=1; l<=5*mx; l++)phi[l]=l;

    //cout<<func(7)<<endl;


    for(l=2; l<=5*mx; l=l+2)
    {
        phi[l]=l;

        phi[l]=phi[l]-(phi[l]/2);

    }
    //cout<<phi[5*mx];

    for(l=3; l<=5*mx; l=l+2)
    {
            if(prime[l] == 0)
            {
                for(long m = l ; m<=5*mx; m=l+m)
                {


                    phi[m]=phi[m]-(phi[m]/l);
                }
            }

    }
//cout<<phi[500]<<" "<<phi[3]<<" "<<phi[6]<<" "<<phi[5]<<endl;
        phi[1]=1;

        for(long v=2; v<=5*mx; v++)
        {
            unsigned long long t=phi[v]*phi[v];
            phi[v] = t+phi[v-1];
        }


//printf("%llu\n",phi[6]-phi[5]);



    unsigned long long a,b;

    long t;

    scanf("%ld",&t);

    for(long i=1; i<=t; i++)
    {
        scanf("%llu %llu",&a,&b);

        unsigned long long sum=0;

        printf("Case %ld: ",i);



        printf("%llu\n",phi[b]-phi[a-1]);

    }


    return 0;
}
