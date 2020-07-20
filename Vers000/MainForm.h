#pragma once

namespace AGZS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic; // for Dictionary
	using namespace System::IO;
	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			toolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainForm::SetBtn_Click); // L"Настройки";
			toolStripMenuItem3->Click += gcnew System::EventHandler(this, &MainForm::UsersBtn_Click); // L"Операторы";
			toolStripMenuItem4->Click += gcnew System::EventHandler(this, &MainForm::InfoBtn_Click); // L"Информация";
			toolStripMenuItem5->Click += gcnew System::EventHandler(this, &MainForm::AddBtn_Click); // L"Добавить ТРК";
			toolStripMenuItem7->Click += gcnew System::EventHandler(this, &MainForm::DelBtn_Click); // Удалить ТРК
			toolStripMenuItem6->Click += gcnew System::EventHandler(this, &MainForm::CloseBtn_Click); // L"Выход";
			smenaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::SmenaMenu_Click);
			//
			//TODO: добавьте код конструктора
			//
			cost = 0.0; // 0.277;
			LitrCost = 0.1;
			kols = 0;
			KolNum = 1;
			MakeDicts();
			LogedAs = "";
			_UserLevel = -1;
			ReadIni();
			MakeComs();
			ActiveKolPanel = nullptr;
			LogAbout();
		}
	public: String^ UserNmKey(String^ user) {
		for each (String ^ key in this->names->Keys) {
			if (this->names[key] == user) { return key; }
		}
		return "";
	}
	public: void SetUserNamePass(String^ userName, String^ userPass) {
		String^ nm = UserNmKey(userName);
		if (nm == "") {
			this->names->Add(this->names->Count.ToString(), userName);
			nm = UserNmKey(userName);
			this->pass->Add(nm, userPass);
		}
		else this->pass[nm] = userPass;
	}
	public: void AddUser(String^ userName, String^ userPass) {
		SetUserNamePass(userName, userPass);
		this->SaveIni(false);
		String^ nm = UserNmKey(userName);
		AddAction( nm, "NewUser", userName + "(" + nm + "-" + userPass + ")");
	}
	public: void ChangeUserPass(String^ userName, String^ userPass) {
		SetUserNamePass(userName, userPass);
		this->SaveIni(false);
		String^ nm = UserNmKey(userName);
		AddAction( nm, "ChangeUserPass", userName + "(" + nm + "-" + userPass + ")");
	}
	private: void MakeDicts(void) {
		this->pass = gcnew Dictionary<String^, String^>(StringComparer::InvariantCultureIgnoreCase);
		this->pass["Admin"] = "admin"; // "ADmin123"
		this->pass["Operator"] = ""; // "123";
		this->pass["User"] = "";
		this->names = gcnew Dictionary<String^, String^>(StringComparer::InvariantCultureIgnoreCase);
		this->names["Admin"] = "Администратор";
		this->names["Operator"] = "Оператор";
		this->names["User"] = "Пользователь";
	}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			/*System.NullReferenceException: HResult=0x80004003, Сообщение = Ссылка на объект не указывает на экземпляр объекта.*/
			if (sw != nullptr) sw->Close();
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ DemoTimer;

	private: System::Windows::Forms::ToolTip^ AddToolTip;
	private: System::Windows::Forms::Label^ UserLabel;
	private: System::Windows::Forms::Panel^ KolPanel;

	public: System::Windows::Forms::Panel^ ActiveKolPanel;

	private: System::ComponentModel::IContainer^ components;

	private:
		int kols; // Kolonka number

	public:
		double cost; // цена за литр
		bool ShowPusk, ShowStop;
		Dictionary<String^, String^>^ pass;
	public:

	public: System::IO::Ports::SerialPort^ serialPort1;
		  System::Void PortWrite(String^ s);
		  System::Void PortWrite(wchar_t c);
		  System::Void LogReceived(String^ s);
	private:
		double lastL, lastS;
		void ShowChangeCalculator(void);

	public:
		String^ comStr;
		String^ errStr;
		String^ ReceivedPacket, ^_Received;
		String ^pStr, ^tStr, ^ilStr, ^lmStr, ^unStr; // - Info answers: $18.50,t36.6,I/L400,"l1.25 L/M5.5500"
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem5;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem6;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem7;
	private: System::Windows::Forms::ToolStripMenuItem^ smenaToolStripMenuItem;

	   String^ lastOuted;
	private: void OutReceived(void); // Analizing comStr
	private: void ErrReceived(void); // Analizing errStr

	public:
		Dictionary<String^, String^>^ names;
		bool ClearDict(Dictionary<String^, String^>^ d);

	public:
		void StartFuel(String^ Mode); // - for Demo mode
		void StartFuel(int mode, String^ data, String^ modeStr);
		void StartFuel(int mode, double data);
		void StartFuel(double data, String^ modeStr);
		void StartFuel(int kNum, double data, String^ modeStr);
		void StopFuel(void);
		void StopFuel(String^ Lit);
		void StopFuel(double lit);
	private: // From ./AGZS.ini:
		int KolNum;
		double LitrCost; // цена за литр
		String^ LogedAs;

	private: System::Void LogAbout(void);
	public: // About loging port operations
		bool doLogPort;
		StreamWriter^ sw;

	private: // Operations/access level
		int _UserLevel; // Admin, Operator, User == {0,1,2}
	public:
		void putLevel(int L); // Released in MainForm.cpp - { _UserLevel = L; }
		int getLevel(); // Released in MainForm.cpp - { return _UserLevel; }

	private:
		void ShowInfo(bool save);
		void _ShowActionsIn(RichTextBox^ InfoText, String^ forUser);
		System::Void MainForm::AddActionDBF(String^ User, String^ Act, String^ Add);
		System::Void MainForm::AddActionMDB(String^ User, String^ Act, String^ Add);
		System::Void MainForm::AddActionXML(String^ User, String^ Act, String^ Add);
		System::Void MainForm::AddAction(String^ User, String^ Act, String^ Add) {
			AddActionDBF(User, Act, Add);
			AddActionMDB(User,Act, Add);
			AddActionXML(User, Act, Add);
		}
		System::Void MainForm::DBaboutDBF(void);
		System::Void MainForm::DBaboutMDB(void);
		System::Void MainForm::DBaboutXML(void);
		System::Void MainForm::DBabout(void) { DBaboutDBF(); DBaboutMDB(); DBaboutXML();  }
		void SaveIni(bool is0); // Released in MainForm.cpp
		void ReadIni(void); // Released in MainForm.cpp
		void MakeComs(void) {
			for (int i = KolNum; i > 0; i--) AddKol(i);
			kols = KolNum;
			AdjustSize();
		}
		void AdjustSize(void);
		void AddKol(void); // Now in MainForm.cpp
		void AddKol(int num);
		void DelKol(void);

	protected:
	private: // Вы вошли как:


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->DemoTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->AddToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->UserLabel = (gcnew System::Windows::Forms::Label());
			this->KolPanel = (gcnew System::Windows::Forms::Panel());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem7 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem6 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->smenaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// DemoTimer
			// 
			this->DemoTimer->Interval = 1000;
			this->DemoTimer->Tick += gcnew System::EventHandler(this, &MainForm::DemoTimer_Tick);
			// 
			// UserLabel
			// 
			this->UserLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->UserLabel->Dock = System::Windows::Forms::DockStyle::Top;
			this->UserLabel->Location = System::Drawing::Point(0, 24);
			this->UserLabel->Name = L"UserLabel";
			this->UserLabel->Size = System::Drawing::Size(236, 18);
			this->UserLabel->TabIndex = 3;
			this->UserLabel->Text = L"Смена:";
			// 
			// KolPanel
			// 
			this->KolPanel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->KolPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->KolPanel->Location = System::Drawing::Point(0, 42);
			this->KolPanel->Name = L"KolPanel";
			this->KolPanel->Size = System::Drawing::Size(236, 272);
			this->KolPanel->TabIndex = 4;
			// 
			// serialPort1
			// 
			this->serialPort1->ErrorReceived += gcnew System::IO::Ports::SerialErrorReceivedEventHandler(this, &MainForm::serialPort1_ErrorReceived);
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MainForm::serialPort1_DataReceived);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripMenuItem1,
					this->smenaToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(236, 24);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->toolStripMenuItem2,
					this->toolStripMenuItem3, this->toolStripMenuItem4, this->toolStripMenuItem5, this->toolStripMenuItem7, this->toolStripMenuItem6
			});
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(48, 20);
			this->toolStripMenuItem1->Text = L"Меню";
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(146, 22);
			this->toolStripMenuItem2->Text = L"Настройки";
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(146, 22);
			this->toolStripMenuItem3->Text = L"Операторы";
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(146, 22);
			this->toolStripMenuItem4->Text = L"Информация";
			// 
			// toolStripMenuItem5
			// 
			this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
			this->toolStripMenuItem5->Size = System::Drawing::Size(146, 22);
			this->toolStripMenuItem5->Text = L"Добавить ТРК";
			// 
			// toolStripMenuItem7
			// 
			this->toolStripMenuItem7->Name = L"toolStripMenuItem7";
			this->toolStripMenuItem7->Size = System::Drawing::Size(146, 22);
			this->toolStripMenuItem7->Text = L"Удалить ТРК";
			// 
			// toolStripMenuItem6
			// 
			this->toolStripMenuItem6->Name = L"toolStripMenuItem6";
			this->toolStripMenuItem6->Size = System::Drawing::Size(146, 22);
			this->toolStripMenuItem6->Text = L"Выход";
			// 
			// smenaToolStripMenuItem
			// 
			this->smenaToolStripMenuItem->Name = L"smenaToolStripMenuItem";
			this->smenaToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->smenaToolStripMenuItem->Text = L"Смена";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(236, 314);
			this->Controls->Add(this->KolPanel);
			this->Controls->Add(this->UserLabel);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Управление АГЗС";
			this->Shown += gcnew System::EventHandler(this, &MainForm::MainForm_Shown);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::MainForm_KeyPress);
			this->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &MainForm::MainForm_PreviewKeyDown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CloseBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if ((this->KolNum != this->kols) || (this->LitrCost != this->cost))
			this->SaveIni(false);
		if (!DemoTimer->Enabled)
			this->Close();
		else if	(MessageBox::Show("Идет заправка! Прервать?", "Процесс", MessageBoxButtons::YesNo) ==
			System::Windows::Forms::DialogResult::Yes)
				this->Close();
	}
	private: System::Void SetBtn_Click(System::Object^ sender, System::EventArgs^ e);  // Now in MainForm.cpp
	private: System::Void MainForm_Shown(System::Object^ sender, System::EventArgs^ e); // Released in MainForm.cpp
	private: System::Void DemoBtn_Click(System::Object^ sender, System::EventArgs^ e) { // Not used any more.
		DemoTimer->Enabled = !DemoTimer->Enabled;
		if (DemoTimer->Enabled) {
			for (int i = 0; i < KolPanel->Controls->Count; i++);
		}
	}
	private: System::Void DemoTimer_Tick(System::Object^ sender, System::EventArgs^ e); // Now in MainForm.cpp
	private: System::Void AddBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		AddKol();
		AdjustSize();
	}
	   System::Void DelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		   DelKol();
		   AdjustSize();
	   }
	   void aboutItem_Click(System::Object^ sender, System::EventArgs^ e) {
		   MessageBox::Show("О программе");
	   }

