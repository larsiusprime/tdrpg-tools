@echo off
cd bin
if "%1"=="debug" (
  :: run debug
  Main-Debug.exe _input/ _output/
) else (
  :: run release
  Main.exe _input/ _output/
)
pause