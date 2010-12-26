#ifndef __SEQUENCE_HPP
#define __SEQUENCE_HPP

#include <boost/mpl/vector.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/remove_if.hpp>
#include <boost/mpl/copy_if.hpp>
#include <boost/mpl/contains.hpp>

namespace LEESA {

using boost::mpl::front;
using boost::mpl::pop_front;
using boost::mpl::push_back;
using boost::mpl::empty;
using boost::mpl::size;
using boost::mpl::remove_if;
using boost::mpl::copy_if;
using boost::mpl::contains;

}

#endif // __SEQUENCE_HPP

