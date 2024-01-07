## About
Репозиторий для совместной работы по ТРПО, ИУ1-73, 2023

## Guides
1. Ссылка на репозиторий группы (там задания, литература, рукописные гайды по плюсам): https://github.com/ale5000/iu73_23_24 
2. Как делать пулл-реквесты: https://gist.github.com/ComradeMashkov/c2bc1801552284c2b43b8aabaef1bae3
3. Стиль кода от Google: https://google.github.io/styleguide/cppguide.html
4. Стиль кода от Google (на русском): https://habr.com/ru/amp/publications/480422/
5. Проектирование архитектуры проекта: https://habr.com/ru/amp/publications/276593/
6. Идиома RAII в C++: https://academy.yandex.ru/handbook/cpp/article/raii-and-smart-pointers
7. **ВАЖНО!** Базовые структуры данных: https://habr.com/ru/articles/422259/
8. Сборка проекта на Windows: https://gist.github.com/ComradeMashkov/4663af23dc89c4dc3d3e2395a6bb1fc7

## Task
На данный семестр поставлена задача разработать программу, которая будет включать в себя:
1. Математическую модель самолета(-ов)
2. Модель САУ самолета(-ов)
3. Систему слежения за погодой
4. Систему сбора данных о самолетах в режиме реального времени
5. Систему визуализации данных
6. Систему логгирования отработанных действий

Ссылка на лог разработки лежит в директории [`devlog`](https://github.com/ComradeMashkov/airborne-crew/blob/main/devlog/README.md). 

## Architecture
Архитектура проекта разработана следующим образом:
![img](https://raw.githubusercontent.com/ComradeMashkov/airborne-crew/044e054cd0e6148b2ecf593b5d3ae3306d178ec0/meta/Разработка%20диспетчерского%20окна.png)

## Build
Сборка проекта может отличаться от того, какая операционная система у вас установлена.

### Windows
Чтобы собрать проект на Windows, посмотрите этот гайд: https://gist.github.com/ComradeMashkov/4663af23dc89c4dc3d3e2395a6bb1fc7

### Linux (Ubuntu)
Для сборки проекта на Ubuntu вам необходимо выполнить следующие этапы:
1. Загрузить репозиторий локально на компьютер:
```bash
git clone https://github.com/ComradeMashkov/airborne-crew.git
```
2. Перейти в директорию проекта:
```bash
cd airborne-crew
```
3. Создать папку под сборку (например, `cmake_build`):
```bash
mkdir cmake_build
cd cmake_build
```
4. Установить Boost версии **не ниже** 1.83.0:
```bash
sudo add-apt-repository ppa:mhier/libboost-latest
sudo apt update
sudo apt install libboost1.83-dev
```
5. Начать сборку и запустить исполняемый файл:
```bash
cmake ../src
cmake --build .
./main
```

### macOS
Для сборки проекта на OSX вам необходимо выполнить следующие этапы:
1. Загрузить репозиторий локально на компьютер:
```bash
git clone https://github.com/ComradeMashkov/airborne-crew.git
```
2. Перейти в директорию проекта:
```bash
cd airborne-crew
```
3. Создать папку под сборку (например, `cmake_build`):
```bash
mkdir cmake_build
cd cmake_build
```
4. Установить Boost версии **не ниже** 1.83.0:
```bash
brew install boost
```
5. Начать сборку и запустить исполняемый файл:
```bash
cmake ../src
cmake --build .
./main
```

## Authors
Участники проекта:
1. Машков Илья
2. Кривозубова Анфиса
3. Семенова Екатерина 
4. Чернавских Елена
5. Зеничев Сергей
6. Кривова Вера

