# Интерфейс
## Класс Canvas
Класс отображения холста приложения. Определение canvas.h, реализация canvas.cpp
### Поля класса
* tgui::CanvasSFML::Ptr canvas_ — холст, объект класса CanvasSFML библиотеки SFML

### Методы класса
* Canvas() — конструктор по умолчанию
* InitializeCanvas(objects::Plane& plane) — параметризированный конструктор холста. Параметр — объект самолета
* tgui::CanvasSFML::Ptr GetCanvas() — возвращает указатель на объект класса CanvasSFML библиотеки SFML
* SetSize(tgui::Layout width, tgui::Layout height) — настройка размеров холста
* SetPosition(tgui::Layout x, tgui::Layout y) — настройка положения хооста
* tgui::Vector2f GetSize() — возвращает размер холста

## Класс Coords
Класс CoordsLabel наследник класса LabelBase. Определение coords.h, реализация coords.cpp
### Поля класса
* tgui::Label::Ptr label_ — метка, объект класса Label библиотеки TGUI

### Методы класса
* CoordsLabel() — дефолтный конструктор
* InitializeLabel() — переопределение. Устанавливает позицию метки координат
* tgui::Label::Ptr GetLabel() — возвращает указатель на объект класса TextLabel
* SetLabelText(const tgui::String& text) — изменяет текст метки

## Класс FPS
Класс FrameRateLabel наследник класса LabelBase. Определение fps.h, реализация fps.cpp
### Поля класса
* tgui::Label::Ptr label_ — метка, объект класса Label библиотеки TGUI
* sf::Clock frame_clock_ — таймер, объект класса Clock библиотеки SFML
* frame_count_ — число прошедших кадров
* frame_rate_ — частота кадров в секунду

### Методы класса
* FrameRateLabel() — конструктор по умолчанию
* InitializeLabel() — переопределение. Устанавливает позицию метки ФПС
* tgui::Label::Ptr GetLabel() — возвраящает указатель на объект класса TextLabel
* FrameRateLabel::SetLabelText(const tgui::String& text) — изменяет текст метки
* FrameRateLabel::GetFrameRate() — возвращается частота обновления кадров
* CalculateFrameRate() — вычисляет частоту кадров на основе кол-ва прошедших кадров, обновляет метку
* ShowLabel() — включает видимость метки ФПС

## Класс Label base
Абстрактный класс LabelBase. Определение label_base.h
### Методы класса
* InitializeLabel() — конструктор
* tgui::Label::Ptr GetLabel() — возвращает указатель на метку
* SetLabelText(const tgui::String& text) — изменяет текст метки
* ~LabelBase() — деструктор

## Класс Menu
Класс UpperMenu верхнего меню приложения. Определение menu.h, реализация menu.cpp
### Поля класса
* tgui::MenuBar::Ptr upper_menu_ — объект класса библиотеки TGUI горизонтального меню

### Методы класса
* UpperMenu() — конструктор по умолчанию
* UpperMenu::InitializeMenu(tgui::Gui& gui, objects::Plane& plane, FrameRateLabel& fps) — параметризированный конструктор верхнего меню. Параметры: объекты интерфейса, самолета, ФПС
* tgui::MenuBar::Ptr GetMenu() — возвращает указатель на объект типа tgui::MenuBar

## Класс Separator
Абстрактный класс Line разделителей областей приложения. Определение separator.h, реализация separator.cpp
### Методы класса
* InitializeLine() — коснтруктор по умолчанию
* SetPosition(tgui::Layout x, tgui::Layout y) — изменяет начальную точку линии
* SetSize(tgui::Layout width, tgui::Layout height) — изменяет ширину и высоту линии
* tgui::Panel::Ptr GetLine() — возвращает указатель на объект класса Line
* sf::Vector2f GetSize() — возвращает размер линии
* ~Line() — деструктор

**Класс VerticalLine**\
Класс рисования вертикальных линий. Наследник класса Line
### Поля класса
* tgui::Panel::Ptr line_ — объект класса Panel библиоткеи TGUI
### Методы класса
Аналогичны методам класса Line.
**Класс HorizontalLine**\
Класс рисования горизонтальных линий. Наследник класса Line
### Поля класса
* tgui::Panel::Ptr line_ — объект класса Panel библиоткеи TGUI
### Методы класса
Аналогичны методам класса Line.

## Класс Stamp
**Класс DateStamp**, наследник класса LabelBase. Метка даты. Определение stamp.h, реализация stamp.cpp
### Поля класса
* tgui::Label::Ptr label_ — метка, объект класса Label библиотеки TGUI
* now — текущее время
* ltm — указатель на текущее время
* tgui::String year — год
* tgui::String month — месяц
* tgui::String day — день

### Методы класса
* DateStamp() — конструктор по умолчанию
* InitializeLabel() — переопределение метки даты: заполнение полей класса
* tgui::Label::Ptr GetLabel() — возвращает указатель на метку
* SetLabelText(const tgui::String& text) — изменяет текст метки
* Update() — обновляет значение полей метки

**Класс TimeStamp**, наследник класса LabelBase. Метка времени. Определение stamp.h, реализация stamp.cpp
### Поля класса
* tgui::Label::Ptr label_ — метка, объект класса Label библиотеки TGUI
* now — текущее время
* ltm — указатель на текущее время
* tgui::String hour — часы
* tgui::String minute— минуты
* tgui::String second— секунды

### Методы класса
* TimeStamp() —  конструктор по умолчанию
* InitializeLabel() — переопределение метки времени: заполнение полей
* tgui::Label::Ptr GetLabel() —  возвращает указатель на метку
* SetLabelText(const tgui::String& text) — изменяет текст метки
* Update() — обновляет значения полей метки

## Text label
Класс TextLabel наследник класса LabelBase. Определение text_label.h, реализация text_label.cpp
### Поля класса
* tgui::Label::Ptr label_ — метка, объект класса Label библиотеки TGUI

### Методы класса
* TextLabel() — конструктор по умолчанию
* InitializeLabel() — переопределение метки
* InitializeLabel(const tgui::Layout2d &position, int text_size) — параметрезированный конструктор: установка размера и расположения
* tgui::Label::Ptr TextLabel::GetLabel() — возвращает указатель на метку
* SetLabelText(const tgui::String& text) — изменяет текст метки
