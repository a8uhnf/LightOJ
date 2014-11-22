#include<bits/stdc++.h>


using namespace std;

long fn(long a)
{
    /* works for any word length */
    long c = (a & -a);
    long r = a+c;
    return ((((r ^ a) >> 2) / c) | r);
}



int main()
{






    long t;


    scanf("%ld",&t);


    for(long i=1; i<=t; i++)
    {



        long a;

        scanf("%ld",&a);


            printf("Case %ld: %ld\n",i,fn(a));
    }


    return 0;
}
