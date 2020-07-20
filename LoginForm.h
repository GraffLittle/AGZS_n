#pragma once

namespace AGZS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ OKbtn;
	private: System::Windows::Forms::Button^ CancelBtn;
	public: System::Windows::Forms::ListBox^ UserListBox;
	public: System::Windows::Forms::TextBox^ ParolTextBox;
	private: System::Windows::Forms::Label^ label1;
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
			this->OKbtn = (gcnew System::Windows::Forms::Button());
			this->CancelBtn = (gcnew System::Windows::Forms::Button());
			this->UserListBox = (gcnew System::Windows::Forms::ListBox());
			this->ParolTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// OKbtn
			// 
			this->OKbtn->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->OKbtn->Location = System::Drawing::Point(54, 111);
			this->OKbtn->Name = L"OKbtn";
			this->OKbtn->Size = System::Drawing::Size(75, 23);
			this->OKbtn->TabIndex = 1;
			this->OKbtn->Text = L"Войти";
			this->OKbtn->UseVisualStyleBackColor = true;
			// 
			// CancelBtn
			// 
			this->CancelBtn->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelBtn->Location = System::Drawing::Point(170, 111);
			this->CancelBtn->Name = L"CancelBtn";
			this->CancelBtn->Size = System::Drawing::Size(75, 23);
			this->CancelBtn->TabIndex = 2;
			this->CancelBtn->Text = L"Отмена";
			this->CancelBtn->UseVisualStyleBackColor = true;
			// 
			// UserListBox
			// 
			this->UserListBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->UserListBox->FormattingEnabled = true;
			this->UserListBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Admin", L"Operator", L"User" });
			this->UserListBox->Location = System::Drawing::Point(0, 0);
			this->UserListBox->Name = L"UserListBox";
			this->UserListBox->Size = System::Drawing::Size(329, 69);
			this->UserListBox->TabIndex = 3;
			this->UserListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &LoginForm::UserListBox_SelectedIndexChanged);
			// 
			// ParolTextBox
			// 
			this->ParolTextBox->Location = System::Drawing::Point(66, 75);
			this->ParolTextBox->Name = L"ParolTextBox";
			this->ParolTextBox->Size = System::Drawing::Size(251, 21);
			this->ParolTextBox->TabIndex = 0;
			this->ParolTextBox->UseSystemPasswordChar = true;
			this->ParolTextBox->TextChanged += gcnew System::EventHandler(this, &LoginForm::ParolTextBox_TextChanged);
			this->ParolTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &LoginForm::ParolTextBox_KeyPress);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Пароль:";
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(329, 148);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ParolTextBox);
			this->Controls->Add(this->UserListBox);
			this->Controls->Add(this->CancelBtn);
			this->Controls->Add(this->OKbtn);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Аутентификация";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ParolTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void UserListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void ParolTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == (char)Keys::Enter)
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
}
};
}
