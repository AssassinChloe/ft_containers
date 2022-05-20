/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:21:47 by cassassi          #+#    #+#             */
/*   Updated: 2022/05/20 15:24:37 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

    //iterator_trait
#ifndef ITERATORS_TRAITS
#define ITERATORS_TRAITS

namespace ft
{
    class random_access_iterator_tag
    {
    };

    class bidirectional_iterator_tag
    {
    };
    
    template <class Iterator>
    class iterator_traits
    {
        public :
            typedef typename Iterator::difference_type difference_type;
            typedef typename Iterator::value_type value_type;
            typedef typename Iterator::reference reference;
            typedef typename Iterator::pointer pointer;
    };

    template <class T>
    class iterator_traits <T *>
    {
	    public:
		    typedef std::ptrdiff_t difference_type;
            typedef T value_type;
            typedef T* pointer;
            typedef T& reference;
            typedef std::random_access_iterator_tag iterator_category;
    };

    template <class T>
    class iterator_traits <const T *>
    {
        public:
            typedef std::ptrdiff_t difference_type;
            typedef T value_type;
            typedef const T* pointer;
            typedef const T& reference;
            typedef std::random_access_iterator_tag iterator_category;
    };

        //                 FUNCTIONS

//Iterator operations

    //advance
        template <class InputIterator, class Distance>
        void advance (InputIterator& it, Distance n)
        {
            return (it + n);
        }

    //distance
        template<class InputIterator>
        typename iterator_traits<InputIterator>::difference_type 
        distance (InputIterator first, InputIterator last)
        {
            return (last - first);
        }
}
#endif