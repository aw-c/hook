#include <iostream>
#include "eventid.hpp"

int main()
{
    hook::Add("Think", [] {
        std::cout << "Think've been runed" << std::endl;
        });

    while (true)
    {
        hook::Run("Think");
    }
}