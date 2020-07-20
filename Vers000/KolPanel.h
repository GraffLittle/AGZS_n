#pragma once
#include "MainForm.h"
#include "FuelForm.h"
#include "ComAbout.h"

namespace AGZS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class TKolPanel : public System::Windows::Forms::Panel
	{
	private: int FKolNum;
		   double cost; // цена за литр
		   MainForm^ FMain;
		   double NowFuel, MaxFuel;
		   double FAccepted;
		   bool isFuelComing;
	public: bool isFuel;
		  int getKolNum(void) { return FKolNum; }
		  double getAccepted(void) { return FAccepted; }
	private: System::Windows::Forms::Label^ NumLabel;
	private: System::Windows::Forms::Label^ FuelLabel;
	private: System::Windows::Forms::Label^ Cost0Label;
	private: System::Windows::Forms::Label^ Cost1Label;
	private: System::Windows::Forms::Label^ InfoLabel;
	private: System::Windows::Forms::Button^ PuskBtn; // Big gorizontal single
	private: System::Windows::Forms::Button^ StopBtn; // Big gorizontal single
	public:
		TKolPanel(void)
		{
			InitializeComponent();
		}
		TKolPanel(int KolNum, double _Cost, MainForm^ MF)
		{
			FKolNum = KolNum;
			cost = _Cost;
			FMain = MF;
			isFuel = false;
			NowFuel = 0.0;  MaxFuel = 0.0;
			InitializeComponent();
			Cost0Label->Text = cost.ToString();
			this->PuskBtn->Visible = MF->ShowPusk;
			this->StopBtn->Visible = MF->ShowStop;
		}
		void PutFuel(double f) { this->NowFuel = f; }
		void StopFuel(void) {
			this->isFuel = false; InfoLabel->Text = "Остановлено";
			StopFuel(NowFuel); // - to enable buttons PUSK, STOP
		}
		void MakeFuel(double f) {
			this->NowFuel = f;
			this->FuelLabel->Text = this->NowFuel.ToString();
			this->Cost1Label->Text = (NowFuel * cost).ToString();
			if (NowFuel >= MaxFuel) {
				this->isFuel = false;
				FMain->StopFuel(this->NowFuel);
				MessageBox::Show("Колонка " + FKolNum + " заправлена! (" + this->NowFuel.ToString() + "L)");
			}
		}
		void MakeFuel(double f, double c);
		void StartFuel(void);
		void StartFuel(double f);
		void StartFuel(double f, double c);
		void StopFuel(double f);
		void StopFuel(double f, double c);
		void GetFuel(void) { // for Demo
			this->NowFuel += 0.3;
		}
		void NewCost(double newc) {
			this->cost = newc;
			Cost0Label->Text = cost.ToString();
		}
		void SetVisPuskBtn(bool _new) {	this->PuskBtn->Visible = _new; }
		void SetVisStopBtn(bool _new) {	this->StopBtn->Visible = _new; }
		void SetInfo(String^ str, System::Drawing::Color back, System::Drawing::Color fore) {
			InfoLabel->BackColor = back;
			InfoLabel->ForeColor = fore;
			InfoLabel->Text = str;
			InfoLabel->Update();
		}
		void SetInfo(String^ str, System::Drawing::Color back) {
			SetInfo(str, back, InfoLabel->ForeColor);
		}
		void SetInfo(String^ str) {
			SetInfo(str, InfoLabel->BackColor);
		}

		void MakeFuel(void) { // for Demo mode (DemoTimer)
			if (!this->isFuel) return;
			GetFuel();
			this->FuelLabel->Text = this->NowFuel.ToString();
			this->Cost1Label->Text = (NowFuel*cost).ToString();
			if (NowFuel >= MaxFuel) {
				this->isFuel = false;
				FMain->StopFuel(this->NowFuel);
				MessageBox::Show("Колонка " + FKolNum + " заправлена! (" + this->NowFuel.ToString() + "L)");
			}
		}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	public: System::Void Panel_Click(System::Object^ sender, System::EventArgs^ e);

		  private: System::Windows::Forms::Label^ MakeLabel1() { // Name label
			  return gcnew System::Windows::Forms::Label();
		  }
		  private: System::Windows::Forms::Label^ MakeLabel2() { // Value label
			  return gcnew System::Windows::Forms::Label();
		  }
		  private: System::Windows::Forms::Label^ MakeLabel(System::Windows::Forms::Panel^ Owner,
			  System::Windows::Forms::DockStyle dock,
			  System::Drawing::Color back, System::Drawing::Color fore) {
			  System::Windows::Forms::Label^ Label = gcnew System::Windows::Forms::Label();
			  Label->BackColor = back;
			  Label->Font = (gcnew System::Drawing::Font(L"Tahoma", 25,
				  System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Pixel,
				  static_cast<System::Byte>(204)));
			  Label->ForeColor = fore;
			  Label->Location = System::Drawing::Point(1, 1);
			  Label->Size = System::Drawing::Size(110, 30);
			  Label->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			  Label->Dock = dock;
			  Label->Parent = Owner;
			  Label->Click += gcnew System::EventHandler(this, &TKolPanel::Panel_Click);
			  return Label;
		  }
		  private:
			  System::Windows::Forms::Panel^ MakePanel(interior_ptr<System::Windows::Forms::Label^> lbl, String^ s) {
			  System::Windows::Forms::Panel^ Panel = (gcnew System::Windows::Forms::Panel());
			  Panel->Location = System::Drawing::Point(0, 0);
			  Panel->Size = System::Drawing::Size(120, 37);
			  Panel->Parent = this;
			  Panel->Dock = System::Windows::Forms::DockStyle::Top;
			  // надписи Литры, Сумма, Цена, сделать синим цветом
			  System::Windows::Forms::Label^ L1 = MakeLabel( Panel, System::Windows::Forms::DockStyle::Left,
				  Control::DefaultBackColor, Color::Blue);
			  L1->Text = s;
			  // цифровые значения этих надписей с расного заменить на зеленый цвет
			  *lbl = MakeLabel( Panel, System::Windows::Forms::DockStyle::Fill, System::Drawing::Color::Black,
				  System::Drawing::Color::Green);
			  return Panel;
		  }
			private:
			  System::Windows::Forms::Button^ MakeButton(String^ name) {
				  System::Windows::Forms::Button^ btn = gcnew System::Windows::Forms::Button();
				  btn->BackColor = System::Drawing::Color::LightBlue;
				  btn->Font = (gcnew System::Drawing::Font(L"Verdana", 25,
					  System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Pixel,
					  static_cast<System::Byte>(204)));
				  btn->Text = name;
				  btn->Size = System::Drawing::Size(101, 40); //34
				  btn->Dock = System::Windows::Forms::DockStyle::Top;
				  btn->Parent = this;
				  return btn;
			  }

	protected:
		/// Освободить все используемые ресурсы.
		~TKolPanel()
		{
			delete this->Controls;
		}
		void InitializeComponent(void) {
			this->SuspendLayout();
			this->Name = L"panel" + FKolNum;
			this->Size = System::Drawing::Size(237, 260);
			this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->BackColor = System::Drawing::SystemColors::GrayText;
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			StopBtn = MakeButton(L"СТОП");
			StopBtn->Click += gcnew System::EventHandler(this, &TKolPanel::button2_Click);
			// Button PUSK - Big gorizontal single:
			PuskBtn = MakeButton(L"ПУСК");
			PuskBtn->Click += gcnew System::EventHandler(this, &TKolPanel::button1_Click);
			// Labels:
			InfoLabel = (gcnew System::Windows::Forms::Label());
			InfoLabel->Text = L"Информация";
			InfoLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 25,
				System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Pixel,
				static_cast<System::Byte>(204)));
			InfoLabel->Location = System::Drawing::Point(98, 36);
			InfoLabel->Name = L"InfoLabel";
			InfoLabel->Size = System::Drawing::Size(101, 38);
			InfoLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			InfoLabel->Dock = System::Windows::Forms::DockStyle::Top;
			InfoLabel->Parent = this;
			InfoLabel->Click += gcnew System::EventHandler(this, &TKolPanel::Panel_Click);
			MakePanel(&Cost0Label, L"ЦЕНА"); Cost0Label->Text = L"0.0";
			MakePanel(&Cost1Label, L"СУММА"); Cost1Label->Text = L"0.0";
			MakePanel(&FuelLabel, L"ЛИТРЫ"); FuelLabel->Text = L"0.0";
			// Label 2
			NumLabel = (gcnew System::Windows::Forms::Label());
			NumLabel->Text = L"Колонка №" + FKolNum;
			NumLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 25,
				System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Pixel,
				static_cast<System::Byte>(204)));
			NumLabel->Location = System::Drawing::Point(98, 36);
			NumLabel->Name = L"NumLabel";
			NumLabel->Size = System::Drawing::Size(101, 38); //30
			NumLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			NumLabel->Dock = System::Windows::Forms::DockStyle::Top;
			NumLabel->Parent = this;
			NumLabel->Click += gcnew System::EventHandler(this, &TKolPanel::Panel_Click);
			this->Click += gcnew System::EventHandler(this, &TKolPanel::Panel_Click);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
	};
}
