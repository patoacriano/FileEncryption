#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string name,msg;
int tam,x;

void decrypt()
{
  cout<<"File name (with extension): ";
  cin.ignore();
  getline(cin,name);
  ifstream read(name);
  stringstream buffer;
  buffer<<read.rdbuf();
  msg = buffer.str();
  tam = msg.length();
  cout<<"Encryption number: ";
  cin>>x;
  for(int i = 0;i<tam;i++)
  {
    msg[i] -= x;
  }
  cout<<"Create new file with decrypted text[1]\nRead decrypted file here[2]\n: ";
  cin>>x;
  if(x == 1)
  {
    ofstream arq("Decrypted_"+name,ios::app);
    arq<<msg;
    arq.close();
  }
  else if(x == 2)
  { 
    cout<<endl<<msg<<endl;
  }

}

void encrypt()
{
  cout<<"File name (with extension): ";
  cin.ignore();
  getline(cin,name);
  ifstream read(name);
  stringstream buffer;
  buffer<<read.rdbuf();
  msg = buffer.str();
  tam = msg.length();
  cout<<"Encryption number: ";
  cin>>x;
  for(int i = 0;i<tam;i++)
  {
    msg[i] += x;
  }
  cout<<"Create new file with encrypted text[1]\nRead encrypted file here[2]\n: ";
  cin>>x;
  if(x == 1)
  {
    ofstream arq("Encrypted_"+name,ios::app);
    arq<<msg;
    arq.close();
  }
  else if(x == 2)
  { 
    cout<<endl<<msg<<endl;
  }

}

int main()
{

  int esc;
  cout<<endl<<"Voce deseja criptografar[1] ou descriptografar[2] um arquivo?\n: ";
  cin>>esc;
  switch (esc)
  {
    case 1:
      encrypt();
      break;
    case 2:
      decrypt();
      break;
    default:
      break;
  }

}

