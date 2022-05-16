/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:05:23 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/16 17:30:42 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "iterators_traits.hpp"
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

            map_iterator(Node *src) : _root(src)
            {
                T tmp = src->getKey();
                ptr = (&tmp);
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
                return (*(this->ptr));
            }
            pointer operator->() const
            {
                return (this->ptr);
            }

            map_iterator &operator++()
            {
                T tmp = this->_root->increase(*this->ptr);
                this->ptr = &tmp;
                return (*this);
            }
            map_iterator operator++(int)
            {
                map_iterator copy = *this;
                T tmp = this->_root->increase(*this->ptr);
                this->ptr = &tmp;
                return (copy);
            }
            map_iterator &operator--()
            {
                T tmp = this->_root->decrease(*this->ptr);
                ptr = &tmp;
                return (*this);
            }
            map_iterator operator--(int)
            {
                map_iterator copy = *this;
                T tmp = this->_root->decrease(*this->ptr);
                ptr = &tmp;
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

                pointer ptr;
                Node    *_root;
    };
}
#endif