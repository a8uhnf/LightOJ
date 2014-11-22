#include<bits/stdc++.h>

using namespace std;
#define mx 1000000

double l[1000005];

void logarithm()
{
    double x;
    long y=1;

    l[0]=0;

    for(x=1; x<=1000000; x++)
    {
        l[y]=((log(x))+l[y-1]);
        y++;
    }

}


int main()
{
        logarithm();

            //cout<<l[5]<<" "<<l[8]<<endl;
    long t;

    scanf("%ld",&t);

    for(long i=1;i<=t;i++)
    {
            double base;
            long n;

            scanf("%ld %lf",&n,&base);

            double ans=(floor)(l[n]/log(base))+1;

            printf("Case %ld: %.0lf\n",i,ans);



    }

    return 0;
}
