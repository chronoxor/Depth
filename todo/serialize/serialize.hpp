/*==========================================================================*/
#ifndef __SERIALIZE_HPP__
#define __SERIALIZE_HPP__
/*==========================================================================*/
#if defined(_MSC_VER)
  #pragma warning(disable:4668)           // Disable warning: 'symbol' is not defined as a preprocessor macro, replacing with '0' for 'directives'.
  #pragma warning(disable:4820)           // Disable warning: 'bytes' bytes padding added after construct 'member_name'.
  #pragma warning(disable:4996)           // Disable warning: 'function': was declared deprecated.
#endif
#include <stdio.h>
#include <cstring>
#include <cwchar>

#ifdef WINCE
extern "C" int DeleteFileW(const wchar_t* lpFileName);
#endif
/*==========================================================================*/
void* openf(bool read)
{
  return fopen("test.out", read ? "r" : "w");
}
/*--------------------------------------------------------------------------*/
bool closef(void* file)
{
  return (fclose((FILE*)file) == 0);
}
/*--------------------------------------------------------------------------*/
bool readf(void* file, void* buffer, size_t count)
{
  return (fread(buffer, 1, count, (FILE*)file) == count);
}
/*--------------------------------------------------------------------------*/
bool writef(void* file, const void* buffer, size_t count)
{
  return (fwrite(buffer, 1, count, (FILE*)file) == count);
}
/*==========================================================================*/
#include <Depth/include/algorithms/string/buffer/AStrLen.hpp>
#include <Depth/include/algorithms/string/buffer/AStrNCmp.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
/*==========================================================================*/
using namespace NDepth;
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*==========================================================================*/
class LoadArchive
{
  //! Type for the MConceptBool constraint checking.
  typedef LoadArchive TIArchiveCheckType;

  // Check LoadArchive class constraint to be a serialization archive.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIArchive, TIArchiveCheckType);

public:
  const static Tbool isLoading = true;
  const static Tbool isSaving  = false;

  Tbool open()
  { CALL
    m_pFile = openf(true);
    return (m_pFile != NULL);
  }
  Tbool close()
  { CALL
    return closef(m_pFile);
  }

  Tbool begin(Tuint& a_Version, Tcstr a_TypeName = NULL, ...)
  { CALL
    if (a_TypeName != NULL)
    {
      Tchar type_name[256];
      CHECK(read((Tbuffer)type_name, sizeof(Tchar) * (NAlgorithms::NString::NBuffer::strLen(a_TypeName) + 1)));
      if (NAlgorithms::NString::NBuffer::strNCmp(a_TypeName, type_name, (NAlgorithms::NString::NBuffer::strLen(a_TypeName) + 1) != 0))
        return false;
    }
    CHECK(read((Tbuffer)&a_Version, sizeof(Tuint)));
    return true;
  }

  Tbool body()
  { CALL
    Tchar body;
    CHECK(read((Tbuffer)&body, sizeof(Tchar)));
    return (body == STR('<'));
  }
  Tbool end()
  { CALL
    Tchar body;
    CHECK(read((Tbuffer)&body, sizeof(Tchar)));
    return (body == STR('>'));
  }

  template <class T>
  Tbool doPointer(T*& a_PointerValue, Tcstr a_PointerName = NULL, ...)
  { CALL
    a_PointerValue = newex T;
    return doValue(*a_PointerValue, a_PointerName);
  }

  template <class T>
  Tbool doProperty(T& a_PropertyValue, Tcstr a_PropertyName = NULL, ...)
  { CALL
    return doValue(a_PropertyValue, a_PropertyName);
  }

  template <class T>
  Tbool doValue(T& a_Value, Tcstr a_ValueName = NULL, ...)
  { CALL
    if (a_ValueName != NULL)
    {
      Tchar value_name[256];
      CHECK(read((Tbuffer)value_name, sizeof(Tchar) * (NAlgorithms::NString::NBuffer::strLen(a_ValueName) + 1)));
      if (NAlgorithms::NString::NBuffer::strNCmp(a_ValueName, value_name, (NAlgorithms::NString::NBuffer::strLen(a_ValueName) + 1)) != 0)
        return false;
    }
    return NSerialization::serialize(*this, a_Value);
  }

  template <class T>
  Tbool doValue(T* a_pValue, Tuint a_Count, Tcstr a_ValueName = NULL, ...)
  { CALL
    if (a_ValueName != NULL)
    {
      Tchar value_name[256];
      CHECK(read((Tbuffer)value_name, sizeof(Tchar) * (NAlgorithms::NString::NBuffer::strLen(a_ValueName) + 1)));
      if (NAlgorithms::NString::NBuffer::strNCmp(a_ValueName, value_name, (NAlgorithms::NString::NBuffer::strLen(a_ValueName) + 1)) != 0)
        return false;
    }
    for (Tuint i = 0; i < a_Count; ++i)
      if (!NSerialization::serialize(*this, a_pValue[i]))
        return false;
    return true;
  }

