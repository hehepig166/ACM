//bat比较程序
@echo off
:loop
    _data.exe >_in.txt
    _my.exe < _in.txt >_myout.txt
    _std.exe < _in.txt > _stdout.txt
    fc _myout.txt _stdout.txt
if not errorlevel 1 goto loop
pause
goto loop