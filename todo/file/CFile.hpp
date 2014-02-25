/*==========================================================================*/
#ifndef __CFILE_HPP__
#define __CFILE_HPP__
/*==========================================================================*/
#if defined(_MSC_VER)
  #pragma warning(disable:4668)           // Disable warning: 'symbol' is not defined as a preprocessor macro, replacing with '0' for 'directives'.
  #pragma warning(disable:4820)           // Disable warning: 'bytes' bytes padding added after construct 'member_name'.
  #pragma warning(disable:4996)           // Disable warning: 'function': was declared deprecated.
#endif
#include <stdio.h>
#include <cstring>
#include <cwchar>
/*==========================================================================*/
void* openf(const char* filename, bool read)
{
  return fopen(filename, read ? "r" : "w");
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
#include <Depth/include/stream/IReaderWriter.hpp>
/*==========================================================================*/
using namespace NDepth;
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NFiles {
/*==========================================================================*/
class CFile :
  public NStream::IReaderWriter
{
public:
  CFile(const NString::CString& a_crFileName) :
    NStream::IReaderWriter(true)
  { CALL
    m_FileName = a_crFileName;
    m_pHandle = NULL;
  }
 ~CFile()
  { CALL
    // Close opened stream.
    if (isOpened())
      close();
  }

protected:
  virtual Tbool onOpen(const NStream::IStream::EOpenType a_cOpenType)
  { CALL
    m_pHandle = openf((Tcsstr)m_FileName, a_cOpenType == NStream::IStream::e_OPEN_READ);
    return (m_pHandle != NULL);
  }
  virtual Tuint onReadBinary(Tptr a_pBuffer, const Tuint a_cSize)
  { CALL
    return readf(m_pHandle, a_pBuffer, a_cSize);
  }
  virtual Tuint onReadText(Tsstr a_pBuffer, const Tuint a_cSize)
  { CALL
    return readf(m_pHandle, a_pBuffer, a_cSize * sizeof(Tschar));
  }
  virtual Tuint onReadText(Twstr a_pBuffer, const Tuint a_cSize)
  { CALL
    return readf(m_pHandle, a_pBuffer, a_cSize * sizeof(Twchar));
  }
  virtual Tuint onWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize)
  { CALL
    return writef(m_pHandle, a_cpBuffer, a_cSize);
  }
  virtual Tuint onWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize)
  { CALL
    return writef(m_pHandle, a_cpBuffer, a_cSize * sizeof(Tschar));
  }
  virtual Tuint onWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize)
  { CALL
    return writef(m_pHandle, a_cpBuffer, a_cSize * sizeof(Twchar));
  }
  virtual Tbool onFlush()
  {
    return true;
  }
  virtual Tbool onClose()
  {
    return closef(m_pHandle);
  }

private:
  NString::CStringASCII m_FileName;
  void* m_pHandle;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
