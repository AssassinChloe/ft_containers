/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:31:22 by cassassi          #+#    #+#             */
/*   Updated: 2022/06/03 09:52:14 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector.hpp"
#include <iostream>
#include "../iterator.hpp"
#include <bits/stdc++.h>


void  affiche(ft::vector<int> test1, std::string name)
{   
    ft::vector<int>::const_iterator ite = test1.end();
    
    std::cout << std::endl << name << std::endl;
    std::cout << "size : " << test1.size() << std::endl;
    std::cout << "capacity : " << test1.capacity() << std::endl;
    
    for(ft::vector<int>::iterator it = test1.begin(); it != ite; it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    clock_t start, end;
    start = clock();

    std::cout << "FT::VECTOR" << std::endl;
    std::cout << std::endl;
    std::cout << "vector<int> test0, test1(4)" << std::endl;
    ft::vector<int> test0;
    ft::vector<int> test1(4);

    std::cout << "7 * push back test 1" << std::endl;
    test1.push_back(45);
    test1.push_back(46);
    test1.push_back(47);
    test1.push_back(48);
    test1.push_back(49);
    test1.push_back(50);
    test1.push_back(51);

    std::cout << "vector copy = test 1" << std::endl;
    ft::vector<int> copy = test1;
    affiche(copy, "copy of test 1");
    std::cout << std::endl;
    
    std::cout << "vector const test2(3, 42)" << std::endl;   
    const ft::vector<int> test2(3, 42);

    std::cout << "vector test3(test2.begin(), test2.end())" << std::endl;
    ft::vector<int> test3(test2.begin(), test2.end());

    std::cout << "2 * push back test 3" << std::endl;
    test3.push_back(30);
    test3.push_back(30);
    
    std::cout << std::endl << "base iterator" << std::endl;
    ft::vector<int>::iterator it;
    ft::vector<int>::iterator ite = test1.end();
    for(it = test1.begin(); it != ite; it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl << "const iterator" << std::endl;
    ft::vector<int>::const_iterator cite = test3.end();
    for (ft::vector<int>::const_iterator cit = test3.begin(); cit!= cite; cit++)
    {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl << "reverse iterator" << std::endl;

    ft::vector<int>::reverse_iterator rite = test1.rend();
    for (ft::vector<int>::reverse_iterator rit = test1.rbegin(); rit != rite; rit++)
    {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl << "const reverse iterator" << std::endl;
    ft::vector<int>::const_reverse_iterator crite = test3.rend();
    for (ft::vector<int>::const_reverse_iterator crit = test3.rbegin(); crit != crite; crit++)
    {
        std::cout << *crit << " ";
    }
    std::cout << std::endl;
    affiche(test1, "TEST 1 ");
    
    std::cout << std::endl << "resize" << std::endl;
    test1.resize(10);
    affiche(test1, "TEST 1 after resize 10");
    test1.resize(20, 55);
    affiche(test1, "TEST 1 after resize 20, 55");
    test1.resize(10);
    affiche(test1, "TEST 1 after resize 10");
    test1.resize(15);
    affiche(test1, "TEST 1 after resize 15");
    
    std::cout << std::endl << "reserve" << std::endl;
    test1.reserve(5);
    affiche(test1, "TEST 1 after reserve 5");
    test1.reserve(40);
    affiche(test1, "TEST 1 after reserve 40");
    
    std::cout << std::endl << "at et [] operator" << std::endl;
    std::cout << "at5 :" << test1.at(5) << std::endl;
    std::cout << "[5] :" << test1[5] << std::endl;
    
    std::cout << std::endl << "empty" << std::endl;    
    affiche(test1, "TEST 1");
    std::cout << "test 1 empty : " << std::boolalpha << test1.empty() << std::endl;
    affiche(test0, "TEST 0");
    std::cout << "test 0 empty : " << std::boolalpha << test0.empty() << std::endl;
    
    std::cout << std::endl << "max size, front et back" << std::endl;
    affiche(test1, "TEST 1");
    std::cout << "max size : " << test1.max_size() << std::endl;
    std::cout << "front : " << test1.front() << std::endl;
    std::cout << "back : " << test1.back() << std::endl;
    
    std::cout << std::endl << "TEST2 (const)" << std::endl;
    std::cout << "test 2 is empty ? : "<< test2.empty() << std::endl;
    std::cout << "size : " << test2.size() << std::endl;
    std::cout << "max size : " << test2.max_size() << std::endl;
    std::cout << "capacity : " << test2.capacity() << std::endl;
    std::cout << "front : " << test2.front() << std::endl;
    std::cout << "back : " << test2.back() << std::endl;
    
    std::cout << std::endl << "assign" << std::endl;
    test1.assign(test3.begin(), test3.end());
    affiche(test1, "TEST 1 after assign test3.begin, test3.end");
    test1.assign(6, 66);
    affiche(test1, "TEST 1 after assign 6, 66");
    
    std::cout << std::endl << "push/pop back" << std::endl;
    test1.push_back(42);
    affiche(test1, "TEST 1 after push back 42");
    std::cout << std::endl;
    test1.pop_back();
    affiche(test1, "TEST 1 after pop back");
    
    std::cout << std::endl << "insert" << std::endl;
    affiche(test3, "TEST 3");
    test1.insert(test1.begin(), test3.begin(), test3.end());
    affiche(test1, "TEST 1 after insert test3.begin, test3.end");
    test1.insert(++test1.begin(), 3, 86);
    affiche(test1, "TEST 1 after insert 1, 3, 86");
    std::cout << std::endl << "erase" << std::endl;
    test1.erase(test1.begin());
    affiche(test1, "TEST 1 after erase test1.begin");
    test1.erase(test1.begin(), test1.end());
    affiche(test1, "TEST 1 after erase t1.begin, t1.end");
    
    std::cout << std::endl << "swap" << std::endl;
    affiche(test3, "TEST 3");
    test1.swap(test3);
    affiche(test1, "TEST 1 after swap with t3");
    affiche(test3, "TEST 3, after swap t1");
    
    std::cout << std::endl << "clear" << std::endl;
    test1.clear();
    test3.clear();
    affiche(test1, "TEST 1 after clear");
    affiche(test3, "TEST 3 after clear");
    
    std::cout << std::endl << "test relational operators t1, t2" << std::endl;

    if (test1 == test2)
        std::cout << "yes ==" << std::endl;
    else
        std::cout << "not ==" << std::endl;
    if (test1 != test2)
        std::cout << "yes !=" << std::endl;
                else
        std::cout << "not !=" << std::endl;
    if (test1 < test2)
        std::cout << "yes <" << std::endl;
                else
        std::cout << "not <" << std::endl;
    if (test1 > test2)
        std::cout << "yes >" << std::endl;
                else
        std::cout << "not >" << std::endl;
    if (test1 <= test2)
        std::cout << "yes <=" << std::endl;
                else
        std::cout << "not <=" << std::endl;       
    if (test1 >= test2)
        std::cout << "yes >=" << std::endl;
                else
        std::cout << "not >=" << std::endl;


    std::cout << std::endl << "test relational operators t1, t3" << std::endl;

    if (test1 == test3)
        std::cout << "yes ==" << std::endl;
    else
        std::cout << "not ==" << std::endl;
    if (test1 != test3)
        std::cout << "yes !=" << std::endl;
                else
        std::cout << "not !=" << std::endl;
    if (test1 < test3)
        std::cout << "yes <" << std::endl;
                else
        std::cout << "not <" << std::endl;
    if (test1 > test3)
        std::cout << "yes >" << std::endl;
                else
        std::cout << "not >" << std::endl;
    if (test1 <= test3)
        std::cout << "yes <=" << std::endl;
                else
        std::cout << "not <=" << std::endl;       
    if (test1 >= test3)
        std::cout << "yes >=" << std::endl;
                else
        std::cout << "not >=" << std::endl;
    
    std::cout << std::endl << "insert 10 000 int in test1" << std::endl;     

    for (int i = 0; i < 10000; i++)
    {
        test1.push_back(i);
    }
    std::cout << "test1 size : " << test1.size() << std::endl;    
    
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << std::endl << "Time taken by program is : " << std::fixed 
         << time_taken << std::setprecision(5);
    std::cout << " sec " << std::endl;
    
    return 0;
}