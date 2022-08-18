#pragma once
#include <cmath>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;


namespace TwoArray {
	public ref class Array2
	{
	public:
		static void entor_mas(int**, int, int);
		static void output_mas(int **array, int n, int m, DataGridView^grid);
		static void copy_massive(int**, int**, int, int);

		static void Algorithm1(int**, int, int);
		static void Algorithm2(int**, int, int); //Сумма всех чисел в исходной матрице
		static void Algorithm3(int**, int, int, int s); //Определени количества положительных чисел в столбце"
		static void Algorithm4(int**, int); // Нахождение наибольшего элемента двумерного массива
		static void Algorithm5(int**, int**, int, int); //Транспонирование матрицы
		static void Algorithm6(int**, int**, int**, int, int, int); //Произведение двух матриц
		static void Algorithm7(int**, int, int, int, int); //Вставка столбца
		static void Algorithm8(int**, int, int); //Номер наименьшего столбца
		static void Algorithm9(int**, int, int, int); //Смена столбцов местами
		static void Algorithm10(int**, int, int, int); //Смена строчек местами
		static void Algorithm11(int**, int, int, int); //Удаление строки
		static void Algorithm12(int**, int, int, int); //Удаление столбца

		static void Del(int**, int); //Удаление массива 

		//БД microsoft access
		static void create_tab(String^ BDname);
		static void create_struct(String^ BDname, int m);
		static void CommBD(String^ commandString, String^ BDname);
		static void add_znach(String^ BDname, int** mas1, int** mas2, int n, int m);
	};
}
