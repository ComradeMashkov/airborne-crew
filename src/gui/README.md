# Интерфес
## Canvas
Класс отображения холста приложения. Определение canvas.h, реализация canvas.cpp\
### Поля класса
*tgui::CanvasSFML::Ptr canvas_* — объект класса CanvasSFML библиотеки SFML\

### Методы класса
*Canvas()* — дефолтный конструктор\
*InitializeCanvas(objects::Plane& plane)* — параметризированный конструктор холста. Параметр — объект самолета\
*tgui::CanvasSFML::Ptr GetCanvas()* — возвращает указатель на объект класса CanvasSFML библиотеки SFML\
*SetSize(tgui::Layout width, tgui::Layout height)* — настройка размеров холста\
*SetPosition(tgui::Layout x, tgui::Layout y)* — настройка положения хооста\
*tgui::Vector2f GetSize()* — возвращает размер холста\

## Coords
Класс CoordsLabel наследник класса LabelBase. Определение coords.h, реализация coords.cpp\
### Поля класса
*tgui::Label::Ptr label_* — объект класса библиотеки TGUI\

### Методы класса
*CoordsLabel()* — дефолтный конструктор\
*InitializeLabel()* — переопределение. Устанавливает позицию метки координат\
*tgui::Label::Ptr GetLabel()* — возвращает указатель на объект класса TextLabel\
*SetLabelText(const tgui::String& text)* — изменяет текст метки

## Fps
Класс  наследник класса LabelBase. Определение coords.h, реализация coords.cpp\
### Поля класса
** — объект класса библиотеки TGUI\

### Методы класса
** —
** —
** —
** —

## Menu
Класс верхнего меню приложения. Определение menu.h, реализация menu.cpp\
### Поля класса
*tgui::MenuBar::Ptr upper_menu_* — объект класса библиотеки TGUI горизонтального меню\

### Методы класса
*UpperMenu()* — дефолтный конструктор
*UpperMenu::InitializeMenu(tgui::Gui& gui, objects::Plane& plane, FrameRateLabel& fps)* — параметризированный конструктор верхнего меню. Параметры: объекты интерфейса, самолета, ФПС\
*tgui::MenuBar::Ptr GetMenu()* — возвращает указатель на объект типа tgui::MenuBar


** —