/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:11:20 by cassassi          #+#    #+#             */
/*   Updated: 2022/06/02 14:33:58 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.hpp"
#include <iostream>

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
                
  
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << std::endl << "Time taken by program is : " << std::fixed 
         << time_taken << std::setprecision(5);
    std::cout << " sec " << std::endl;
    
    return 0;
}
