
#include <tchar.h>
#include <iostream>
#include <Windows.h>
#ifdef UNICODE
typedef		wchar_t	TCHAR;
#define	TEXT(a)	L##a
#define	_tcslen		wcslen
#else
typedef 	char	   	TCHAR;
#define 	TEXT(a)	a
#define	_tcslen		strlen
#endif

bool checkIfUnicode(TCHAR* text);
size_t getLengthInBytes(TCHAR* text);

int main()
{
    using namespace std;
    TCHAR * text;
    text = new TCHAR[256];
    cin.getline(text, 256);
    if (checkIfUnicode(text)) {
        cout << "It is unicode";
    }
    else {
        cout << "It is ASCII";
    }

    delete[];
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