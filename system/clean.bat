@echo off
RD /Q /S build
DEL /F /Q /S "..\bin\*"
DEL /F /Q /S "..\doc\*.tmp"
DEL /F /Q /S "..\doc\chm\*"
DEL /F /Q /S "..\doc\html\*"
DEL /F /Q /S "..\lib\shared\*"
DEL /F /Q /S "..\lib\static\*"
@echo on