/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:31:42 by cassassi          #+#    #+#             */
/*   Updated: 2022/06/03 14:29:55 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

# include "iterators_traits.hpp"

namespace ft
{   

    
    class random_access_iterator_tag;
    
    template <typename T>
    class iterator
    {
        public:
            typedef T value_type;
            typedef std::ptrdiff_t difference_type;
            typedef T* pointer;
            typedef T& reference;
            typedef ft::random_access_iterator_tag iterator_category;

            iterator() : ptr(NULL) {}
            
            iterator(pointer src)
            {
                this->ptr = src;
            }
            
            template<typename Tr>
            iterator(Tr *src)
            {
                this->ptr = src;
            }
            
            iterator(const iterator &src) 
            {
                *this = src;
            }

            template <typename Tr>
            iterator(const ft::iterator<Tr> &src)
            {
                *this = src;
            }

            
            iterator &operator=(const iterator &rhs)
            {
                if (this != &rhs)
                    this->ptr = rhs.ptr;
                return (*this);
            }

            template<typename Tr>
            iterator &operator=(const ft::iterator<Tr> rhs)
            {
                this->ptr = rhs.getPtr();
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

            bool operator==(const iterator &rhs)
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
            
            pointer getPtr() const
            {
                return (this->ptr);
            }
            
        private:
            pointer ptr;
    };

    template<typename Tl, typename Tr>
    typename ft::iterator<Tl>::difference_type operator==(const ft::iterator<Tl> lhs,
    const ft::iterator<Tr> rhs)
    {
        return (lhs.getPtr() == rhs.getPtr());
    }
    
    template<typename Tl, typename Tr>
    typename ft::iterator<Tl>::difference_type operator!=(const ft::iterator<Tl> lhs,
    const ft::iterator<Tr> rhs)
    {
        return (lhs.getPtr() != rhs.getPtr());
    }
    
}
#endif