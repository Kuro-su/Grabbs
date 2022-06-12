#include "MyForm.h"
#include "MyForm1.h"
#include <Windows.h>
#undef min
#undef max
#include <cmath>
#include <vector>

using namespace Grabbs; // Название проекта

const static int count = 10;
std::vector<double> v;
std::vector<double> b;
std::vector<double> c;

double table[147] = {
0.1,
0.1,
1.148,
1.425,
1.602,
1.729,
1.828,
1.909,
1.977,
2.036,
2.088,
2.134,
2.175,
2.213,
2.247,
2.279,
2.309,
2.335,
2.361,
2.385,
2.408,
2.429,
2.448,
2.467,
2.486,
2.502,
2.519,
2.534,
2.549,
2.563,
2.577,
2.591,
2.604,
2.616,
2.628,
2.639,
2.65,
2.661,
2.671,
2.682,
2.692,
2.700,
2.710,
2.719,
2.727,
2.736,
2.744,
2.753,
2.760,
2.768,
2.775,
2.783,
2.790,
2.798,
2.804,
2.811,
2.818,
2.824,
2.831,
2.837,
2.842,
2.849,
2.854,
2.860,
2.866,
2.871,
2.875,
2.880,
2.888,
2.893,
2.897,
2.903,
2.908,
2.912,
2.917,
2.922,
2.927,
2.931,
2.935,
2.940,
2.945,
2.949,
2.953,
2.957,
2.961,
2.966,
2.970,
2.973,
2.977,
2.981,
2.984,
2.989,
2.993,
2.996,
3.000,
3.003,
3.007,
3.011,
3.014,
3.017,
3.021,
3.024,
3.027,
3.030,
3.033,
3.037,
3.040,
3.043,
3.046,
3.049,
3.052,
3.055,
3.058,
3.061,
3.064,
3.067,
3.070,
3.073,
3.075,
3.078,
3.081,
3.083,
3.086,
3.089,
3.092,
3.095,
3.097,
3.100,
3.102,
3.104,
3.107,
3.109,
3.112,
3.114,
3.116,
3.119,
3.122,
3.124,
3.126,
3.129,
3.131,
3.133,
3.135,
3.138,
3.140,
3.142,
3.144,
};

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);

	return 0;
}

double findMax(std::vector<double> vt) {
	double max = v[0];

	for (int i = 1; i < v.size(); i++)
		if (v[i] > max)
			max = v[i];

	return max;
}

System::Void Grabbs::MyForm1::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
	return System::Void();
}

