/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:31:22 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/04 17:18:26 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>
#include "iterator.hpp"

void  affiche(ft::vector<int> test1, std::string name)
{   
    ft::vector<int>::iterator it;
    ft::vector<int>::iterator ite = test1.end();
    std::cout << std::endl << name << std::endl;
    std::cout << "size : " << test1.size() << std::endl;
    std::cout << "capacity : " << test1.capacity() << std::endl;
    for(it = test1.begin(); it != ite; it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    try
    {
        
        ft::vector<int> test0;
        ft::vector<int> test1(4);
        test1.push_back(45);
        test1.push_back(46);
        test1.push_back(47);
        test1.push_back(48);
        test1.push_back(49);
        test1.push_back(50);
        test1.push_back(51);
        ft::vector<int> copy = test1;
        ft::vector<const int> test2(3, 42);
        ft::vector<int> test3(test1.begin(), test1.end());
        
        std::cout << std::endl << "iterators" << std::endl;
        ft::vector<int>::iterator it;
        ft::vector<int>::iterator ite = test1.end();
        for( it = test1.begin(); it != ite; it++)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        ft::vector<const int>::const_iterator cite = test2.end();
        for (ft::vector<const int>::const_iterator cit = test2.begin(); cit!= cite; cit++)
        {
            std::cout << *cit << " ";

        }
        std::cout << std::endl;
        ft::vector<int>::reverse_iterator rite = test1.rend();
        for (ft::vector<int>::reverse_iterator rit = test1.rbegin(); rit != rite; rit++)
        {
            std::cout << *rit << " ";

        }
        std::cout << std::endl;
        ft::vector<int>::const_reverse_iterator crite = test1.rend();
        for (ft::vector<int>::const_reverse_iterator crit = test1.rbegin(); crit != crite; crit++)
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
        std::cout << "test 1 is empty ? : "<< test1.empty() << std::endl;
        affiche(test0, "TEST 0");
        std::cout << "test 0 is empty ? : "<< test0.empty() << std::endl;

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
        affiche(copy, "COPY");
        affiche(test1, "TEST 1 assign test3.gebin, test3.end");
        test1.assign(test3.begin(), test3.end());


        affiche(test1, "TEST 1 assign 6, 66");
        test1.assign(6, 66);


        std::cout << std::endl << "push/pop back" << std::endl;
        test1.push_back(42);
        affiche(test1, "TEST 1 after push back 42");

        std::cout << std::endl;
        test1.pop_back();
        affiche(test1, "TEST 1 after pop back");

        std::cout << std::endl << "insert" << std::endl;

        affiche(test3, "TEST 3");
        test1.insert(test1.begin(), test3.begin(), test3.end());
        // affiche(test2, "TEST 2");
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
        affiche(test1, "TEST 1 after clear");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "Try again !" << std::endl;
    }
}