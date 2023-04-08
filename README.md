# homework5 08.04.23
## Спроектировать простейший графический векторный редактор.

## Задание
+ Функционал для макетирования следующий:
+ - создание нового документа
+ - импорт документа из файла
+ - экспорт документа в файл
+ - создание графического примитива
+ - удаление графического примитива
+ Основной упор сделать на шаблон контроллера (MVC) и полиморфизм. 
+ Задание считается выполненным успешно, если все файлы прошли стадию компиляции, все классы охвачены диаграммами, код успешно прошел анализ.

## Native build
+ mkdir build
+ cd build
+ cmake ../
+ cmake --build . --config Release|Debug

## Install build
+ cmake --install .

## Run tests (GTest & BoostTest)
### Linux
+ cmake --build . --target test --config Release|Debug
### Windows
+ cmake --build . --target RUN_TESTS --config Release|Debug

## CPack (build ZIP & DEB)
+ cpack -C Release|Debug

## Проверка Linux
+ apt update && apt install -y simple_graphical_vector_editor-0.0.X-Linux.deb
+ ./simple_graphical_vector_editor

## Проверка Windows
+ unzip simple_graphical_vector_editor-0.0.X-win(64|32).zip
+ simple_graphical_vector_editor.exe