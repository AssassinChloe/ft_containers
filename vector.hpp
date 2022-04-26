/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:12:39 by cassassi          #+#    #+#             */
/*   Updated: 2022/04/26 15:28:47 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

# include <memory>

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
        typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
        typedef typename allocator_type::size_type                      size_type;

        //                  PUBLIC MEMBER FUNCTION

    //
        // Constructors

        vector();
        explicit vector(const allocator_type& alloc = allocator_type());
        explicit vector(size_type n, const value_type& val = value_type(),
                        const allocator_type& alloc = allocator_type());
        template <class InputIterator>
        vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type());
        vector(const vector&);
        
        // Destructors
        ~vector();

        // Operator=
        vector& operator=(const vector&);

    //ITERATORS
        
        // begin
        iterator begin();
        const_iterator begin() const;
        
        // end
        iterator end();
        const_iterator end() const;
        
        // rbegin     
        reverse_iterator rbegin(); 
        const_reverse_iterator rbegin() const;
        
        // rend
        reverse_iterator rend(); 
        const_reverse_iterator rend() const; 

    //CAPACITY
        
        // size
        size_type size() const;
        
        // max_size
        size_type max_size() const;

        // resize
        void resize (size_type n, value_type val = value_type());
        
        // capacity
        size_type capacity() const;

        // empty
        bool empty() const;

        // reserve
        void reserve (size_type n);

        //ELEMENT ACCESS
        
        // Operator[]
        reference operator[](size_type);
        const_reference operator[](size_type) const;
        
        // At
        reference at(size_type);
        const_reference at(size_type) const;

        // Front
        reference front();
        const_reference front() const;

        // Back
        reference back();
        const_reference back() const;
        
    //MODIFIERS
        
        // assign
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last);
        void assign (size_type n, const value_type& val);
        
        // push_back
        void push_back (const value_type& val);
        
        // pop_back
        void pop_back();
        
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
        allocator_type get_allocator() const;

        private :
        
        
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