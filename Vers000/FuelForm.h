#pragma once

namespace AGZS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// Сводка для FuelForm
	/// </summary>
	public ref class FuelForm : public System::Windows::Forms::Form
	{
	public:
		FuelForm(void)
		{
			InitializeComponent();
			Method = 0;
		}
		FuelForm(double lc)
		{
			lCost = lc;
			InitializeComponent();
			Method = 0;
		}
		FuelForm(System::Windows::Forms::Form^ Main) {
			MF = Main;
			InitializeComponent();
			Method = 0;
		}
		FuelForm(System::Windows::Forms::Panel^ P) {
			KP = P;
			InitializeComponent();
			Method = 0;
		}
		FuelForm(System::Windows::Forms::Form^ Main, System::Windows::Forms::Panel^ P) {
			MF = Main;
			KP = P;
			InitializeComponent();
			Method = 0;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FuelForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: double getMFCost(void) { return lCost; }

	private: System::Windows::Forms::Button^ StartBtn;
	private: System::Windows::Forms::Button^ CancelBtn;
	public: System::Windows::Forms::Label^ KolNumLabel;
	private: System::Windows::Forms::GroupBox^ HowGroupBox;

	private:
		   System::Windows::Forms::Form^ MF;
		   System::Windows::Forms::Panel^ KP;
		   double lCost;
		   bool ShowingForChange;
	public: int Method;
		  void ShowForChange(int kolnum, double accept);


	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	public: System::Windows::Forms::TextBox^ textBox2;
	public: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ CostLbl;
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::TextBox^ GotTextBox;
	private: System::Windows::Forms::Label^ ChangeLbl;
	private: System::Windows::Forms::Button^ ChangeBtn;

	public:
	public:
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->StartBtn = (gcnew System::Windows::Forms::Button());
			this->CancelBtn = (gcnew System::Windows::Forms::Button());
			this->KolNumLabel = (gcnew System::Windows::Forms::Label());
			this->HowGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->CostLbl = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->GotTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ChangeLbl = (gcnew System::Windows::Forms::Label());
			this->ChangeBtn = (gcnew System::Windows::Forms::Button());
			this->HowGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// StartBtn
			// 
			this->StartBtn->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->StartBtn->Enabled = false;
			this->StartBtn->Location = System::Drawing::Point(15, 336);
			this->StartBtn->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->StartBtn->Name = L"StartBtn";
			this->StartBtn->Size = System::Drawing::Size(138, 43);
			this->StartBtn->TabIndex = 1;
			this->StartBtn->Text = L"Начать";
			this->StartBtn->UseVisualStyleBackColor = true;
			// 
			// CancelBtn
			// 
			this->CancelBtn->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelBtn->Location = System::Drawing::Point(165, 335);
			this->CancelBtn->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->CancelBtn->Name = L"CancelBtn";
			this->CancelBtn->Size = System::Drawing::Size(138, 43);
			this->CancelBtn->TabIndex = 2;
			this->CancelBtn->Text = L"Отмена";
			this->CancelBtn->UseVisualStyleBackColor = true;
			// 
			// KolNumLabel
			// 
			this->KolNumLabel->Dock = System::Windows::Forms::DockStyle::Top;
			this->KolNumLabel->Location = System::Drawing::Point(0, 0);
			this->KolNumLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->KolNumLabel->Name = L"KolNumLabel";
			this->KolNumLabel->Size = System::Drawing::Size(326, 43);
			this->KolNumLabel->TabIndex = 3;
			this->KolNumLabel->Text = L"Колонка №";
			this->KolNumLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// HowGroupBox
			// 
			this->HowGroupBox->Controls->Add(this->textBox2);
			this->HowGroupBox->Controls->Add(this->textBox1);
			this->HowGroupBox->Controls->Add(this->radioButton3);
			this->HowGroupBox->Controls->Add(this->radioButton2);
			this->HowGroupBox->Controls->Add(this->radioButton1);
			this->HowGroupBox->Location = System::Drawing::Point(15, 48);
			this->HowGroupBox->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->HowGroupBox->Name = L"HowGroupBox";
			this->HowGroupBox->Padding = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->HowGroupBox->Size = System::Drawing::Size(301, 178);
			this->HowGroupBox->TabIndex = 5;
			this->HowGroupBox->TabStop = false;
			this->HowGroupBox->Text = L"Заливать";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(150, 83);
			this->textBox2->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(138, 32);
			this->textBox2->TabIndex = 4;
			this->textBox2->Text = L"0.0";
			this->textBox2->Enter += gcnew System::EventHandler(this, &FuelForm::textBox2_Enter);
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FuelForm::textBox2_KeyPress);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(150, 37);
			this->textBox1->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(138, 32);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"0.0";
			this->textBox1->Enter += gcnew System::EventHandler(this, &FuelForm::textBox1_Enter);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FuelForm::textBox1_KeyPress);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(14, 127);
			this->radioButton3->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(173, 28);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"До заполнения.";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &FuelForm::radioButton3_CheckedChanged);
			this->radioButton3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FuelForm::radioButton3_KeyPress);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(14, 84);
			this->radioButton2->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(121, 28);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"На сумму:";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &FuelForm::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(14, 38);
			this->radioButton1->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(132, 28);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"По литрам:";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &FuelForm::radioButton1_CheckedChanged);
			// 
			// CostLbl
			// 
			this->CostLbl->AutoSize = true;
			this->CostLbl->Location = System::Drawing::Point(11, 231);
			this->CostLbl->Name = L"CostLbl";
			this->CostLbl->Size = System::Drawing::Size(114, 24);
			this->CostLbl->TabIndex = 6;
			this->CostLbl->Text = L"Цена/литр:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 262);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 24);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Принято:";
			// 
			// GotTextBox
			// 
			this->GotTextBox->Location = System::Drawing::Point(124, 259);
			this->GotTextBox->Name = L"GotTextBox";
			this->GotTextBox->Size = System::Drawing::Size(179, 32);
			this->GotTextBox->TabIndex = 8;
			this->GotTextBox->TextChanged += gcnew System::EventHandler(this, &FuelForm::GotTextBox_TextChanged);
			this->GotTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FuelForm::GotTextBox_KeyPress);
			// 
			// ChangeLbl
			// 
			this->ChangeLbl->AutoSize = true;
			this->ChangeLbl->Location = System::Drawing::Point(12, 297);
			this->ChangeLbl->Name = L"ChangeLbl";
			this->ChangeLbl->Size = System::Drawing::Size(73, 24);
			this->ChangeLbl->TabIndex = 9;
			this->ChangeLbl->Text = L"Сдача:";
			// 
			// ChangeBtn
			// 
			this->ChangeBtn->Enabled = false;
			this->ChangeBtn->Location = System::Drawing::Point(265, 298);
			this->ChangeBtn->Name = L"ChangeBtn";
			this->ChangeBtn->Size = System::Drawing::Size(49, 29);
			this->ChangeBtn->TabIndex = 10;
			this->ChangeBtn->Text = L"<=";
			this->ChangeBtn->UseVisualStyleBackColor = true;
			this->ChangeBtn->Click += gcnew System::EventHandler(this, &FuelForm::ChangeBtn_Click);
			// 
			// FuelForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(326, 393);
			this->Controls->Add(this->ChangeBtn);
			this->Controls->Add(this->ChangeLbl);
			this->Controls->Add(this->GotTextBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->CostLbl);
			this->Controls->Add(this->HowGroupBox);
			this->Controls->Add(this->KolNumLabel);
			this->Controls->Add(this->CancelBtn);
			this->Controls->Add(this->StartBtn);
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->Name = L"FuelForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Заправить колонку";
			this->Load += gcnew System::EventHandler(this, &FuelForm::FuelForm_Load);
			this->Shown += gcnew System::EventHandler(this, &FuelForm::FuelForm_Shown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FuelForm::FuelForm_KeyPress);
			this->HowGroupBox->ResumeLayout(false);
			this->HowGroupBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (radioButton3->Checked) {
			Method = 3;
			StartBtn->Enabled = true;
		}
		Debug::Print("3.Method=" + Method.ToString());
	}
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (radioButton1->Checked) {
		textBox1->Focus();
		Method = 1;
		StartBtn->Enabled = true;
	}
	Debug::Print("1.Method=" + Method.ToString());
}
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (radioButton2->Checked) {
		textBox2->Focus();
		Method = 2;
		StartBtn->Enabled = true;
	}
	Debug::Print("2.Method=" + Method.ToString());
}
private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == (char)Keys::Enter)
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
}
private: System::Void textBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == (char)Keys::Enter)
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
}
private: System::Void textBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	radioButton1->Checked = true;
}
private: System::Void textBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
	radioButton2->Checked = true;
}
private: System::Void FuelForm_Load(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void FuelForm_Shown(System::Object^ sender, System::EventArgs^ e) {
	this->CostLbl->Text = "Цена/литр: " + this->lCost.ToString();
}
private: System::Void ChangeBtn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void GotTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void FuelForm_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	int key = e->KeyChar;
	Debug::Print("key=" + key.ToString());
	if (e->KeyChar == (char)Keys::Escape)
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
	if (e->KeyChar == (char)Keys::Enter)
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
}
private: System::Void GotTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	int key = e->KeyChar;
	Debug::Print("key=" + key.ToString());
	if (e->KeyChar == (char)Keys::Escape) // 'Escape' key == 27
		this->DialogResult = System::Windows::Forms::DialogResult::Yes;
	if (e->KeyChar == (char)Keys::Enter) // 'Enter' key == 13
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
}
private: System::Void radioButton3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == (char)Keys::Enter)
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
}
};
}
