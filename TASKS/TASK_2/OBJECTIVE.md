1.  Лабораторная работа №2
    ======================

    1.  Цель работы
        -----------

Освоение методов использования динамической памяти, изучение свойства полиморфизма, реализуемого перегрузкой функций и операций в классах C++.

Задание к лабораторной работе
-----------------------------

Составить описание класса для объектов прямоугольных матриц, задаваемых массивом вещественных чисел типа **double**, располагающегося в памяти по строкам. Компоненты матрицы должны быть скрыты (инкапсулированы) в объекте.

Предусмотреть применение конструкторов:

а) по умолчанию;

б) для инициализации квадратной матрицы заданного размера с заданными компонентами;

в) для инициализации прямоугольной матрицы заданных размеров с заданными компонентами;

г) копирования.

Можно использовать параметры по умолчанию для сокращения количества конструкторов.

Конструкторы должны создавать объекты в динамической памяти (оператор **new**), а деструктор – освобождать память (оператор **delete**). Способ размещения объекта в динамической памяти (в виде одномерного или двумерного динамического массива, либо комбинированный вариант – одномерный массив с массивом указателей на начало каждой строки матрицы) выбрать самостоятельно. Все эти способы имеют как достоинства, так и недостатки.

Организовать в конструкторах и деструкторе вывод на экран информационных сообщений, например, «*Конструктор 1*», «*Деструктор*» и т.д.

I. С помощью функций-элементов класса обеспечить:

1) проверку возможности умножения двух матриц;

2) проверку возможности сложения двух матриц;

3) максимального элемента матрицы;

4) минимального элемента матрицы.

II. С помощью операторов-элементов класса обеспечить:

1) доступ к элементам матрицы по индексу строки и столбца (чтение/запись), т.е. переопределить оператор \[\];

2) вывод на экран матрицы в построчной форме, т.е. переопределить оператор вывода на поток &lt;&lt;;

3) математические действия над матрицами *A* и *B* без получения новых матриц, т.е. переопределить операторы

а) *A* = *B*;

б) *A* += *B*;

в) *A* –= *B*;

г) *A* \*= *B*;

д) а также *A* \*= *k* – умножение матрицы на скаляр.

III. C помощью внешних операторов обеспечить двуместные операции над матрицами *A* и *B* с получением новой матрицы *C*:

1) сложение (*C* = *A* + *B*);

2) вычитание (*C* = *A* – *B*);

3) произведение (*С* = *A* \* *B*);

4) умножение матрицы на скаляр (*С* = *A* \* *k*).

Выполнению операций сложения, вычитания и умножения матриц должна предшествовать проверка возможности их выполнения над данными объектами.

*УКАЗАНИЕ*: Для выравнивания позиций при выводе матрицы на экран можно использовать функции-манипуляторы потока (библиотека **iomanip.h**) либо функции-элементы (методы) класса ostream (библиотека **iostream.h**):

|                                         |                                                    |
|-----------------------------------------|----------------------------------------------------|
| Манипуляторы потока                     | Методы класса ostream                              |
| fixed                                   
                                          
 scientific                               
                                          
 setprecision(int n)                      
                                          
 setw(int n)                              
                                          
 resetiosflags(ios\_base::fmtflags flag)  
                                          
 setiosflags(ios\_base::fmtflags flag)    | setf(ios\_base::fixed, ios\_base::floatfield)      
                                                                                               
                                           setf(ios\_base::scientific, ios\_base::floatfield)  
                                                                                               
                                           precision(int n)                                    
                                                                                               
                                           width(int n)                                        
                                                                                               
                                           setf(0, flag)                                       
                                                                                               
                                           setf(flag)                                          |

