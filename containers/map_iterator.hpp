/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:05:23 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/13 17:43:48 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "iterators_traits.hpp"
#include "map.hpp"

namespace ft
{
    class bidirectional_iterator_tag;
    template <typename T>
    class map_iterator
    {
        public:
            typedef T value_type;
            typedef std::ptrdiff_t difference_type;
            typedef T* pointer;
            typedef T& reference;
            typedef ft::bidirectional_iterator_tag iterator_category;

            map_iterator() : ptr(NULL)
            {}

            map_iterator(pointer src) : ptr(src)
            {}

            map_iterator(const map_iterator &src) 
            {
                *this = src;
            }

            map_iterator &operator=(const map_iterator &rhs)
            {
                if (this != &rhs)
                {
                    this->ptr = rhs.ptr;
                    this->prev = rhs.prev;
                }
                return (*this);
            }
            ~map_iterator() 
            {}

            reference operator*() const
            {
                return (*(this->ptr));
            }
            pointer operator->() const
            {
                return (this->ptr);
            }

            map_iterator &operator++()
            {
                this->ptr = *(this->ptr)->increase(this->ptr);
                return (*this);
            }
            map_iterator operator++(int)
            {
                map_iterator tmp = this;
                this->ptr = *(this->ptr)->increase(this->ptr);
                return (tmp);
            }
            map_iterator &operator--()
            {
                this->ptr = *(this->ptr)->decrease(this->ptr);
                return (*this);
            }
            map_iterator operator--(int)
            {
                map_iterator tmp = this;
                this->ptr = *(this->ptr)->decrease(this->ptr);
                return (tmp);
            }

            bool operator==(const map_iterator &rhs) const
            {
                return (this->ptr == rhs.ptr);
            }
            bool operator!=(const map_iterator &rhs) const
            {
                return (this->ptr != rhs.ptr);
            }

            private:

                pointer ptr;
    };
}
#endif