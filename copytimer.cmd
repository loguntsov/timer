cls
rem ����஢���� ⠩��� � ����ਡ�⨢�� ��⠫��
del ZipLib.exe
rem �������� ��ண� ⠩���
del Distrib\Timer\Timer.exe
rem del e:\Install.All\Timer\TimerAgent.exe
rem ���⨥ UPX
del Distrib\Timer\Timer.exe
copy Timer.exe "Distrib\Timer\Timer.exe" 
rem upx --best --crp-ms=999999 -o"Distrib\Timer\Timer.exe" Timer.exe


rem ����஢���� �몮��� 䠩���
copy Language\*.* "Distrib\Timer\Language\*.*"
rem ����஢���� 䠩��� �����
copy Help\*.* "Distrib\Timer\Help\*.*"

rem ����஢���� ��������
del Distrib\Timer\Plugin\TimerGluk\RuberForm.dll 
copy Plugin\TimerGluk\RuberForm.dll Distrib\Timer\Plugin\TimerGluk\RuberForm.dll 
rem upx --best --crp-ms=999999 --compress-resources=0 -o"Distrib\Timer\Plugin\TimerGluk\RuberForm.dll" Plugin\TimerGluk\RuberForm.dll 
 
del Distrib\Timer\Plugin\MultiTimer\MultiTimer.dll
copy Plugin\MultiTimer\MultiTimer.dll Distrib\Timer\Plugin\MultiTimer\MultiTimer.dll

rem upx --best --crp-ms=999999 --compress-resources=0 -o"Distrib\Timer\Plugin\MultiTimer\MultiTimer.dll" Plugin\MultiTimer\MultiTimer.dll 

copy Plugin\RunProgram\help.htm Distrib\Timer\Plugin\RunProgram

del Distrib\Timer\Plugin\RunProgram\RunProgram.dll

copy Plugin\RunProgram\RunProgram.dll Distrib\Timer\Plugin\RunProgram\RunProgram.dll

rem upx --best --crp-ms=999999 --compress-resources=0 -o"Distrib\Timer\Plugin\RunProgram\RunProgram.dll" Plugin\RunProgram\RunProgram.dll 

rem ����� �������⥫��� ����⢨� ��� ᮧ����� ����ਡ�⨢�
cd Distrib
call Work.bat
rem �����
