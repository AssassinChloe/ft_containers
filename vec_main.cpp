#include "vector.hpp"
#include <iostream>

int main()
{
    ft::vector<int> test;
    
    test.push_back(45);
    std::cout << "size : " << test.size() << std::endl;
    std::cout << "capacity : " << test.capacity() << std::endl;
    std::cout << "front : " << test.front() << std::endl;
    std::cout << "back : " << test.back() << std::endl;
    // std::cout << "at : " << test.at(5) << std::endl;
    // std::cout << "[] : " << test[5] << std::endl;

 
    test.push_back(46);
    test.push_back(47);
    test.push_back(48);
    test.push_back(49);
    test.push_back(50);
    test.push_back(51);

    std::cout << "size : " << test.size() << std::endl;
    std::cout << "capacity : " << test.capacity() << std::endl;
    std::cout << "front :" << test.front() << std::endl;
    std::cout << "back :" << test.back() << std::endl;
    std::cout << "at :" << test.at(5) << std::endl;
    std::cout << "[] :" << test[5] << std::endl;
}