#include "map.hpp"
#include <iostream>
#include <string>

int main ()
{
    std::cout << "Debut" << std::endl;
    
    std::cout << "Init map sana argument" << std::endl;

    ft::map<const int, char> maptest;

    std::cout << "empty : " << std::boolalpha << maptest.empty() << std::endl;
    std::cout << "Create pairs" << std::endl;

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

    std::cout << "Insert pairs" << std::endl;
    
    maptest.insert(bar2);
    maptest.insert(bar3);
    maptest.insert(bar4);
    maptest.insert(bar5);
    maptest.insert(bar6);
    std::cout << "insert pair with it position" << std::endl;

    maptest.insert(maptest.begin(), bar7);
    std::cout << "empty : " << std::boolalpha << maptest.empty() << std::endl;
    std::cout << "size : " << maptest.size() << std::endl;
    std::cout << "maxsize : " << maptest.max_size() << std::endl;
    std::cout << "operator[] : " << maptest[19] << std::endl;
    
    std::cout << "init map2 it first, it last" << std::endl;

    ft::map<const int, char> maptest2(maptest.begin(), maptest.end());
    
    std::cout << "insert in map 2" << std::endl;

    maptest2.insert(bar7);
    maptest2.insert(bar8);
    maptest2.insert(bar9);
    maptest2.insert(bar10);
    maptest2.insert(bar11);
    maptest2.insert(bar12);

    // maptest.printMap();
    // std::cout << std::endl;

    // maptest.insert(maptest.begin(), maptest2.begin(), maptest2.end());
    std::cout << "Print Map2" << std::endl;
    std::cout << "size : " << maptest2.size() << std::endl;

    maptest2.printMap();
    std::cout << std::endl;
    std::cout << "Print Map" << std::endl;
    std::cout << "size : " << maptest.size() << std::endl;
    maptest.printMap();
    std::cout << std::endl;

    std::cout << "init map3 using map2" << std::endl;

    ft::map<const int, char> maptest3(maptest2);

    std::cout << "insert pair in map3" << std::endl;

    ft::pair<const int,char> bar13(42,'*');
    maptest3.insert(bar13);

    std::cout << "Print Map3" << std::endl;
    std::cout << "size : " << maptest3.size() << std::endl;
    maptest3.printMap();
    std::cout << std::endl;
    std::cout << "Print Map2" << std::endl;
    maptest2.printMap();
    std::cout << std::endl;

    std::cout << "maptest = maptest2" << std::endl;

    maptest = maptest2;
    std::cout << "Print Map2" << std::endl;
    std::cout << "size : " << maptest2.size() << std::endl;
    maptest2.printMap();
    std::cout << std::endl;
    std::cout << "Print Map" << std::endl;
    std::cout << "size : " << maptest2.size() << std::endl;
    maptest.printMap();
    std::cout << std::endl;

    std::cout << "Erase map3 from map2" << std::endl;

    maptest3.erase(maptest.begin(), maptest.end());
    std::cout << "Print Map3" << std::endl;
    std::cout << "size : " << maptest3.size() << std::endl;
    maptest3.printMap();
    
    std::cout << "Erase map3 45" << std::endl;
    maptest3.erase(45);
    std::cout << "Print Map3" << std::endl;
    std::cout << "size : " << maptest3.size() << std::endl;
    maptest3.printMap();

    std::cout << "Erase map3 begin()" << std::endl;
    maptest3.erase(maptest3.begin());
    maptest3.insert(bar13);
    std::cout << "Print Map3" << std::endl;
    std::cout << "size : " << maptest3.size() << std::endl;
    maptest3.printMap();
    std::cout << std::endl;
    std::cout << "Print Map2" << std::endl;
    std::cout << "size : " << maptest2.size() << std::endl;
    maptest2.printMap();
    std::cout << std::endl;


    return 0;
}