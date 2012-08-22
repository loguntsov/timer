rem Удаление старой версии архива.
del Timer.exe
del Timer.rar
rem Удаление файла инициализации
del Timer\Timer.ini

rem Архивация sfx-rar
rar a -m5 -r -s -k -zComment.txt Timer.rar Timer\*.* 
rar s Timer.rar Timer.exe 