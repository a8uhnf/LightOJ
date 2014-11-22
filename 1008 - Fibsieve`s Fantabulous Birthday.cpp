#include<stdio.h>
#include<iostream>
#include<queue>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<vector>
#include<stdlib.h>
#include<bitset>
#include<deque>



using namespace std;


//long a[100005][100005];




int main()
{


    long t;

    cin>>t;

    for(long i=1; i <= t; i++)
    {
        long n;

        cin>>n;


        long x,y;

        double sq = (sqrt(n));
        double ceilsq = ceil(sq);


        long lsq=sq;

        double test=(double)(0.5+lsq);

        double dist=ceilsq-lsq;


        if(ceilsq == sq)
        {
            if(lsq%2==0)
            {
                x=sq;
                y=1;
            }
            else
            {
                y=sq;
                x=1;
            }
        }
        else if(sq>=test  && lsq%2==0)
        {
            y=lsq+1;

            x=(ceilsq*ceilsq)-n+1;
        }

        else if(sq<test  &&  lsq %2 ==0)
        {
            x=lsq+1;

            y=n-(lsq*lsq);
        }
        else if(sq >= test  &&  lsq%2 != 0)
        {
            x=lsq+1;

            y=(ceilsq*ceilsq)-n+1;
        }
        else if(sq < test  && lsq %2 != 0)
        {
            y=lsq+1;
            x= n - (lsq*lsq);
        }
        //cout<<sq<<" "<<lsq<<endl;





        printf("Case %d: %ld %ld\n",i,x,y);

    }


    return 0;
}
