    //iterator_trait
#ifndef ITERATORS_TRAITS
#define ITERATORS_TRAITS

namespace ft
{
    class random_access_iterator_tag
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
            // typedef std::input_iterator_tag iterator_category;
            // typedef std::output_iterator_tag iterator_category;
            // typedef std::forward_iterator_tag iterator_category;
            // typedef std::bidirectional_iterator_tag iterator_category;
            typedef ft::random_access_iterator_tag iterator_category;
    };


}
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
        typename ft::iterator_traits<InputIterator>::difference_type 
        distance (InputIterator first, InputIterator last)
        {
            return (last - first);
        }

//Iterator generator

    // //back_inserter
    //     template <class Container>
    //     back_insert_iterator<Container> back_inserter (Container& x);
    
    // //front_inserter
    //     template <class Container>
    //     front_insert_iterator<Container> front_inserter (Container& x);

    // //inserter
    //     template <class Container, class Iterator>
    //     insert_iterator<Container> inserter (Container& x, Iterator it);
    #endif