  template <class T>
  Tbool serialize(T& a_Instance)
  { CALL
    return NSerialization::serialize(*this, a_Instance);
  }

  Tbool read(Tbuffer buffer, size_t size)
  { CALL
    return readf(m_pFile, buffer, size);
  }

private:
  void* m_pFile;
};
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, Tschar*& a_pValue)
{ CALL
  Tuint n = 0;
  if (!a_rArchive.read((Tbuffer)(&n), sizeof(Tuint)))
    return false;
  a_pValue = new Tschar[n];
  return a_rArchive.read((Tbuffer)a_pValue, sizeof(Tschar) * n);
}
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, Twchar*& a_pValue)
{ CALL
  Tuint n = 0;
  if (!a_rArchive.read((Tbuffer)(&n), sizeof(Tuint)))
    return false;
  a_pValue = new Twchar[n];
  return a_rArchive.read((Tbuffer)a_pValue, sizeof(Twchar) * n);
}
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, Tschar& a_Value)
{ CALL
  return a_rArchive.read((Tbuffer)(&a_Value), sizeof(Tschar));
}
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, Twchar& a_Value)
{ CALL
  return a_rArchive.read((Tbuffer)(&a_Value), sizeof(Twchar));
}
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, Tbool& a_Value)
{ CALL
  return a_rArchive.read((Tbuffer)(&a_Value), sizeof(Tbool));
}
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, Tsint08& a_Value)
{ CALL
  return a_rArchive.read((Tbuffer)(&a_Value), sizeof(Tsint08));
}
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, Tsint16& a_Value)
{ CALL
  return a_rArchive.read((Tbuffer)(&a_Value), sizeof(Tsint16));
}
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, Tsint32& a_Value)
{ CALL
  return a_rArchive.read((Tbuffer)(&a_Value), sizeof(Tsint32));
}
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, Tsint64& a_Value)
{ CALL
  return a_rArchive.read((Tbuffer)(&a_Value), sizeof(Tsint64));
}
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, Tuint08& a_Value)
{ CALL
  return a_rArchive.read((Tbuffer)(&a_Value), sizeof(Tuint08));
}
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, Tuint16& a_Value)
{ CALL
  return a_rArchive.read((Tbuffer)(&a_Value), sizeof(Tuint16));
}
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, Tuint32& a_Value)
{ CALL
  return a_rArchive.read((Tbuffer)(&a_Value), sizeof(Tuint32));
}
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, Tuint64& a_Value)
{ CALL
  return a_rArchive.read((Tbuffer)(&a_Value), sizeof(Tuint64));
}
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, Tfloat& a_Value)
{ CALL
  return a_rArchive.read((Tbuffer)(&a_Value), sizeof(Tfloat));
}
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, Tdouble& a_Value)
{ CALL
  return a_rArchive.read((Tbuffer)(&a_Value), sizeof(Tdouble));
}
/*==========================================================================*/
class SaveArchive
{
  //! Type for the MConceptBool constraint checking.
  typedef SaveArchive TIArchiveCheckType;

  // Check SaveArchive class constraint to be a serialization archive.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIArchive, TIArchiveCheckType);

public:
  const static Tbool isLoading = false;
  const static Tbool isSaving  = true;

 ~SaveArchive()
  { CALL
#ifdef WINCE
    DeleteFileW(L"test.out");
#else
    remove("test.out");
#endif
  }

  Tbool open()
  { CALL
    m_pFile = openf(false);
    return (m_pFile != NULL);
  }
  Tbool close()
  { CALL
    return closef(m_pFile);
  }

  Tbool begin(const Tuint a_Version, Tcstr a_TypeName = NULL, ...)
  { CALL
    if (a_TypeName != NULL)
    {
      CHECK(write((Tbuffer)a_TypeName, sizeof(Tchar) * (NAlgorithms::NString::NBuffer::strLen(a_TypeName) + 1)));
    }
    CHECK(write((Tbuffer)&a_Version, sizeof(Tuint)));
    return true;
  }

  Tbool body()
  { CALL
    CHECK(write((Tbuffer)STR("<"), sizeof(Tchar)));
    return true;
  }
  Tbool end()
  { CALL
    CHECK(write((Tbuffer)STR(">"), sizeof(Tchar)));
    return true;
  }

  template <class T>
  Tbool doPointer(const T* a_PointerValue, Tcstr a_PointerName = NULL, ...)
  { CALL
    return doValue(*a_PointerValue, a_PointerName);
  }

  template <class T>
  Tbool doProperty(const T& a_PropertyValue, Tcstr a_PropertyName = NULL, ...)
  { CALL
    return doValue(a_PropertyValue, a_PropertyName);
  }

