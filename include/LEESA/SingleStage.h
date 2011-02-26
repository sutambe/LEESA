#ifndef __LEESA_SINGLE_STAGE_H_
#define __LEESA_SINGLE_STAGE_H_

#ifndef DOMAIN_NAMESPACE
#error "Please #define DOMAIN_NAMESPACE"
#endif

#include "LEESA/Kind_Traits.h"
#include "LEESA/Concepts.h"

#include <boost/foreach.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits.hpp>

#ifdef OPTIMIZED_CARRIER
#include "LEESA/Carrier_Optimized.h"
#else
#include "LEESA/Carrier_Simple.h"
#endif // OPTIMIZED_CARRIER

namespace LEESA {
namespace SingleStage {

struct OpBase {} ;

template <class Kind>
struct ConstCast : std::unary_function<LEESA::Carrier<Kind>, LEESA::Carrier<Kind> >, OpBase
{
  typedef typename LEESA::Carrier<Kind> result_type;
  typedef typename LEESA::Carrier<Kind> argument_type;

  result_type operator () (argument_type const & arg) const
  {
    argument_type & non_const_arg = const_cast<argument_type &>(arg);
#ifdef LEESA_SUPPORTS_RVALUE_REF
    return std::move(non_const_arg);
#else
    return non_const_arg;
#endif // LEESA_SUPPORTS_RVALUE_REF 
  }
};

template <class Kind>
ConstCast<Kind> RemoveConst(Kind)
{
  return ConstCast<Kind>();
}

template <class T>
struct IsDomainVisitorBaseOf
{
  typedef IsDomainVisitorBaseOf type;
#ifndef LEESA_NO_VISITOR
  enum { value = boost::is_base_of<SchemaVisitor, T>::value };
#else
  enum { value = 0 };
#endif // LEESA_NO_VISITOR
};

template <class ParentKind, class ChildKind>
typename 
  boost::disable_if <IsDomainVisitorBaseOf<ChildKind>,
                     Carrier<ChildKind> >::type
#ifdef LEESA_SUPPORTS_RVALUE_REF
operator >> (Carrier<ParentKind> && cpk, ChildKind const & ck)
#else
operator >> (Carrier<ParentKind> & cpk, ChildKind const & ck)
#endif // LEESA_SUPPORTS_RVALUE_REF
{
  BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept<ParentKind, ChildKind>));
  Carrier<ChildKind> retval;
  BOOST_FOREACH(typename Carrier<ParentKind>::reference parent, cpk)
  {
#ifdef LEESA_FOR_UDM
    retval.push_back(parent.template children_kind<ChildKind>());
#else
    retval.push_back(children_kind(parent, &ck));
#endif // LEESA_FOR_UDM
  }
  return retval;
}

/* 
 * const reference has priority over rvalue-reference when the acutal
 * parameter is a lvalue. So for a non-const query, we've to use rvalue
 * overloaded functions. That means, the query must begin with a
 *
 *   1. temporary or
 *   2. explictely 'moved' object or
 *   3. (non-const) t >> visitor
 *
 *   Such queries remain with rvalue overloaded operators and so 
 *   allow non-const invocations.
 * */
template <class ParentKind, class ChildKind>
typename 
  boost::disable_if <IsDomainVisitorBaseOf<ChildKind>,
                     const Carrier<ChildKind> >::type
operator >> (Carrier<ParentKind> const & cpk, ChildKind const & ck)
{
  BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept<ParentKind, ChildKind>));
  Carrier<ChildKind> retval;
  BOOST_FOREACH(typename Carrier<ParentKind>::reference parent, cpk)
  {
#ifdef LEESA_FOR_UDM
    retval.push_back(parent.template children_kind<ChildKind>());
#else
    retval.push_back(children_kind(parent, &ck));
#endif // LEESA_FOR_UDM
  }
  return retval;
}

template <class Kind>
Carrier<Kind>
operator >> (Carrier<Kind> const & ck, ConstCast<Kind> const & cc)
{
  return cc(ck);
}

template <class Kind>
Carrier<Kind>
#ifdef LEESA_SUPPORTS_RVALUE_REF
operator >> (Carrier<Kind> && ck, SchemaVisitor & v)
#else
operator >> (Carrier<Kind> & ck, SchemaVisitor & v)
#endif // LEESA_SUPPORTS_RVALUE_REF
{
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<Kind>));
  BOOST_FOREACH(typename Carrier<Kind>::reference kind, ck)
  {
#ifdef LEESA_FOR_UDM
    kind.Accept(v);
#else
    kind.accept(v);
#endif // LEESA_FOR_UDM
  }
#ifdef LEESA_SUPPORTS_RVALUE_REF
  return std::move(ck);
#else
  return ck;
#endif // LEESA_SUPPORTS_RVALUE_REF
}

} // namespace SingleStage
} // namespace LEESA



#endif // __LEESA_SINGLE_STAGE_H_

