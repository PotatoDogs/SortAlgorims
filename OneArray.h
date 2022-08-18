#pragma once
#include <cmath>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;

namespace OneArray {
	public ref class Array1
	{
	public:
		static void output_mas(int *array, int len, DataGridView^t);
		static void entor_mas(int*, int);
		//Алгоритмы
		static void Algorithm1(int*, int); //Вычислить сумму элементов одномерного массива.
		static void Algorithm2(int*, int); //Определение наибольшего элемента массива
		static void Algorithm3(int*, int&n); //Удаление элементов массива
		static void Algorithm4(int*, int&n, int, int); //Вставка элементов массива
		static void Algorithm5(int*, int); //Обмен элементов массива
		static void Algorithm6(int*, int); //Сортировка массива простой вставкой
		static void Algorithm7(int*, int); //Сортировка массива бинарными включениями
		static void Algorithm8(int*, int); //Сортировка массива методом простого выбора
		static void Algorithm9_1(int*, int); //Сортировка массива методом пузырька 1 способ
		static void Algorithm9_2(int*, int); //Сортировка массива методом пузырька 2 способ
		static void Algorithm10(int*, int); //Сортировка массива по убыванию
		static void Algorithm11(int*, int); //Монотонно убывающая последовательность или нет?
		static void Algorithm12(int*, int); //Наличие в массиве кого-либо элемента (в примере находится отрицательный)
		//БД microsoft access
		static void create_tab();
		static void create_struct();
		static void add_znach(int*, int);
	};
}
