/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:12:39 by cassassi          #+#    #+#             */
/*   Updated: 2022/04/28 17:16:14 by cassassi         ###   ########.fr       */
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

        vector(): _alloc(allocator_type()), _arr(NULL), _capacity(0), _current(0) {}
        
        explicit vector(const allocator_type& alloc = allocator_type())
         : _alloc(alloc), _arr(NULL) _capacity(0), _current(0) {}
        
        explicit vector(size_type n, const value_type& val = value_type(),
                        const allocator_type& alloc = allocator_type())
         : _alloc(alloc), _arr(_alloc.allocate(n + 10)), _capacity(n + 10) 
        {
            for (size_type i = 0; i < n; i++)
            {
                _alloc.construct(this->_arr[i], val);
                this->_current++;
            }
        }
                        
        template <class InputIterator>
        vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type());
                 
        vector(const vector&);
        {
            if (&vector != this)
            {
                *this = vector;                    
            }
            return (*this)
        }
        
        // Operator=
        vector& operator=(const vector& x)
        {
            if (this->_current > 0)
            {
                this->clear();
                this->insert(x.begin(), x.end());
                
            }
        }
        
        // Destructors
        ~vector()
        {
            this->clear();
            allocator_type.destroy(this->_arr);
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
            return (this->_current);
        }
        
        // max_size
        size_type max_size() const
        {
            const size_t diffmax = PTRDIFF_MAX / sizeof(value_type);
            const size_t allocmax = _alloc.max_size();
            return (std::min(diffmax, allocmax));
        }

        // resize
        void resize (size_type n, value_type val = value_type())
        {
            if (n < this->_current)
                
        }
        
        // capacity
        size_type capacity() const { return (this->_capacity);}

        // empty
        bool empty() const
        {
            if (this->_current == 0)
                return (true);
            return (false);
        }

        // reserve
        void reserve (size_type n)
        {
            T* tmp = allocator_type.allocate(n);
            for (unsigned int i = 0; i < this->_capacity; i++) 
            {
                tmp[i] = this->_arr[i];
            }
            this->clear();
            allocator_type.destroy(this->_arr);
            this->_capacity = n;
            this->_arr = tmp;
        }

        //ELEMENT ACCESS
        
        // Operator[]
        reference operator[](size_type index)
        {
            if (index < this->_current && index >= 0)
                return (this->_arr[index]);
            throw std::out_of_range("");
        }
        const_reference operator[](size_type index) const
        {
            if (index < this->_current && index >= 0)
                return (this->_arr[index]);
            throw std::out_of_range("");
        }
        
        // At
        reference at(size_type n) { return (this->_arr[n]); }
        const_reference at(size_type n) const { return (this->_arr[n]); }
        
        // Front
        reference front() {return (this->_arr[0]);}
        const_reference front() const {return (this->_arr[0]);}

        // Back
        reference back() {return (this->_arr[this->_current - 1]);}
        const_reference back() const {return (this->_arr[this->_current - 1]);}
        
    //MODIFIERS
        
        // assign
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last);
        void assign (size_type n, const value_type& val)
        {
            this->clear();
            _alloc.destroy(this->_arr);
            this->_arr = _alloc.allocate(n + 10);
            this->_capacity = n + 10;
            for (size_type i = 0; i < n; i++)
            {
                arr[i] = val;
                this->_current++;
            }
        }
        
        // push_back
        void push_back (const value_type& val) 
        {
            if (this->_current == this->_capacity)
                this->reserve(this->capacity + 10);
            this->_arr[this->_current] = val;
            this->_current++;
        }
        
        // pop_back
        void pop_back() 
        { 
            if (this->_current > 0)
                this->_current--; 
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
        void clear() { allocator_type.deallocate(this->_arr, this->_capacity);}
        
    //ALLOCATOR
        
        // get_allocaor
        allocator_type get_allocator() const { return (this->_alloc);}

        private :

            allocator_type  _alloc;
            T*              _arr;
            size_type       _capacity;
            size_type       _current;
        
        
    };
        //                  NON MEMBER FUNCTION OVERLOADS
        
        // relational operators
        
        template <class T, class Alloc>
        bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
        {
            if (lhs.capacity() != rhs.capacity() || lhs.size() != rhs.size())
                return (false);
            for (size_type i = 0; i < lhs.size(); i++)
            {
                if (lhs[i] != rhs[i])
                    return (false);
            }
            return (true);
        }

        template <class T, class Alloc>
        bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
        {
            if (lhs.capacity() != rhs.capacity() || lhs.size() != rhs.size())
                return (true);
            for (size_type i = 0; i < lhs.size(); i++)
            {
                if (lhs[i] != rhs[i])
                    return (true);
            }
            return (false);
        }

        template <class T, class Alloc>
        bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
        {
            if (lhs.capacity() < rhs.capacity() || lhs.size() < rhs.size())
                return (true);
            for (size_type i = 0; i < lhs.size(); i++)
            {
                if (lhs[i] < rhs[i])
                    return (true);
            }
            return (false);
        }
        
        template <class T, class Alloc>
        bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)        
        {
            if (lhs.capacity() > rhs.capacity() || lhs.size() > rhs.size())
                return (true);
            for (size_type i = 0; i < lhs.size(); i++)
            {
                if (lhs[i] > rhs[i])
                    return (true);
            }
            return (false);
        }
        template <class T, class Alloc>
        bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

        template <class T, class Alloc>
        bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
        
        // swap
        
        template <class T, class Alloc>
        void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
}
#endif