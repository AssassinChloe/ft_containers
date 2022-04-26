template <class Iterator> class iterator_traits;
template <class T> class iterator_traits<T*>;
template <class T> class iterator_traits<const T*>;

typedef typename Iterator::difference_type difference_type;
typedef typename Iterator::value_type value_type;
typedef typename Iterator::reference reference;
typedef typename Iterator::pointer pointer;
typedef std::random_access_iterator_tag iterator_category;
typedef std::output_iterator_tag iterator_category;
typedef std::forward_iterator_tag iterator_category;
typedef std::bidirectional_iterator_tag iterator_category;
typedef std::random_access_iterator_tag iterator_category;
