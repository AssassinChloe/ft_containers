template <class Iterator> class iterator_traits;
template <class T> class iterator_traits<T*>;
template <class T> class iterator_traits<const T*>;



    //iterator_trait

        template <class Iterator>
        class iterator_traits
        {
            typedef typename Iterator::difference_type difference_type;
            typedef typename Iterator::value_type value_type;
            typedef typename Iterator::reference reference;
            typedef typename Iterator::pointer pointer;
            typedef std::random_access_iterator_tag iterator_category;
            typedef std::output_iterator_tag iterator_category;
            typedef std::forward_iterator_tag iterator_category;
            typedef std::bidirectional_iterator_tag iterator_category;
            typedef std::random_access_iterator_tag iterator_category;
        };

        template <class T> class iterator_traits<T*>;
        template <class T> class iterator_traits<const T*>;

    //reverse iterator

    template <class Iterator>
    class reverse_iterator
    {

    }

        //                 FUNCTIONS


//Iterator operations

    //advance
        template <class InputIterator, class Distance>
        void advance (InputIterator& it, Distance n);

    //distance
        template<class InputIterator>
        typename iterator_traits<InputIterator>::difference_type 
        distance (InputIterator first, InputIterator last);

//Iterator generator

    //back_inserter
        template <class Container> class back_insert_iterator;
    
    //front_inserter
        template <class Container>
        front_insert_iterator<Container> front_inserter (Container& x);

    //inserter
        template <class Container, class Iterator>
        insert_iterator<Container> inserter (Container& x, Iterator it);