## Класс Plane

### Поля класса
- *angle_speed* — угловая скорость объекта
- *angle* — угол рысканья
- *target_angle* — целевой курс
- *tracking_target* — флаг достижения цели
- *sf::Sprite plane_* — изображения объекта в библиотеке SFML
- *speed_* — скорость движения
- *to_draw_* — флаг о начале работы программы управления
- *sf::Vector2f target_position_* — двумерный вектор целевых координат в библиотеке SFML

### Методы класса
- *SetPrimitive(const sf::Sprite& circle)* — устанавливает в качестве изображения объекта переданую картинку
- *SetToDraw(bool to_draw)* — устанавливает флаг to_draw_
- *SetTargetPosition(const sf::Vector2f& target_position)* — обновляет целевую точку
- *Plane::GetPrimitive()* — возвращает текстуру объекта
- *Plane::GetSpeed()* — возвращает скорость объекта
- *Plane::GetTargetPosition()* — возвразает целевую точку
- *Plane::GetCurrentPosition()* — возвращает текущее положение
- *Plane::GetPlaneSize()* — возвразает ширину и высоту текстуры объекта
- *Plane::Control()* — выводит текущие координаты объекта, рассчитывает необходимое перемещение и поворот объекта

