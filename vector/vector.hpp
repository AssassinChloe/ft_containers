/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:12:39 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/03 19:05:34 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <bits/stdc++.h>
#include <cstddef>
#include <algorithm>
#include <stdint.h> 
#include <limits.h>
#include "iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
            typedef T                                               value_type;
            typedef Alloc                                           allocator_type;
            typedef typename allocator_type::reference              reference;
            typedef typename allocator_type::const_reference        const_reference;
            typedef typename allocator_type::pointer                pointer;
            typedef typename allocator_type::const_pointer          const_pointer;
            typedef typename ft::iterator<value_type>               iterator;
            typedef typename ft::iterator<const value_type>         const_iterator;
            typedef typename ft::reverse_iterator<iterator>         reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator>   const_reverse_iterator;
            typedef typename allocator_type::difference_type        difference_type;
            typedef typename allocator_type::size_type              size_type;

            //                  PUBLIC MEMBER FUNCTION


            // Constructors


            explicit vector(const allocator_type &alloc = allocator_type()) 
            : _alloc(alloc), _capacity(10), _arr(_alloc.allocate(_capacity)), _current(0) 
            {}

            explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) 
            : _alloc(alloc), _capacity(10 + n * 2), _arr(_alloc.allocate(_capacity)), _current(n)
            {
                unsigned int i;
                for (i = 0; i < n; i++)
                {
                    _alloc.construct(this->_arr + i, val);
                }
            }
            
            vector(const vector & copy)
            : _alloc(allocator_type()), _capacity(10), _arr(_alloc.allocate(_capacity)), _current(0)
            {
                if (&copy != this)
                    *this = copy;
            }
            vector (iterator first, iterator last, const allocator_type &alloc = allocator_type()) 
            : _alloc(alloc), _capacity(10), _arr(_alloc.allocate(_capacity)), _current(0)
            {
                this->insert(this->begin(), first, last);
            }

        	// Operator=
            vector &operator=(const vector &x)
            {
                this->clear();
                this->_capacity = x.capacity();
                this->_arr = _alloc.allocate(this->_capacity);
                this->_current = x.size();
                for (unsigned int i = 0; i < this->_current; i++)
                {
                    _alloc.construct(this->_arr + i, x[i]);
                }
                return (*this);
            }

        	// Destructors
            ~vector()
            {
                this->clear();
            }

        // ITERATORS

            // begin
            iterator begin() 
            { return (this->_arr); }
            
            const_iterator begin() const 
            { return (this->_arr); }

            // end
            iterator end() 
            { return (this->_arr + this->_current);}
            
            const_iterator end() const 
            {return (this->_arr + this->_current);}

            // rbegin
            reverse_iterator rbegin() 
            { return (this->end()); }
            
            const_reverse_iterator rbegin() const 
            { return (this->end()); }

            // rend
            reverse_iterator rend() 
            { return (this->begin()); }

            const_reverse_iterator rend() const 
            { return (this->begin()); }

        // CAPACITY

            // size
            size_type size() const
            {
                return (this->_current);
            }

            // max_size
            size_type max_size() const
            {
                const size_type diffmax = PTRDIFF_MAX / sizeof(value_type);
                const size_type allocmax = _alloc.max_size();
                return (std::min(diffmax, allocmax));
            }

            // resize
            void resize(size_type n, value_type val = value_type())
            {
                if (n > this->_current)
                {
                    while (this->_current != n)
                        _alloc.destroy(this->_arr + (--this->_current));
                    return ;
                }
                if (n >= this->_capacity)
                    this->reserve(n + 1);
                insert(this->end(), n, val);
            }

            // capacity
            size_type capacity() const 
            { return (this->_capacity); }

            // empty
            bool empty() const
            {
                if (this->_current == 0)
                    return (true);
                return (false);
            }

            // reserve
            void reserve(size_type n)
            {
                if (n > this->_capacity)
                {
                    pointer tmp = _alloc.allocate(n);
                    if (_current > 0)
                    {
                        for (size_type i = 0; i < this->_current; i++)
                        {
                            tmp[i] = this->_arr[i];
                        }
                        this->clear();
                    }
                    this->_capacity = n;
                    this->_arr = tmp;
                }
            }

        // ELEMENT ACCESS

            // Operator[]
            reference operator[](size_type index)
            {    return (this->_arr[index]); }
            
            const_reference operator[](size_type index) const
            {    return (this->_arr[index]); }

            // At
            reference at(size_type n) 
            {
                if (n < this->_current && n >= 0)
                    return (this->_arr[n]);
                throw std::out_of_range("out of range"); 
            }
            
            const_reference at(size_type n) const 
            {
                if (n < this->_current && n >= 0)
                    return (this->_arr[n]);
                throw std::out_of_range("out of range"); 
            }

            // Front
            reference front() 
            { return (this->_arr[0]); }
            
            const_reference front() const 
            { return (this->_arr[0]); }

            // Back
            reference back() 
            { return (this->_arr[this->_current - 1]); }
            
            const_reference back() const 
            { return (this->_arr[this->_current - 1]); }

            // MODIFIERS

            // assign
            void assign(iterator first, iterator last) 
            {
                size_type i;
                for (i = 0; i < this->_current; i++)
                {    
                    _alloc.destroy(this->_arr + i);
                }    
                i = 0;           
                while (first != last)
                {
                    if (i == this->_capacity)
                        reserve(this->_capacity * 2);
                    _alloc.construct(this->_arr + i++, *first);               
                    first++;
                }
                this->_current = i;
            }
            void assign(size_type n, const value_type &val)
            {
                if (n > this->_capacity)
                {
                    this->clear();
                    this->_arr = _alloc.allocate(n * 2);
                    this->_capacity = n * 2;
                }
                else
                {
                    for (size_type i = 0; i < this->_current; i++)
                    {    
                        _alloc.destroy(this->_arr + i);
                    }  
                }
                for (size_type i = 0; i < n; i++)
                {
                    _alloc.construct(this->_arr + i, val);
                }
                this->_current = n;
            }

            // push_back
            void push_back(const value_type &val)
            {
                if (this->_current == this->_capacity)
                    this->reserve(this->_capacity * 2);
                this->_arr[this->_current] = val;
                this->_current++;
            }

            // pop_back
            void pop_back()
            {
                if (this->_current == 0)
                    return ;
                this->_current--;
                _alloc.destroy(this->_arr + (this->_current));
            }

            // insert
            iterator insert(iterator position, const value_type &val) 
            {
                this->insert(position, 1, val);
                return (position);
            }
            
            void insert(iterator position, size_type n, const value_type &val) 
            {
                size_type i = 0;
                while ((this->_current + n) >= this->_capacity)
                        this->reserve(this->_capacity * 2);
                if (position == this->end())
                {
                    while (i < n)
                    {
                        this->push_back(val);
                        i++;
                    }
                }
                else
                {
                    iterator it;
                    vector copy = *this;
                    this->_current += n;
                    i = 0;
                    for (it = this->begin(); it != position; it++)
                    {
                        i++;
                    }
                    for (size_type nb = 0; nb < n; nb++)
                    {
                        *it = val;
                        i++;
                    }
                    while(it != this->end())
                    {
                        this->_arr[i] = copy[i - n];
                        i++;
                        it++;
                    }
                }
            }
            
            void insert(iterator position, iterator first, iterator last)
            {
                while (first != last)
                {
                    this->insert(position, *first);
                    position++; 
                    first++;
                }
            }

            // erase
            iterator erase(iterator position) 
            {
                if (position == --this->end())
                {
                    this->pop_back();
                }
                else 
                {
                    size_type i = 0;
                    vector copy = *this;
                    iterator it;
                    for (it = this->begin(); it != position; it++)
                    {
                        i++;
                    }
                    this->_current--;
                    iterator ite = this->end();
                    while (it != ite)
                    {
                        _alloc.destroy(_arr + i);
                        _alloc.construct(_arr + i, copy[i + 1]);
                        i++;
                        it++;
                    }
                }
                return (position);
            }
            
            iterator erase(iterator first, iterator last) 
            {
                if (first == last)
                {
                    return (erase(first));
                }
                else
                {
                    size_type i = 0;
                    size_type j = 0;
                    size_type k = 0;
                    vector copy = *this;
                    iterator it;
                    for (it = this->begin(); it != first; it++)
                    {
                        i++;
						j++;
                    }
                    while (it != last)
                    {
                        _alloc.destroy(_arr + i++);
						k++;
                        it++;
                        
                    }
                    while (it != this->end())
                    {
						_alloc.destroy(_arr + i++);
                        _alloc.construct(_arr + j, copy[j + k]);
						j++;
                        it++;
                    }
                }
                return (last);
            }

            // swap
            void swap(vector &x) 
            {
				std::swap(this->_alloc, x.get_allocator());
				std::swap(this->_capacity, x.capacity());
				std::swap(this->_current, x.size());
				std::swap(this->_arr, x.begin());
            }

            // clear
            void clear() 
            {
                for (size_type i = 0; i < this->_current; i++)
                {
                    _alloc.destroy(_arr + i);
                }
                _alloc.deallocate(this->_arr, this->_capacity);
                this->_capacity = 0;
                this->_current = 0; 
            }

        // ALLOCATOR

            // get_allocator
            allocator_type get_allocator() const 
            { return (this->_alloc); }

        private:
            allocator_type  _alloc;
            size_type       _capacity;
            pointer         _arr;
            size_type       _current;
    };
	
    //                  NON MEMBER FUNCTION OVERLOADS

    // relational operators

    template <class T, class Alloc>
    bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        if (lhs.capacity() != rhs.capacity() || lhs.size() != rhs.size())
            return (false);
        for (size_t i = 0; i < lhs.size(); i++)
        {
            if (lhs[i] != rhs[i])
                return (false);
        }
        return (true);
    }

    template <class T, class Alloc>
    bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        if (lhs.capacity() != rhs.capacity() || lhs.size() != rhs.size())
            return (true);
        for (size_t i = 0; i < lhs.size(); i++)
        {
            if (lhs[i] != rhs[i])
                return (true);
        }
        return (false);
    }

    template <class T, class Alloc>
    bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        if (lhs.capacity() < rhs.capacity() || lhs.size() < rhs.size())
            return (true);
        for (size_t i = 0; i < lhs.size(); i++)
        {
            if (lhs[i] < rhs[i])
                return (true);
        }
        return (false);
    }

    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        if (lhs.capacity() <= rhs.capacity() || lhs.size() <= rhs.size())
            return (true);
        for (size_t i = 0; i < lhs.size(); i++)
        {
            if (lhs[i] <= rhs[i])
                return (true);
        }
        return (false);
    }
    
    template <class T, class Alloc>
    bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        if (lhs.capacity() > rhs.capacity() || lhs.size() > rhs.size())
            return (true);
        for (size_t i = 0; i < lhs.size(); i++)
        {
            if (lhs[i] > rhs[i])
                return (true);
        }
        return (false);
    }
    
    template <class T, class Alloc>
    bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
   {
        if (lhs.capacity() >= rhs.capacity() || lhs.size() >= rhs.size())
            return (true);
        for (size_t i = 0; i < lhs.size(); i++)
        {
            if (lhs[i] >= rhs[i])
                return (true);
        }
        return (false);
    }
    
    // swap
    template <class T, class Alloc>
    void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
    {
		x.swap(y);
    }
}
#endif