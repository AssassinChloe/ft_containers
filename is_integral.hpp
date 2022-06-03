/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:09:38 by cassassi          #+#    #+#             */
/*   Updated: 2022/06/03 12:15:30 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft
{
    //integral_constant
    template <class T, T v>
    struct integral_constant
    {
        enum { value = v };
        typedef T value_type;
        typedef integral_constant<T,v> type;
        operator T() 
        { 
            return v;
        }
    };

    //true_type
    typedef integral_constant<bool, true> true_type;
    
    //false_type
    typedef integral_constant<bool, false> false_type;

    // is_integral
    template <class T>
    struct is_integral : public false_type
    {};

    template <>
    struct is_integral<bool> : public true_type
    {};
    
    template <>
    struct is_integral<char> : public true_type
    {};    
    
    template <>
    struct is_integral<wchar_t> : public true_type
    {};    
    
    template <>
    struct is_integral<signed char> : public true_type
    {};    
    
    template <>
    struct is_integral<short int> : public true_type
    {};    
    
    template <>
    struct is_integral<int> : public true_type
    {};    
    
    template <>
    struct is_integral<long int> : public true_type
    {};    
    
    template <>
    struct is_integral<long long int> : public true_type
    {};    
    
    template <>
    struct is_integral<unsigned char> : public true_type
    {};    
    
    template <>
    struct is_integral<unsigned short int> : public true_type
    {};    
    
    template <>
    struct is_integral<unsigned int> : public true_type
    {};    
    
    template <>
    struct is_integral<unsigned long int> : public true_type
    {};    
    
    template <>
    struct is_integral<unsigned long long int> : public true_type
    {};
    
    template <typename T>
    struct is_integral<const T> : public is_integral<T>
    {};
}
#endif