#include <iostream>
#include <cstddef>

using namespace std;

// Inserire qui la dichiarazione di get_elements

void get_elements(char *s,int dimS,char * &d1,int &dimD1,char * &d2,int &dimD2);
void print(const char a[], const int s, const char * prefix) {
  cout << prefix;
  for (int i = 0; i < s; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void read_elements(char s[], const int ms, int & s_s) {
  char r = '\0';
  for (s_s = 0; ((s_s < ms) && (r != '\n')); ) {
    r = cin.get();
    if ((r != '\n') && (r != ' ')) s[s_s++] = r;
  }
}



int main() {
  const int maxdim = 10;

  char * d1;
  int d1_s = 0;

  char * d2;
  int d2_s = 0;

  const int ms = maxdim;
  char s[ms];
  int s_s = 0;

  read_elements(s, ms, s_s);
  print(s, s_s, "Source = ");

  get_elements(s, s_s, d1, d1_s, d2, d2_s);

  print(d1, d1_s, "D1= ");
  print(d2, d2_s, "D2= ");

  delete [] d1;
  delete [] d2;
}

// Inserire qui la definizione di get_elements e di eventuali altre
// funzioni ausiliarie
void get_elements_aux(char *s,int dimS,char * &d1,int &dimD1,char * &d2,int &dimD2,int i){
   if(i>=dimS){
      d1=new char[dimD1];
      d2=new char[dimD2];
   }
   else if(s[i]>='a' && s[i]<='z'){
      int p=dimD1++;
      get_elements_aux(s,dimS,d1,dimD1,d2,dimD2,i+1);
      d1[p]='Z'-(s[i]-'a');

   }
   else if(s[i]>='0' && s[i]<='9'){
      int p=dimD1++;
      get_elements_aux(s,dimS,d1,dimD1,d2,dimD2,i+1);
      d2[p]='9'-(s[i]-'0');
   }
   else{
      ++i;
      get_elements_aux(s,dimS,d1,dimD1,d2,dimD2,i);
   }
}

void get_elements(char *s,int dimS,char * &d1,int &dimD1,char * &d2,int &dimD2){
   get_elements_aux(s,dimS,d1,dimD1,d2,dimD2,0);
}
