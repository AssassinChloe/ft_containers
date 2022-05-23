/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:22:12 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/23 10:45:49 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stack>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>


int main()
{
    clock_t start, end;
    start = clock();
    try
    {
        std::stack<int, std::vector<int> > test1;
        std::stack<int, std::vector<int> > copy = test1;
        std::stack<int, std::vector<int> > test2;

        test1.push(45);
        test1.push(46);
        test1.push(47);
        test1.push(48);
        test1.push(49);
        test1.push(50);
        test1.push(51);
        
        test2.push(45);
        test2.push(46);
        test2.push(47);
        test2.push(48);
        test2.push(49);
        test2.push(50);
        test2.push(51);
        
        if (test1 == test2)
            std::cout << "==" << std::endl;
        else
            std::cout << "not ==" << std::endl;
        if (test1 != test2)
            std::cout << "!=" << std::endl;
                    else
            std::cout << "not !=" << std::endl;
        if (test1 < test2)
            std::cout << "<" << std::endl;
                    else
            std::cout << "not <" << std::endl;
        if (test1 > test2)
            std::cout << ">" << std::endl;
                    else
            std::cout << "not >" << std::endl;
        if (test1 <= test2)
            std::cout << "<=" << std::endl;
                    else
            std::cout << "not <=" << std::endl;       
        if (test1 >= test2)
            std::cout << ">=" << std::endl;
                    else
            std::cout << "not >=" << std::endl;
        std::cout << std::endl << "empty" << std::endl;    
        std::cout << "test 1 is empty ? : "<< test1.empty() << std::endl;
        std::cout << "copy (before push) is empty ? : "<< copy.empty() << std::endl;

        std::cout << std::endl << "size, front et back" << std::endl;
        std::cout << "t1 size : " << test1.size() << std::endl;
        std::cout << "t1 top : " << test1.top() << std::endl;        
        std::cout << "copy size : " << test1.size() << std::endl;
        std::cout << "copy top : " << test1.top() << std::endl;

        test1.pop();
        test1.pop();

        std::cout << std::endl << "size, front et back after 2 pop()" << std::endl;
        std::cout << "t1 size : " << test1.size() << std::endl;
        std::cout << "t1 top : " << test1.top() << std::endl;        
        std::cout << "copy size : " << test1.size() << std::endl;
        std::cout << "copy top : " << test1.top() << std::endl;
        
        copy.push(49);
        copy.push(50);
        copy.push(51);
        
        std::cout << std::endl << "size, front et back after 2 pop()" << std::endl;
        std::cout << "t1 size : " << test1.size() << std::endl;
        std::cout << "t1 top : " << test1.top() << std::endl;        
        std::cout << "copy size : " << test1.size() << std::endl;
        std::cout << "copy top : " << test1.top() << std::endl;

        std::cout << "test 1 is empty ? : "<< test1.empty() << std::endl;
        std::cout << "copy (before push) is empty ? : "<< copy.empty() << std::endl;
        
        std::cout << "clear stack" << std::endl;
        while(test1.size() > 0)
            test1.pop();

        std::cout << "fill stack" << std::endl;
        for (int i = 0; i < 10000; i++)
        {
            test1.push(i);
        }
        std::cout << test1.size() << std::endl;
                
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "Try again !" << std::endl;
    }
    
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << std::endl << "Time taken by program is : " << std::fixed 
         << time_taken << std::setprecision(5);
    std::cout << " sec " << std::endl;
    
    return 0;
}