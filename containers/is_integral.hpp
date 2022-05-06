/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:09:38 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/06 13:59:38 by cassassi         ###   ########.fr       */
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
        operator T() { return v; }
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
    
        /*
        fundamental integral types
    bool
    char
    char16_t
    char32_t
    wchar_t
    signed char
    short int
    int
    long int
    long long int
    unsigned char
    unsigned short int
    unsigned int
    unsigned long int
    unsigned long long int

        Template parameters
    T
    A type.
        */

}
/*
Template parameters
T
Type of the integral constant.
Aliased as member type integral_constant::value_type.
v
Value of the integral constant.
Accessible as member integral_constant::value, or through type casting.


member type	definition
value_type	The type of the constant (template parameter T)
type	The integral_constant type itself
*/

#endif