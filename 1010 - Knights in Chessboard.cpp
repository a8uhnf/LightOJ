#include<bits/stdc++.h>

using namespace std;

int main()
{


    long t;

    scanf("%ld",&t);

    for(long i=1; i<=t; i++)
    {


            long n,m,sum=0;


            scanf("%ld %ld",&n,&m);

            if(n>m)swap(n,m);


            printf("Case %ld: ",i);


            if(n == 1)
            sum=m;

            else if(n == 2)
            {


                if(m>3)
                sum=(n*m)-(4*((m/n)/2));
                else
                sum=4;


            }

            else if(m%2 != 0)
            {
                sum=((m/2)+1);
                if(n%2 != 0)
                {
                    sum = sum*(n/2+1);
                }
                else
                {
                    sum=sum*(n/2);
                }

                sum=sum+((n/2)*(m/2));


            }
            else
            {
                sum = n*(m/2);

            }


            printf("%ld\n",sum);

    }

    return 0;
}
