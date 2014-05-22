@echo off

set /p version=< %haxepath%\lib\systools\.current
set version=%version:.=,%

set origin=%haxepath%\lib\systools\%version%\ndll\Windows\systools.ndll
set destination=%cd%\bin\windows\cpp\bin\systools.ndll

if %1==windows (
  if %2==release (
    :copy the necessary ndll files to the binary folder
    echo FY|xcopy %origin% %destination%
  )
)
