#include<bits/stdc++.h>

using namespace std;

#define mx 10000007

long fib[10005];

long fn(unsigned long long n)
{
            if(n == 0 || n==1 || n== 2 || n==3 ||  n==4  || n==5)return fib[n];

            if(fib[n] == -1)
            return fib[n] = (fn(n-1)%mx+fn(n-2)%mx+fn(n-3)%mx+fn(n-4)%mx+fn(n-5)%mx+fn(n-6)%mx)%mx;
            else
            return fib[n]%mx;
}


int main()
{



    long t;

    scanf("%ld",&t);

    for(long i=1; i<=t; i++)
    {

            memset(fib,-1,sizeof(fib));

            long a,b,c,d,e,f,n;

            scanf("%ld %ld %ld %ld %ld %ld %ld",&a,&b,&c,&d,&e,&f,&n);


            fib[0]=a;
            fib[1]=b;
            fib[2]=c;
            fib[3]=d;
            fib[4]=e;
            fib[5]=f;

            long ans = fn(n)%10000007;


            printf("Case %ld: %ld\n",i,ans);

    }


    return 0;
}
