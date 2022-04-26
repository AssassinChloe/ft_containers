/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:12:46 by cassassi          #+#    #+#             */
/*   Updated: 2022/04/26 16:44:03 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

# include <iostream>
# include "vector.h"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        typedef T           value_type;
        typedef Container   container_type;
        typedef size_t      size_type
        
                //                  PUBLIC MEMBER FUNCTIONS
    
    // Constructors
        explicit stack (const container_type& ctnr = container_type());
     
    //empty
        bool empty() const;
        
    //size
        size_type size() const;
        
    //top
        value_type& top();
        const value_type& top() const;
        
    //push
        void push (const value_type& val);
    
    //pop
        void pop();
    };
}
                //                  NON-MEMBER FUNCTION OVERLOADS
                
    //relational operator

        template <class T, class Container>
        bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

        template <class T, class Container>
        bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

        template <class T, class Container>
        bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

        template <class T, class Container>
        bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

        template <class T, class Container>
        bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

        template <class T, class Container>
        bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

#endif