/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:31:22 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/02 18:31:23 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>
#

int main()
{
    try
    {
        ft::vector<int> test(10);
        std::cout << " is empty "<< test.empty() << std::endl;
        test.push_back(45);
        std::cout << "size : " << test.size() << std::endl;
        std::cout << "capacity : " << test.capacity() << std::endl;
        std::cout << "front : " << test.front() << std::endl;
        std::cout << "back : " << test.back() << std::endl;
    
        test.push_back(46);
        test.push_back(47);
        test.push_back(48);
        test.push_back(49);
        test.push_back(50);
        // test.push_back(51);
        std::cout << "at12 :" << test.at(12) << std::endl;

        ft::vector<int> copy = test;
        std::cout << std::endl << "TEST" << std::endl;
        std::cout << "size : " << test.size() << std::endl;
        std::cout << "capacity : " << test.capacity() << std::endl;
        std::cout << "front :" << test.front() << std::endl;
        std::cout << "back :" << test.back() << std::endl;
        std::cout << "at5 :" << test.at(5) << std::endl;
        std::cout << "[5] :" << test[5] << std::endl;
        std::cout << "[16] :" << test[16] << std::endl;
        std::cout << " is empty "<< test.empty() << std::endl;
        test.pop_back();
        std::cout << "size : " << test.size() << std::endl;
        std::cout << "[16] :" << test[16] << std::endl;
        //std::cout << "at16 :" << test.at(16) << std::endl;

        std::cout << std::endl << "COPY" << std::endl;
        std::cout << "size : " << copy.size() << std::endl;
        std::cout << "capacity : " << copy.capacity() << std::endl;
        std::cout << "front :" << copy.front() << std::endl;
        std::cout << "back :" << copy.back() << std::endl;
        std::cout << "at5 :" << copy.at(5) << std::endl;
        std::cout << "[5] :" << copy[5] << std::endl;
        std::cout << "[16] :" << copy[16] << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "Try again !" << std::endl;
    }
    

}