  template <class T>
  Tbool doValue(const T& a_Value, Tcstr a_ValueName = NULL, ...)
  { CALL
    if (a_ValueName != NULL)
    {
      CHECK(write((Tbuffer)a_ValueName, sizeof(Tchar) * (NAlgorithms::NString::NBuffer::strLen(a_ValueName) + 1)));
    }
    return NSerialization::serialize(*this, const_cast<T&>(a_Value));
  }

  template <class T>
  Tbool doValue(const T* a_pValue, Tuint a_Count, Tcstr a_ValueName = NULL, ...)
  { CALL
    if (a_ValueName != NULL)
    {
      CHECK(write((Tbuffer)a_ValueName, sizeof(Tchar) * (NAlgorithms::NString::NBuffer::strLen(a_ValueName) + 1)));
    }
    for (Tuint i = 0; i < a_Count; ++i)
      if (!NSerialization::serialize(*this, const_cast<T&>(a_pValue[i])))
        return false;
    return true;
  }

  template <class T>
  Tbool serialize(const T& a_Instance)
  { CALL
    return NSerialization::serialize(*this, const_cast<T&>(a_Instance));
  }

  Tbool write(Tcbuffer buffer, size_t size)
  { CALL
    return writef(m_pFile, buffer, size);
  }

private:
  void* m_pFile;
};
/*--------------------------------------------------------------------------*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const Tschar* a_Value)
{ CALL
  Tuint n = NAlgorithms::NString::NBuffer::strLen(a_Value) + 1;
  if (!a_rArchive.write((Tcbuffer)(&n), sizeof(Tuint)))
    return false;
  return a_rArchive.write((Tcbuffer)a_Value, sizeof(Tschar) * n);
}
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, Tschar* a_Value)
{ CALL
  Tuint n = NAlgorithms::NString::NBuffer::strLen(a_Value) + 1;
  if (!a_rArchive.write((Tcbuffer)(&n), sizeof(Tuint)))
    return false;
  return a_rArchive.write((Tcbuffer)a_Value, sizeof(Tschar) * n);
}
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const Twchar* a_Value)
{ CALL
  Tuint n = NAlgorithms::NString::NBuffer::strLen(a_Value) + 1;
  if (!a_rArchive.write((Tcbuffer)(&n), sizeof(Tuint)))
    return false;
  return a_rArchive.write((Tcbuffer)a_Value, sizeof(Twchar) * n);
}
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, Twchar* a_Value)
{ CALL
  Tuint n = NAlgorithms::NString::NBuffer::strLen(a_Value) + 1;
  if (!a_rArchive.write((Tcbuffer)(&n), sizeof(Tuint)))
    return false;
  return a_rArchive.write((Tcbuffer)a_Value, sizeof(Twchar) * n);
}
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const Tschar& a_Value)
{ CALL
  return a_rArchive.write((Tcbuffer)(&a_Value), sizeof(Tschar));
}
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const Twchar& a_Value)
{ CALL
  return a_rArchive.write((Tcbuffer)(&a_Value), sizeof(Twchar));
}
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const Tbool& a_Value)
{ CALL
  return a_rArchive.write((Tcbuffer)(&a_Value), sizeof(Tbool));
}
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const Tsint08& a_Value)
{ CALL
  return a_rArchive.write((Tcbuffer)(&a_Value), sizeof(Tsint08));
}
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const Tsint16& a_Value)
{ CALL
  return a_rArchive.write((Tcbuffer)(&a_Value), sizeof(Tsint16));
}
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const Tsint32& a_Value)
{ CALL
  return a_rArchive.write((Tcbuffer)(&a_Value), sizeof(Tsint32));
}
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const Tsint64& a_Value)
{ CALL
  return a_rArchive.write((Tcbuffer)(&a_Value), sizeof(Tsint64));
}
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const Tuint08& a_Value)
{ CALL
  return a_rArchive.write((Tcbuffer)(&a_Value), sizeof(Tuint08));
}
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const Tuint16& a_Value)
{ CALL
  return a_rArchive.write((Tcbuffer)(&a_Value), sizeof(Tuint16));
}
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const Tuint32& a_Value)
{ CALL
  return a_rArchive.write((Tcbuffer)(&a_Value), sizeof(Tuint32));
}
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const Tuint64& a_Value)
{ CALL
  return a_rArchive.write((Tcbuffer)(&a_Value), sizeof(Tuint64));
}
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const Tfloat& a_Value)
{ CALL
  return a_rArchive.write((Tcbuffer)(&a_Value), sizeof(Tfloat));
}
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const Tdouble& a_Value)
{ CALL
  return a_rArchive.write((Tcbuffer)(&a_Value), sizeof(Tdouble));
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
