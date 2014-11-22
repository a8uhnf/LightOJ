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

                long a=0,b=n;

                if(n%2==0)
                {
                    a=n/2;
                    b=n/2;
                }
                else
                {
                    a=n/2;
                    b=n/2+1;
                }


                cout<<(a)<<" "<<abs(b)<<endl;
    }

    return 0;
}
