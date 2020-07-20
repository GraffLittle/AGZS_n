#include "SettingsForm.h"
#include "MainForm.h"
#include "DebugForm.h"
#include "ComAbout.h"
#include "Utils.h"
#include "stdlib.h"

namespace AGZS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::IO::Ports;
	using namespace System::Threading;

System::Void SettingsForm::SettingsForm_Shown(System::Object^ sender, System::EventArgs^ e) {
	Helper::addText("\r\nSettingsForm::SettingsForm_Shown()");
	if (!this->SerialComPort->IsOpen) {
			Helper::addText("\r\nSettingsForm::SerialComPort not IsOpen!");
			doComOpen(this->SerialComPort, SerialComPort->PortName, Helper::DF->DebugTextBox);
	}
	if (this->SerialComPort->IsOpen) Helper::addText("\r\nSettingsForm::SerialComPort->IsOpen: " + this->SerialComPort->PortName);
}
System::Void SettingsForm::SettingsForm_Load(System::Object^ sender, System::EventArgs^ e) {
	Helper::addText("\r\nSettingsForm::SettingsForm_Load()");
	MainForm^ MF = dynamic_cast<MainForm^>(this->MForm);
	this->ComBox->Text = MF->serialPort1->PortName;
	if (!this->SerialComPort->IsOpen)
		doComOpen(this->SerialComPort, MF->serialPort1->PortName,Helper::DF->DebugTextBox);
	if (this->SerialComPort->IsOpen) Helper::addText("\r\nSettingsForm::SerialComPort->IsOpen: " + this->SerialComPort->PortName);
}
System::String^ correctDouble(System::String^ s) { return s; }
System::String^ correctPoint(System::String^ s) {
	String^ out = s;
	if (out->Contains(",")) {
		Helper::DF->addText("\r\n '" + out + "' contains ',' - replacing:");
		out = out->Replace(",", ".");
		Helper::DF->addText(" '" + out + "'");
	}
	return s;
}
System::String^ correctMLinL(System::String^ s) {
	String^ out = s;
	try {
		out = out->Replace(".", Globalization::NumberFormatInfo::CurrentInfo->NumberDecimalSeparator);
		out = out->Replace(",", Globalization::NumberFormatInfo::CurrentInfo->NumberDecimalSeparator);
		double dbl = ConvertAnyToDouble(out);
		dbl = dbl / 1000;
		out = dbl.ToString();
	}
	catch (FormatException^ ex) {
		Helper::DF->addText("\r\n-FormatException: " + ex->ToString() + "!\r\n toWrite=" + out + "!~!\r\n");
	}
	return out;
}
System::Void SettingsForm::button1_Click(System::Object^ sender, System::EventArgs^ e) { // Залить
	Helper::addText("\r\n~Залить" + textBox1->Text);
	//Значения милилитров пишем тысячами а отправляем в порт делённое на 1000 значение
	String^ toWrite = textBox1->Text;
	toWrite = correctPoint(correctMLinL(toWrite));
	toWrite = toWrite + ";p";
	PortWrite(toWrite);
	Helper::addText("\r\nMAKED: SerialComPort->Write(" + toWrite + ")-" + this->SerialComPort->ReadExisting());
}
System::Void SettingsForm::button2_Click(System::Object^ sender, System::EventArgs^ e) { // Залито
	String^ toWrite = textBox2->Text;
	Helper::addText("\r\n~Залитo!-" + toWrite);
	/*Калибровка точности колонки k9.789; (k маленькая, колличество реально залитого топлива в мерник)*/
	toWrite = correctPoint(correctMLinL(toWrite));
	toWrite = "k" + toWrite + ";";
	PortWrite(toWrite);
	Helper::addText("\r\nMAKED: SerialComPort->Write(" + toWrite + ")-" + this->SerialComPort->ReadExisting());
}
System::Void SettingsForm::StartInfo(void) {
	this->UpdateBtn->Enabled = false;
	UpdateBtn->Text = "Doing...";
	lbl1i->Enabled = false;
	lbl2i->Enabled = false;
	lbl3i->Enabled = false;
	lbl4i->Enabled = false;
	this->pStr = ""; this->tStr = ""; this->ilStr = ""; this->lmStr = "";
	this->_InfoStage = 0;
	this->InfTimer->Start();
}
System::Void SettingsForm::StopInfo(void) {
	this->InfTimer->Stop();
	this->InfTimer->Enabled = false;
	this->UpdateBtn->Enabled = true;
	UpdateBtn->Text = "Обновить все";
	lbl1i->Enabled = true;
	lbl2i->Enabled = true;
	lbl3i->Enabled = true;
	lbl4i->Enabled = true;
}
System::Void SettingsForm::button3_Click(System::Object^ sender, System::EventArgs^ e) { // UpdateBtn
	StartInfo();
	return;
	// 1i = P/L (lblPL), 2i = T (lblT), 3i = I/L (lblIL), 4i = L/M (lblLM)
	lblPL->Text = "цену за литр";
	lblT->Text = "температура сжиженного газа";
	lblIL->Text = "импульсов на литр";
	lblLM->Text = "расход литров в минуту";
	if (!SerialComPort->IsOpen) doComOpen(SerialComPort, SerialComPort->PortName);
	if (SerialComPort->IsOpen) {
		String^ dtstr = String::Format("{2:D2}.{1:D2}.{0:D4}-{3:D2}:{4:D2}:{5:D2}",
			DateTime::Now.Year, DateTime::Now.Month, DateTime::Now.Day,
			DateTime::Now.Hour, DateTime::Now.Minute, DateTime::Now.Second);
		Helper::addText("\r\n~Info started: " + dtstr);
		String^ was = lblPL->Text;
		if (check1i->Checked) {
			Helper::DF->addText("\r\n>check1i->Checked");
			PortWrite("1i");
			Thread::Sleep(750);
			lblPL->Text = pStr;
		}
		was = lblT->Text;
		if (check2i->Checked) {
			Helper::DF->addText("\r\n>check2i->Checked");
			PortWrite("2i");
			Thread::Sleep(750);
			lblPL->Text = tStr;
		}
		was = lblIL->Text;
		if (check3i->Checked) {
			Helper::DF->addText("\r\n>check3i->Checked");
			PortWrite("3i");
			Thread::Sleep(800);
			lblPL->Text = ilStr;
		}
		was = lblLM->Text;
		if (check4i->Checked) {
			Helper::DF->addText("\r\n>check4i->Checked");
			PortWrite("4i");
			Thread::Sleep(800);
			lblPL->Text = lmStr;
		}
		dtstr = String::Format("{0:D4}.{1:D2}.{2:D2}-{3:D2}:{4:D2}:{5:D2}",
			DateTime::Now.Year, DateTime::Now.Month, DateTime::Now.Day,
			DateTime::Now.Hour, DateTime::Now.Minute, DateTime::Now.Second);
		lblDT->Text = "Updated: " + dtstr;
	}
	else lblDT->Text = "CoM '" + SerialComPort->PortName + "' not opened.";
	StopInfo();
}
// 1i = P/L (lblPL), 2i = T (lblT), 3i = I/L (lblIL), 4i = L/M (lblLM)
System::Void SettingsForm::lbl1i_Click(System::Object^ sender, System::EventArgs^ e) {
	pStr = "";
	PortWrite("1i");
	lblDT->Text = "Updated: " + DateTime::Now.ToString();
}
System::Void SettingsForm::lbl2i_Click(System::Object^ sender, System::EventArgs^ e) {
	tStr = "";
	PortWrite("2i");
	lblDT->Text = "Updated: " + DateTime::Now.ToString();
}
System::Void SettingsForm::lbl3i_Click(System::Object^ sender, System::EventArgs^ e) {
	ilStr = "";
	PortWrite("3i");
	lblDT->Text = "Updated: " + DateTime::Now.ToString();
}
System::Void SettingsForm::lbl4i_Click(System::Object^ sender, System::EventArgs^ e) {
	lmStr = "";
	PortWrite("4i");
	lblDT->Text = "Updated: " + DateTime::Now.ToString();
}
System::Void SettingsForm::SettingsForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	StopInfo();
	this->SerialComPort->Close();
}
void SettingsForm::OutReceived(void) {
	this->Invoke(gcnew Action<String^>(&Helper::addText), "\r\n-SettingsForm::OutReceived(" + comStr + ")");
	if (lastOuted != comStr) {
		ReceivedPacket += comStr;
		lastOuted = comStr;
		if (comStr->Contains("\r\n")) {
			try {
				if (ReceivedPacket[0] == '$') {
					pStr = ReceivedPacket;
					lblPL->Text = pStr;
				}
				else
					if (ReceivedPacket[0] == 't') {
						tStr = ReceivedPacket;
						lblT->Text = tStr;
					}
					else
						if (ReceivedPacket[0] == 'I') {
							ilStr = ReceivedPacket;
							lblIL->Text = ilStr;
						}
						else
							if (ReceivedPacket->Contains("L/M")) {
								lmStr = ReceivedPacket;
								lblLM->Text = lmStr;
							}
							else unStr = ReceivedPacket;
			}
			catch (Exception^ ex)
			{
				this->Invoke(gcnew Action<String^>(&Helper::addText), "\r\n>SettingsForm::OutReceived-Exception: " + ex->ToString());
			}
			_Received = ReceivedPacket;
			ReceivedPacket = "";
		} // if (comStr->Contains("\r\n"))
	}
}
void SettingsForm::ErrReceived(void) {
	this->Invoke(gcnew Action<String^>(&Helper::addText), "\r\n-SettingsForm::ErrReceived:" + errStr);
}
System::Void SettingsForm::SerialComPort_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e) {
	comStr = this->SerialComPort->ReadExisting();
	LogReceived(comStr);
	this->Invoke(gcnew Action(this, &SettingsForm::OutReceived));
}
System::Void SettingsForm::SerialComPort_ErrorReceived(System::Object^ sender, System::IO::Ports::SerialErrorReceivedEventArgs^ e) {
	this->errStr = e->ToString();
	LogReceived(errStr);
	this->Invoke(gcnew Action(this, &SettingsForm::ErrReceived));
}
System::Void SettingsForm::InfTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (!this->SerialComPort->IsOpen) {
		this->Invoke(gcnew Action<String^>(&Helper::addText), "\r\n=SerialComPort closed.");
		return;
	}
	this->Invoke(gcnew Action<String^>(&Helper::addText), "<IT:Stage=" + _InfoStage + ">");
	bool is1i = check1i->Checked;
	bool is2i = check2i->Checked;
	bool is3i = check3i->Checked;
	bool is4i = check4i->Checked;
	if (!_InfoStage) {
		if (is1i) {
			PortWrite("1i");
			this->Invoke(gcnew Action<String^>(&Helper::addText), "\r\n-Writed '1i'");
		}
		_InfoStage = 1; return;
	}
	if (_InfoStage == 1) {
		if ((is1i) && (this->pStr == "")) return;
		else {
			if (is2i) {
				PortWrite("2i");
				this->Invoke(gcnew Action<String^>(&Helper::addText), "-Writed '2i'");
			}
			_InfoStage = 2; return;
		}
	}
	if (_InfoStage == 2) {
		if ((is2i) && (this->tStr == "")) return;
		else {
			if (is3i) {
				PortWrite("3i");
				this->Invoke(gcnew Action<String^>(&Helper::addText), "-Writed '3i'");
			}
			_InfoStage = 3; return;
		}
	}
	if (_InfoStage == 3) {
		if ((is3i) && (this->ilStr == "")) return;
		else {
			if (is4i) {
				PortWrite("4i");
				this->Invoke(gcnew Action<String^>(&Helper::addText), "-Writed '4i'");
			}
			_InfoStage = 4; return;
		}
	}
	if (_InfoStage == 4) {
		StopInfo();
	}
}
System::Void SettingsForm::PortWrite(String^ s)
{
	this->SerialComPort->Write(s);
	MainForm^ MF = safe_cast<MainForm^>(this->MForm);
	if (MF->sw) MF->sw->WriteLine(DateTime::Now.ToString() + ": Writed '" + s + "'");
	return System::Void();
}
System::Void SettingsForm::LogReceived(String^ s)
{
	MainForm^ MF = safe_cast<MainForm^>(this->MForm);
	if (MF->sw) MF->sw->WriteLine(DateTime::Now.ToString() + ": Received '" + s->Trim() + "'");
	return System::Void();
}
}
