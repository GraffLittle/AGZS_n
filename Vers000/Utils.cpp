#include "Utils.h"
#include "DebugForm.h"

String^ to3num(String^ str) {
	String^ out = "";
	for (int i = 0; i < str->Length; i++) out += String::Format("{0:000}", str[i] + 12);
	return out;
}
String^ _3num2str(String^ str) {
	String^ out = "";
	for (int i = 0; i < str->Length / 3; i++) {
		String^ sub = str->Substring(i * 3, 3);
		int num = Convert::ToInt32(sub);
		out += wchar_t(num - 12);
	}
	return out;
}

array<wchar_t>^ xorString(String^ toEncrypt) {
	char key[3] = { 'E', 'B', 'A' };
	array<wchar_t>^ wc = toEncrypt->ToCharArray();
	for (int i = 0; i < toEncrypt->Length; i++)
		wc[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];
	return wc;
}

String^ encryptDecrypt(String^ toEncrypt) {
	char key[3] = { 'E', 'B', 'A' };
	String^ output = toEncrypt;

	array<wchar_t>^ wc = toEncrypt->ToCharArray();
	for (int i = 0; i < toEncrypt->Length; i++)
		wc[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];
	output = wc->ToString();
	return output;
}

array<wchar_t>^ xors(String^ toEncrypt) {
	array<wchar_t>^ wc = toEncrypt->ToCharArray();
	for (int i = 0; i < toEncrypt->Length; i++)
		wc[i] = toEncrypt[i] + 1;
	return wc;
}

double ConvertAnyToDouble(String^ S) {
	double out;
	try {
		String^ ds = Globalization::NumberFormatInfo::CurrentInfo->NumberDecimalSeparator;
		String^ s2 = S->Replace(".", ds);
		s2 = s2->Replace(",", ds);
		out = Convert::ToDouble(s2);
	}
	catch (FormatException^ ex) {
		Helper::addText("\r\n~ConvertAnyToDouble(" + S + ")-FormatException: " + ex->ToString());
	}
	return out;
}
