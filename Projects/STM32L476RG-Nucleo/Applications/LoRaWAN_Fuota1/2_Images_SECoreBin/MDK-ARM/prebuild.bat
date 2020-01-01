@echo off
echo prebuild.bat : started > %1\\output.txt
set "ecckey=%1\\..\\Binary\\ECCKEY.txt"
set "asmfile=%1\\se_key.s"
::comment this line to force python
::python is used if windows executeable not found
pushd %1\..\..\..\..\..\..\Middlewares\ST\STM32_Secure_Engine\Utilities\KeysAndImages
set basedir=%cd%
popd
goto exe:
goto py:
:exe
::line for window executeable
echo Prebuild with windows executable
set "prepareimage=%basedir%\\win\\prepareimage\\prepareimage.exe"
set "python="
if exist %prepareimage% (
goto prebuild
)
:py
::line for python
echo Prebuild with python script
set "prepareimage=%basedir%\\prepareimage.py"
set "python=python "
echo "python: %prepareimage%" >> %1\\output.txt 2>>&1
:prebuild
set "crypto_h=%1\\..\\Inc\\se_crypto_config.h"

::clean
if exist %1\\crypto.txt (
  del %1\\crypto.txt
)
if exist %asmfile% (
  del %asmfile%
)
if exist %1\\postbuild.bat (
  del %1\\postbuild.bat
)

::get crypto name
set "command=%python%%prepareimage% conf %crypto_h% > %1\\crypto.txt"
%command%
IF %ERRORLEVEL% NEQ 0 goto :error
set /P crypto=<%1\\crypto.txt >> %1\\output.txt 2>>&1
echo crypto %crypto% selected >> %1\\output.txt 2>>&1

if "%crypto%"=="SECBOOT_AES128_GCM_AES128_GCM_AES128_GCM" goto AES128_GCM_AES128_GCM_AES128_GCM
if "%crypto%"=="SECBOOT_ECCDSA_WITH_AES128_CBC_SHA256" goto ECCDSA_WITH_AES128_CBC_SHA256
if "%crypto%"=="SECBOOT_ECCDSA_WITHOUT_ENCRYPT_SHA256" goto ECCDSA_WITHOUT_ENCRYPT_SHA256
goto end

:AES128_GCM_AES128_GCM_AES128_GCM
set "oemkey=%1\\..\\Binary\\OEM_KEY_COMPANY1_key_AES_GCM.bin"
set "command=%python%%prepareimage% trans  -a ARM -k %oemkey% -f SE_ReadKey -s .SE_Key_Data -e 1 -v V7M > %asmfile%"
%command%
IF %ERRORLEVEL% NEQ 0 goto :error
:: The ECC keys are not needed so the SE_ReadKey_Pub is not generated
goto end

:ECCDSA_WITH_AES128_CBC_SHA256
set "oemkey=%1\\..\\Binary\\OEM_KEY_COMPANY1_key_AES_CBC.bin"
set "command=%python%%prepareimage% trans  -a ARM -k %oemkey% -f SE_ReadKey -s .SE_Key_Data -v V7M > %asmfile%"
%command%
IF %ERRORLEVEL% NEQ 0 goto :error
set "command=%python%%prepareimage% trans  -a ARM -k %ecckey% -f SE_ReadKey_Pub -e 1 -v V7M >> %asmfile%"
%command%
IF %ERRORLEVEL% NEQ 0 goto :error
goto end

:ECCDSA_WITHOUT_ENCRYPT_SHA256
set "oemkey="
:: The OEM key is not needed as the Firmware is not encrypted so the SE_ReadKey is not generated
set "command=%python%%prepareimage% trans  -a ARM -k %ecckey% -f SE_ReadKey_Pub  -s .SE_Key_Data -e 1 -v V7M >> %asmfile%"
%command%
IF %ERRORLEVEL% NEQ 0 goto :error
goto end

:end
set "command=copy %1\\%crypto%.bat %1\\postbuild.bat"
%command%
IF %ERRORLEVEL% NEQ 0 goto :error
exit 0
:error
echo %command% : failed >> %1\\output.txt 2>&1
echo %command% : failed
pause
exit 1