#include "function.h"

#include <stdio.h>

using namespace std;
HugeInteger::HugeInteger()
{
    for(int i = 0 ; i < 42 ; i++)
    {
        integer[i] = 0;
    }
    noOfDigits = 0;
}

HugeInteger::HugeInteger(const string &num)
{
    int i;
    for(i = 0 ; i < num.length() ; i++)
    {
        integer[i] = num[num.length()-1-i] - '0';
    }
    for(;i < 42 ; i++)
    {
        integer[i] = 0;
    }
    noOfDigits = num.length();

}

bool HugeInteger::isGreaterThan(const HugeInteger & a)const
{
    if(noOfDigits > a.noOfDigits)
        return true;
    else if(noOfDigits < a.noOfDigits)
        return false;
    else
    {
        for(int i = 41 ; i >= 0 ; i--)
        {
            if(integer[i] > a.integer[i])
                return true;
            else if(integer[i] == a.integer[i])
                continue;
            else
                break;
        }
        return false;
    }
}
HugeInteger HugeInteger::add(const HugeInteger & a)const
{
    int i;
    HugeInteger sol;
    for(i = 0 ; i < 42 ; i++)
    {
        if(integer[i]+a.integer[i]+sol.integer[i]>=10)
        {sol.integer[i] = integer[i]+a.integer[i] - 10+sol.integer[i];
         sol.integer[i+1]++;
        }

        else
        {
            sol.integer[i] = integer[i]+a.integer[i]+sol.integer[i];
        }

    }
            return sol;

}

void HugeInteger::output() const
{
    int i;
    int flag=0;
    for(i = 41 ; i >= 0 ; i--)
    {
        if(integer[i]!=0)
            flag = 1;

        if (flag)
        printf("%d",integer[i]);




    }
    if(!flag)
    printf("0");
}


HugeInteger HugeInteger::add(const string &num)const
{
    int i;
    HugeInteger sol;
    for(i = 0 ; i < num.length() ; i++)
    {
        sol.integer[i] = num[num.length()-1-i] - '0';
    }
    for(;i < 42 ; i++)
    {
        sol.integer[i] = 0;
    }


    for(i = 0 ; i < 42 ; i++)
    {
        if(integer[i]+sol.integer[i]>=10)
        {sol.integer[i] = integer[i]+sol.integer[i] - 10;
         sol.integer[i+1]++;
        }

        else
        {
            sol.integer[i] = integer[i]+sol.integer[i];
        }

    }
            return sol;




}

//  ---------

HugeInteger HugeInteger::subtract(const HugeInteger & a)const
{
    int i;
    HugeInteger sol;
    for(i = 0 ; i < 42 ; i++)
    {
          sol.integer[i] = integer[i]-a.integer[i]+sol.integer[i] ;

         if(sol.integer[i]<0)

         {sol.integer[i+1]--;
           sol.integer[i]+=10;


         }
        }




            return sol;

}

HugeInteger HugeInteger::subtract(const string &num)const
{
    int i;
    HugeInteger sol, tmp;

    for(i = 0 ; i < num.length() ; i++)
    {
        tmp.integer[i] = num[num.length()-1-i] - '0';
    }
    for(;i < 42 ; i++)
    {
        tmp.integer[i] = 0;
    }


    for(i = 0 ; i < 42 ; i++)
    {
          sol.integer[i] = integer[i]-tmp.integer[i]+sol.integer[i] ;

         if(sol.integer[i]<0)

         {sol.integer[i+1]--;
           sol.integer[i]+=10;


         }
        }

            return sol;




}

/*192.168.136.1*//*CSY103062316*/
