#include <memory>
#include <iostream>
#include <boost/foreach.hpp>

#include "PICML.hxx"

using std::cerr;
using std::endl;
using std::auto_ptr;

#if (defined WITH_LEESA || defined WITH_LEESA_DESC)

#include "PICML-meta.hxx"
#include "LEESA/LEESA.h"

using namespace LEESA;

#endif 

template <class T>
struct SeqType
{
  typedef ::xsd::cxx::tree::sequence< T > type;
};

/* We don't use BOOST_FOREACH here because it expands into some
 * incomprehensible code that heavily uses type-traits and 
 * meta-programming.
 * */
#define MY_FOREACH(TYPE, VAR, CONTAINER)                             \
for(::SeqType<TYPE>::type::iterator TYPE##_iter(CONTAINER.begin());  \
    TYPE##_iter != CONTAINER.end();                                  \
    ++TYPE##_iter)                                                   \
    {                                                                \
      TYPE & VAR = *TYPE##_iter;

::SeqType<AttributeMemberType>::type
get_member_child_axis(RootFolderType & rf)
{
#ifdef WITH_LEESA
  ::SeqType<AttributeMemberType>::type members =   
    evaluate (rf, RootFolderType() >> InterfaceDefinitionsType()
                                   >> FileType() 
                                   >> PackageType()
                                   >> ComponentType() 
                                   >> AttributeType()
                                   >> AttributeMemberType());
  return members;
#elif WITH_LEESA_DESC
  ::SeqType<AttributeMemberType>::type members =   
    evaluate (rf, RootFolderType() >> DescendantsOf(RootFolderType(), AttributeMemberType()));
  return members;
#else
  ::SeqType<AttributeMemberType>::type members;   
  
  MY_FOREACH(InterfaceDefinitionsType, iface, rf.InterfaceDefinitions())
    MY_FOREACH(FileType, file, iface.File())
      MY_FOREACH(PackageType, package, file.Package())
        MY_FOREACH(ComponentType, component, package.Component())
          MY_FOREACH(AttributeType, attribute, component.Attribute())
            members.push_back(attribute.AttributeMember());
          }
        }
      }
    }
  } 

  return members;
#endif
}



::SeqType<ServiceProviderType>::type
get_service_provider_child_axis(RootFolderType & rf)
{
#ifdef WITH_LEESA
  ::SeqType<ServiceProviderType>::type service_providers =   
    evaluate (rf, RootFolderType() >> ComponentImplementationsType()
                                   >> ComponentImplementationContainerType() 
                                   >> ComponentAssemblyType()
                                   >> RTRequirementsType() 
                                   >> ServiceProviderType());
  return service_providers;
#elif WITH_LEESA_DESC
  ::SeqType<ServiceProviderType>::type service_providers =   
    evaluate (rf, RootFolderType() >> DescendantsOf(RootFolderType(), ServiceProviderType()));
  return service_providers;
#else
  ::SeqType<ServiceProviderType>::type service_providers;   
  MY_FOREACH(ComponentImplementationsType, ci, rf.ComponentImplementations())
    MY_FOREACH(ComponentImplementationContainerType, cic, ci.ComponentImplementationContainer())
      MY_FOREACH(ComponentAssemblyType, ca, cic.ComponentAssembly())
        MY_FOREACH(RTRequirementsType, rtr, ca.RTRequirements())
          if(rtr.ServiceProvider().present())
            service_providers.push_back(rtr.ServiceProvider().get());
        }
      }
    }
  }
  return service_providers;
#endif
}



