@echo off
cd bin
if "%1"=="debug" (
  :: run debug
  java -jar Main-Debug.jar input.csv output.tsv
) else (
  :: run release
  java -jar Main.jar input.tsv output.csv -reverse -escapeallthethings
)
pause
