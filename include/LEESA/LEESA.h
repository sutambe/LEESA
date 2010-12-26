#ifndef __LEESA_H
#define __LEESA_H

#ifndef DOMAIN_NAMESPACE
#error "Please define DOMAIN_NAMESPACE."
#endif // DOMAIN_NAMESPACE

#define MembersOf(A,...) ((A, __VA_ARGS__))
#define DEPTH_FIRST    >>=
#define BREADTH_FIRST  >>
#define PARENT         <<
#define FOLLOWED_BY    ,
#define AND            ,
#define Association(X) &X

// FOLLOWED_BY defined above is used in LEESA.cpp
#include "LEESA/LEESA.cpp"

#endif // __LEESA_H

