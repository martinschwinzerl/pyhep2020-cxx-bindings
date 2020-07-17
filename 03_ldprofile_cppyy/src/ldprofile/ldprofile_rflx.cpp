// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME srcdIldprofiledIldprofile_rflx
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// The generated code does not explicitly qualifies STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "src/ldprofile/ldprofile.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *ldprofilecLcLTLineDensityProfileBaselEdoublegR_Dictionary();
   static void ldprofilecLcLTLineDensityProfileBaselEdoublegR_TClassManip(TClass*);
   static void delete_ldprofilecLcLTLineDensityProfileBaselEdoublegR(void *p);
   static void deleteArray_ldprofilecLcLTLineDensityProfileBaselEdoublegR(void *p);
   static void destruct_ldprofilecLcLTLineDensityProfileBaselEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ldprofile::TLineDensityProfileBase<double>*)
   {
      ::ldprofile::TLineDensityProfileBase<double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ldprofile::TLineDensityProfileBase<double>));
      static ::ROOT::TGenericClassInfo 
         instance("ldprofile::TLineDensityProfileBase<double>", "ldprofile/base_profile.h", 25,
                  typeid(::ldprofile::TLineDensityProfileBase<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ldprofilecLcLTLineDensityProfileBaselEdoublegR_Dictionary, isa_proxy, 4,
                  sizeof(::ldprofile::TLineDensityProfileBase<double>) );
      instance.SetDelete(&delete_ldprofilecLcLTLineDensityProfileBaselEdoublegR);
      instance.SetDeleteArray(&deleteArray_ldprofilecLcLTLineDensityProfileBaselEdoublegR);
      instance.SetDestructor(&destruct_ldprofilecLcLTLineDensityProfileBaselEdoublegR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ldprofile::TLineDensityProfileBase<double>*)
   {
      return GenerateInitInstanceLocal((::ldprofile::TLineDensityProfileBase<double>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ldprofile::TLineDensityProfileBase<double>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ldprofilecLcLTLineDensityProfileBaselEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ldprofile::TLineDensityProfileBase<double>*)0x0)->GetClass();
      ldprofilecLcLTLineDensityProfileBaselEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void ldprofilecLcLTLineDensityProfileBaselEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ldprofilecLcLTCoastingLDProfilelEdoublegR_Dictionary();
   static void ldprofilecLcLTCoastingLDProfilelEdoublegR_TClassManip(TClass*);
   static void *new_ldprofilecLcLTCoastingLDProfilelEdoublegR(void *p = 0);
   static void *newArray_ldprofilecLcLTCoastingLDProfilelEdoublegR(Long_t size, void *p);
   static void delete_ldprofilecLcLTCoastingLDProfilelEdoublegR(void *p);
   static void deleteArray_ldprofilecLcLTCoastingLDProfilelEdoublegR(void *p);
   static void destruct_ldprofilecLcLTCoastingLDProfilelEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ldprofile::TCoastingLDProfile<double>*)
   {
      ::ldprofile::TCoastingLDProfile<double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ldprofile::TCoastingLDProfile<double>));
      static ::ROOT::TGenericClassInfo 
         instance("ldprofile::TCoastingLDProfile<double>", "ldprofile/ld_coasting.h", 15,
                  typeid(::ldprofile::TCoastingLDProfile<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ldprofilecLcLTCoastingLDProfilelEdoublegR_Dictionary, isa_proxy, 4,
                  sizeof(::ldprofile::TCoastingLDProfile<double>) );
      instance.SetNew(&new_ldprofilecLcLTCoastingLDProfilelEdoublegR);
      instance.SetNewArray(&newArray_ldprofilecLcLTCoastingLDProfilelEdoublegR);
      instance.SetDelete(&delete_ldprofilecLcLTCoastingLDProfilelEdoublegR);
      instance.SetDeleteArray(&deleteArray_ldprofilecLcLTCoastingLDProfilelEdoublegR);
      instance.SetDestructor(&destruct_ldprofilecLcLTCoastingLDProfilelEdoublegR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ldprofile::TCoastingLDProfile<double>*)
   {
      return GenerateInitInstanceLocal((::ldprofile::TCoastingLDProfile<double>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ldprofile::TCoastingLDProfile<double>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ldprofilecLcLTCoastingLDProfilelEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ldprofile::TCoastingLDProfile<double>*)0x0)->GetClass();
      ldprofilecLcLTCoastingLDProfilelEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void ldprofilecLcLTCoastingLDProfilelEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ldprofilecLcLTQGaussianLDProfilelEdoublegR_Dictionary();
   static void ldprofilecLcLTQGaussianLDProfilelEdoublegR_TClassManip(TClass*);
   static void *new_ldprofilecLcLTQGaussianLDProfilelEdoublegR(void *p = 0);
   static void *newArray_ldprofilecLcLTQGaussianLDProfilelEdoublegR(Long_t size, void *p);
   static void delete_ldprofilecLcLTQGaussianLDProfilelEdoublegR(void *p);
   static void deleteArray_ldprofilecLcLTQGaussianLDProfilelEdoublegR(void *p);
   static void destruct_ldprofilecLcLTQGaussianLDProfilelEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ldprofile::TQGaussianLDProfile<double>*)
   {
      ::ldprofile::TQGaussianLDProfile<double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ldprofile::TQGaussianLDProfile<double>));
      static ::ROOT::TGenericClassInfo 
         instance("ldprofile::TQGaussianLDProfile<double>", "ldprofile/ld_qgauss.h", 27,
                  typeid(::ldprofile::TQGaussianLDProfile<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ldprofilecLcLTQGaussianLDProfilelEdoublegR_Dictionary, isa_proxy, 4,
                  sizeof(::ldprofile::TQGaussianLDProfile<double>) );
      instance.SetNew(&new_ldprofilecLcLTQGaussianLDProfilelEdoublegR);
      instance.SetNewArray(&newArray_ldprofilecLcLTQGaussianLDProfilelEdoublegR);
      instance.SetDelete(&delete_ldprofilecLcLTQGaussianLDProfilelEdoublegR);
      instance.SetDeleteArray(&deleteArray_ldprofilecLcLTQGaussianLDProfilelEdoublegR);
      instance.SetDestructor(&destruct_ldprofilecLcLTQGaussianLDProfilelEdoublegR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ldprofile::TQGaussianLDProfile<double>*)
   {
      return GenerateInitInstanceLocal((::ldprofile::TQGaussianLDProfile<double>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ldprofile::TQGaussianLDProfile<double>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ldprofilecLcLTQGaussianLDProfilelEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ldprofile::TQGaussianLDProfile<double>*)0x0)->GetClass();
      ldprofilecLcLTQGaussianLDProfilelEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void ldprofilecLcLTQGaussianLDProfilelEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ldprofilecLcLTLinInterpolLDProfilelEdoublegR_Dictionary();
   static void ldprofilecLcLTLinInterpolLDProfilelEdoublegR_TClassManip(TClass*);
   static void delete_ldprofilecLcLTLinInterpolLDProfilelEdoublegR(void *p);
   static void deleteArray_ldprofilecLcLTLinInterpolLDProfilelEdoublegR(void *p);
   static void destruct_ldprofilecLcLTLinInterpolLDProfilelEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ldprofile::TLinInterpolLDProfile<double>*)
   {
      ::ldprofile::TLinInterpolLDProfile<double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ldprofile::TLinInterpolLDProfile<double>));
      static ::ROOT::TGenericClassInfo 
         instance("ldprofile::TLinInterpolLDProfile<double>", "ldprofile/ld_lin_interpol.h", 22,
                  typeid(::ldprofile::TLinInterpolLDProfile<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ldprofilecLcLTLinInterpolLDProfilelEdoublegR_Dictionary, isa_proxy, 4,
                  sizeof(::ldprofile::TLinInterpolLDProfile<double>) );
      instance.SetDelete(&delete_ldprofilecLcLTLinInterpolLDProfilelEdoublegR);
      instance.SetDeleteArray(&deleteArray_ldprofilecLcLTLinInterpolLDProfilelEdoublegR);
      instance.SetDestructor(&destruct_ldprofilecLcLTLinInterpolLDProfilelEdoublegR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ldprofile::TLinInterpolLDProfile<double>*)
   {
      return GenerateInitInstanceLocal((::ldprofile::TLinInterpolLDProfile<double>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ldprofile::TLinInterpolLDProfile<double>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ldprofilecLcLTLinInterpolLDProfilelEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ldprofile::TLinInterpolLDProfile<double>*)0x0)->GetClass();
      ldprofilecLcLTLinInterpolLDProfilelEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void ldprofilecLcLTLinInterpolLDProfilelEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_ldprofilecLcLTLineDensityProfileBaselEdoublegR(void *p) {
      delete ((::ldprofile::TLineDensityProfileBase<double>*)p);
   }
   static void deleteArray_ldprofilecLcLTLineDensityProfileBaselEdoublegR(void *p) {
      delete [] ((::ldprofile::TLineDensityProfileBase<double>*)p);
   }
   static void destruct_ldprofilecLcLTLineDensityProfileBaselEdoublegR(void *p) {
      typedef ::ldprofile::TLineDensityProfileBase<double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ldprofile::TLineDensityProfileBase<double>

namespace ROOT {
   // Wrappers around operator new
   static void *new_ldprofilecLcLTCoastingLDProfilelEdoublegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::ldprofile::TCoastingLDProfile<double> : new ::ldprofile::TCoastingLDProfile<double>;
   }
   static void *newArray_ldprofilecLcLTCoastingLDProfilelEdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::ldprofile::TCoastingLDProfile<double>[nElements] : new ::ldprofile::TCoastingLDProfile<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ldprofilecLcLTCoastingLDProfilelEdoublegR(void *p) {
      delete ((::ldprofile::TCoastingLDProfile<double>*)p);
   }
   static void deleteArray_ldprofilecLcLTCoastingLDProfilelEdoublegR(void *p) {
      delete [] ((::ldprofile::TCoastingLDProfile<double>*)p);
   }
   static void destruct_ldprofilecLcLTCoastingLDProfilelEdoublegR(void *p) {
      typedef ::ldprofile::TCoastingLDProfile<double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ldprofile::TCoastingLDProfile<double>

namespace ROOT {
   // Wrappers around operator new
   static void *new_ldprofilecLcLTQGaussianLDProfilelEdoublegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::ldprofile::TQGaussianLDProfile<double> : new ::ldprofile::TQGaussianLDProfile<double>;
   }
   static void *newArray_ldprofilecLcLTQGaussianLDProfilelEdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::ldprofile::TQGaussianLDProfile<double>[nElements] : new ::ldprofile::TQGaussianLDProfile<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ldprofilecLcLTQGaussianLDProfilelEdoublegR(void *p) {
      delete ((::ldprofile::TQGaussianLDProfile<double>*)p);
   }
   static void deleteArray_ldprofilecLcLTQGaussianLDProfilelEdoublegR(void *p) {
      delete [] ((::ldprofile::TQGaussianLDProfile<double>*)p);
   }
   static void destruct_ldprofilecLcLTQGaussianLDProfilelEdoublegR(void *p) {
      typedef ::ldprofile::TQGaussianLDProfile<double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ldprofile::TQGaussianLDProfile<double>

namespace ROOT {
   // Wrapper around operator delete
   static void delete_ldprofilecLcLTLinInterpolLDProfilelEdoublegR(void *p) {
      delete ((::ldprofile::TLinInterpolLDProfile<double>*)p);
   }
   static void deleteArray_ldprofilecLcLTLinInterpolLDProfilelEdoublegR(void *p) {
      delete [] ((::ldprofile::TLinInterpolLDProfile<double>*)p);
   }
   static void destruct_ldprofilecLcLTLinInterpolLDProfilelEdoublegR(void *p) {
      typedef ::ldprofile::TLinInterpolLDProfile<double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ldprofile::TLinInterpolLDProfile<double>

namespace {
  void TriggerDictionaryInitialization_ldprofile_rflx_Impl() {
    static const char* headers[] = {
"src/ldprofile/ldprofile.h",
0
    };
    static const char* includePaths[] = {
"/home/martin/.conda/envs/pyhep2020_presentation/include",
"./src",
"/home/martin/.conda/envs/pyhep2020_presentation/lib/python3.8/site-packages/cppyy_backend/include",
"/home/martin/temp/pyhep2020/pyhep2020-cxx-bindings/03_ldprofile_cppyy/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "ldprofile_rflx dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace ldprofile{template <class T> class __attribute__((annotate("$clingAutoload$ldprofile/base_profile.h")))  __attribute__((annotate("$clingAutoload$src/ldprofile/ldprofile.h")))  TLineDensityProfileBase;
}
namespace ldprofile{template <class T> class __attribute__((annotate("$clingAutoload$ldprofile/ld_coasting.h")))  __attribute__((annotate("$clingAutoload$src/ldprofile/ldprofile.h")))  TCoastingLDProfile;
}
namespace ldprofile{template <class T> class __attribute__((annotate("$clingAutoload$ldprofile/ld_qgauss.h")))  __attribute__((annotate("$clingAutoload$src/ldprofile/ldprofile.h")))  TQGaussianLDProfile;
}
namespace ldprofile{template <class T> class __attribute__((annotate("$clingAutoload$ldprofile/ld_lin_interpol.h")))  __attribute__((annotate("$clingAutoload$src/ldprofile/ldprofile.h")))  TLinInterpolLDProfile;
}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "ldprofile_rflx dictionary payload"

#ifndef SYSTEM_TYPE_unix
  #define SYSTEM_TYPE_unix 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "src/ldprofile/ldprofile.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"ldprofile::TCoastingLDProfile<double>", payloadCode, "@",
"ldprofile::TLinInterpolLDProfile<double>", payloadCode, "@",
"ldprofile::TLineDensityProfileBase<double>", payloadCode, "@",
"ldprofile::TQGaussianLDProfile<double>", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("ldprofile_rflx",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_ldprofile_rflx_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_ldprofile_rflx_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_ldprofile_rflx() {
  TriggerDictionaryInitialization_ldprofile_rflx_Impl();
}
