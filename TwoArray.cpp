#include "pch.h"

#include "TwoArray.h"

namespace TwoArray {
	void Array2::entor_mas(int **mas, int n, int m) {
		srand(NULL);
		for (int i = 0; i < n; i++) {
			mas[i] = new int[m];
			for (int j = 0; j < m; j++) {
				mas[i][j] = (1 + rand() % 1001);
			}
		}
	}
	
	void Array2::output_mas(int **array, int n, int m, DataGridView^grid) {
		grid->RowCount = n + 1;
		grid->ColumnCount = m + 1;
		grid->Rows[0]->Cells[0]->Value = n + "/ " + m;
		for (int i = 0; i < n; i++) {
			grid->Rows[i + 1]->Cells[0]->Value = " [ " + i + "] ";
		}
		for (int j = 0; j < m; j++) {
			grid->Rows[0]->Cells[j + 1]->Value = " [ " + j + "] ";
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				grid->Rows[i + 1]->Cells[j + 1]->Value = array[i][j];
			}
		}
		int width = 0;
		for (int s = 0; s < grid->ColumnCount; s++) {
			width += grid->Columns[s]->Width;
			if (width == 210)
				grid->Width = 210;
			else
				grid->Width = width + 3;
		}
		int height = 0;
		for (int s = 0; s < grid->RowCount; s++) {
			height += grid->Rows[s]->Height;
			if (height == 210)
				grid->Height = 210;
			else
				grid->Height = height + 3;
		}
	}
	
	void Array2::copy_massive(int** a, int** b, int n, int m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				b[i][j] = a[i][j];
			}
		}
	}

	void Array2::Algorithm1(int** array, int n, int m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				array[i][j] = (i + j) / 2;
			}
		}
	}
	void Array2::Algorithm2(int** array, int n, int m) {
		int p = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (array[i][j] > 0)
					p += array[i][j];
			}
		}
		MessageBox::Show("Сумма всех чисел в исходной матрице " + p, "Произведения", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
	
	void Array2::Algorithm3(int** array, int n, int m, int s) {
		int k = 0;
		for (int i = 0; i < n; i++) {
			if (array[i][s] > 0)
				k++;
		}
		MessageBox::Show("Количество положительных чисел \nв исходной матрице" + k, "Полож", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
	
	void Array2::Algorithm4(int** array, int n) {
		int im = 1;
		int jm = 0;
		int xm = array[1][0];
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i-1; j++) {
				if (array[i][j]>xm){
					xm = array[i][j];
					im = i;
					jm = j;
				}
			}
		}
		MessageBox::Show("Наибольший элемент массива " + xm + "\nC индексами i-" + im + " и j-"+ jm, "Наибольший", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
	
	void Array2::Algorithm5(int** x, int** y, int n, int m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				y[i][j] = x[j][i];
			}
		}
	}
	
	void Array2::Algorithm6(int** a, int** b, int** c, int n, int m1, int m2) {
		int s;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m2; j++) {
				s = 0;
				for (int k = 0; k < m1; k++)
					s += a[i][k] * b[k][j];
				c[i][j] = s;
			}
		}
	}
	
	void Array2::Algorithm7(int**array, int n, int m, int insool, int insval) {
		for (int i = 0; i < n; i++) {
			for (int j = m ; j > insool; j--) {
				array[i][j] = array[i][j - 1];
			}
		}
		for (int i = 0; i < n; i++) {
			array[i][insool] = insval;
		}
	}
	
	void Array2::Algorithm8(int** array, int n, int m) {
		int k = 0;
		int min = array[0][0];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (array[i][j] < min) {
					min = array[i][j];
					k = j;
				}
			}
		}
		MessageBox::Show("Наименьший номер столбца" + k, "MIN", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
	
	void Array2::Algorithm9(int**array, int n, int nst1, int nst2) {
		for (int i = 0; i < n; i++) {
			int next = array[i][nst2];
			array[i][nst2] = array[i][nst1];
			array[i][nst1] = next;
		}
	}
	
	void Array2::Algorithm10(int**array, int m, int nst1, int nst2) {
		for (int j = 0; j < m; j++) {
			int n = array[nst2][j];
			array[nst2][j] = array[nst1][j];
			array[nst1][j] = n;
		}
	}
	
	void Array2::Algorithm11(int**array, int n, int m, int st) {
		for (int i = st + 1; i < n; i++) {
			for (int j = 0; j < m; j++)
				array[i - 1][j] = array[i][j];
		}
	}
	
	void Array2::Algorithm12(int**array, int n, int m, int st){
		for (int i = 0; i < n; i++) {
			for (int j = st + 1; j < m; j++)
				array[i][j - 1] = array[i][j];
		}
	}

	void Array2::Del(int **array, int m) {
		for (int i = 0; i < m; i++)
			delete[] * (array + i);
		delete[] array;
	}

	void Array2::create_tab(String^ BDname) {
		String^ Connection = "Provider = Microsoft.Jet.OLEDB.4.0; Data Source =" + Application::StartupPath + "\\" + BDname + ".mdb";
		ADOX::Catalog^ k = gcnew ADOX::CatalogClass();
		try {
			k->Create(Connection);
			MessageBox::Show("База данных создана", "БД", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
		catch (System::Runtime::InteropServices::COMException^ situation) {
			MessageBox::Show(situation->Message);
		}
		finally{
			k = nullptr;
		}
	}
	void Array2::create_struct(String^ BDname, int m) {
		String^ Connection = "Provider = Microsoft.Jet.OLEDB.4.0; Data Source =" + Application::StartupPath + "\\" + BDname + ".mdb";
		auto p = gcnew OleDbConnection(Connection);
		p->Open();
		String^ Col = "CREATE TABLE [Matrix]([Rows] counter";
		for (int i = 0; i < m; i++) {
			Col = Col + ", [" + "Col_" + Convert::ToString(i + 1) + "] char(20)";
		}
		Col = Col + ",[****] char(20)";
		for (int i = 0; i < m - 1; i++) {
			Col = Col + ", [" + "Col2_" + Convert::ToString(i + 1) + "] char(20)";

		}
		auto Command = gcnew OleDbCommand(Col + ")", p);
		try {
			Command->ExecuteNonQuery();
			MessageBox::Show("База Данных Структурирована", "БД", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
		catch (System::Data::OleDb::OleDbException^ situation) {
			MessageBox::Show(situation->Message);
		}
		p->Close();
	}
	void Array2::CommBD(String^ commandString, String^ BDname) {
		String^ Connection = "Provider = Microsoft.Jet.OLEDB.4.0; Data Source =" + Application::StartupPath + "\\" + BDname + ".mdb";
		auto Connect = gcnew OleDbConnection(Connection);
		Connect->Open();
		auto Command = gcnew OleDbCommand(commandString);
		Command->Connection = Connect;
		Command->ExecuteNonQuery();
		Connect->Close();
	}
	void Array2::add_znach(String^ BDname, int** mas1, int** mas2, int n, int m) {
		String^ cmdString;
		String^ cmdString2;
		try {
			for (int i = 0; i < n - 1; i++) {
				cmdString = "INSERT INTO [Matrix]([Rows]";
				cmdString2 = ") VALUES ('" + Convert::ToString(i + 1) + "'";
				for (int j = 0; j < m-1; j++) {
					cmdString = cmdString + ", [" + "Col_" + Convert::ToString(j + 1) + "]";
					cmdString2 = cmdString2 + ", '" + Convert::ToString(mas1[i][j]) + "'";
				}
				cmdString = cmdString + ",[****]";
				cmdString2 = cmdString2 + ",''";

				for (int j = 0; j < m - 1; j++) {
					cmdString = cmdString + ", [" + "Col2_" + Convert::ToString(j + 1) + "]";
					cmdString2 = cmdString2 + ", '" + Convert::ToString(mas2[i][j]) + "'";
				}
				cmdString2 = cmdString2 + ")";
				CommBD(cmdString + cmdString2, BDname);
			}
			cmdString = "INSERT INTO [Matrix]([Rows]";
			cmdString2 = ") VALUES ('" + Convert::ToString(n + 1) + "'";
			for (int j = 0; j < m; j++) {
				cmdString = cmdString + ", [" + "Col_" + Convert::ToString(j + 1) + "]";
				cmdString2 = cmdString2 + ", '" + Convert::ToString(mas1[n - 1][j]) + "'";
			}
			CommBD(cmdString + cmdString2 + ")", BDname);
			MessageBox::Show("База Данных Заполнена", "БД", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
		catch (System::Data::OleDb::OleDbException^ situation) {
			MessageBox::Show(situation->Message);
		}
	}
}
