/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:12:39 by cassassi          #+#    #+#             */
/*   Updated: 2022/04/28 14:56:51 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

# include <memory>
# include <bits/stdc++.h>
# include <cstddef>
# include <algorithm>
# include <limits.h>

namespace ft
{
    template < class T, class Alloc = std::allocator<T> > 
    class vector
    {
        public:
        
        typedef T                                                       value_type; 
        typedef Alloc                                                   allocator_type;
        typedef typename allocator_type::reference                      reference;
        typedef typename allocator_type::const_reference                const_reference;
        typedef typename allocator_type::pointer                        pointer;
        typedef typename allocator_type::const_pointer                  const_pointer;
        typedef typename ft::random_access_iterator<value_type>         iterator;
        typedef typename ft::random_access_iterator<const value_type>   const_iterator;
        typedef typename ft::reverse_iterator<iterator>                 reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator>           const_reverse_iterator;
        typedef typename allocator_type::ptrdiff_t                      difference_type;
        typedef typename allocator_type::size_type                      size_type;

        //                  PUBLIC MEMBER FUNCTION

    //
        // Constructors

        vector()
         : arr(allocator_type.allocate(1)), _capacity(1), _current(0) {}
        
        explicit vector(const allocator_type& alloc = allocator_type())
         : arr(alloc), _capacity(alloc.capacity()), _current(size()) {}
        
        explicit vector(size_type n, const value_type& val = value_type(),
                        const allocator_type& alloc = allocator_type())
        : arr(allocator_type(n)), _capacity(n), _current(0) {}
                        
        template <class InputIterator>
        vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type());
                 
        vector(const vector&);
        {
            if (&vector != this)
            {
                this = vector;                    
            }
            return (*this)
        }
        
        // Operator=
        vector& operator=(const vector& x)
        {
            if (this->_current > 0)
            {
                
                
            }
        }
        
        // Destructors
        ~vector()
        {
            allocator_type.deallocate(this->arr, this->_capacity);
            allocator_type.destroy(this->arr);
        }

    //ITERATORS
        
        // begin
        iterator begin() {return (c.begin());}
        const_iterator begin() const {return (c.begin());}
        
        // end
        iterator end() {return (c.end());}
        const_iterator end() const {return (c.end());}
        
        // rbegin     
        reverse_iterator rbegin() {return (c.rbegin());}
        const_reverse_iterator rbegin() const {return (c.rbegin());}
        
        // rend
        reverse_iterator rend() {return (c.rend());}
        const_reverse_iterator rend() const {return (c.rend());}

    //CAPACITY
        
        // size
        size_type size() const 
        {
            return (_current);
        }
        
        // max_size
        size_type max_size() const
        {
            const size_t diffmax = PTRDIFF_MAX / sizeof(value_type);
            const size_t allocmax = allocator_type::max_size();
            return (std::min(diffmax, allocmax));
        }

        // resize
        void resize (size_type n, value_type val = value_type());
        
        // capacity
        size_type capacity() const { return (_capacity)}

        // empty
        bool empty() const
        {
            if (_current == 0)
                return (true);
            return (false);
        }

        // reserve
        void reserve (size_type n);

        //ELEMENT ACCESS
        
        // Operator[]
        reference operator[](size_type index)
        {
            if (index < this->_current)
            return (arr[index]);
        }
        const_reference operator[](size_type index) const
        {
            if (index < this->_current)
            return (arr[index]);
        }
        
        // At
        reference at(size_type n);
        const_reference at(size_type n) const;

        // Front
        reference front() {return (arr[0]);}
        const_reference front() const {return (arr[0]);}

        // Back
        reference back() {return (arr[_current - 1]);}
        const_reference back() const {return (arr[_current - 1]);}
        
    //MODIFIERS
        
        // assign
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last);
        void assign (size_type n, const value_type& val);
        
        // push_back
        void push_back (const value_type& val) 
        {
            if (_current == _capacity)
            {
                T* temp = allocator_type.allocate(2 * _capacity);
                for (unsigned int i = 0; i < _capacity; i++) 
                {
                    temp[i] = arr[i];
                }
                allocator_type.deallocate(this->arr, _capacity);
                allocator_type.destroy(this->arr);
                _capacity *= 2;
                this->arr = temp;
            }
            arr[_current] = val;
            _current++;
        }
        
        // pop_back
        void pop_back() 
        { 
            if (_current > 0)
                _current--; 
        }
        
        // insert
        iterator insert (iterator position, const value_type& val);
        void insert (iterator position, size_type n, const value_type& val);
        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last);

        // erase
        iterator erase (iterator position);
        iterator erase (iterator first, iterator last);
        
        // swap
        void swap (vector& x);
        
        // clear
        void clear();
        
    //ALLOCATOR
        
        // get_allocaor
        allocator_type get_allocator() const { return (allocator_type) ;}

        private :

            T* arr;
            unsigned int _capacity;
            unsigned int _current;
        
        
    };
        //                  NON MEMBER FUNCTION OVERLOADS
        
        // relational operators
        
        template <class T, class Alloc>
        bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

        template <class T, class Alloc>
        bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

        template <class T, class Alloc>
        bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

        template <class T, class Alloc>
        bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

        template <class T, class Alloc>
        bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

        template <class T, class Alloc>
        bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
        
        // swap
        
        template <class T, class Alloc>
        void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
}
#endif