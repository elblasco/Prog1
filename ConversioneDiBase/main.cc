#include<iostream>
using namespace std;

int potenza(int b, int e){
   if(e==0){
      return 1;
   }
   else{
      return b*potenza(b,e-1);
   }
}

int atoi(const char c){
   return (int)c;
}

int strlen(const char *c ,int i=0){
   if(c[i]=='\0'){
      return 0;
   }
   else{
      return 1+strlen(c,i+1);
   }
}

void gira(char* c,int fine,int inizio=0){
   if(inizio>=fine){
      return;
   }
   else{
      char tmp=c[inizio];
      c[inizio]=c[fine];
      c[fine]=tmp;
      gira(c,fine-1,inizio+1);
   }
}

void aux(int n,int b,char* c,int i,int resto){
   if(n==0){
      c[i]='\0';
   }
   else if(n!=0){
      resto=n%b;
      n=n/b;
      c[i]=(resto>=10)?resto-10+'A':resto+'0';
      aux(n,b,c,i+1,resto);
   }
}

char* decToB(int n,int b){
   char* risultato=new char[256];
   aux(n,b,risultato,0,0);
   gira(risultato,strlen(risultato)-1);
   return risultato;
}

int auxBToDec(char* n,int b,int i,int risultato){
   if(i==strlen(n)){
      return risultato;
   }
   int tmp=(n[strlen(n)-1-i]>='A' && n[strlen(n)-1-i]<='Z')?n[strlen(n)-1-i]-'A'+10:n[strlen(n)-1-i]-'0';
   tmp=tmp*potenza(b,i);
   risultato+=tmp;
   return auxBToDec(n,b,i+1,risultato);
}

int bToDec(char* n,int b){
   return auxBToDec(n,b,0,0);
}


int main(){
   int n;
   cout<<"Inerisci numero:";
   cin>>n;
   cout<<"Inserire base:";
   int b;
   cin>>b;
   char* tmp;
   tmp=decToB(n,b);
   cout<<"Nuova base "<<tmp<<endl;
   cout<<"Vecchia base "<<bToDec(tmp,b)<<endl;
   delete[] tmp;
   return 0;
}