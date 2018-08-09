/* 
 * File:   main.cpp
 * Author: hugo
 *
 * Created on 9. août 2018, 01:55
 */

#include <iostream>
#include <math.h>
#include <sstream>
#include <string>

using namespace std;

bool isPrime(int n)
{
    bool isprime = true;
    for(int i=2; i<=sqrt(n); ++i)
    {
        if(n % i == 0) isprime = false;
    }
    return isprime;
}

string GetDivides(int n)
{
    string str = "";
    if(isPrime(n)) str = "prime!";
    else
    {
    for(int i=2;i<n;++i)
        {
            if(n % i == 0)
            {
                std::stringstream ss;
                ss << str << i << "; ";
                str = ss.str();
            }
        }
    }
    return str;
}

string GetPrimeFactors(int n)
{
    string str = "";
    if(!isPrime(n))
    {
        for(int i=2;i<=n;++i)
        {
            if(n % i == 0 )
            {

                if(isPrime(i))
                {
                    int m = n;
                    int x = 0;
                    while(m % i == 0)
                    {
                        m = m / i;
                        ++x;
                    }                    
                    std::stringstream ss;
                    ss << str << i << " pow " << x << "; ";
                    str = ss.str();
                }
            }
        }
    }
    else str = "prime!";
    return str;
}

int main()
{
    int n;
    cout << "Enter a number" << endl;
    cin >> n;
    //if(!isPrime(n))
    {
        cout << n << " is dividable by " << GetDivides(n) << endl;
        cout << "Prime factory of " << n << " : " << GetPrimeFactors(n) << endl;
    }
    //else cout << n << " is prime!" << endl;

    return 0;
}