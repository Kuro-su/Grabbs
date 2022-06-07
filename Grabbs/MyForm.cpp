#include "MyForm.h"
#include <Windows.h>
#include <cmath>

using namespace Grabbs; // Название проекта

const static int count = 10;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

int findMax(int arr[10]) {
	int max = arr[0];

	for (int i = 1; i < 10; i++)
		if (arr[i] > max)
			max = arr[i];

	return max;
}

System::Void Grabbs::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	int a[10];
	double b[10];
	double c[10];
	double sum = 0;
	double sum_c = 0;
	double mid;
	double S; //Среднее квадратическое отклонение 
	double max;
	double G1;

	a[0] = { Convert::ToInt32(this->numericUpDown1->Value) };
	a[1] = { Convert::ToInt32(this->numericUpDown2->Value) };
	a[2] = { Convert::ToInt32(this->numericUpDown3->Value) };
	a[3] = { Convert::ToInt32(this->numericUpDown4->Value) };
	a[4] = { Convert::ToInt32(this->numericUpDown5->Value) };
	a[5] = { Convert::ToInt32(this->numericUpDown6->Value) };
	a[6] = { Convert::ToInt32(this->numericUpDown7->Value) };
	a[7] = { Convert::ToInt32(this->numericUpDown8->Value) };
	a[8] = { Convert::ToInt32(this->numericUpDown9->Value) };
	a[9] = { Convert::ToInt32(this->numericUpDown10->Value) };

	for (int i = 0; i < 10; i++)
		sum += a[i];

	mid = sum / count;

	for (int i = 0; i < 10; i++) {
		b[i] = a[i] - mid;
		c[i] = pow(b[i], 2);
		sum_c += c[i];
	}

	S = sqrt(sum_c / (sum - 1)); //Среднее квадратическое отклонение 
	max = findMax(a);

	G1 = (max - mid) / S;

	textBox1->Text = System::Convert::ToString(a[0]);
	textBox2->Text = System::Convert::ToString(a[1]);
	textBox3->Text = System::Convert::ToString(a[2]);
	textBox4->Text = System::Convert::ToString(a[3]);
	textBox5->Text = System::Convert::ToString(a[4]);
	textBox6->Text = System::Convert::ToString(a[5]);
	textBox7->Text = System::Convert::ToString(a[6]);
	textBox8->Text = System::Convert::ToString(a[7]);
	textBox9->Text = System::Convert::ToString(a[8]);
	textBox10->Text = System::Convert::ToString(a[9]);
	
	textBox11->Text = System::Convert::ToString(b[0]);
	textBox12->Text = System::Convert::ToString(b[1]);
	textBox13->Text = System::Convert::ToString(b[2]);
	textBox14->Text = System::Convert::ToString(b[3]);
	textBox15->Text = System::Convert::ToString(b[4]);
	textBox16->Text = System::Convert::ToString(b[5]);
	textBox17->Text = System::Convert::ToString(b[6]);
	textBox18->Text = System::Convert::ToString(b[7]);
	textBox19->Text = System::Convert::ToString(b[8]);
	textBox20->Text = System::Convert::ToString(b[9]);
	
	textBox21->Text = System::Convert::ToString(c[0]);
	textBox22->Text = System::Convert::ToString(c[1]);
	textBox23->Text = System::Convert::ToString(c[2]);
	textBox24->Text = System::Convert::ToString(c[3]);
	textBox25->Text = System::Convert::ToString(c[4]);
	textBox26->Text = System::Convert::ToString(c[5]);
	textBox27->Text = System::Convert::ToString(c[6]);
	textBox28->Text = System::Convert::ToString(c[7]);
	textBox29->Text = System::Convert::ToString(c[8]);
	textBox30->Text = System::Convert::ToString(c[9]);

	textBox31->Text = System::Convert::ToString(mid);
	textBox32->Text = System::Convert::ToString(S);
	textBox33->Text = System::Convert::ToString(G1);

	return System::Void();
}


