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
#include <utility>


bool isPrime(uint64_t n)
{
    if(n % 2 == 0) // Removes half of the iterations that would be used to get to a big prime
            return false;
    for(auto i = 3ull; i <= std::sqrt(n); i += 2ull)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

std::string GetDivides(uint64_t n)
{
    std::stringstream ss;
    if(isPrime(n))
        return "prime!";
    else
    {
    for(auto i = 2ull; i < n; ++i)
        {
            if(n % i == 0)
                ss << i << "; ";
        }
    }
    return std::move(ss.str());
}

std::string GetPrimeFactors(uint64_t n)
{
    std::stringstream ss;
    if(isPrime(n))
        return "prime!";
    
    for(auto i = 2ull; i <= n; ++i)
    {
        if(n % i == 0)
        {
            if(isPrime(i))
            {
                uint64_t m = n, x = 0ull;
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
    return std::move(ss.str());
}

int main()
{
    uint64_t n;
    std::cout << "Enter a number" << std::endl;
    std::cin >> n;
    //if(!isPrime(n))
    {
        std::cout << n << " is dividable by " << GetDivides(n) << std::endl;
        std::cout << "Prime factors of " << n << " : " << GetPrimeFactors(n) << std::endl;
    }
    //else
    //  std::cout << n << " is prime!" << std::endl;

    return 0;
}
