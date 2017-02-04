@echo off
if %1 == debug (
	build\hxwidgets\Main-debug.exe
) else (
	build\hxwidgets\Main.exe
)
