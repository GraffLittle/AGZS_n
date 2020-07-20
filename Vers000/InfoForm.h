#pragma once

namespace AGZS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class TInfoForm : public System::Windows::Forms::Form {
	public: TInfoForm(System::Windows::Forms::Form^ M_Form, String^ user) {
		InitializeComponent();
		MForm = M_Form;
		Text = user;
	}
	void InitializeComponent(void) {
		InfoTextBox = gcnew System::Windows::Forms::RichTextBox();
		InfoTextBox->Multiline = true;
		InfoTextBox->AutoSize = false; // true;
		InfoTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
		InfoTextBox->Text = L"Info:";
		this->Controls->Add(InfoTextBox);
		this->Text = L"Info";
		this->Location = System::Drawing::Point(1, 1);
		this->Size = System::Drawing::Size(700, 500);
	}
	protected:
		System::Windows::Forms::Form^ MForm;
	public:
		System::Windows::Forms::RichTextBox^ InfoTextBox;
	public:
		  void putText(String^ T) { this->InfoTextBox->Text = T; }
		  String^ getText() { return this->InfoTextBox->Text; }
		  void addText(String^ T) { this->InfoTextBox->Text += T; }
		  void FormatText(String^ T) {
			  int f = -1;
			  while ((f = InfoTextBox->Find(T, f+1, RichTextBoxFinds::WholeWord)) >= 0) {
			  InfoTextBox->SelectionFont = gcnew System::Drawing::Font("Verdana", 12, FontStyle::Bold);
			  InfoTextBox->SelectionColor = Color::Red;
			  }
		  }
	};
}
