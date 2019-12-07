#include <QCoreApplication>
#include <iostream>
using namespace std;

int KMPSearch(QString nstring, QString nsubstring){ //в качестве параметров в функцию передается строка и субстрока
  QString string=nstring;
  QString substring=nsubstring;
  int  sl, ssl;
  int res = -1;
  sl = string.count();                                            //присваивается длина строки
  ssl = substring.count();                                      //присваивается длина субстроки
  if ( sl == 0 )                                                    //проверка строки
    cout << "Неверно задана строка\n";
  else if ( ssl == 0 )                                            //проверка субстроки
    cout << "Неверно задана подстрока\n";
  else {                                                            //Если все нормально - поехали
    int  i, j = 0, k = -1;
    int  *d;
    d = new int[1000];                                         //создали динамический одномерный массив
    d[0] = -1;                                                    //первый элемент делаем равным -1
    while ( j < ssl - 1 ) {                                      //пока  j < кол-ва эл-тов строки
      while ( k >= 0 && substring[j] != substring[k] ) /*пока k больше или равно 0 и j-тый элемент субстроки не равен
                                                                     k-тому присваиваем k k-тый элемент динамического массива*/
        k = d[k];
      j++;                                                         //увеличиваем j
      k++;
      if ( substring[j] == substring[k] )                   //если j-ый элемент субстроки равен k-тому
        d[j] = d[k];                                             //присваиваем j-тому элементу динамического массива k-тый
      else                                                         //иначе
        d[j] = k;                                                 //присваиваем k
    }
    i = 0;
    j = 0;                                                         //обнулили i, j
    while ( j < ssl && i < sl ){                               //пока j < длины субстроки и i < длины строки
      while ( j >= 0 && string[i] != substring[j] )       // пока j >= 0 и i-ый элемент субстроки не равен j-ому
        j = d[j];                                                  //j присваивается j-ый элемент динамического массива
      i++;
      j++;                                                         //увеличиваем i и j
    }


    delete [] d;                                                 //удаляем динам. массив
    res =  j == ssl ? i - ssl : -1;                           // результатом будет i-ssl если j = ssl и -1 в противном случае
  }
  return res;
}

int main(int argc, char *argv[])
{
    QString string,str;
    string = "etotipastroka"; //Текст
    str= "ti"; // Образец
    cout << KMPSearch(string,str); /*Вернет первое вхождение в образце
        В данном случае образец ti начинается с 3 символа строки текста
        если образцов много то наверное можно зациклить*/

    QCoreApplication a(argc, argv);

    return a.exec();
}
