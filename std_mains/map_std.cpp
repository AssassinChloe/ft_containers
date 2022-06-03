/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_std.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:31:27 by cassassi          #+#    #+#             */
/*   Updated: 2022/06/03 13:25:17 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <iomanip>

void printMap(std::map<const int, char> *map)
{
    if (map->size() == 0)
        return ;
    std::map<const int, char>::const_iterator ite = map->end();
    std::map<const int, char>::iterator it = map->begin();
    for (;it != ite; it++)
    {
        std::cout << (*it).first << " ";   
    }
    std::cout << std::endl;
}

void printMapstr(std::map<const std::string, std::string> *map)
{
    if (map->size() == 0)
        return ;
    std::map<const std::string, std::string>::const_iterator ite = map->end();
    std::map<const std::string, std::string>::iterator it = map->begin();
    for (;it != ite; it++)
    {
        std::cout << (*it).first << " ";   
    }
    std::cout << std::endl;
}

int main ()
{
    clock_t start, end;
    start = clock();

    std::cout << "STD::MAP" << std::endl;
    
    std::cout << "Init map sans arguments" << std::endl;
    std::map<const int, char> maptest;
    std::cout << "empty : " << std::boolalpha << maptest.empty() << std::endl;
    
    std::cout << "Create pairs" << std::endl;
    std::pair<const int,char> bar2 (90,'g');
    std::pair<const int,char> bar3 (45,'f');
    std::pair<const int,char> bar4 (9,'b');
    std::pair<const int,char> bar5 (19,'d');
    std::pair<const int,char> bar6 (5,'a');
    std::pair<const int,char> bar7 (20,'e');
    std::pair<const int,char> bar8 (21,'e');
    std::pair<const int,char> bar9 (22,'e');
    std::pair<const int,char> bar10(23,'e');
    std::pair<const int,char> bar11(24,'e');
    std::pair<const int,char> bar12(25,'h');

    std::cout << "Insert pairs in map" << std::endl;
    maptest.insert(bar2);
    maptest.insert(bar3);
    maptest.insert(bar4);
    maptest.insert(bar5);
    maptest.insert(bar6);
    std::cout << std::endl;
    std::cout << "Map 1 : ";
    printMap(&maptest);
    std::cout << std::endl;
    
    std::cout << "Insert pair with it position"<< std::endl << std::endl;
    maptest.insert(maptest.begin(), bar7);
    std::cout << "Map 1 : ";
    printMap(&maptest);
    std::cout << "empty : " << std::boolalpha << maptest.empty() << std::endl;
    std::cout << "size : " << maptest.size() << std::endl;
    std::cout << "maxsize : " << maptest.max_size() << std::endl;
    std::cout << "operator[] : " << maptest[654] << std::endl;
    std::cout << std::endl;
    std::cout << "Map 1 : ";
    printMap(&maptest);

    std::cout << "init map2 with it first, it last of map" << std::endl;
    std::map<const int, char>::iterator ite = maptest.end();
    std::map<const int, char>::iterator it = maptest.begin();
    std::map<const int, char> maptest2(it, ite);
    std::cout << "size : " << maptest2.size() << std::endl;
    std::cout << "Map 2 : ";
    printMap(&maptest2);
    std::cout << std::endl;

    std::cout << "insert pairs in map 2" << std::endl;
    maptest2.insert(bar7);
    maptest2.insert(bar8);
    maptest2.insert(bar9);
    maptest2.insert(bar10);
    maptest2.insert(bar11);
    maptest2.insert(bar12);

    std::cout << "size : " << maptest2.size() << std::endl;
    std::cout << "Map 2 : ";
    printMap(&maptest2);
    std::cout << std::endl;

    std::cout << "insert in map with it first, it last of map2" << std::endl;
    maptest.insert(maptest2.begin(), maptest2.end());
    std::cout << "size : " << maptest2.size() << std::endl;
    std::cout << "Map 2 : ";
    printMap(&maptest2);
    std::cout << std::endl;
    std::cout << "size : " << maptest.size() << std::endl;
    std::cout << "Map 1 : ";
    printMap(&maptest);
    std::cout << std::endl;

    std::cout << "init map3 using map2" << std::endl;
    std::map<const int, char> maptest3(maptest2);

    std::cout << "maptest = maptest3" << std::endl;
    maptest = maptest3;
    std::cout << "size : " << maptest3.size() << std::endl;
    std::cout << "Map 3 : ";
    printMap(&maptest3);
    std::cout << std::endl;
    std::cout << "size : " << maptest.size() << std::endl;
    std::cout << "Map 1 : ";
    printMap(&maptest);

    std::cout << std::endl << "test relational operators maptest, maptest3" << std::endl;
    if (maptest == maptest3)
        std::cout << "yes ==" << std::endl;
    else
        std::cout << "not ==" << std::endl;
    if (maptest != maptest3)
        std::cout << "yes !=" << std::endl;
                else
        std::cout << "not !=" << std::endl;
    if (maptest < maptest3)
        std::cout << "yes <" << std::endl;
                else
        std::cout << "not <" << std::endl;
    if (maptest > maptest3)
        std::cout << "yes >" << std::endl;
                else
        std::cout << "not >" << std::endl;
    if (maptest <= maptest3)
        std::cout << "yes <=" << std::endl;
                else
        std::cout << "not <=" << std::endl;       
    if (maptest >= maptest3)
        std::cout << "yes >=" << std::endl;
                else
        std::cout << "not >=" << std::endl;
    std::cout << std::endl;
    
    std::cout << "insert pair in map3" << std::endl;
    std::pair<const int,char> bar13(42,'*');
    maptest3.insert(bar13);

    std::cout << "size : " << maptest3.size() << std::endl;
    std::cout << "Map 3 : ";
    printMap(&maptest3);
    std::cout << std::endl;
    
    std::cout << "Erase map3 42" << std::endl;
    maptest3.erase(42);
    std::cout << "size : " << maptest3.size() << std::endl;
    std::cout << "Map 3 : ";
    printMap(&maptest3);
    std::cout << std::endl;

    std::cout << "Erase map3 begin()" << std::endl;
    maptest3.erase(maptest3.begin());
    std::cout << "empty : " << std::boolalpha << maptest3.empty() << std::endl;
    std::cout << "size : " << maptest3.size() << std::endl;
    std::cout << "Map 3 : ";
    printMap(&maptest3);
    std::cout << std::endl;

    std::cout << "Erase map3 range begin-end" << std::endl;
    maptest3.erase(maptest3.begin(), maptest3.end());
    std::cout << "size : " << maptest3.size() << std::endl;
    std::cout << "Map 3 : ";
    printMap(&maptest3);
    std::cout << std::endl;

    
    std::cout << std::endl << "test relational operators maptest, maptest3" << std::endl;
    if (maptest == maptest3)
        std::cout << "yes ==" << std::endl;
    else
        std::cout << "not ==" << std::endl;
    if (maptest != maptest3)
        std::cout << "yes !=" << std::endl;
                else
        std::cout << "not !=" << std::endl;
    if (maptest < maptest3)
        std::cout << "yes <" << std::endl;
                else
        std::cout << "not <" << std::endl;
    if (maptest > maptest3)
        std::cout << "yes >" << std::endl;
                else
        std::cout << "not >" << std::endl;
    if (maptest <= maptest3)
        std::cout << "yes <=" << std::endl;
                else
        std::cout << "not <=" << std::endl;       
    if (maptest >= maptest3)
        std::cout << "yes >=" << std::endl;
                else
        std::cout << "not >=" << std::endl;
    std::cout << std::endl;
      
    std::cout << "insert in empty map" << std::endl;
    maptest3.insert(bar11);
    std::cout << "empty : " << std::boolalpha << maptest3.empty() << std::endl;
    std::cout << "size : " << maptest3.size() << std::endl;
    std::cout << "Map 3 : ";
    printMap(&maptest3);
    std::cout << std::endl;

    std::cout << "size : " << maptest2.size() << std::endl;
    std::cout << "Map 2 : ";
    printMap(&maptest2);
    std::cout << std::endl;

    std::cout << "CLEAR map2" << std::endl;
    maptest2.clear();
    std::cout << "size : " << maptest2.size() << std::endl;
    std::cout << "Map 2 : ";
    printMap(&maptest2);
    std::cout << std::endl;


    std::cout << "size : " << maptest.size() << std::endl;
    std::cout << "Map 1 : ";
    printMap(&maptest);
    std::cout << std::endl;
    std::cout << "Find 90 in map" << std::endl;
    it = maptest.find(90);
    std::cout << "At Key : " << (*it).first << " there is : " << (*it).second << std::endl;
    std::cout << std::endl;

    std::cout << "Count in map" << std::endl;
    std::cout << "count 24 : " << maptest.count(24) << std::endl;
    std::cout << "count 82 : " << maptest.count(82) << std::endl;
    std::cout << std::endl;

    std::cout << "Lower Bound in map" << std::endl;
    it = maptest.lower_bound(654);
    std::cout << "Lower Bond 654 : " << (*it).first << std::endl;
    it = maptest.lower_bound(24);
    std::cout << "Lower Bond 24 : " << (*it).first << std::endl;
    it = maptest.lower_bound(42);
    std::cout << "Lower Bond 42 : " << (*it).first << std::endl;
    it = maptest.lower_bound(5);
    std::cout << "Lower Bond 5 : " << (*it).first << std::endl;
    std::cout << std::endl;

    std::cout << "upper Bound in map" << std::endl;
    it = maptest.upper_bound(654);
    std::cout << "upper Bond 654 : " << (*it).first << std::endl;
    it = maptest.upper_bound(24);
    std::cout << "upper Bond 24 : " << (*it).first << std::endl;
    it = maptest.upper_bound(42);
    std::cout << "upper Bond 42 : " << (*it).first << std::endl;
    it = maptest.upper_bound(5);
    std::cout << "upper Bond 5 : " << (*it).first << std::endl;
    std::cout << std::endl;

    std::cout << "Equal_Range(24) maptest" << std::endl;
    std::pair<std::map<const int, char>::iterator, std::map<const int, char>::iterator> ret;
    ret = maptest.equal_range(24);
    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << std::endl;
    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << std::endl;
    std::cout << std::endl;

    std::cout << "create map4 and insert 10 000 pairs (int i, 'a')" << std::endl;
    std::map<const int, char> maptest4;
    for (int i = 0; i < 10000; i++)
    {
        maptest4.insert(std::make_pair(i, 'a'));
    }
    std::cout << "map4 size : " << maptest4.size() << std::endl;
    std::cout << "Find 7584 in map4" << std::endl;
    it = maptest4.find(7584);
    std::cout << "At Key : " << (*it).first << " there is : " << (*it).second << std::endl;

    std::cout << "map 3 : ";
    printMap(&maptest3);
    std::cout << std::endl;

    std::cout << "SWAP Map4 et 3" << std::endl;
    maptest4.swap(maptest3);

    std::cout << "map 4 : ";
    printMap(&maptest4);
    std::cout << "map3 size : " << maptest3.size() << std::endl;
    std::cout << "Find 7584 in map3" << std::endl;
    it = maptest3.find(7584);
    std::cout << "At Key : " << (*it).first << " there is : " << (*it).second << std::endl;
    std::cout << std::endl;

    std::cout << "SWAP Map4 et 3 using non-member overload" << std::endl;
    swap(maptest3, maptest4);
    std::cout << "map 3 : ";
    printMap(&maptest3);
    std::cout << "map4 size : " << maptest4.size() << std::endl;
    std::cout << "Find 7584 in map4" << std::endl;
    it = maptest4.find(7584);
    std::cout << "At Key : " << (*it).first << " there is : " << (*it).second << std::endl;
    std::cout << std::endl;

    std::cout << std::endl << "FIN DES TEST MAP<int, char>" << std::endl;
    std::cout << "DEBUT DES TEST MAP<string, string>" << std::endl;

    std::map<const std::string, std::string> teststr;
    std::pair<const std::string, std::string> paire("test", "patate");
    std::pair<const std::string, std::string> paire2("carotte", "lapin");
    
    std::cout << "insert" << std::endl;
    teststr.insert(paire);
    teststr.insert(paire2);
    teststr["paire3"];
    teststr["aspic"];
    teststr["aspirateur"];
    teststr["as"];

    printMapstr(&teststr);

    std::cout << "Erase by key and by it" << std::endl;
    teststr.erase("as");
    teststr.erase(teststr.begin());
    printMapstr(&teststr);

    std::cout << "Find" << std::endl;
    std::map<const std::string, std::string>::iterator strit = teststr.find("test");
    std::cout << "At Key : " << (*strit).first << " there is : " << (*strit).second << std::endl;

    std::cout << "Lower Bound" << std::endl;
    strit = teststr.lower_bound("carotte");
    std::cout << "Lower Bond carotte : " << (*strit).first << std::endl;
    strit = teststr.lower_bound("caribou");
    std::cout << "Lower Bond caribou : " << (*strit).first << std::endl;
    strit = teststr.lower_bound("carotteur");
    std::cout << "Lower Bond carotteur : " << (*strit).first << std::endl;

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << std::endl << "Time taken by program is : " << std::fixed 
         << time_taken << std::setprecision(5);
    std::cout << " sec " << std::endl;
    
    return (0);
}