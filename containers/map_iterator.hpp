/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:05:23 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/24 11:53:21 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "iterators_traits.hpp"
#include "pair.hpp"
#include "binary_search_tree.hpp"
#include "map.hpp"

namespace ft
{
    class bidirectional_iterator_tag;
    template <typename Node, typename T>
    class map_iterator
    {
        public:
            typedef T value_type;
            typedef std::ptrdiff_t difference_type;
            typedef T* pointer;
            typedef T& reference;
            typedef ft::bidirectional_iterator_tag iterator_category;

            map_iterator() : ptr(NULL), _root(NULL)
            {}

            map_iterator(Node *src) : ptr(src), _root(src)
            {
                
            }

            map_iterator(const map_iterator &src) 
            {
                *this = src;
            }

            map_iterator &operator=(const map_iterator &rhs)
            {
                if (this != &rhs)
                {
                    this->ptr = rhs.ptr;
                    this->_root = rhs._root;
                }
                return (*this);
            }
            ~map_iterator() 
            {}

            reference operator*() const
            {
                Node *tmp = this->ptr;
                return (tmp->_key);
            }
            
            pointer operator->() const
            {
                return (this->ptr);
            }

            map_iterator &operator++()
            {
                this->ptr = this->ptr->increase(this->ptr);
                return (*this);
            }
            
            map_iterator operator++(int)
            {
                map_iterator copy = *this;
                this->ptr = this->ptr->increase(this->ptr);
                return (copy);
            }
            
            map_iterator &operator--()
            {
                this->ptr = this->ptr->decrease(this->ptr);
                return (*this);
            }
            
            map_iterator operator--(int)
            {
                map_iterator copy = *this;
                this->ptr = this->ptr->decrease(this->ptr);
                return (copy);
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

                Node    *ptr;
                Node    *_root;
    };
}
#endif