1.  Лабораторная работа №3
    ======================

    1.  Цель работы
        -----------

Изучение механизма наследования классов и полиморфизма, виртуальных методов, а также абстрактных методов и классов.

Задание к лабораторной работе
-----------------------------

Необходимо разработать иерархическую структуру классов, позволяющую создавать два типа объектов – вектора и матрицы. Вектор представляет собой одномерный массив произвольной длины, матрица – двумерный массив произвольной размерности (см. ЛР№2). При этом с обоими типами объектов должны быть предусмотрены:

1.  Конструкторы (по умолчанию, с параметрами, копирующий);

2.  Проверка возможности сложения и умножения объектов (вектора и вектора, вектора и матрицы, матрицы и вектора, матрицы и матрицы);

3.  Оператор доступа к элементам вектора и матрицы \[\];

4.  Оператор вывода в поток &lt;&lt;;

5.  Математические операторы (+, –, \*, +=, –=, \*=, =) с объектами, а также умножение объектов на скаляр;

Указание. Структуру иерархии классов продумать самостоятельно. Возможны, как минимум, три варианта (рис. 1). При выборе варианта №3 пользователь не должен иметь возможности создания экземпляров базового класса. Также необходимо самостоятельно решить, какие методы должны быть виртуальными.