#include "../map.hpp"
#include <iostream>
#include <string>
#include <iomanip>

void printMap(ft::map<const int, char> *map)
{
    if (map->size() == 0)
        return ;
    ft::map<const int, char>::iterator ite = map->end();
    ft::map<const int, char>::iterator it = map->begin();
    for (;it != ite; it++)
    {
        std::cout << (*it).first << ", ";   
    }
}

int main ()
{
    clock_t start, end;
    start = clock();
    std::cout << "FT::MAP" << std::endl;

    
    std::cout << "Init map sans arguments" << std::endl;

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
    std::cout << std::endl;
    printMap(&maptest);
    std::cout << std::endl;

    std::cout << "Insert pairs" << std::endl;
    maptest.insert(bar3);
     std::cout << std::endl;
    printMap(&maptest);
    std::cout << std::endl;

    std::cout << "Insert pairs" << std::endl;
    maptest.insert(bar4);
    std::cout << std::endl;
    printMap(&maptest);
    std::cout << std::endl;
    
    std::cout << "Insert pairs" << std::endl;
    maptest.insert(bar5);
    std::cout << std::endl;
    printMap(&maptest);
    std::cout << std::endl;
    
    std::cout << "Insert pairs" << std::endl;
    maptest.insert(bar6);
    std::cout << std::endl << "insert pair with it position"<< std::endl << std::endl;

    maptest.insert(maptest.begin(), bar7);
    std::cout << "empty : " << std::boolalpha << maptest.empty() << std::endl;
    std::cout << "size : " << maptest.size() << std::endl;
    std::cout << "maxsize : " << maptest.max_size() << std::endl;
    std::cout << "operator[] : " << maptest[654] << std::endl;
    

    std::cout << "init map2 it first, it last" << std::endl;

    std::cout << "ite" << std::endl;
    ft::map<const int, char>::iterator ite = maptest.end();
    std::cout << "it" << std::endl;
    ft::map<const int, char>::iterator it = maptest.begin();

    std::cout << "insert" << std::endl;
    ft::map<const int, char> maptest2(it, ite);
    
    std::cout << "insert in map 2" << std::endl;

    maptest2.insert(bar7);
    maptest2.insert(bar8);
    maptest2.insert(bar9);
    maptest2.insert(bar10);
    maptest2.insert(bar11);
    maptest2.insert(bar12);

    printMap(&maptest);
    std::cout << std::endl;

    maptest.insert(maptest2.begin(), maptest2.end());
    std::cout << "Print Map2" << std::endl;
    std::cout << "size : " << maptest2.size() << std::endl;

    printMap(&maptest2);
    std::cout << std::endl;
    std::cout << "Print Map" << std::endl;
    std::cout << "size : " << maptest.size() << std::endl;
    printMap(&maptest);
    std::cout << std::endl;

    std::cout << "init map3 using map2" << std::endl;

    ft::map<const int, char> maptest3(maptest2);

    std::cout << "insert pair in map3" << std::endl;

    ft::pair<const int,char> bar13(42,'*');
    maptest3.insert(bar13);

    std::cout << "Print Map3" << std::endl;
    std::cout << "size : " << maptest3.size() << std::endl;
    printMap(&maptest3);
    std::cout << std::endl;
    std::cout << "Print Map2" << std::endl;
    printMap(&maptest2);
    std::cout << std::endl;

    std::cout << "maptest = maptest2" << std::endl;

    maptest = maptest2;
    std::cout << "Print Map2" << std::endl;
    std::cout << "size : " << maptest2.size() << std::endl;
    printMap(&maptest2);
    std::cout << std::endl;
    std::cout << "Print Map" << std::endl;
    std::cout << "size : " << maptest.size() << std::endl;
    printMap(&maptest);
    std::cout << std::endl;

    // std::cout << "Erase map3 from map2" << std::endl;

    // maptest3.erase(maptest.begin(), maptest.end());
   
    std::cout << "Print Map3" << std::endl;
    std::cout << "size : " << maptest3.size() << std::endl;
    printMap(&maptest3);
    
    std::cout << "Erase map3 45" << std::endl;
    maptest3.erase(45);
    std::cout << "Print Map3" << std::endl;
    std::cout << "size : " << maptest3.size() << std::endl;
    printMap(&maptest3);

    std::cout << "Erase map3 begin()" << std::endl;
    maptest3.erase(maptest3.begin());
    std::cout << "Print Map3" << std::endl;
    std::cout << "empty : " << std::boolalpha << maptest3.empty() << std::endl;

    std::cout << "size : " << maptest3.size() << std::endl;
    printMap(&maptest3);
    std::cout << "insert in empty map" << std::endl;

    maptest3.insert(bar11);
    std::cout << "Print Map3" << std::endl;
    std::cout << "empty : " << std::boolalpha << maptest3.empty() << std::endl;

    std::cout << "size : " << maptest3.size() << std::endl;
    printMap(&maptest3);
    std::cout << std::endl;
    std::cout << "Print Map2" << std::endl;
    std::cout << "size : " << maptest2.size() << std::endl;
    printMap(&maptest2);
    std::cout << std::endl;

    std::cout << "CLEAR" << std::endl;
    maptest2.clear();
    std::cout << "Print Map2" << std::endl;
    std::cout << "size : " << maptest2.size() << std::endl;
    printMap(&maptest2);
    std::cout << std::endl;

    std::cout << "Find 22" << std::endl;
    it = maptest.find(90);
    std::cout << "At Key : " << (*it).first << " there is : " << (*it).second << std::endl;
    std::cout << std::endl;

    std::cout << "Print Map" << std::endl;
    std::cout << "size : " << maptest.size() << std::endl;
    printMap(&maptest);
    std::cout << std::endl;

    std::cout << "Count" << std::endl;
    std::cout << "count 24 : " << maptest.count(24) << std::endl;
    std::cout << "count 42 : " << maptest.count(42) << std::endl;
    std::cout << std::endl;

    std::cout << "Lower Bound" << std::endl;
    it = maptest.lower_bound(90);
    std::cout << "Lower Bond 90 : " << (*it).first << std::endl;
    it = maptest.lower_bound(24);
    std::cout << "Lower Bond 24 : " << (*it).first << std::endl;
    it = maptest.lower_bound(42);
    std::cout << "Lower Bond 42 : " << (*it).first << std::endl;
    it = maptest.lower_bound(5);
    std::cout << "Lower Bond 5 : " << (*it).first << std::endl;
    std::cout << std::endl;

    std::cout << "upper Bound" << std::endl;
    it = maptest.upper_bound(90);
    std::cout << "upper Bond 90 : " << (*it).first << std::endl;
    it = maptest.upper_bound(24);
    std::cout << "upper Bond 24 : " << (*it).first << std::endl;
    it = maptest.upper_bound(42);
    std::cout << "upper Bond 42 : " << (*it).first << std::endl;
    it = maptest.upper_bound(5);
    std::cout << "upper Bond 5 : " << (*it).first << std::endl;
    std::cout << std::endl;

    ft::map<const int, char> maptest4;
    for (int i = 0; i < 10000; i++)
    {
        maptest4.insert(ft::make_pair(i, 'a'));
    }

    std::cout << std::endl;
    printMap(&maptest);
    std::cout << std::endl;
    printMap(&maptest2);
    std::cout << std::endl;
    printMap(&maptest3);
    std::cout << std::endl;

    maptest4.swap(maptest3);
    printMap(&maptest4);
    std::cout << std::endl;

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << std::endl << "Time taken by program is : " << std::fixed 
         << time_taken << std::setprecision(5);
    std::cout << " sec " << std::endl;

    return 0;
}