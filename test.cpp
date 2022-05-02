#include <vector>
#include <iostream>

int main()
{
    try
    {
        std::vector<int> tab(11, 11);
        tab.pop_back();
        std::cout << tab[10] << std::endl;
        std::cout << tab.at(10) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}