::SeqType<ImplementationArtifactReferenceType>::type
get_impl_artifact_ref_child_axis(RootFolderType & rf)
{
#ifdef WITH_LEESA
  ::SeqType<ImplementationArtifactReferenceType>::type impl_artifact_refs =   
    evaluate (rf, RootFolderType() >> ComponentBuildType()
                                   >> MPCType() 
                                   >> ProjectType()
                                   >> ServantProjectType() 
                                   >> ImplementationArtifactReferenceType());
  return impl_artifact_refs;
#elif WITH_LEESA_DESC
  ::SeqType<ImplementationArtifactReferenceType>::type impl_artifact_refs =   
    evaluate (rf, RootFolderType() >> DescendantsOf(RootFolderType(), ImplementationArtifactReferenceType()));
  return impl_artifact_refs;
#else
  ::SeqType<ImplementationArtifactReferenceType>::type impl_artifact_refs;   
  MY_FOREACH(ComponentBuildType, cb, rf.ComponentBuild())
    MY_FOREACH(MPCType, mpc, cb.MPC())
      MY_FOREACH(ProjectType, prj, mpc.Project())
        MY_FOREACH(ServantProjectType, sp, prj.ServantProject())
          if (sp.ImplementationArtifactReference().present())
          {
            impl_artifact_refs.push_back(sp.ImplementationArtifactReference().get());
          }
        }
      }
    }
  }
  return impl_artifact_refs;
#endif
}


/*
// DataTypeType is present all over the place.
// It takes quite some time to compile using the descendant axis.
::SeqType<DataTypeType>::type
get_datatype_child_axis(RootFolderType & rf)
{
#ifdef WITH_LEESA
  ::SeqType<DataTypeType>::type datatypes =   
    evaluate (rf, RootFolderType() >> TargetsType()
                                   >> DomainType() 
                                   >> NodeType()
                                   >> ResourceType() 
                                   >> SatisfierPropertyType()
                                   >> DataTypeType());
  return datatypes;
#elif WITH_LEESA_DESC
  ::SeqType<DataTypeType>::type datatypes =   
    evaluate (rf, RootFolderType() >> DescendantsOf(RootFolderType(), DataTypeType()));
  return datatypes;
#else
  ::SeqType<DataTypeType>::type datatypes;   
  MY_FOREACH(TargetsType, tt, rf.Targets())
    MY_FOREACH(DomainType, dt, tt.Domain())
      MY_FOREACH(NodeType, nt, dt.Node())
        MY_FOREACH(ResourceType, rt, nt.Resource())
          MY_FOREACH(SatisfierPropertyType, spt, rt.SatisfierProperty())
              datatypes.push_back(spt.DataType());
          }
        }
      }
    }
  }
  return datatypes;
#endif
}
*/


::SeqType<AttributeType>::type
get_member_descendants(RootFolderType & rf)
{
#ifdef WITH_LEESA_DESC
  ::SeqType<AttributeType>::type attrs =   
    evaluate (rf, RootFolderType() >> DescendantsOf(RootFolderType(), AttributeType()));
  return attrs;
#else
// AtrributeMemberType was found to be a descendant of 19
// elements. Moreover, one pair of elements is known to be recursive.
// We count 6 lines for each element and 10 lines for each member of
// mutually recursive elements. Finally, 1 line for push_back and 
// one line for return. So we get 6*19 + 10*2 + 2 = 136 lines. 
#endif
}



::SeqType<AttributeMemberType>::type
get_member_level_descendants(RootFolderType & rf)
{
#ifdef WITH_LEESA_DESC
  ::SeqType<AttributeMemberType>::type members =   
    evaluate (rf, RootFolderType() 
        >> LevelDescendantsOf(RootFolderType(), _, _, _, _, AttributeMemberType()));
  return members;
#else
// There are 5 wildcards and 7 types in total. But AttributeMembers could be
// inside many types at that level. So we simply take an average of simple
// nested looping based solution and the recursive solution. 
// We get (39+136)/2 = 88 lines. This metric is highly schema-specific.
#endif
}


int main (int argc, char* argv[])
{
  if (argc != 2)
  {
    cerr << "usage: " << argv[0] << " PICML.xml" << endl;
    return 1;
  }

  try
  {
    auto_ptr<RootFolderType> rf_root (RootFolder (argv[1]));
  }
  catch (const xml_schema::exception& e)
  {
    cerr << e << endl;
    return 1;
  }
}


