/* 
 * File:   main.cpp
 * Author: hugo
 *
 * Created on 9. août 2018, 01:55
 */

#include <iostream>
#include <cmath>
#include <sstream>
#include <string>


bool isPrime(int n)
{
    for(int i = 2; i <= std::sqrt(n); ++i)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

std::string GetDivides(int n)
{
    std::string str;
    if(isPrime(n))
        str = "prime!";
    else
    {
    for(int i = 2; i < n; ++i)
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

std::string GetPrimeFactors(int n)
{
    std::stringstream ss;
    if(!isPrime(n))
    {
        for(int i = 2; i <= n; ++i)
        {
            if(n % i == 0 )
            {
                if(isPrime(i))
                {
                    int m = n, x = 0;
                    while(m % i == 0)
                    {
                        m /= i;
                        ++x;
                    }                    
                    ss << i << " pow " << x << "; ";
                }
            }
        }
    }
    else
        return "prime!";
    return ss.str();
}

int main()
{
    int n;
    std::cout << "Enter a number" << std::endl;
    std::cin >> n;
    //if(!isPrime(n))
    {
        std::cout << n << " is dividable by " << std::GetDivides(n) << std::endl;
        std::cout << "Prime factory of " << n << " : " << std::GetPrimeFactors(n) << std::endl;
    }
    //else
    //  std::cout << n << " is prime!" << std::endl;

    return 0;
}
