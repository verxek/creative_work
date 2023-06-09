# Автоматизированное рабочее место специалиста
## Постановка задачи
Реализовать автоматизированное рабочее место специалиста (АРМ) - цифрового художника. Программа должна выполнять следующие функции:

- Управление событиями
- Авторизация пользователя
- Создание и управление художественными проектами

## Анализ задачи
- Приложение  разработано с использованием фреймворка Qt, который предоставляет широкий набор инструментов для создания кросс-платформенных приложений на C++. В основе приложения лежит объектно-ориентированный подход, использующий классы и сигналы/слоты для обработки событий и связи между компонентами.
- Для хранения информации необходимо создать три CSV-таблицы: Accounts - для хранения логинов и паролей пользователей, Orders - для хранения информации о всех заказах, CompletedOrders - для хранения выполненных заказов. 
- Для управления заказами используется виджет календаря: в него можно добавлять новые заказы, заполнив форму, а также удалять выполненные заказы.
- Для отображения ближайших заказов и статистики используются текстовые виджеты, которые изменяются при входе в систему.

## Работа программы
### Главное окно
![image](https://github.com/verxek/creative_work/assets/88082592/9423696d-c2f1-45d5-8a05-ef94e9056c54)

### Демонстрация добавления
![image](https://github.com/verxek/creative_work/assets/88082592/acdc00e2-0383-432b-a368-f07c30c81df4)

![image](https://github.com/verxek/creative_work/assets/88082592/1645df5c-c0de-4c93-bcc1-4819aa662775)

### Демонстрация удаления
Удаление заказа от 24.06

![image](https://github.com/verxek/creative_work/assets/88082592/25ab60a0-dfa4-422c-9da7-17ce51f0947f)
![image](https://github.com/verxek/creative_work/assets/88082592/1c4f5653-a9f3-4085-bd80-016eee1c6f29)

## Диаграмма классов
![image](https://github.com/verxek/creative_work/assets/88082592/8ed7b10a-a785-4897-9b87-c0a82cfa953d)

## Исходный код
Исходный код представлен в репозитории: https://github.com/verxek/creative_work/tree/main/digital_artist_arm/ex2
