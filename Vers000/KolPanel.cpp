#include "KolPanel.h"
#include "DebugForm.h"
#include "Utils.h"

namespace AGZS {

	System::Void TKolPanel::button1_Click(System::Object^ sender, System::EventArgs^ e) { // PUSK
		if (!this->isFuelComing)
			this->FMain->SendE();
	}
	System::Void TKolPanel::button2_Click(System::Object^ sender, System::EventArgs^ e) { // STOP
		if (isFuelComing) {
			this->FMain->SendS();
			isFuelComing = false;
		}
	}
	System::Void TKolPanel::Panel_Click(System::Object^ sender, System::EventArgs^ e) {
		FuelForm^ ff = gcnew FuelForm(this->cost);
		ff->KolNumLabel->Text = "Колонка №" + FKolNum;
		if (ff->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (!ff->Method) {
				this->Invoke(gcnew Action<String^>(&Helper::addText), "-Cansel, NOT FuelForm->Method!");
				return;
			}
			String^ Mode = "";
			switch (ff->Method) { // ~По литрам, !На сумму, =До заполнения
			case 1:
				Mode = "~По литрам:" + ff->textBox1->Text;
				this->Invoke(gcnew Action<String^>(&Helper::addText), "\r\n" + Mode);
				this->MaxFuel = ConvertAnyToDouble(ff->textBox1->Text);
				Mode = "~:" + ff->textBox1->Text + "-" + this->MaxFuel.ToString();
				break;
			case 2:
				Mode = "!На сумму:" + ff->textBox2->Text;
				this->Invoke(gcnew Action<String^>(&Helper::addText), "\r\n" + Mode);
				this->MaxFuel = ConvertAnyToDouble(ff->textBox2->Text) / cost;
				MaxFuel = double(int(MaxFuel * 100)) / 100;
				Mode = "!:" + ff->textBox2->Text + "-" + this->MaxFuel.ToString();
				break;
			case 3:
				this->MaxFuel = 999.0;
				Mode = "=До заполнения:" + Convert::ToString(this->MaxFuel);
				this->Invoke(gcnew Action<String^>(&Helper::addText), "\r\n" + Mode);
				Mode = "=:" + this->MaxFuel.ToString();
				break;
			}
			this->NowFuel = 0.0;
			this->isFuel = true;
			this->FAccepted = ConvertAnyToDouble(ff->GotTextBox->Text);
			SetInfo("Нажмите ПУСК");
			FMain->ActiveKolPanel = this;
			//FMain->StartFuel(this->MaxFuel, Mode);
			FMain->StartFuel(FKolNum,this->MaxFuel, Mode);
			this->Invoke(gcnew Action<String^>(&Helper::addText),
				"\r\n FMain->StartFuel(" + this->MaxFuel.ToString() + ", " + Mode + ");");
		}
		else
			this->Invoke(gcnew Action<String^>(&Helper::addText), "\r\n-Fuel-Canseled!");
	}

	void TKolPanel::MakeFuel(double f, double c) {
		this->NowFuel = f;
		String^ str = String::Format("{0:0.00}", f);
		this->FuelLabel->Text = str;
		str = String::Format("{0:0.00}", c);
		this->Cost1Label->Text = str;
		if (NowFuel >= MaxFuel) {
			this->isFuel = false;
			SetInfo("Заправлено!");
			FMain->StopFuel(this->NowFuel);
			this->Invoke(gcnew Action<String^>(&Helper::addText), "\r\n Колонка " + FKolNum + " заправлена! (" +
				NowFuel.ToString() + ", " + MaxFuel.ToString() + "L)");
			isFuelComing = false;
		}
		else {
			isFuelComing = true;
			if (this->isFuel) {
				SetInfo("Идет заправка");
			}
		}
	}
	void TKolPanel::StartFuel(void) { // to disable buttons PUSK, STOP
		isFuelComing = true;
	}
	void TKolPanel::StartFuel(double f) { MaxFuel = f; StartFuel(); }
	void TKolPanel::StartFuel(double f, double c) { StartFuel(f); }
	void TKolPanel::StopFuel(double f) { // - to enable buttons PUSK, STOP
		isFuelComing = false;
	}
	void TKolPanel::StopFuel(double f, double c) { StopFuel(f); }

} // namespace AGZS
