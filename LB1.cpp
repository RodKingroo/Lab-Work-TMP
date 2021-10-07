#include <iostream>

using namespace std;

int main(){

  unsigned char bit_string1[8];
  unsigned char bit_string2[8];
  unsigned char bit_string3[8];

  for (int j=0; j<8; j++){
    bit_string1[j] = '0';
    bit_string2[j] = '0';
    bit_string3[j] = '0';
  }

  cout<<"Введите bit sring 1: ";
  char tmp;
  unsigned char tmps[8];
  for (int j = 0; j < 8; j++) tmps[j] = '0';
  int i = 0;
  cin.get(tmp);
  while(tmp != '\n'){
    if(((tmp != '0')&&(tmp != '1')) || (i>=8)){
      cout<<"Некорректный ввод" << endl;
      return 1;
    }
    tmps[i] = (unsigned char)tmp;
    cin.get(tmp);
    i++;
  }

  i--;
  for(int j = 0; j<=i; j++)bit_string1[7-i+j] = tmps[j];

  cout<<"Введите bit sring 2: ";
  for (int j = 0; j < 8; j++) tmps[j] = '0';
  i = 0;
  cin.get(tmp);
  while(tmp != '\n'){
    if(((tmp != '0')&&(tmp != '1')) || (i>=8)){
      cout<<"Некорректный ввод" << endl;
      return 1;
    }
    tmps[i] = (unsigned char)tmp;
    cin.get(tmp);
    i++;
  }

  for(int j = 0; j<=i; j++){
    if ((bit_string1[j]=='1') && (bit_string2[j] == '1')) bit_string3[j] ='1';
    else bit_string3[j]='0';
      }
  cout<<"Результат: ";
  for (int j = 0; j<8; j++)cout<<bit_string3[j];
  cout<<endl;
  return 0;
}
