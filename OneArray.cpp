#include "pch.h"

#include "OneArray.h"

namespace OneArray {

	void Array1::output_mas(int *array, int len, DataGridView^t) {
		int width = 0;
		t->ColumnCount = len;
		t->RowCount = 2;
		t->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		t->Height = 2 * t->Rows[0]->Height + 3;
		for (int i = 0; i < len; i++) {
			t->Rows[0]->Cells[i]->Value = "[" + i + "]";
			t->Rows[1]->Cells[i]->Value = array[i];
		}
		for (int s = 0; s < t->ColumnCount; s++) {
			width += t->Columns[s]->Width;
			if (width > 410) {
				t->Width = 413;
				t->Height = 3 * t->Rows[0]->Height;
			}
			else
				t->Width = width + 3;
		}
	}
	void Array1::entor_mas(int *mas, int n) {
		for (int i = 0; i < n; i++)
			mas[i] = (1 + rand() % 101);
	}
	
	void Array1::Algorithm1(int *array, int n) {
		int Summ = 0;
		for (int i = 0; i < n; i++)
			Summ += array[i];
		MessageBox::Show("Сумма массива = "+Summ, "Сумма", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
	
	void Array1::Algorithm2(int *array, int n) {
		int k = 1;
		int a = array[0];
		for (int i = 1; i < n; i++){
			if (a<array[i]){
				a = array[i];
				k = i;
			}
		}
		MessageBox::Show("Наибольший элемент  - " + a + "\nПод номером -" + k, "Наибольший", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
	
	//Для решения задачи необходимо:
	//1) найти номер k наибольшего элемента массива.
	//2) сдвинуть все элементы массива, начиная с k-го, на один элемент влево.
	void Array1::Algorithm3(int* mas, int &n) {
		int k = 0;
		for (int i = 1; i < n; i++) {
			if (mas[i] > mas[k])
				k = i;
		}
		for (int i = k; i < n - 1; i++)
			mas[i] = mas[i + 1];
		n--;
		MessageBox::Show("Удаление минимального числа" + mas[k], "Миниммальное", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
	
	// Осуществляется следующим образом:
	// 1) первые k элементов массива остаются без изменения;
	// 2) все элементы, начиная с (k + 1)-го необходимо сдвинуть вправо, чтобы
	// освободить место для вставляемого элемента;
	// 3) элементу с номером (k + 1) присвоить значение m. Количество элементов
	// массива увеличить на 1.
	void Array1::Algorithm4(int* array, int &n, int pos, int val) {
		for (int i = n; i > pos+1; i--) {
			array[i+1] = array[i];
		}
		array[pos] = val;
		n++;
	}
	
	void Array1::Algorithm5(int* a, int n) {
		int nommax, nommin;
		int max = a[0];
		int min = a[0];
		for (int i = 0; i < n; i++) {
			if (a[i] < min) {
				min = a[i];
				nommin = i;
			}
			if (a[i] > max) {
				max = a[i];
				nommax = i;
			}
		}
		int j = a[nommin];
		a[nommin] = a[nommax];
		a[nommax] = j;
	}
	
	void Array1::Algorithm6(int* a, int n) {
		int x, j;
		for (int i = 1; i < n; i++){
			x = a[i];
			j = i - 1;
			while (x < a[j]){
				a[j + 1] = a[j];
				j = j - 1;
			}
			a[j + 1] = x;
		}
	}
	
	// Метод на каждом шаге сравнивает х со средним (по положению)
	// элементом отсортированной последовательности до тех пор, пока не будет
	// найдено место включения.
	// Left - левая граница отсортированного массива
	// Right - правая
	void Array1::Algorithm7(int* a, int n) {
		int x, left, right, m;
		for (int i = 1; i < n; i++) {
			x = a[i];
			left = 0;
			right = i - 1;
			while (left <= right) {
				m = (left + right) / 2;
				if (x < a[m])
					right = m - 1;
				else
					left = m + 1;
			}
			for (int j = i - 1; j > left - 1; j--)
				a[j + 1] = a[j];
			a[left] = x;
		}
	}
	
	// В массиве выбирается наименьший элемент. Наименьший элемент
	// записывается на i-е место исходного массива, а элемент с i-го места
	// перемещается на место выбранного. Затем ситуация повторяется.
	// Упорядоченные элементы исключаются из дальнейшей сортировки, поэтому
	// длина оставшегося неупорядоченного массива должна быть на один элемент
	// меньше предыдущего.
	void Array1::Algorithm8(int* a, int n) {
		for (int i = 0; i < n - 1; i++) {
			int k = i;
			int x = a[i];
			for (int j = i + 1; j < n; j++) {
				if (a[j] < x) {
					k = j;
					x = a[j];
				}
			}
			a[k] = a[i];
			a[i] = x;
		}
	}
	
	// Начиная с конца массива, сравниваем два соседних элемента (a[n] и a[n – 1]).
	// Если выполняется условие a[n – 1] > a[n], то значения элементов
	// меняются местами. Процесс продолжается для a[n – 1] и a[n – 2] и т. д., пока
	// не будет произведено сравнение a[2] и a[1]. После этого на месте a[1] окажется
	// элемент массива с наименьшим значением.
	// На втором шаге процесс повторяется, но последними сравниваются a[3]
	// и a[2]. На последнем шаге будут сравниваться только значения a[n] и a[n – 1].
	// Понятна аналогия с пузырьком, поскольку наименьшие элементы (самые
	// «легкие») постепенно «всплывают» к верхней границе массива.
	void Array1::Algorithm9_1(int* a, int n) {
		int x;
		for (int i = 1; i < n; i++) {
			for (int j = n - 1; j >= i; j--) {
				if (a[j - 1] > a[j]) {
					x = a[j - 1];
					a[j - 1] = a[j];
					a[j] = x;
				}
			}
		}
	}
	
	// запоминать, производился ли на
	// данном проходе какой-либо обмен. Если нет, то алгоритм может закончить
	// свою работу.
	// Пусть переменная Flag = 1, если на очередном шаге был выполнен обмен
	// элементов, и Flag = 0, если обмена не было
	void Array1::Algorithm9_2(int* a, int n) {
		int Flag = 1;
		int m = n - 1;
		int x;
		while ((m > 1) && (Flag == 1)) {
			Flag = 0;
			for (int i = 0; i < m; i++) {
				if (a[i] > a[i + 1]) {
					x = a[i];
					a[i] = a[i + 1];
					a[i + 1] = x;
					Flag = 1;
				}
			}
			m--;
		}
	}
	

	void Array1::Algorithm10(int* a, int n) {
		for (int i = 0; i < n - 1; i++) {
			int max = a[i];
			for (int j = i + 1; j < n; j++) {
				if (a[j] > max) {
					a[i] = a[j];
					a[j] = max;
					max = a[i];
				}
			}
		}
	}
	
	void Array1::Algorithm11(int* a, int n) {
		int i = 0;
		int Flag = 1;
		while ((i <= n - 1) && (Flag == 1)) {
			if (a[i] >= a[i + 1])
				i++;
			else
				Flag = 0;
		}
		if(Flag)
			MessageBox::Show("Монотонно возрастающая" + Flag, "Сумма", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		else
			MessageBox::Show("Монотонно убывающая " + Flag, "Сумма", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
	
	void Array1::Algorithm12(int* a, int n) {
		int i = 0;
		int Flag = 0;
		while ((i <= n) && (Flag == 0)) {
			if (a[i] < 0)
				Flag = 1;
			else
				i++;
		}
		if (Flag)
			MessageBox::Show("Отрицательный элемент присутствует" + Flag, "Сумма", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		else
			MessageBox::Show("Отрицательный эллемент отсутствует" + Flag, "Сумма", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}


	void Array1::create_tab() {
		ADOX::Catalog^ x = gcnew ADOX::CatalogClass();
		try {
			x->Create("Provider = Microsoft.Jet.OLEDB.4.0; Data Source =" + Application::StartupPath + "\\tableMASS.mdb");
			MessageBox::Show("База данных создана", "БД", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
		catch (System::Runtime::InteropServices::COMException^ situation) {
			MessageBox::Show(situation->Message);
		}
		finally{
			x = nullptr;
		}
	}
	void Array1::create_struct() {
		auto p = gcnew OleDbConnection("Provider = Microsoft.Jet.OLEDB.4.0; Data Source =" + Application::StartupPath + "\\tableMASS.mdb");
		p->Open();
		auto c = gcnew OleDbCommand("CREATE TABLE Tabl(Индекс counter, [Отсортированный Массив] char(200))", p);
		try {
			c->ExecuteNonQuery();
			MessageBox::Show("База Данных Структурирована", "БД", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
		catch (System::Data::OleDb::OleDbException^ situation) {
			MessageBox::Show(situation->Message);
		}
		p->Close();
	}
	void Array1::add_znach(int* mas, int n) {
		auto p = gcnew OleDbConnection("Provider = Microsoft.Jet.OLEDB.4.0; Data Source =" + Application::StartupPath + "\\tableMASS.mdb");
		p->Open();
		try {
			for (int i = 0; i < n; i++) {
				auto cc = gcnew OleDbCommand("INSERT INTO Tabl(Индекс, [Отсортированный Массив]) VALUES('" + i + "','" + mas[i] + "')");
				cc->Connection = p;
				cc->ExecuteNonQuery();
			}
			MessageBox::Show("База Данных Заполнена", "БД", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
		catch (System::Data::OleDb::OleDbException^ situation) {
			MessageBox::Show(situation->Message);
		}
		p->Close();
	}
}

