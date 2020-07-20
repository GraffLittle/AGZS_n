#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO::Ports;

System::Void doComOpen(System::IO::Ports::SerialPort^ SerialComPort, String^ PName, System::Windows::Forms::TextBox^ OutTextBox = nullptr);
String^ SendComand(System::IO::Ports::SerialPort^ SerialComPort, int Command, String^ DataString);
