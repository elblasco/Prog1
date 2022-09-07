#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(char *s,int dimTot,char* d1,const int dimd1Tot,int &dimd1,char* d2,const int dimd2Tot, int &dimd2);
void aux(char *s,int dimTot,char* d1,const int dimd1Tot,int &dimd1,char* d2,const int dimd2Tot, int &dimd2,int i);


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

  const int md1_s = maxdim;
  char d1[md1_s];
  int d1_s = 0;

  const int md2_s = maxdim;
  char d2[md2_s];
  int d2_s = 0;

  const int ms = maxdim;
  char s[ms];
  int s_s = 0;

  read_elements(s, ms, s_s);

  get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);

  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}

void get_elements(char *s,int dimTot,char* d1,const int dimd1Tot,int &dimd1,char* d2,const int dimd2Tot, int &dimd2){
   aux(s,dimTot,d1,dimd1Tot,dimd1,d2,dimd2Tot,dimd2,0);
}

void aux(char *s,int dimTot,char* d1,const int dimd1Tot,int &dimd1,char* d2,const int dimd2Tot, int &dimd2,int i){
   if(i==dimTot || dimd1==dimd1Tot ||dimd2==dimd2Tot){
      return;
   }
   else if(s[i]>='a'&&s[i]<='z'){
      d1[dimd1]='A'+(s[i]-'a');
      ++i;
      ++dimd1;
      aux(s,dimTot,d1,dimd1Tot,dimd1,d2,dimd2Tot,dimd2,i);
   }
   else if(s[i]>='0'&&s[i]<='9'){
      d2[dimd2]='9'-(s[i]-'0');
      ++dimd2;
      ++i;
      aux(s,dimTot,d1,dimd1Tot,dimd1,d2,dimd2Tot,dimd2,i);
   }
   else{
      ++i;
      aux(s,dimTot,d1,dimd1Tot,dimd1,d2,dimd2Tot,dimd2,i);
   }
}
