/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:25:25 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/06 17:25:26 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP
namespace ft
{
    template <bool Cond, class T = void>
    struct enable_if
    {};
    
    template<class T>
    struct enable_if<true, T> { typedef T type; };
}
//SFINAE

#endif