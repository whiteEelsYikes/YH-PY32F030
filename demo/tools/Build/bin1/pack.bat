@echo off
set MCONF_ERRORLEVEL=
if "%OS%" == "Windows_NT" goto WinNT

:WinNT
setlocal
@REM ensure the script will be executed with the Python it was installed for
set path=%PYTHONHOME%;%CD%;%path%

@REM try the script named as the .bat file in current dir, then in Scripts subdir
set scriptname=%CUBE_ROOT%\scripts\%~n0.py
python "%scriptname%" %*
endlocal & set MCONF_ERRORLEVEL=%ERRORLEVEL%

if NOT "%COMSPEC%" == "%SystemRoot%\system32\cmd.exe" goto returncode
if errorlevel 9009 echo you do not have python in your PATH
goto endmconf

:returncode
exit /B %MCONF_ERRORLEVEL%

:endmconf
call :returncode %MCONF_ERRORLEVEL%