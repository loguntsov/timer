rem �������� ��ன ���ᨨ ��娢�.
del Timer.exe
del Timer.rar
rem �������� 䠩�� ���樠����樨
del Timer\Timer.ini

rem ��娢��� sfx-rar
rar a -m5 -r -s -k -zComment.txt Timer.rar Timer\*.* 
rar s Timer.rar Timer.exe 