#include "ComAbout.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO::Ports;

System::Void doComOpen(System::IO::Ports::SerialPort^ SerialComPort, String^ PName, System::Windows::Forms::TextBox^ OutTextBox)
{
	if (SerialComPort->IsOpen) SerialComPort->Close();
	SerialComPort->PortName = PName;
	SerialComPort->StopBits = System::IO::Ports::StopBits::One;
	SerialComPort->DataBits = 8;
	SerialComPort->BaudRate = 19200; // BaudRate — скорость передачи данных. Возможно указание следующих констант: CBR_110, CBR_300, CBR_600, CBR_1200, CBR_2400, CBR_4800, CBR_9600, CBR_14400, CBR_19200, CBR_38400, CBR_56000, CBR_57600, CBR_115200, CBR_128000, CBR_256000.
	SerialComPort->Parity = System::IO::Ports::Parity::None; // Even = 2, Mark = 3, None = 0, Odd = 1, Space = 4
	SerialComPort->Handshake = System::IO::Ports::Handshake::None; // None = 0, RequestToSend = 2, RequestToSendXOnXOff = 3, XOnXOff = 1
	try {
		SerialComPort->Open();
	}
	catch (Exception^ E) {
		if (OutTextBox != nullptr) OutTextBox->Text += "\r\n doComOpen() - SerialComPort->Open() - Exception: " +
			E->Message;
	}
	if (OutTextBox != nullptr) {
		OutTextBox->Text += "\r\nSerialPort PortName=" + SerialComPort->PortName;
		OutTextBox->Text += "\r\nSerialPort Parity=" + SerialComPort->Parity.ToString();
		OutTextBox->Text += "\r\nSerialPort BaudRate=" + SerialComPort->BaudRate.ToString();
		OutTextBox->Text += "\r\nSerialPort DataBits=" + SerialComPort->DataBits.ToString();
		OutTextBox->Text += "\r\nSerialPort StopBits=" + SerialComPort->StopBits.ToString();
		OutTextBox->Text += "\r\nSerialPort Handshake=" + SerialComPort->Handshake.ToString();
		OutTextBox->Text += "\r\nSerialPort IsOpen=" + SerialComPort->IsOpen.ToString();
	}
}

String^ SendComand(System::IO::Ports::SerialPort^ SerialComPort, int Command, String^ DataString) {
	if (!SerialComPort->IsOpen) doComOpen(SerialComPort,SerialComPort->PortName);
	switch (Command)
	{
	case 0: //Заправить до полного балона  (;)
		SerialComPort->Write(";p");
		break;
	case 1: //Заправить необходимое колличество(10.25;)
		SerialComPort->Write(DataString + ";p");
		break;
	case 2: //Запись цены в устройство($25.25;)
		SerialComPort->WriteLine("$" + DataString + ";");
		break;
	case 3: //Калибровка точности колонки(k9.789;)
		SerialComPort->Write("k" + DataString + ";");
		break;
	case 4: //Как написано.
		SerialComPort->Write(DataString);
		break;
	default:
		break;
	}
	if (SerialComPort->IsOpen) {
		int bytesCount = SerialComPort->BytesToRead;
		return SerialComPort->ReadExisting();
	}
	return "";
}

String^ DataReceive(System::IO::Ports::SerialPort^ SerialComPort) {
	String^ out;
	System::Threading::Monitor::Enter(SerialComPort);
	out = SerialComPort->BytesToRead + ":" + SerialComPort->ReadExisting();
	System::Threading::Monitor::Exit(SerialComPort);
	return out;
}