System::Void Grabbs::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	//double a[10];
	/*double b[10];
	double c[10];*/
	double sum = 0;
	double sum_c = 0;
	double mid;
	double S; //Среднее квадратическое отклонение 
	double max;
	double G1;

	/*a[0] = { Convert::ToDouble(this->numericUpDown1->Value) };
	a[1] = { Convert::ToDouble(this->numericUpDown2->Value) };
	a[2] = { Convert::ToDouble(this->numericUpDown3->Value) };
	a[3] = { Convert::ToDouble(this->numericUpDown4->Value) };
	a[4] = { Convert::ToDouble(this->numericUpDown5->Value) };
	a[5] = { Convert::ToDouble(this->numericUpDown6->Value) };
	a[6] = { Convert::ToDouble(this->numericUpDown7->Value) };
	a[7] = { Convert::ToDouble(this->numericUpDown8->Value) };
	a[8] = { Convert::ToDouble(this->numericUpDown9->Value) };
	a[9] = { Convert::ToDouble(this->numericUpDown10->Value) };*/

	for (int i = 0; i < v.size(); i++)
		sum += v[i];

	mid = sum / count;

	for (int i = 0; i < v.size(); i++) {
		b.push_back(v[i] - mid);
		c.push_back(pow(b[i], 2));
		sum_c += c[i];
	}

	S = sqrt(sum_c / (sum - 1)); //Среднее квадратическое отклонение 
	max = findMax(v);

	G1 = (max - mid) / S;

	/*textBox1->Text = System::Convert::ToString(a[0]);
	textBox2->Text = System::Convert::ToString(a[1]);
	textBox3->Text = System::Convert::ToString(a[2]);
	textBox4->Text = System::Convert::ToString(a[3]);
	textBox5->Text = System::Convert::ToString(a[4]);
	textBox6->Text = System::Convert::ToString(a[5]);
	textBox7->Text = System::Convert::ToString(a[6]);
	textBox8->Text = System::Convert::ToString(a[7]);
	textBox9->Text = System::Convert::ToString(a[8]);
	textBox10->Text = System::Convert::ToString(a[9]);*/
	/*for(int i = 0; i < v.size(); i++)
		this->textBox35->Text = this->textBox35->Text + " " + v[i];*/

	/*textBox11->Text = System::Convert::ToString(b[0]);
	textBox12->Text = System::Convert::ToString(b[1]);
	textBox13->Text = System::Convert::ToString(b[2]);
	textBox14->Text = System::Convert::ToString(b[3]);
	textBox15->Text = System::Convert::ToString(b[4]);
	textBox16->Text = System::Convert::ToString(b[5]);
	textBox17->Text = System::Convert::ToString(b[6]);
	textBox18->Text = System::Convert::ToString(b[7]);
	textBox19->Text = System::Convert::ToString(b[8]);
	textBox20->Text = System::Convert::ToString(b[9]);*/
	
	for (int i = 0; i < b.size(); i++)
		this->textBox35->Text = this->textBox35->Text + " " + b[i];

	/*textBox21->Text = System::Convert::ToString(c[0]);
	textBox22->Text = System::Convert::ToString(c[1]);
	textBox23->Text = System::Convert::ToString(c[2]);
	textBox24->Text = System::Convert::ToString(c[3]);
	textBox25->Text = System::Convert::ToString(c[4]);
	textBox26->Text = System::Convert::ToString(c[5]);
	textBox27->Text = System::Convert::ToString(c[6]);
	textBox28->Text = System::Convert::ToString(c[7]);
	textBox29->Text = System::Convert::ToString(c[8]);
	textBox30->Text = System::Convert::ToString(c[9]);*/

	MyForm1^ mf1 = gcnew MyForm1();

	for (int i = 0; i < c.size(); i++)
		this->textBox36->Text = this->textBox36->Text + " " + c[i];

	textBox31->Text = System::Convert::ToString(mid);
	textBox32->Text = System::Convert::ToString(S);
	textBox33->Text = System::Convert::ToString(G1);
	
	mf1->chart1->Series[0]->Points->Clear();
	for(int i = 0; i < b.size(); i++)
		mf1->chart1->Series[0]->Points->AddXY(b[i], i);

	if (G1 > table[v.size() - 1]) {
		auto result = remove(v.begin(), v.end(), max);
		v.erase(result, v.end());
		textBox1->Text = System::Convert::ToString(max) + " - Жойылды!";
	}
	else
		textBox1->Text = "Жок";

	mf1->Show();
	////////////////////////////////////////////////////////////////
	for (int i = 0; i < v.size(); i++)
		textBox4->Text = textBox4->Text + " " + v[i];

	for (int i = 0; i < v.size(); i++)
		sum += v[i];

	mid = sum / count;

	for (int i = 0; i < v.size(); i++) {
		b.push_back(v[i] - mid);
		c.push_back(pow(b[i], 2));
		sum_c += c[i];
	}

	S = sqrt(sum_c / (sum - 1)); //Среднее квадратическое отклонение 
	max = findMax(v);

	G1 = (max - mid) / S;

	for (int i = 0; i < b.size(); i++)
		this->textBox3->Text = this->textBox3->Text + " " + b[i];

	mf1 = gcnew MyForm1();

	for (int i = 0; i < c.size(); i++)
		this->textBox2->Text = this->textBox36->Text + " " + c[i];

	textBox8->Text = System::Convert::ToString(mid);
	textBox7->Text = System::Convert::ToString(S);
	textBox6->Text = System::Convert::ToString(G1);

	mf1->chart1->Series[0]->Points->Clear();

	for (int i = 0; i < b.size(); i++)
		mf1->chart1->Series[0]->Points->AddXY(b[i], i);

	if (G1 > table[v.size() - 1]) {
		auto result = remove(v.begin(), v.end(), max);
		v.erase(result, v.end());
		textBox5->Text = System::Convert::ToString(max) + " - Жойылды!";
	}
	else
		textBox5->Text = "Жок";

	mf1->chart1->Series[0]->Name = "Итерация 2";
	mf1->Show();

	v.clear();
	b.clear();
	c.clear();

	return System::Void();
}

System::Void Grabbs::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	v.push_back(Convert::ToInt32(this->numericUpDown11->Text));

	this->textBox34->Text = this->textBox34->Text + " " + this->numericUpDown11->Text;
	
	return System::Void();
}


