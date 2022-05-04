/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:31:42 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/04 17:28:49 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterators_traits.hpp"

namespace ft
{
    class random_access_iterator_tag
    {
    };

    template <typename T>
    class iterator
    {
        public:
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            typedef T* pointer;
            typedef T& reference;
            typedef ft::random_access_iterator_tag iterator_category;

            iterator() : ptr(NULL) {}

            iterator(pointer src) : ptr(src) {}

            iterator(const iterator &src) : ptr(src->ptr) 
            {}

            iterator &operator=(const iterator &rhs)
            {
                if (this != &rhs)
                    this->ptr = rhs.ptr;
                return (*this);
            }
            ~iterator() 
            {}

            reference operator*() const
            {
                return (*(this->ptr));
            }
            pointer operator->() const
            {
                return (this->ptr);
            }

            iterator &operator++()
            {
                this->ptr++;
                return (*this);
            }
            iterator operator++(int)
            {
                iterator tmp = *this;
                this->ptr++;
                return (tmp);
            }
            iterator &operator--()
            {
                this->ptr--;
                return (*this);
            }
            iterator operator--(int)
            {
                iterator tmp = *this;
                this->ptr--;
                return (tmp);
            }

            bool operator==(const iterator &rhs) const
            {
                return (this->ptr == rhs.ptr);
            }
            bool operator!=(const iterator &rhs) const
            {
                return (this->ptr != rhs.ptr);
            }
            bool operator<(const iterator &rhs) const
            {
                return (this->ptr < rhs.ptr);
            }
            bool operator>(const iterator &rhs) const
            {
                return (this->ptr > rhs.ptr);
            }
            bool operator<=(const iterator &rhs) const
            {
                return (this->ptr <= rhs.ptr);
            }
            bool operator>=(const iterator &rhs) const
            {
                return (this->ptr >= rhs.ptr);
            }

            iterator operator+(const difference_type rhs) const
            {
                iterator tmp = *this;
                tmp.ptr += rhs;
                return (tmp);
            }
            iterator operator-(const difference_type rhs) const
            {
                iterator tmp = *this;
                tmp.ptr -= rhs;
                return (tmp);
            }
            iterator &operator+=(const difference_type rhs)
            {
                this->ptr += rhs;
                return (*this);
            }
            iterator &operator-=(const difference_type rhs)
            {
                this->ptr -= rhs;
                return (*this);
            }

            reference operator[](const size_t index) const
            {
                return (this->ptr[index]);
            }

        private:
            pointer ptr;
    };
}
#endif