# Windows Mobile system name
SET(CMAKE_SYSTEM_NAME WindowsMobile)

# Windows Mobile system version:
#   0x420 - Windows CE 2003
#   0x501 - Windows Mobile 5.0 (default)
IF(NOT DEFINED CMAKE_SYSTEM_VERSION)
  SET(CMAKE_SYSTEM_VERSION 0x501)
ENDIF(NOT DEFINED CMAKE_SYSTEM_VERSION)

# Windows Mobile platform:
#   POCKETPC   - Pocket PC (default)
#   SMARTPHONE - Smartphone
IF(NOT DEFINED CMAKE_MOBILE_PLATFORM)
  SET(CMAKE_MOBILE_PLATFORM POCKETPC)
ENDIF(NOT DEFINED CMAKE_MOBILE_PLATFORM)

# specify the cross compiler
SET(CMAKE_C_COMPILER   cl)
SET(CMAKE_CXX_COMPILER cl)

# search for programs in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
