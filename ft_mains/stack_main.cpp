/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:11:20 by cassassi          #+#    #+#             */
/*   Updated: 2022/06/03 13:45:46 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.hpp"
#include <iostream>
#include <deque>
#include <list>
#include <vector>

int main()
{
    clock_t start, end;
    start = clock();
    
    std::cout << "FT::STACK" << std::endl;
    
    std::cout << "stack <int, vector<int>> test1, test2" << std::endl;
    
    ft::stack<int, ft::vector<int> > test1;
    ft::stack<int, ft::vector<int> > test2;
    
    std::cout << "test 1 empty : " << std::boolalpha << test1.empty() << std::endl;
    
    std::cout << "push in test1" << std::endl;

    test1.push(45);
    test1.push(46);
    test1.push(47);
    test1.push(48);
    test1.push(49);
    test1.push(50);
    test1.push(51);
    
    std::cout << "same push in test2" << std::endl;

    test2.push(45);
    test2.push(46);
    test2.push(47);
    test2.push(48);
    test2.push(49);
    test2.push(50);
    test2.push(51);
    
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
        
    std::cout << std::endl << "test 1 empty : " << std::boolalpha << test1.empty() << std::endl;
    std::cout << "t1 size : " << test1.size() << std::endl;
    std::cout << "t1 top : " << test1.top() << std::endl;        

    test1.pop();
    test1.pop();
    std::cout << std::endl << "test1 size, front after 2 pop()" << std::endl;
    std::cout << "t1 size : " << test1.size() << std::endl;
    std::cout << "t1 top : " << test1.top() << std::endl;        

    std::cout  << std::endl << "test relational operators t1, t2" << std::endl;

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
    
    std::cout  << std::endl << "clear stack" << std::endl;
    while(test1.size() > 0)
        test1.pop();
    std::cout << "fill stack with 10 000 value" << std::endl;
    for (int i = 0; i < 10000; i++)
    {
        test1.push(i);
    }
    std::cout << "Test1 size : " << test1.size() << std::endl;

    std::cout << std::endl << "Test with STL containers" << std::endl;
          
    ft::stack<int, std::vector<int> > testvect;
    ft::stack<int, std::list<int> > testlist;
    ft::stack<int, std::deque<int> > testdeq;

    std::cout << "test vector empty : " << std::boolalpha << testvect.empty() << std::endl;
    std::cout << "test list empty : " << std::boolalpha << testlist.empty() << std::endl;
    std::cout << "test deque empty : " << std::boolalpha << testdeq.empty() << std::endl;
    
    std::cout << std::endl << "Push * 3 (24, 7, 42)" << std::endl;

    testvect.push(24);
    testlist.push(24);
    testdeq.push(24);

    testvect.push(7);
    testlist.push(7);
    testdeq.push(7);

    testvect.push(42);
    testlist.push(42);
    testdeq.push(42);
    
    std::cout << "vector size : " << testvect.size() << std::endl;
    std::cout << "vector top : " << testvect.top() << std::endl;
    std::cout << "list size : " << testlist.size() << std::endl;
    std::cout << "list top : " << testlist.top() << std::endl;
    std::cout << "deque size : " << testdeq.size() << std::endl;
    std::cout << "deque top : " << testdeq.top() << std::endl;

    std::cout << std::endl << "Pop" << std::endl;

    testvect.pop();
    testlist.pop();
    testdeq.pop();

    std::cout << "vector size : " << testvect.size() << std::endl;
    std::cout << "vector top : " << testvect.top() << std::endl;
    std::cout << "list size : " << testlist.size() << std::endl;
    std::cout << "list top : " << testlist.top() << std::endl;
    std::cout << "deque size : " << testdeq.size() << std::endl;
    std::cout << "deque top : " << testdeq.top() << std::endl;
    
    ft::stack<int, std::vector<int> > testvect2;
    ft::stack<int, std::list<int> > testlist2;
    ft::stack<int, std::deque<int> > testdeq2;

    testvect2.push(42);
    testlist2.push(42);
    testdeq2.push(42);

    std::cout  << std::endl << "test relational operators vector" << std::endl;
    if (testvect == testvect2)
        std::cout << "yes ==" << std::endl;
    else
        std::cout << "not ==" << std::endl;
    if (testvect != testvect2)
        std::cout << "yes !=" << std::endl;
    else
        std::cout << "not !=" << std::endl;
    if (testvect < testvect2)
        std::cout << "yes <" << std::endl;
    else
        std::cout << "not <" << std::endl;
    if (testvect > testvect2)
        std::cout << "yes >" << std::endl;
    else
        std::cout << "not >" << std::endl;
    if (testvect <= testvect2)
        std::cout << "yes <=" << std::endl;
    else
        std::cout << "not <=" << std::endl;       
    if (testvect >= testvect2)
        std::cout << "yes >=" << std::endl;
    else
        std::cout << "not >=" << std::endl;

    std::cout  << std::endl << "test relational operators list" << std::endl;
    if (testlist == testlist2)
        std::cout << "yes ==" << std::endl;
    else
        std::cout << "not ==" << std::endl;
    if (testlist != testlist2)
        std::cout << "yes !=" << std::endl;
    else
        std::cout << "not !=" << std::endl;
    if (testlist < testlist2)
        std::cout << "yes <" << std::endl;
    else
        std::cout << "not <" << std::endl;
    if (testlist > testlist2)
        std::cout << "yes >" << std::endl;
    else
        std::cout << "not >" << std::endl;
    if (testlist <= testlist2)
        std::cout << "yes <=" << std::endl;
    else
        std::cout << "not <=" << std::endl;       
    if (testlist >= testlist2)
        std::cout << "yes >=" << std::endl;
    else
        std::cout << "not >=" << std::endl;

    std::cout  << std::endl << "test relational operators deque" << std::endl;
    if (testdeq == testdeq2)
        std::cout << "yes ==" << std::endl;
    else
        std::cout << "not ==" << std::endl;
    if (testdeq != testdeq2)
        std::cout << "yes !=" << std::endl;
    else
        std::cout << "not !=" << std::endl;
    if (testdeq < testdeq2)
        std::cout << "yes <" << std::endl;
    else
        std::cout << "not <" << std::endl;
    if (testdeq > testdeq2)
        std::cout << "yes >" << std::endl;
    else
        std::cout << "not >" << std::endl;
    if (testdeq <= testdeq2)
        std::cout << "yes <=" << std::endl;
    else
        std::cout << "not <=" << std::endl;       
    if (testdeq >= testdeq2)
        std::cout << "yes >=" << std::endl;
    else
        std::cout << "not >=" << std::endl;
        
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << std::endl << "Time taken by program is : " << std::fixed 
         << time_taken << std::setprecision(5);
    std::cout << " sec " << std::endl;
    
    return 0;
}
