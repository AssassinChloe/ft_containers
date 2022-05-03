/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:59:00 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/03 18:59:29 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_ITERATOR_HPP
#define CONST_ITERATOR_HPP

namespace ft
{
    class random_access_iterator_tag
    {
    };

    template <typename T>
    class const_iterator
    {
        public:
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            typedef T* pointer;
            typedef T& reference;
            typedef ft::random_access_iterator_tag iterator_category;

            const_iterator() : ptr(NULL) {}
            
            const_iterator(pointer src) : ptr(src) {}

            const_iterator(const const_iterator &src) : ptr(src->ptr) {}
            
            const_iterator &operator=(const const_iterator &rhs)
            {
                if (this != &rhs)
                    this->ptr = rhs.ptr;
                return (*this);
            }
            ~const_iterator() {}

            reference operator*() const
            {
                return (*(this->ptr));
            }
            pointer operator->() const
            {
                return (this->ptr);
            }

            bool operator==(const const_iterator &rhs) const
            {
                return (this->ptr == rhs.ptr);
            }
            bool operator!=(const const_iterator &rhs) const
            {
                return (this->ptr != rhs.ptr);
            }
            bool operator<(const const_iterator &rhs) const
            {
                return (this->ptr < rhs.ptr);
            }
            bool operator>(const const_iterator &rhs) const
            {
                return (this->ptr > rhs.ptr);
            }
            bool operator<=(const const_iterator &rhs) const
            {
                return (this->ptr <= rhs.ptr);
            }
            bool operator>=(const const_iterator &rhs) const
            {
                return (this->ptr >= rhs.ptr);
            }

            const_iterator operator+(const difference_type rhs) const
            {
                const_iterator tmp = *this;
                tmp.ptr += rhs;
                return (tmp);
            }
            const_iterator operator-(const difference_type rhs) const
            {
                const_iterator tmp = *this;
                tmp.ptr -= rhs;
                return (tmp);
            }
            const_iterator &operator+=(const difference_type rhs)
            {
                this->ptr += rhs;
                return (*this);
            }
            const_iterator &operator-=(const difference_type rhs)
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