#include <iostream>
#include <fstream>

using namespace std;


void input(unsigned char m[]){
  char tmp;
  unsigned char tmps[8];
  for (int j = 0; j < 8; j++) tmps[j] = '0';
  int i = 0;
  cin.get(tmp);
  while(tmp != '\n'){
    if(((tmp != '0')&&(tmp != '1')) || (i>=8)){
      cout<<"Некорректный ввод" << endl;
      exit(0);
    }
    tmps[i] = (unsigned char)tmp;
    cin.get(tmp);
    i++;
  }

  i--;
  for(int j = 0; j<=i; j++)m[7-i+j] = tmps[j];
}

void fileinput(string filename, unsigned char m[]){

  ifstream file(filename);
  if(!file.is_open()){
    cout << "Ввывести файл не удалось"<<endl;
    exit(0);
  }

  char tmp;
  unsigned char tmps[8];
  for (int j = 0; j < 8; j++) tmps[j] = '0';
  int i = 0;
  while(file.get(tmp)){
    if(((tmp != '0')&&(tmp != '1')) || (i>=8)){
      cout<<"Некорректный файл" << endl;
      exit(0);
    }
    tmps[i] = (unsigned char)tmp;
    i++;
  }

  i--;
  for(int j = 0; j<=i; j++)m[7-i+j] = tmps[j];
  
  file.close();
}

void output(unsigned char m[]){

  for (int j=0; j<8; j++) cout << m[j];

}

void fileoutput(string filename, unsigned char m[]){

  ofstream file(filename);
  file<<"Результат: ";

  for(int j=0; j<8; j++) file << m[j];
  
  file.close();

}

void conjanction(unsigned char a[], unsigned char b[], unsigned char c[]){

for(int j = 0; j<8; j++){
    if ((a[j]=='1') && (b[j] == '1')) c[j] ='1';
    else c[j]='0';
      }

}

int main(){
  unsigned char bit_string1[8];
  unsigned char bit_string2[8];
  unsigned char result[8];

  for (int j=0; j<8; j++){
    bit_string1[j] = '0';
    bit_string2[j] = '0';
    result[j] = '0';
  }

  //cout<<"Введите bit sring 1: ";
  //input(bit_string1);
  cout<<"Загрузка файла... \n ";
  fileinput("a.txt", bit_string1);
  
  cout<<"Введите bit string 2: ";
  input(bit_string2);

  cout<<"Bit String 1: ";
  output(bit_string1);
  cout << endl;

  cout<<"Bit String 2: ";
  output(bit_string2);
  cout << endl;

  //cout << "Результат: ";
  cout << "Загрузка результата в файл... ";
  conjanction(bit_string1, bit_string2, result);
  //output(result);
  fileoutput("c.txt", result);
  cout << endl;
  system("pause");

}
