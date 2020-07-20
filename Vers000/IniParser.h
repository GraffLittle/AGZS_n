#pragma once

using namespace System;
using namespace System::Text;
using namespace System::IO;
using namespace System::Globalization;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices; // for Marshal

namespace AGZS
{
    char* and_SysStringToChar(System::String^ string)
    {
        return (char*)(void*)Marshal::StringToHGlobalAnsi(string);
    }
    System::String^ and_CharToSysString(char* ch)
    {
        char* chr = ch;
        System::String^ str;
        for (int i = 0; chr[i] != '\0'; i++)
        {
            str += wchar_t(ch[i]);
        }
        return str;
    }

    ref class IniParser
    {
    public:
        IniParser()
        {
            _values = gcnew Dictionary<String^, Dictionary<String^, String^>^>(StringComparer::CurrentCulture);
        }

        IniParser(String^ path) 
        {
            _values = gcnew Dictionary<String^, Dictionary<String^, String^>^>(
                StringComparer::InvariantCultureIgnoreCase);

            Load(path);
        }
        String^ ToText(void)
        {
            String^ text;
            for each (String ^ key in _values->Keys) {
                text += ("[" + key + "]\r\n");
                Dictionary<String^, String^>^ values = GetSection(key);
                for each (KeyValuePair<String^, String^> kvp in values) {
                    if (kvp.Value == "") text += kvp.Key + "\r\n";
                    else text += (kvp.Key + "=" + kvp.Value + "\r\n");
                }
            }
            return text;
        }

        void Save(String^ path)
        {
            TextWriter^ tw = gcnew StreamWriter(path);
            tw->Write(this->ToText());
            tw->Close();
        }
        
        void Load(String^ path)
        {
            String^ currentSection = "";
            for each (String^ line in File::ReadAllLines(path))
            {
                if (String::IsNullOrWhiteSpace(line))
                    continue;

                if (line->StartsWith(L";", StringComparison::InvariantCultureIgnoreCase))
                    continue;

                if (line->StartsWith(L"[", StringComparison::InvariantCultureIgnoreCase) && line->EndsWith(L"]", StringComparison::InvariantCultureIgnoreCase))
                {
                    String^ sectionName = line->Substring(1, line->Length - 2);
                    if (String::IsNullOrWhiteSpace(sectionName))
                        continue;

                    currentSection = sectionName;
                }

                array<String^>^ parts = line->Split(gcnew array<wchar_t>(2) { '=' }, 2);
                if (parts->Length == 1)
                    SetString(currentSection, parts[0]->Trim(), "");
                else
                    SetString(currentSection, parts[0]->Trim(), parts[1]->Trim());
            }
        }

        bool ContainsSection(String^ sectionName)
        {
            return _values->ContainsKey(sectionName);
        }

        bool ContainsValue(String^ sectionName, String^ valueName)
        {
            Dictionary<String^, String^>^ values = GetSection(sectionName);
            if (values == nullptr)
                return false;

            return values->ContainsKey(valueName);
        }

        void Clear()
        {
            _values->Clear();
        }

        void SetString(String^ sectionName, String^ valueName, String^ value)
        {
            Dictionary<String^, String^>^ values = GetSection(sectionName);
            if (values == nullptr)
            {
                values = gcnew Dictionary<String^, String^>(StringComparer::InvariantCultureIgnoreCase);
                _values->Add(sectionName, values);
            }
            if (values->ContainsKey(valueName))
                values[valueName] = value;
            else
                values->Add(valueName, value);
        }

        String^ GetString(String^ sectionName, String^ valueName, String^ defaultValue)
        {
            Dictionary<String^, String^>^ values = GetSection(sectionName);
            if (values == nullptr)
                return defaultValue;

            if (values->ContainsKey(valueName)) {
                return values[valueName];
            }

            return defaultValue;
        }

    private:
        Dictionary<String^, Dictionary<String^, String^>^>^ _values;
    public:
        Dictionary<String^, String^>^ GetSection(String^ sectionName)
        {
            if (_values->ContainsKey(sectionName))
                return _values[sectionName];

            return nullptr;
        }
    };
}
