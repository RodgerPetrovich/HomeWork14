#include <iostream>
#include <string>
#include "Trie.h"
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    fstream libr;
    Trie a;

    libr.open("engwords.txt");
    if (libr)cout << "Введите начало слова (на английском)" << endl;
    else cout << "Что-то пошло не так, не могу найти словарь!" << endl;

    string fromFile;
    for (libr >> fromFile; !libr.eof(); libr >> fromFile)
    {
        a.insert(fromFile);
    }

    string word;
    int choise = 0;
    while (true)
    {
         choise = _getch();
         if (choise >= 'a' && choise <= 'z')
         {
             system("cls");
             cout << "Нажмите Enter для подтверждения, BackSpace - удалить символ, Esc - выйти из программы.\n" << endl;
             word.push_back(choise);
             cout << "Возможно вы имели ввиду - ";
             a.printWordsByKey(word);    
             cout << endl<< word;

         }

         if (choise == 27)
         {
             cout << "\n Good Bye!!!";
             break;
         }

         if (choise == 13)
         {
             cout << endl;
             if (a.printWordsByKey(word)) {
                 cout << "\nОтлично ваше слово - ";
                 a.printWordsByKey(word);
                 cout << ", попробуем ещё? \n";
             }
            
             word.clear();
            
         }
         if (choise == 8)
         {

             if (!word.empty()) 
             {
                 system("cls");
                 cout << "Нажмите Enter для подтверждения, BackSpace - удалить символ, Esc - выйти из программы.\n" << endl;
                 cout << "Возможно вы имели ввиду - ";
                 word.pop_back();
                 a.printWordsByKey(word);        
                 cout << endl<< word;
             }
             else
             {
                 system("cls");
                 cout << "Введите начало слова (на английском)" << endl;
             }
         
       }
     
  }

    
    return 0;
}
