/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:12:46 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/20 17:06:54 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

# include <iostream>
# include "vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        public:
        
            typedef T           value_type;
            typedef Container   container_type;
            typedef size_t      size_type;
            
                    //                  PUBLIC MEMBER FUNCTIONS
        
        // Constructors
            explicit stack (const container_type& ctnr = container_type()) : c(ctnr)
            {}
        
        //empty
            bool empty() const
            {
                return (c.empty());
            }
            
        //size
            size_type size() const        
            {
                return (c.size());
            }
        //top
            value_type& top()
            {
                return (c.back());
            }

            const value_type& top() const
            {
                return (c.back());
            }
        //push
            void push(const value_type& val)
            {
                return (c.push_back(val));
            }
        
        //pop
            void pop()
            {
                return (c.pop_back());
            }

            template <class Tsrc, class Containersrc>
            friend bool operator== (const stack<Tsrc,Containersrc>& lhs, const stack<Tsrc,Containersrc>& rhs);
            
            template <class Tsrc, class Containersrc>
            friend bool operator!= (const stack<Tsrc,Containersrc>& lhs, const stack<Tsrc,Containersrc>& rhs);
            
            template <class Tsrc, class Containersrc>
            friend bool operator<  (const stack<Tsrc,Containersrc>& lhs, const stack<Tsrc,Containersrc>& rhs);
            
            template <class Tsrc, class Containersrc>
            friend bool operator<= (const stack<Tsrc,Containersrc>& lhs, const stack<Tsrc,Containersrc>& rhs);
            
            template <class Tsrc, class Containersrc>
            friend bool operator>  (const stack<Tsrc,Containersrc>& lhs, const stack<Tsrc,Containersrc>& rhs);
            
            template <class Tsrc, class Containersrc>
            friend bool operator>= (const stack<Tsrc,Containersrc>& lhs, const stack<Tsrc,Containersrc>& rhs);
        
        protected :
            container_type c;
            
    };

                //                  NON-MEMBER FUNCTION OVERLOADS
                
    //relational operator

        template <class T, class Container>
        bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return(lhs.c == rhs.c);
        }

        template <class T, class Container>
        bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return(lhs.c != rhs.c);
        }

        template <class T, class Container>
        bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return(lhs.c < rhs.c);
        }

        template <class T, class Container>
        bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return(lhs.c >= rhs.c);
        }

        template <class T, class Container>
        bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return(lhs.c > rhs.c);
        }

        template <class T, class Container>
        bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return(lhs.c >= rhs.c);
        }
}
#endif