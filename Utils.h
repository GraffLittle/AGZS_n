#pragma once
using namespace System;

String^ to3num(String^ str);
String^ _3num2str(String^ str);

// NOT used any more:
array<wchar_t>^ xorString(String^ toEncrypt);
String^ encryptDecrypt(String^ toEncrypt);
array<wchar_t>^ xors(String^ toEncrypt);

double ConvertAnyToDouble(String^ S);
