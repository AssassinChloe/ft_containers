/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_main.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:25:52 by cassassi          #+#    #+#             */
/*   Updated: 2022/06/03 12:18:02 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector.hpp"
#include <iostream>
#include "../iterator.hpp"
#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
#include <iomanip>
#include <stdlib.h>
#include <type_traits>

int main()
{
    ft::vector<int>v1(10);
    ft::vector<char>plop(10);
    ft::vector<int>v2(10, 42);
    // std::vector<int const>v3(10, 1);
    // std::vector<int const>v4(10, 43);
    // std::vector<int const>v5(10);

    // std::vector<int const>::iterator it0 = v1.begin();
    ft::vector<int>::iterator it1(v1.begin());
    ft::vector<int>::const_iterator it2 = v1.begin();  
    ft::vector<int>::const_iterator it3(v1.begin());  
    // std::vector<int const>::iterator it3 = v3.begin();
    // std::vector<int const>::const_iterator it4 = v3.begin();
    if (it1 == it2 && it2 == it3)
        std::cout << "comparaison ok" << std::endl;

}
