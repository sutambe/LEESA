#include <set>
#include <vector>

#define EXPRESSION_TRAITS_1PARA(OP)            \
template <class T>                             \
struct ET <OP<T> >                             \
  : public ETBase <OP<T> > {}; 

#define EXPRESSION_TRAITS_2PARA(OP)            \
template <class T, class U>                    \
struct ET <OP<T, U> >                          \
  : public ETBase <OP<T, U> > {};

#define EXPRESSION_TRAITS_3PARA(OP)            \
template <class X, class Y, class Z>           \
struct ET <OP<X, Y, Z> >                       \
  : public ETBase <OP<X, Y, Z> > {};

#define EXPRESSION_TRAITS_4PARA(OP)            \
template <class W, class X, class Y, class Z>  \
struct ET <OP<W, X, Y, Z> >                    \
  : public ETBase <OP<W, X, Y, Z> > {};


namespace LEESA {

template <class T>
struct ET
{
  /* BOOST_CLASS_REQUIRE(T, LEESA, DomainKindConcept);
     DomainKindConcept check is disabled because user-defined
     visitor types are possible parameters of this trait class.
     In such a case, the following associated types do not make
     sense. However, they are never instantiated and hence we are ok. */
  typedef Carrier<T> expression_type;
  typedef Carrier<T> result_type;
  typedef Carrier<T> argument_type;
  typedef T result_kind;
  typedef T argument_kind;
};

template <class T, class U>
struct ET <T (*) (U)>
{
  typedef Carrier<U> expression_type;
  typedef Carrier<T> result_type;
  typedef Carrier<U> argument_type;
  typedef T result_kind;
  typedef U argument_kind;
};

template <class Kind>
struct ET <std::set<Kind> >
{
  BOOST_CLASS_REQUIRE(Kind, LEESA, DomainKindConcept);
  typedef Carrier<Kind> expression_type;
  typedef Carrier<Kind> result_type;
  typedef Carrier<Kind> argument_type;
  typedef Kind result_kind;
  typedef Kind argument_kind;
};

template <class Kind>
struct ET <std::vector<Kind> >
{
  BOOST_CLASS_REQUIRE(Kind, LEESA, DomainKindConcept);
  typedef Carrier<Kind> expression_type;
  typedef Carrier<Kind> result_type;
  typedef Carrier<Kind> argument_type;
  typedef Kind result_kind;
  typedef Kind argument_kind;
};

template <class T>
struct ETBase
{
  typedef typename T::expression_type expression_type;
  typedef typename T::result_type result_type;
  typedef typename T::argument_type argument_type;
  typedef typename T::result_kind result_kind;
  typedef typename T::argument_kind argument_kind;
};

EXPRESSION_TRAITS_1PARA(Carrier);
EXPRESSION_TRAITS_1PARA(SelectorOp);
EXPRESSION_TRAITS_1PARA(RegexOp);
EXPRESSION_TRAITS_1PARA(StoreAtOp);
#ifndef LEESA_NO_VISITOR
EXPRESSION_TRAITS_1PARA(VisitorOp);
EXPRESSION_TRAITS_1PARA(LeaveCallerOp);
EXPRESSION_TRAITS_2PARA(PairCallerOp);
#endif // LEESA_NO_VISITOR

EXPRESSION_TRAITS_2PARA(ChainExpr);
EXPRESSION_TRAITS_2PARA(SequenceExpr);
EXPRESSION_TRAITS_2PARA(GetChildrenOp);
EXPRESSION_TRAITS_2PARA(DFSOp);
EXPRESSION_TRAITS_2PARA(FilterOp);
EXPRESSION_TRAITS_2PARA(ForEachOp);
EXPRESSION_TRAITS_2PARA(SortOp);
EXPRESSION_TRAITS_2PARA(UniqueOp);
EXPRESSION_TRAITS_2PARA(CastOp);
#ifndef LEESA_FOR_UDM
EXPRESSION_TRAITS_2PARA(MembersAsTupleOp);
#endif 

#ifdef LEESA_FOR_UDM

EXPRESSION_TRAITS_1PARA(NonNullOp);
EXPRESSION_TRAITS_2PARA(GetParentOp);
EXPRESSION_TRAITS_2PARA(AssociationOp);
EXPRESSION_TRAITS_2PARA(AssociationEndOp);
EXPRESSION_TRAITS_3PARA(AssociationManyOp);

template <class RESULT, class TARGETCLASS>
struct ET <Udm::AClassPointerAttr<RESULT, TARGETCLASS> (TARGETCLASS::*)() const>
  : public ETBase <AssociationOp<RESULT, TARGETCLASS> > {};

template <class ASSOC, class SOURCECLASS, class TARGETCLASS>
struct ET <Udm::AClassAssocAttr<ASSOC, TARGETCLASS> (SOURCECLASS::*)() const>
  : public ETBase <AssociationManyOp<ASSOC, SOURCECLASS, TARGETCLASS> > {};

template <class RESULT, class TARGETCLASS>
struct ET <Udm::AssocEndAttr<RESULT> (TARGETCLASS::*)() const>
  : public ETBase <AssociationEndOp<RESULT, TARGETCLASS> > {};

#endif // LEESA_FOR_UDM


template <class L, class R = L>
struct LEESAUnaryFunction 
  : public std::unary_function <typename ET<L>::argument_type,
                                typename ET<R>::result_type>
{
  typedef typename ET<L>::argument_kind argument_kind;
  typedef typename ET<L>::argument_type argument_type;
  typedef typename ET<R>::result_kind result_kind;
  typedef typename ET<R>::result_type result_type;

  //BOOST_CLASS_REQUIRE(result_kind, LEESA, DomainKindConcept);
  BOOST_CLASS_REQUIRE(argument_kind, LEESA, DomainKindConcept);
};

template <class L>
struct LEESAUnaryFunction <L, void> 
  : public std::unary_function <typename ET<L>::argument_type,
                                void>
{
  typedef typename ET<L>::argument_kind argument_kind;
  typedef typename ET<L>::argument_type argument_type;
  typedef void result_kind;
  typedef void result_type;

  //BOOST_CLASS_REQUIRE(result_kind, LEESA, DomainKindConcept);
  BOOST_CLASS_REQUIRE(argument_kind, LEESA, DomainKindConcept);
};


#ifdef LEESA_SUPPORTS_DECLTYPE

template <typename T> 
struct function_traits : function_traits<decltype(&T::operator())>
{};

#else // LEESA_SUPPORTS_DECLTYPE

template <typename T>
struct function_traits 
{ 
  typedef typename T::result_type result_type;
  typedef typename T::argument_type argument_type;
};

#endif // LEESA_SUPPORTS_DECLTYPE

template <typename R, typename C>
struct function_traits<R (C::*)()> 
{
  typedef R result_type;
};

template <typename R, typename C, typename Arg>
struct function_traits<R (C::*)(Arg)> 
{
  typedef R result_type;
  typedef Arg argument_type;
};

template <typename R, typename C, typename Arg1, typename Arg2>
struct function_traits<R (C::*)(Arg1, Arg2)> 
{
  typedef R result_type;
  typedef Arg1 first_argument_type;
  typedef Arg2 second_argument_type;
};

template <typename R, typename C>
struct function_traits<R (C::*)() const> 
{
  typedef R result_type;
};

template <typename R, typename C, typename Arg>
struct function_traits<R (C::*)(Arg) const> 
{
  typedef R result_type;
  typedef Arg argument_type;
};

template <typename R, typename C, typename Arg1, typename Arg2>
struct function_traits<R (C::*)(Arg1, Arg2) const> 
{
  typedef R result_type;
  typedef Arg1 first_argument_type;
  typedef Arg2 second_argument_type;
};

template <typename R>
struct function_traits<R (*)()> 
{
  typedef R result_type;
};

template <typename R, typename Arg>
struct function_traits<R (*)(Arg)> 
{
  typedef R result_type;
  typedef Arg argument_type;
};

template <typename R, typename Arg1, typename Arg2>
struct function_traits<R (*)(Arg1, Arg2)> 
{
  typedef R result_type;
  typedef Arg1 first_argument_type;
  typedef Arg2 second_argument_type;
};

template <typename R>
struct function_traits<R ()> 
{
  typedef R result_type;
};

template <typename R, typename Arg>
struct function_traits<R (Arg)> 
{
  typedef R result_type;
  typedef Arg argument_type;
};


} // namespace LEESA

