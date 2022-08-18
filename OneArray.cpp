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
		MessageBox::Show("����� ������� = "+Summ, "�����", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
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
		MessageBox::Show("���������� �������  - " + a + "\n��� ������� -" + k, "����������", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
	
	//��� ������� ������ ����������:
	//1) ����� ����� k ����������� �������� �������.
	//2) �������� ��� �������� �������, ������� � k-��, �� ���� ������� �����.
	void Array1::Algorithm3(int* mas, int &n) {
		int k = 0;
		for (int i = 1; i < n; i++) {
			if (mas[i] > mas[k])
				k = i;
		}
		for (int i = k; i < n - 1; i++)
			mas[i] = mas[i + 1];
		n--;
		MessageBox::Show("�������� ������������ �����" + mas[k], "������������", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
	
	// �������������� ��������� �������:
	// 1) ������ k ��������� ������� �������� ��� ���������;
	// 2) ��� ��������, ������� � (k + 1)-�� ���������� �������� ������, �����
	// ���������� ����� ��� ������������ ��������;
	// 3) �������� � ������� (k + 1) ��������� �������� m. ���������� ���������
	// ������� ��������� �� 1.
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
	
	// ����� �� ������ ���� ���������� � �� ������� (�� ���������)
	// ��������� ��������������� ������������������ �� ��� ���, ���� �� �����
	// ������� ����� ���������.
	// Left - ����� ������� ���������������� �������
	// Right - ������
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
	
	// � ������� ���������� ���������� �������. ���������� �������
	// ������������ �� i-� ����� ��������� �������, � ������� � i-�� �����
	// ������������ �� ����� ����������. ����� �������� �����������.
	// ������������� �������� ����������� �� ���������� ����������, �������
	// ����� ����������� ���������������� ������� ������ ���� �� ���� �������
	// ������ �����������.
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
	
	// ������� � ����� �������, ���������� ��� �������� �������� (a[n] � a[n � 1]).
	// ���� ����������� ������� a[n � 1] > a[n], �� �������� ���������
	// �������� �������. ������� ������������ ��� a[n � 1] � a[n � 2] � �. �., ����
	// �� ����� ����������� ��������� a[2] � a[1]. ����� ����� �� ����� a[1] ��������
	// ������� ������� � ���������� ���������.
	// �� ������ ���� ������� �����������, �� ���������� ������������ a[3]
	// � a[2]. �� ��������� ���� ����� ������������ ������ �������� a[n] � a[n � 1].
	// ������� �������� � ���������, ��������� ���������� �������� (�����
	// �������) ���������� ���������� � ������� ������� �������.
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
	
	// ����������, ������������ �� ��
	// ������ ������� �����-���� �����. ���� ���, �� �������� ����� ���������
	// ���� ������.
	// ����� ���������� Flag = 1, ���� �� ��������� ���� ��� �������� �����
	// ���������, � Flag = 0, ���� ������ �� ����
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
			MessageBox::Show("��������� ������������" + Flag, "�����", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		else
			MessageBox::Show("��������� ��������� " + Flag, "�����", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
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
			MessageBox::Show("������������� ������� ������������" + Flag, "�����", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		else
			MessageBox::Show("������������� �������� �����������" + Flag, "�����", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}


	void Array1::create_tab() {
		ADOX::Catalog^ x = gcnew ADOX::CatalogClass();
		try {
			x->Create("Provider = Microsoft.Jet.OLEDB.4.0; Data Source =" + Application::StartupPath + "\\tableMASS.mdb");
			MessageBox::Show("���� ������ �������", "��", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
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
		auto c = gcnew OleDbCommand("CREATE TABLE Tabl(������ counter, [��������������� ������] char(200))", p);
		try {
			c->ExecuteNonQuery();
			MessageBox::Show("���� ������ ���������������", "��", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
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
				auto cc = gcnew OleDbCommand("INSERT INTO Tabl(������, [��������������� ������]) VALUES('" + i + "','" + mas[i] + "')");
				cc->Connection = p;
				cc->ExecuteNonQuery();
			}
			MessageBox::Show("���� ������ ���������", "��", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
		catch (System::Data::OleDb::OleDbException^ situation) {
			MessageBox::Show(situation->Message);
		}
		p->Close();
	}
}

