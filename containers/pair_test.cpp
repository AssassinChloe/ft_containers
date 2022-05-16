#include "map.hpp"
#include <iostream>
#include <string>

int main ()
{
    std::cout << "test init" << std::endl;
    ft::map<const int, char> maptest;
    std::cout << "test post map" << std::endl;

    ft::pair<const int,char> bar2 (90,'g');
    ft::pair<const int,char> bar3 (45,'f');
    ft::pair<const int,char> bar4 (9,'b');
    ft::pair<const int,char> bar5 (19,'d');
    ft::pair<const int,char> bar6 (5,'a');
    ft::pair<const int,char> bar7 (20,'e');
    ft::pair<const int,char> bar8 (21,'e');
    ft::pair<const int,char> bar9 (22,'e');
    ft::pair<const int,char> bar10(23,'e');
    ft::pair<const int,char> bar11(24,'e');
    ft::pair<const int,char> bar12(25,'e');

    std::cout << "test post pair" << std::endl;
    
    maptest.insert(bar2);
    std::cout << maptest.getRoot()<< "   test post first insert" << std::endl;

    maptest.insert(bar3);
    std::cout << maptest.getRoot()<< "   test post 2nd insert" << std::endl;

    maptest.insert(bar4);
    std::cout << maptest.getRoot()<< "   test post 3rd insert" << std::endl;

    // maptest.insert(bar5);
    // maptest.insert(bar6);
    // maptest.insert(bar7);
    // maptest.insert(bar8);
    // maptest.insert(bar9);
    // maptest.insert(bar10);
    // maptest.insert(bar11);
    // maptest.insert(bar12);

    return 0;
}