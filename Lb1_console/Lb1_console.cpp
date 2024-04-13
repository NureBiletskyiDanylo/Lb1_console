
#include <tchar.h>
#include <iostream>
#include <Windows.h>
#ifdef UNICODE
typedef		wchar_t	TCHAR;
#define	TEXT(a)	L##a
#define	_tcslen		wcslen
#define _tcin wcin
#else
typedef 	char	   	TCHAR;
#define 	TEXT(a)	a
#define	_tcslen		strlen
#define _tcin cin
#endif

bool checkIfUnicode(TCHAR* text);
size_t getLengthInBytes(TCHAR* text);

int main()
{
    using namespace std;
    TCHAR* text = new TCHAR[256]; // Allocate memory for input
    _tcin.getline(text, 256);
    if (checkIfUnicode(text)) {
        cout << "It is unicode";
    }
    else {
        cout << "It is ASCII";
    }

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