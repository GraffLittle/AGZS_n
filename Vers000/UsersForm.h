#pragma once

namespace AGZS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для UsersForm
	/// </summary>
	public ref class UsersForm : public System::Windows::Forms::Form
	{
	public:
		UsersForm(void)
		{
			MForm = nullptr;
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		UsersForm(System::Windows::Forms::Form^ M_Form) {
			MForm = M_Form;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~UsersForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	public: System::Windows::Forms::TextBox^ ParolTextBox;
	public: System::Windows::Forms::ListBox^ UserList;
	private:
	protected:
		System::Windows::Forms::Form^ MForm;


	public:

	private: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::TextBox^ UserTextBox;
	private: System::Windows::Forms::Label^ HintLabel;
	private: System::Windows::Forms::Button^ PassBtn;
	private: System::Windows::Forms::Button^ AddUserBtn;
	public:

	public:
	private: bool inEditMode;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ParolTextBox = (gcnew System::Windows::Forms::TextBox());
			this->UserList = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->UserTextBox = (gcnew System::Windows::Forms::TextBox());
			this->HintLabel = (gcnew System::Windows::Forms::Label());
			this->PassBtn = (gcnew System::Windows::Forms::Button());
			this->AddUserBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 184);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Пароль:";
			// 
			// ParolTextBox
			// 
			this->ParolTextBox->Enabled = false;
			this->ParolTextBox->Location = System::Drawing::Point(63, 181);
			this->ParolTextBox->Name = L"ParolTextBox";
			this->ParolTextBox->Size = System::Drawing::Size(211, 21);
			this->ParolTextBox->TabIndex = 5;
			this->ParolTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &UsersForm::ParolTextBox_KeyPress);
			// 
			// UserList
			// 
			this->UserList->Dock = System::Windows::Forms::DockStyle::Top;
			this->UserList->FormattingEnabled = true;
			this->UserList->Location = System::Drawing::Point(0, 0);
			this->UserList->Name = L"UserList";
			this->UserList->Size = System::Drawing::Size(286, 121);
			this->UserList->TabIndex = 8;
			this->UserList->SelectedIndexChanged += gcnew System::EventHandler(this, &UsersForm::UserList_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 157);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Пользователь:";
			// 
			// UserTextBox
			// 
			this->UserTextBox->Enabled = false;
			this->UserTextBox->Location = System::Drawing::Point(98, 154);
			this->UserTextBox->Name = L"UserTextBox";
			this->UserTextBox->Size = System::Drawing::Size(176, 21);
			this->UserTextBox->TabIndex = 10;
			// 
			// HintLabel
			// 
			this->HintLabel->AutoSize = true;
			this->HintLabel->Dock = System::Windows::Forms::DockStyle::Top;
			this->HintLabel->Location = System::Drawing::Point(0, 121);
			this->HintLabel->Name = L"HintLabel";
			this->HintLabel->Size = System::Drawing::Size(142, 13);
			this->HintLabel->TabIndex = 12;
			this->HintLabel->Text = L"Выберите пользователя ^";
			// 
			// PassBtn
			// 
			this->PassBtn->Location = System::Drawing::Point(12, 208);
			this->PassBtn->Name = L"PassBtn";
			this->PassBtn->Size = System::Drawing::Size(105, 23);
			this->PassBtn->TabIndex = 13;
			this->PassBtn->Text = L"Изменить пароль";
			this->PassBtn->UseVisualStyleBackColor = true;
			this->PassBtn->Click += gcnew System::EventHandler(this, &UsersForm::PassBtn_Click);
			// 
			// AddUserBtn
			// 
			this->AddUserBtn->Location = System::Drawing::Point(142, 208);
			this->AddUserBtn->Name = L"AddUserBtn";
			this->AddUserBtn->Size = System::Drawing::Size(132, 23);
			this->AddUserBtn->TabIndex = 14;
			this->AddUserBtn->Text = L"Добавить оператора";
			this->AddUserBtn->UseVisualStyleBackColor = true;
			this->AddUserBtn->Click += gcnew System::EventHandler(this, &UsersForm::AddUserBtn_Click);
			// 
			// UsersForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(286, 241);
			this->Controls->Add(this->AddUserBtn);
			this->Controls->Add(this->PassBtn);
			this->Controls->Add(this->HintLabel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->UserTextBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ParolTextBox);
			this->Controls->Add(this->UserList);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"UsersForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Пользователи";
			this->Load += gcnew System::EventHandler(this, &UsersForm::UsersForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void UserList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e); // {}
private: System::Void AddUserBtn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void PassBtn_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void UsersForm_Load(System::Object^ sender, System::EventArgs^ e) {
	inEditMode = false;
	this->UserList->SelectedIndex = 0;
}
private: System::Void ParolTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!(((e->KeyChar >= '0') && (e->KeyChar <= '9')) || ((e->KeyChar >= 'a') && (e->KeyChar <= 'z')) ||
		((e->KeyChar >= 'A') && (e->KeyChar <= 'Z')) || (e->KeyChar == ',') || (e->KeyChar == '.')))
			{ e->Handled = true; }
}
};
}