// Not used here any more - now in TKolPanel::Panel_Click()
private: System::Void KolPanel_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("KolPanel_Click(" + sender->ToString() + "-" + sender->GetType() + ")", L"Click");
}
private: System::Void AddBtn_MouseHover(System::Object^ sender, System::EventArgs^ e) { // AddBtn hint
	//AddToolTip->SetToolTip(AddBtn, "Добавить колонку");
}
private: System::Void MainForm_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
private: System::Void MainForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {}
private: System::Void MainForm_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e) {}
private: System::Void SetBtn_MouseHover(System::Object^ sender, System::EventArgs^ e) {
	//AddToolTip->SetToolTip(SetBtn, "Настройки");
}
private: System::Void CloseBtn_MouseHover(System::Object^ sender, System::EventArgs^ e) {
	//AddToolTip->SetToolTip(CloseBtn, "Закрыть");
}
private: System::Void Usersbtn_MouseHover(System::Object^ sender, System::EventArgs^ e) {
	//AddToolTip->SetToolTip(UsersBtn, "Пользователи");
}
private: System::Void UsersBtn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void InfoBtn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void InfoBtn_MouseHover(System::Object^ sender, System::EventArgs^ e) {
	//AddToolTip->SetToolTip(InfoBtn, "Информация");
}
private: System::Void serialPort1_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e);
private: System::Void serialPort1_ErrorReceived(System::Object^ sender, System::IO::Ports::SerialErrorReceivedEventArgs^ e);

private: System::Void SmenaMenu_Click(System::Object^ sender, System::EventArgs^ e);

public: System::Void SendE(void); //Command to start fuel
public: System::Void SendS(void); //Command to stop fuel
};
}
