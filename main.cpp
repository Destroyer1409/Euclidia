/* 
 * File:   main.cpp
 * Author: hugo
 *
 * Created on 9. août 2018, 01:55
 */

#include <iostream>
#include <cmath>
#include <cstdint>
#include <sstream>
#include <string>


bool isPrime(uint64_t n)
{
    for(int i = 2; i <= std::sqrt(n); ++i)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

std::string GetDivides(uint64_t n)
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

std::string GetPrimeFactors(uint64_t n)
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
    uint64_t n;
    std::cout << "Enter a number" << std::endl;
    std::cin >> n;
    //if(!isPrime(n))
    {
        std::cout << n << " is dividable by " << GetDivides(n) << std::endl;
        std::cout << "Prime factory of " << n << " : " << GetPrimeFactors(n) << std::endl;
    }
    //else
    //  std::cout << n << " is prime!" << std::endl;

    return 0;
}
