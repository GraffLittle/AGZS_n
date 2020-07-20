#include "UsersForm.h"
#include "MainForm.h"

namespace AGZS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	System::Void UsersForm::UserList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		MainForm^ MF = dynamic_cast<MainForm^>(this->MForm);
		if (UserList->SelectedItem) {
			String^ slctd = UserList->SelectedItem->ToString();
			String^ nm = MF->UserNmKey(slctd);
			this->ParolTextBox->Text = MF->pass[nm];
			this->UserTextBox->Text = slctd;
		} else {
			this->ParolTextBox->Text = "";
			this->UserTextBox->Text = "";
		}
	}
System::Void UsersForm::AddUserBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	MainForm^ MF = dynamic_cast<MainForm^>(this->MForm);
	if (inEditMode) {
		// Accept new operator (!)
		MF->AddUser(this->UserTextBox->Text, this->ParolTextBox->Text);
		this->Close();
	}
	else {
		this->AddUserBtn->Text = "Запомнить";
		this->PassBtn->Enabled = false;
		this->UserList->Enabled = false;
		this->UserList->SelectedIndex = -1;
		this->HintLabel->Text = "Задайте имя и пароль:";
		this->ParolTextBox->Enabled = true;
		this->UserTextBox->Enabled = true;
		this->UserTextBox->Focus();
		inEditMode = true;
	}
}
System::Void UsersForm::PassBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	MainForm^ MF = dynamic_cast<MainForm^>(this->MForm);
	if (inEditMode) {
		// Change user password
		MF->ChangeUserPass(this->UserTextBox->Text, this->ParolTextBox->Text);
		this->Close();
	}
	else {
		this->PassBtn->Text = "Запомнить";
		this->AddUserBtn->Enabled = false;
		this->UserList->Enabled = false;
		this->HintLabel->Text = "Задайте новый пароль (англ):";
		this->UserList->Enabled = false;
		this->ParolTextBox->Enabled = true;
		this->ParolTextBox->Focus();
		inEditMode = true;
	}
}
}
