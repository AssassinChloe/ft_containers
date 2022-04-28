/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:12:42 by cassassi          #+#    #+#             */
/*   Updated: 2022/04/28 12:18:35 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

# include <iostream>
# include <functional>
# include <memory>

namespace ft
{
    template < class Key,                                 
           class T,                                       
           class Compare = std::less<Key>,            
           class Alloc = std::allocator<std::pair<const Key,T> >
           >
    class map
    {
        typedef Key                                                     key_type;
        typedef T                                                       mapped_type;
        typedef ft::pair<const key_type, mapped_type>                   value_type;
        typedef Compare                                                 key_compare;
        typedef Alloc                                                   allocator_type;
        class map::value_compare : binary_function<value_type,value_type,bool>
        {
            friend map<key_type, mapped_type, key_compare, allocator_type>
            
            protected:
                Compare comp;
                value_compare (Compare c) : comp(c) {}
            public:
            // typedef bool result_type;
            // typedef value_type first_argument_type;
            // typedef value_type second_argument_type;
                bool operator()(const value_type& x, const value_type& y) const
                {
                    return comp(x.first, y.first);
                }
        };        
        typedef typename allocator_type::reference                      reference;
        typedef typename allocator_type::const_reference                const_reference;
        typedef typename allocator_type::pointer                        pointer;
        typedef typename allocator_type::const_pointer                  const_pointer;
        typedef typename ft::bidirectional_iterator<value_type>         iterator;
        typedef typename ft::bidirectional_iterator<const value_type>   const_iterator;
        typedef typename ft::reverse_iterator<iterator>                 reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator>           const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
        typedef typename allocator_type::size_type                      size_type;
        
        //                  PUBLIC MEMBER FUNCTION

    //
        // Constructors
        explicit map (const key_compare& comp = key_compare(),
                     const allocator_type& alloc = allocator_type());
        template <class InputIterator>
        map (InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type());
        map (const map& x);
        
        // destructor
        ~map();

        // operator=
        map& operator= (const map& x);

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
        
        // empty
        bool empty() const;
        
        // size
        size_type size() const;
        
        // max_size
        size_type max_size() const;

    //ELEMENT ACCESS
    
        //operator[]
        mapped_type& operator[] (const key_type& k);
    
    //MODIFIERS
    
        // insert
        pair<iterator,bool> insert (const value_type& val);
        iterator insert (iterator position, const value_type& val);
        template <class InputIterator>
        void insert (InputIterator first, InputIterator last);

        // erase
        void erase (iterator position);
        size_type erase (const key_type& k);
        void erase (iterator first, iterator last);
        
        // swap
        void swap (map& x);
        
        // clear
        void clear();
        
    //OBSERVERS
    
        // key_comp
        key_compare key_comp() const;
        
        // value_comp
        value_compare value_comp() const;
        
    //OPERATION
    
        // find
        iterator find (const key_type& k);
        const_iterator find (const key_type& k) const;
        
        // count
        size_type count (const key_type& k) const;
        
        // lower_bound
        iterator lower_bound (const key_type& k);
        const_iterator lower_bound (const key_type& k) const;
        
        // upper_bond
        iterator upper_bound (const key_type& k);
        const_iterator upper_bound (const key_type& k) const;
        
        // equal_range
        pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
        pair<iterator,iterator> equal_range (const key_type& k);
        
    //ALLOCATOR
    
        // get_allocator
        allocator_type get_allocator() const;
        
    };
}

#endif