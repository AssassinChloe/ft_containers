/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:50:56 by cassassi          #+#    #+#             */
/*   Updated: 2022/06/02 10:57:19 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
    template <class Arg1, class Arg2, class Result>
    struct binary_function 
    {
        typedef Arg1 first_argument_type;
        typedef Arg2 second_argument_type;
        typedef Result result_type;
    };
    
    template <class T> 
    class less : ft::binary_function<T,T,bool>
    {
        public :
        bool operator() (const T& x, const T& y) const 
        {
            return x<y;
        }
    };
}