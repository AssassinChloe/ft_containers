#include "map.hpp"
#include <iostream>
#include <string>

int main ()
{
    ft::map<int, char> maptest;

    ft::pair<int,char> bar2 (90,'g');
    ft::pair<int,char> bar3 (45,'f');
    ft::pair<int,char> bar4 (9,'b');
    ft::pair<int,char> bar5 (19,'d');
    ft::pair<int,char> bar6 (5,'a');
    ft::pair<int,char> bar7 (20,'e');
    ft::pair<int,char> bar8 (21,'e');
    ft::pair<int,char> bar9 (22,'e');
    ft::pair<int,char> bar10(23,'e');
    ft::pair<int,char> bar11(24,'e');
    ft::pair<int,char> bar12(25,'e');
    
    maptest.insert(bar2);
    maptest.insert(bar3);
    maptest.insert(bar4);
    maptest.insert(bar5);
    maptest.insert(bar6);
    maptest.insert(bar7);
    maptest.insert(bar8);
    maptest.insert(bar9);
    maptest.insert(bar10);
    maptest.insert(bar11);
    maptest.insert(bar12);

    return 0;
}