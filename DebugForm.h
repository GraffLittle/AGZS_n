#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace AGZS_dbg{

	ref class TDebugForm : public System::Windows::Forms::Form {
	public: TDebugForm(void) {
		DebugTextBox = gcnew System::Windows::Forms::TextBox();
		DebugTextBox->Multiline = true;
		DebugTextBox->AutoSize = false; // true;
		DebugTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
		DebugTextBox->Text = L"Debug info:";
		DebugTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
		this->Controls->Add(DebugTextBox);
		this->Text = L"DEBUG";
		this->Location = System::Drawing::Point(1, 1);
		this->Name = L"DF";
		this->Size = System::Drawing::Size(500, 500);
	}
	public: System::Windows::Forms::TextBox^ DebugTextBox;
	void putText(String^ T) { this->DebugTextBox->Text = T; }
	String^ getText() { return this->DebugTextBox->Text; }
	void addText(String^ T) { this->DebugTextBox->Text += T; }
	};
}

private ref class Helper
{
public:
	static AGZS_dbg::TDebugForm^ DF = gcnew AGZS_dbg::TDebugForm();
	static System::Void addText(String^ txt) { DF->addText(txt); }
	static void putText(String^ T) { DF->putText(T); }
};
