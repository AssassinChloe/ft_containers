/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:31:31 by cassassi          #+#    #+#             */
/*   Updated: 2022/06/03 14:30:24 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

# include "iterator.hpp"
# include "iterators_traits.hpp"

namespace ft
{
    class random_access_iterator_tag;

    template <typename T>
    class reverse_iterator
    {
        public:
            typedef T iterator_type;
            typedef typename ft::iterator_traits<T>::difference_type difference_type;
            typedef typename ft::iterator_traits<T>::value_type value_type;
            typedef typename ft::iterator_traits<T>::pointer pointer;
            typedef typename ft::iterator_traits<T>::reference reference;
            typedef typename ft::iterator_traits<T>::iterator_category iterator_category;

            
            reverse_iterator() {}

            explicit reverse_iterator(iterator_type it = iterator_type()) : _base(it)
            {}
            
            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it) : _base(rev_it.base())
            {}
            reverse_iterator &operator=(const reverse_iterator &rhs)
            {
                if (this != &rhs)
                    _base = rhs.base();
                return (*this);
            }
            
            virtual ~reverse_iterator() {}

            iterator_type base() const
            {
                return (this->_base);
            }
            
            reference operator*() const
            {
                iterator_type tmp = this->_base;
                tmp--;
                return (*tmp);
            }
            
            pointer operator->() const
            {
                return (&operator*());
            }
            
            reverse_iterator &operator++()
            {
                this->_base--;
                return (*this);
            }
            reverse_iterator operator++(int)
            {
                reverse_iterator tmp = *this;
                this->_base--;
                return (tmp);
            }
            reverse_iterator &operator--()
            {
                this->_base++;
                return (*this);
            }
            reverse_iterator operator--(int)
            {
                reverse_iterator tmp = *this;
                this->_base++;
                return (tmp);
            }

            reverse_iterator operator+(const difference_type n) const
            {
                reverse_iterator tmp = *this;
                tmp._base -= n;
                return (tmp);
            }
            reverse_iterator operator-(const difference_type n) const
            {
                reverse_iterator tmp = *this;
                tmp._base += n;
                return (tmp);
            }
            reverse_iterator &operator+=(const difference_type n)
            {
                this->_base -= n;
                return (*this);
            }
            reverse_iterator &operator-=(const difference_type n)
            {
                this->_base += n;
                return (*this);
            }

            reference operator[](difference_type n) const
            {
                return (this->_base[n - 1]);
            }

        protected:
           T _base;

        private :   
    };
    
    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    template <class Iterator>
    reverse_iterator<Iterator> operator+ (
    typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
    {
        return (rev_it + n);
    }
            
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator- (
    const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs - rhs);
    }

}
#endif