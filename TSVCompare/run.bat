@echo off
cd bin
if "%1"=="debug" (
  :: run debug
  java -jar Main-Debug.jar a.txt b.txt
) else (
  :: run release
  java -jar Main.jar
)
pause
