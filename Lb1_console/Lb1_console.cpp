#include <tchar.h>
#include <iostream>
#include <Windows.h>

#ifdef UNICODE
typedef		wchar_t	TCHAR;
#define	TEXT(a)	L##a
#define	_tcslen		wcslen
#define _tcin wcin
#define _tsetlocale _wsetlocale
#else
typedef 	char	   	TCHAR;
#define 	TEXT(a)	a
#define	_tcslen		strlen
#define _tcin cin
#define _tsetlocale setlocale
#endif
using namespace std;
bool checkIfUnicode(TCHAR* text);
size_t getLengthInBytes(TCHAR* text);
void parents();

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    _tsetlocale(LC_ALL, _T("Ukrainian"));
    TCHAR* text = new TCHAR[256]; // Allocate memory for input
    _tcin.getline(text, 256);
    if (checkIfUnicode(text)) {
        cout << "It is ASCII";
    }
    else {
        cout << "It is unicode";
    }

    parents();
    return 0;
}


size_t getLengthInBytes(TCHAR* text) {
    size_t length = _tcslen(text) * sizeof(text);
    return length;
}
bool checkIfUnicode(TCHAR* text)
{
    bool isUnicode = false;
    size_t length = getLengthInBytes(text);
    if (IsTextUnicode(text, length , NULL)) {
        isUnicode = true;
    }
    return isUnicode;
}

void parents() {
    const char* parents[] = {"Білецька", "Білецький"};
    const int length = 2;
    for (int i = 0; i < length; i++) {
        cout << parents[i];
    }
}