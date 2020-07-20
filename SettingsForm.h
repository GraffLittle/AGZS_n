#pragma once

namespace AGZS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// Сводка для SettingsForm
	/// </summary>
	public ref class SettingsForm : public System::Windows::Forms::Form
	{
	public:
		SettingsForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			array<String^>^ ports = SerialPort::GetPortNames();
			ComBox->Items->Clear();
			ComBox->Items->AddRange(ports);
			ComBox->SelectedItem = ComBox->Items[ComBox->Items->Count - 1];
			ComBox->Text = ports[ports->Length - 1];
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label5;
	//private: System::Windows::Forms::Label^ lblPL;
	public: System::Windows::Forms::Button^ UpdateBtn;
	//private: System::Windows::Forms::Label^ lblT;
	private: System::Windows::Forms::Label^ label7;
	//private: System::Windows::Forms::Label^ lblLM;
	private: System::Windows::Forms::Label^ label11;
	//private: System::Windows::Forms::Label^ lblIL;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ lblDT;
	public: System::Windows::Forms::Label^ lblPL;
	public: System::Windows::Forms::Label^ lblT;
	public: System::Windows::Forms::Label^ lblLM;
	public: System::Windows::Forms::Label^ lblIL;
	private: System::Windows::Forms::Label^ lbl1i;
	private: System::Windows::Forms::Label^ lbl2i;
	private: System::Windows::Forms::Label^ lbl3i;
	private: System::Windows::Forms::Label^ lbl4i;
	public: System::Windows::Forms::CheckBox^ check1i;
	public: System::Windows::Forms::CheckBox^ check4i;
	public: System::Windows::Forms::CheckBox^ check3i;
	public: System::Windows::Forms::CheckBox^ check2i;
	private: System::Windows::Forms::Timer^ InfTimer;
	public:
	private: System::IO::Ports::SerialPort^ SerialComPort;
		   String^ comStr;
		   String^ errStr;
		   String^ ReceivedPacket, ^ _Received;
		   String^ pStr, ^ tStr, ^ ilStr, ^ lmStr, ^ unStr; // - Info answers: $18.50,t36.6,I/L400,"l1.25 L/M5.5500"
	public: System::Windows::Forms::CheckBox^ checkPusk;
	public: System::Windows::Forms::CheckBox^ checkLog;
	public: System::Windows::Forms::CheckBox^ checkStop;
	private:
		   String^ lastOuted;
	private: void OutReceived(void); // Analizing comStr
	private: void ErrReceived(void); // Analizing errStr
	private: int _InfoStage;
	public: System::Windows::Forms::Form^ MForm;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	protected:
	public: System::Windows::Forms::ComboBox^ ComBox;
	private:
	private: System::Windows::Forms::Label^ label1;
	public:
	public: System::Windows::Forms::TextBox^ CostBox;
	private: System::Windows::Forms::Button^ ApplyBtn;
	private: System::ComponentModel::IContainer^ components;
	public:
	private:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ComBox = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->CostBox = (gcnew System::Windows::Forms::TextBox());
			this->ApplyBtn = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->check4i = (gcnew System::Windows::Forms::CheckBox());
			this->check3i = (gcnew System::Windows::Forms::CheckBox());
			this->check2i = (gcnew System::Windows::Forms::CheckBox());
			this->check1i = (gcnew System::Windows::Forms::CheckBox());
			this->lbl4i = (gcnew System::Windows::Forms::Label());
			this->lbl3i = (gcnew System::Windows::Forms::Label());
			this->lbl2i = (gcnew System::Windows::Forms::Label());
			this->lbl1i = (gcnew System::Windows::Forms::Label());
			this->lblDT = (gcnew System::Windows::Forms::Label());
			this->lblLM = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->lblIL = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->lblT = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->UpdateBtn = (gcnew System::Windows::Forms::Button());
			this->lblPL = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->InfTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SerialComPort = (gcnew System::IO::Ports::SerialPort(this->components));
			this->checkPusk = (gcnew System::Windows::Forms::CheckBox());
			this->checkLog = (gcnew System::Windows::Forms::CheckBox());
			this->checkStop = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(46, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"COM№";
			// 
			// ComBox
			// 
			this->ComBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ComBox->FormattingEnabled = true;
			this->ComBox->Location = System::Drawing::Point(95, 39);
			this->ComBox->Name = L"ComBox";
			this->ComBox->Size = System::Drawing::Size(121, 21);
			this->ComBox->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(28, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Цена/литр:";
			// 
			// CostBox
			// 
			this->CostBox->Location = System::Drawing::Point(95, 12);
			this->CostBox->Name = L"CostBox";
			this->CostBox->Size = System::Drawing::Size(121, 21);
			this->CostBox->TabIndex = 5;
			// 
			// ApplyBtn
			// 
			this->ApplyBtn->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->ApplyBtn->Location = System::Drawing::Point(104, 345);
			this->ApplyBtn->Name = L"ApplyBtn";
			this->ApplyBtn->Size = System::Drawing::Size(75, 23);
			this->ApplyBtn->TabIndex = 9;
			this->ApplyBtn->Text = L"Принять";
			this->ApplyBtn->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(12, 91);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(262, 88);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Юстировка";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(148, 49);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(22, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"МЛ";
			this->label4->Click += gcnew System::EventHandler(this, &SettingsForm::label4_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(148, 21);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(22, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"МЛ";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(181, 47);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Залито";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &SettingsForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(181, 21);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Залить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SettingsForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(16, 49);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(126, 21);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &SettingsForm::textBox2_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(16, 21);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(126, 21);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &SettingsForm::textBox1_TextChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->check4i);
			this->groupBox2->Controls->Add(this->check3i);
			this->groupBox2->Controls->Add(this->check2i);
			this->groupBox2->Controls->Add(this->check1i);
			this->groupBox2->Controls->Add(this->lbl4i);
			this->groupBox2->Controls->Add(this->lbl3i);
			this->groupBox2->Controls->Add(this->lbl2i);
			this->groupBox2->Controls->Add(this->lbl1i);
			this->groupBox2->Controls->Add(this->lblDT);
			this->groupBox2->Controls->Add(this->lblLM);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->lblIL);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->lblT);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->UpdateBtn);
			this->groupBox2->Controls->Add(this->lblPL);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Location = System::Drawing::Point(12, 185);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(262, 154);
			this->groupBox2->TabIndex = 11;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Информация";
			this->groupBox2->Enter += gcnew System::EventHandler(this, &SettingsForm::groupBox2_Enter);
			// 
			// check4i
			// 
			this->check4i->AutoSize = true;
			this->check4i->Location = System::Drawing::Point(218, 95);
			this->check4i->Name = L"check4i";
			this->check4i->Size = System::Drawing::Size(15, 14);
			this->check4i->TabIndex = 17;
			this->check4i->UseVisualStyleBackColor = true;
			// 
			// check3i
			// 
			this->check3i->AutoSize = true;
			this->check3i->Location = System::Drawing::Point(218, 69);
			this->check3i->Name = L"check3i";
			this->check3i->Size = System::Drawing::Size(15, 14);
			this->check3i->TabIndex = 16;
			this->check3i->UseVisualStyleBackColor = true;
			// 
			// check2i
			// 
			this->check2i->AutoSize = true;
			this->check2i->Location = System::Drawing::Point(218, 44);
			this->check2i->Name = L"check2i";
			this->check2i->Size = System::Drawing::Size(15, 14);
			this->check2i->TabIndex = 15;
			this->check2i->UseVisualStyleBackColor = true;
			// 
			// check1i
			// 
			this->check1i->AutoSize = true;
			this->check1i->Location = System::Drawing::Point(218, 20);
			this->check1i->Name = L"check1i";
			this->check1i->Size = System::Drawing::Size(15, 14);
			this->check1i->TabIndex = 14;
			this->check1i->UseVisualStyleBackColor = true;
			// 
			// lbl4i
			// 
			this->lbl4i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->lbl4i->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lbl4i->Location = System::Drawing::Point(239, 93);
			this->lbl4i->Name = L"lbl4i";
			this->lbl4i->Size = System::Drawing::Size(17, 17);
			this->lbl4i->TabIndex = 13;
			this->lbl4i->Text = L"4i";
			this->lbl4i->Click += gcnew System::EventHandler(this, &SettingsForm::lbl4i_Click);
			// 
			// lbl3i
			// 
			this->lbl3i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->lbl3i->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lbl3i->Location = System::Drawing::Point(239, 70);
			this->lbl3i->Name = L"lbl3i";
			this->lbl3i->Size = System::Drawing::Size(17, 17);
			this->lbl3i->TabIndex = 12;
			this->lbl3i->Text = L"3i";
			this->lbl3i->Click += gcnew System::EventHandler(this, &SettingsForm::lbl3i_Click);
			// 
			// lbl2i
			// 
			this->lbl2i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->lbl2i->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lbl2i->Location = System::Drawing::Point(239, 45);
			this->lbl2i->Name = L"lbl2i";
			this->lbl2i->Size = System::Drawing::Size(17, 17);
			this->lbl2i->TabIndex = 11;
			this->lbl2i->Text = L"2i";
			this->lbl2i->Click += gcnew System::EventHandler(this, &SettingsForm::lbl2i_Click);
			// 
			// lbl1i
			// 
			this->lbl1i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->lbl1i->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lbl1i->Location = System::Drawing::Point(239, 21);
			this->lbl1i->Name = L"lbl1i";
			this->lbl1i->Size = System::Drawing::Size(17, 17);
			this->lbl1i->TabIndex = 10;
			this->lbl1i->Text = L"1i";
			this->lbl1i->Click += gcnew System::EventHandler(this, &SettingsForm::lbl1i_Click);
			// 
			// lblDT
			// 
			this->lblDT->AutoSize = true;
			this->lblDT->Location = System::Drawing::Point(97, 125);
			this->lblDT->Name = L"lblDT";
			this->lblDT->Size = System::Drawing::Size(52, 13);
			this->lblDT->TabIndex = 9;
			this->lblDT->Text = L"Updated:";
			// 
			// lblLM
			// 
			this->lblLM->AutoSize = true;
			this->lblLM->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblLM->Location = System::Drawing::Point(92, 95);
			this->lblLM->Name = L"lblLM";
			this->lblLM->Size = System::Drawing::Size(26, 15);
			this->lblLM->TabIndex = 8;
			this->lblLM->Text = L"L/M";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(7, 95);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(84, 13);
			this->label11->TabIndex = 7;
			this->label11->Text = L"Литр в минуту:";
			// 
			// lblIL
			// 
			this->lblIL->AutoSize = true;
			this->lblIL->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblIL->Location = System::Drawing::Point(92, 70);
			this->lblIL->Name = L"lblIL";
			this->lblIL->Size = System::Drawing::Size(22, 15);
			this->lblIL->TabIndex = 6;
			this->lblIL->Text = L"I/L";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(7, 70);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(76, 13);
			this->label9->TabIndex = 5;
			this->label9->Text = L"Имп. на литр:";
			// 
			// lblT
			// 
			this->lblT->AutoSize = true;
			this->lblT->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblT->Location = System::Drawing::Point(92, 45);
			this->lblT->Name = L"lblT";
			this->lblT->Size = System::Drawing::Size(15, 15);
			this->lblT->TabIndex = 4;
			this->lblT->Text = L"T";
			this->lblT->Click += gcnew System::EventHandler(this, &SettingsForm::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(7, 45);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(77, 13);
			this->label7->TabIndex = 3;
			this->label7->Text = L"Tемпература:";
			// 
			// UpdateBtn
			// 
			this->UpdateBtn->Location = System::Drawing::Point(6, 125);
			this->UpdateBtn->Name = L"UpdateBtn";
			this->UpdateBtn->Size = System::Drawing::Size(85, 23);
			this->UpdateBtn->TabIndex = 2;
			this->UpdateBtn->Text = L"Обновить все";
			this->UpdateBtn->UseVisualStyleBackColor = true;
			this->UpdateBtn->Click += gcnew System::EventHandler(this, &SettingsForm::button3_Click);
			// 
			// lblPL
			// 
			this->lblPL->AutoSize = true;
			this->lblPL->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblPL->Location = System::Drawing::Point(92, 21);
			this->lblPL->Name = L"lblPL";
			this->lblPL->Size = System::Drawing::Size(24, 15);
			this->lblPL->TabIndex = 1;
			this->lblPL->Text = L"P/L";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(7, 21);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(78, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Цена за литр:";
			// 
			// InfTimer
			// 
			this->InfTimer->Tick += gcnew System::EventHandler(this, &SettingsForm::InfTimer_Tick);
			// 
			// SerialComPort
			// 
			this->SerialComPort->ErrorReceived += gcnew System::IO::Ports::SerialErrorReceivedEventHandler(this, &SettingsForm::SerialComPort_ErrorReceived);
			this->SerialComPort->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &SettingsForm::SerialComPort_DataReceived);
			// 
			// checkPusk
			// 
			this->checkPusk->AutoSize = true;
			this->checkPusk->Location = System::Drawing::Point(12, 68);
			this->checkPusk->Name = L"checkPusk";
			this->checkPusk->Size = System::Drawing::Size(62, 17);
			this->checkPusk->TabIndex = 12;
			this->checkPusk->Text = L"\"ПУСК\"";
			this->checkPusk->UseVisualStyleBackColor = true;
			// 
			// checkLog
			// 
			this->checkLog->AutoSize = true;
			this->checkLog->Location = System::Drawing::Point(151, 68);
			this->checkLog->Name = L"checkLog";
			this->checkLog->Size = System::Drawing::Size(140, 17);
			this->checkLog->TabIndex = 13;
			this->checkLog->Text = L"Вести лог обмена СОМ";
			this->checkLog->UseVisualStyleBackColor = true;
			// 
			// checkStop
			// 
			this->checkStop->AutoSize = true;
			this->checkStop->Location = System::Drawing::Point(80, 68);
			this->checkStop->Name = L"checkStop";
			this->checkStop->Size = System::Drawing::Size(62, 17);
			this->checkStop->TabIndex = 14;
			this->checkStop->Text = L"\"СТОП\"";
			this->checkStop->UseVisualStyleBackColor = true;
			// 
			// SettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(286, 376);
			this->Controls->Add(this->checkStop);
			this->Controls->Add(this->checkLog);
			this->Controls->Add(this->checkPusk);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->ApplyBtn);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->ComBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->CostBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"SettingsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Настройки";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &SettingsForm::SettingsForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &SettingsForm::SettingsForm_Load);
			this->Shown += gcnew System::EventHandler(this, &SettingsForm::SettingsForm_Shown);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void SettingsForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void SettingsForm_Shown(System::Object^ sender, System::EventArgs^ e);

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e); // UpdateBtn
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void lbl1i_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void lbl2i_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void lbl3i_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void lbl4i_Click(System::Object^ sender, System::EventArgs^ e);
	public: System::Void StartInfo(void);
	public: System::Void StopInfo(void);
private: System::Void SettingsForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
private: System::Void SerialComPort_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e);
private: System::Void SerialComPort_ErrorReceived(System::Object^ sender, System::IO::Ports::SerialErrorReceivedEventArgs^ e);
private: System::Void InfTimer_Tick(System::Object^ sender, System::EventArgs^ e);
	   System::Void PortWrite(String^ s);
	   System::Void LogReceived(String^ s);
};
}
