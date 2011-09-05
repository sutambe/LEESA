#ifndef __SEQUENCE_HPP
#define __SEQUENCE_HPP

#ifdef LEESA_SUPPORTS_VARIADIC_TEMPLATES 

#include <typeinfo>

namespace boost {
namespace mpl {

struct null_type {};

template <typename... Arg>
struct vector {};

template <typename V> struct front;
template <typename V> struct pop_front;

template <typename Head, typename... Tail>
struct front <vector <Head, Tail...> >
{
  typedef Head type;
};

template <>
struct front <vector <> >
{
  typedef null_type type;
};

template <typename Head, typename... Tail>
struct pop_front <vector <Head, Tail...> >
{
  typedef vector<Tail...> type;
};

template <>
struct pop_front <vector <> >
{
  typedef vector<> type;
};

template <typename Vector, typename T> struct push_back;

template <typename T, typename... Args>
struct push_back < vector<Args...>, T>
{
  typedef vector<Args..., T> type;
};

template <typename Vector> struct size;

template <typename... Args>
struct size <vector <Args...> >
{
  typedef size type;
  enum { value = sizeof...(Args) };
};

template <typename Vector> struct empty;

template <typename... Args>
struct empty <vector <Args...> >
{
  typedef empty type;
  enum { value = 0 };
};

template<>
struct empty <vector<> >
{
  typedef empty type;
  enum { value = 1 };
};

template <typename Vector, typename What> struct contains;

template <typename What, typename Head, typename... Tail>
struct contains < vector<Head, Tail...>, What> :
       std::conditional < std::is_same<Head, What>::value,
                          std::true_type,
                          contains < vector<Tail...>, What>
                        >::type
{
  typedef contains type;
};

template <typename What>
struct contains <vector<>, What>
{
  typedef contains type;
  enum { value = 0 };
};

template <class V1, template <typename> class Pred>
struct copy_if
{
  typedef typename front<V1>::type Head;
  typedef typename pop_front<V1>::type Tail;
  typedef typename std::conditional<
                      Pred<Head>::value,
                      typename push_back<typename copy_if<Tail, Pred>::type,
                                         Head
                                        >::type,
                      typename copy_if<Tail, Pred>::type>::type type;
};

template <template <typename> class Pred>
struct copy_if <vector<>, Pred>
{
  typedef vector<> type;
};

template <class V1, template <typename> class Pred>
struct remove_if
{
  typedef typename front<V1>::type Head;
  typedef typename pop_front<V1>::type Tail;
  typedef typename std::conditional<
                      !Pred<Head>::value,
                      typename push_back<typename copy_if<Tail, Pred>::type,
                                         Head
                                        >::type,
                      typename copy_if<Tail, Pred>::type>::type type;
};

template <template <typename> class Pred>
struct remove_if <vector<>, Pred>
{
  typedef vector<> type;
};

template <class V1, template <typename> class Pred>
struct count_if
{
  typedef count_if type;
  typedef typename front<V1>::type Head;
  typedef typename pop_front<V1>::type Tail;
  enum { value = bool(Pred<Head>::value) + count_if<Tail, Pred>::value };
};

template <template <typename> class Pred>
struct count_if <vector<>, Pred>
{
  typedef count_if type;
  enum { value = 0 };
};

} // namespace mpl
} // namespace boost

#define LEESA_MPL_VECTOR_N(N,...) boost::mpl::vector<__VA_ARGS__>

#else // LEESA_SUPPORTS_VARIADIC_TEMPLATES 

#define LEESA_MPL_VECTOR_N(N,...) boost::mpl::vector##N<__VA_ARGS__>

#if (LEESA_MAX_MPL_VECTOR_SIZE < 20)
// That's fine.
#elif (LEESA_MAX_MPL_VECTOR_SIZE < 30) 
  #define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
  #define BOOST_MPL_LIMIT_VECTOR_SIZE 30
#elif (LEESA_MAX_MPL_VECTOR_SIZE < 40) 
  #define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
  #define BOOST_MPL_LIMIT_VECTOR_SIZE 40
#elif (LEESA_MAX_MPL_VECTOR_SIZE < 50) 
  #define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
  #define BOOST_MPL_LIMIT_VECTOR_SIZE 50
#else
  #define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
  #define BOOST_MPL_LIMIT_VECTOR_SIZE 50

  #include <boost/mpl/vector.hpp>
  #include <boost/mpl/aux_/config/ctps.hpp>
  #include <boost/preprocessor/iterate.hpp>

  namespace boost {
    namespace mpl {
        #define BOOST_PP_ITERATION_PARAMS_1 (3,( \
                      BOOST_PP_INC(BOOST_MPL_LIMIT_VECTOR_SIZE), \
                      LEESA_MAX_MPL_VECTOR_SIZE, \
                      "boost/mpl/vector/aux_/numbered.hpp"))
        #include BOOST_PP_ITERATE()
    }
  }

#endif // LEESA_SUPPORTS_VARIADIC_TEMPLATES

#include <boost/mpl/vector.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/remove_if.hpp>
#include <boost/mpl/count_if.hpp>
#include <boost/mpl/copy_if.hpp>
#include <boost/mpl/contains.hpp>

#endif // LEESA_SUPPORTS_VARIADIC_TEMPLATES 

namespace LEESA {

using boost::mpl::front;
using boost::mpl::pop_front;
using boost::mpl::push_back;
using boost::mpl::empty;
using boost::mpl::size;
using boost::mpl::remove_if;
using boost::mpl::count_if;
using boost::mpl::copy_if;
using boost::mpl::contains;

}

#endif // __SEQUENCE_HPP

