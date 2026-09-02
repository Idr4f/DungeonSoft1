@echo off
:: Crear la carpeta output si no existe
if not exist "output" mkdir "output"

echo Compilando el proyecto con g++...
g++ -Wall -Wextra -g3 main.cpp game/Game.cpp direction/*.cpp lucky/*.cpp room/*.cpp player/*.cpp -I. -o output/main.exe

:: Verificar si la compilación fue exitosa
if %ERRORLEVEL% equ 0 (
    echo.
    echo [EXITO] Compilacion completada con exito.
    echo Guardado en: output/main.exe
) else (
    echo.
    echo [ERROR] Hubo un error durante la compilacion.
)

echo.
pause