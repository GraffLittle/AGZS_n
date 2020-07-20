#include "FuelForm.h"
#include "DebugForm.h"
#include "Utils.h"

using namespace AGZS;

void FuelForm::ShowForChange(int kolnum, double accepted) {
	Debug::Print("FuelForm::ShowForChange( " + kolnum + ", " + accepted + ")");
	this->Text = "Сдача";
	KolNumLabel->Text = "Колонка N" + kolnum;
	this->HowGroupBox->Enabled = false;
	this->StartBtn->Enabled = false;
	this->CancelBtn->Enabled = false;
	this->Method = 2;
	String^ accstr = String::Format("{0:0.00}", accepted);
	this->GotTextBox->Text = accstr;
	ShowingForChange = true;
	ShowDialog();
}

System::Void FuelForm::GotTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	try {
		ConvertAnyToDouble(this->GotTextBox->Text);
		if (HowGroupBox->Enabled) this->ChangeBtn->Enabled = true;
		ChangeBtn_Click(sender,e);
	}
	catch (FormatException^ ex) {
		this->ChangeBtn->Enabled = false;
		Helper::addText("\r\n-FormatException: " + ex->ToString());
	}
}
System::Void FuelForm::ChangeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	double got = ConvertAnyToDouble(this->GotTextBox->Text);; // Accepted
	String^ Mode = "";
	double MaxFuel = 0.0, p = 0; // p == Price
	switch (Method) { // ~По литрам, !На сумму, =До заполнения
	case 1:
		Mode = "~По литрам:" + textBox1->Text;
		MaxFuel = ConvertAnyToDouble(textBox1->Text);
		p = MaxFuel * lCost;
		break;
	case 2:
		Mode = "!На сумму:" + textBox2->Text;
		p = ConvertAnyToDouble(textBox2->Text);
		MaxFuel = p / lCost;
		break;
	case 3:
		MaxFuel = 999.0;
		Mode = "=До заполнения: 999.0";
		p = MaxFuel * lCost;
		break;
	default: // 0!
		Mode = "0.0";
		//break;
	}
	double ch = got - p;
	String^ str = String::Format("{0:0.00}", ch);
	this->ChangeLbl->Text = "Сдача: " + str;
}
