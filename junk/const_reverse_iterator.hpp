/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_reverse_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:31:31 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/04 17:50:09 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_REVERSE_ITERATOR_HPP
#define CONST_REVERSE_ITERATOR_HPP

#include "iterator.hpp"
#include "iterators_traits.hpp"

namespace ft
{
    class random_access_iterator_tag
    {
    };

    template <typename T>
    class const_reverse_iterator
    {
        public:
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            typedef T *pointer;
            typedef T &reference;
            typedef ft::random_access_iterator_tag iterator_category;

            const_reverse_iterator() : base(NULL) {}
            
            const_reverse_iterator(const const_reverse_iterator &src) 
            {
                *this = src;
            }
            
            const_reverse_iterator &operator=(const const_reverse_iterator &rhs)
            {
                if (this != &rhs)
                    this->base = rhs.base;
                return (*this);
            }
            ~const_reverse_iterator() {}

            reference operator*() const
            {
                return (*(this->base));
            }
            pointer operator->() const
            {
                return (this->base);
            }

            bool operator==(const const_reverse_iterator &rhs) const
            {
                return (this->base == rhs.base);
            }
            bool operator!=(const const_reverse_iterator &rhs) const
            {
                return (this->base != rhs.base);
            }
            bool operator<(const const_reverse_iterator &rhs) const
            {
                return (this->base > rhs.base);
            }
            bool operator>(const const_reverse_iterator &rhs) const
            {
                return (this->base < rhs.base);
            }
            bool operator<=(const const_reverse_iterator &rhs) const
            {
                return (this->base >= rhs.base);
            }
            bool operator>=(const const_reverse_iterator &rhs) const
            {
                return (this->base <= rhs.base);
            }

            const_reverse_iterator operator+(const difference_type rhs) const
            {
                const_reverse_iterator tmp = *this;
                tmp.base -= rhs;
                return (tmp);
            }
            const_reverse_iterator operator-(const difference_type rhs) const
            {
                const_reverse_iterator tmp = *this;
                tmp.base += rhs;
                return (tmp);
            }
            const_reverse_iterator &operator+=(const difference_type rhs)
            {
                this->base -= rhs;
                return (*this);
            }
            const_reverse_iterator &operator-=(const difference_type rhs)
            {
                this->base += rhs;
                return (*this);
            }

            reference operator[](const size_t index) const
            {
                return (this->base[index - 1]);
            }

        private:
            ft::iterator<const T> base;
    };

}
#endif