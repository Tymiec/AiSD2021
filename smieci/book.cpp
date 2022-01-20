#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
#define Capacity 2000
#define max_char 80
namespace bookstore{
 int counter;
 int choice;
 signed char option;
 string tat;
 string bab;
 string xpb;
 double p;
 int qq;
};

void border();
void header();
void trace();
void footer();

class book{
  private:
    char title[max_char];
    char author[max_char];
    char pblser[max_char];
    
    double cost;
    int quantity;

  protected:
    char addTitle(string &t){
      cout << '\n'<<'\n' << setw(35) << "Enter the title of the Book: ";
      getline(cin, t);
      
      for (int i = 0; i < max_char; i++){
         if (t[0] == char(0)){
                t[0] = char(95);
                title[i]=t[i];
               return title[max_char];
            };
            if (t[i] == char(32)){
                t[i] = char(95);
            };
            title[i]=t[i];
      };
     return title[max_char];
    };
    
    char setTitle(string &t){
      for (int i = 0; i < max_char; i++){
     if (t[0] == char(0)){
                t[0] = char(95);
        title[i]=t[i];
               return title[max_char];
            };
            if (t[i] == char(32)){
                t[i] = char(95);
            };
        title[i] = t[i];
      };
     return title[max_char];
    };
    
    string getTitle(){
      return title;
    };

    char addAuthor(string &a){
      cout << '\n';
      cout << setw(35) << "Enter the author\'s name: ";
      getline(cin,a);
        
      for (int c = 0; c < max_char; c++){
         if (a[0] == char(0)){
                a[0] = char(95);
        author[c]=a[c];
               return author[max_char];
            };
            if (a[c] == char(32)){
                a[c] = char(95);
            };
    author[c] = a[c];
      };
     return author[max_char];
    };
    
    char setAuthor(string &a){    
      for (int c = 0; c < max_char; c++){
    if (a[0] == char(0)){
                a[0] = char(99);
        author[c]=a[c];
               return author[max_char];
            };
            if (a[c] == char(35)){
                a[c] = char(95);
            };
        author[c] = a[c];
      };
     return author[max_char];
    };
    
    string getAuthor(){
      return author;
    };

    char addPblser(string &Pb){
       cout << '\n';
       cout << setw(39) << "Enter the publishers\'s name: ";
       getline(cin, Pb);
        
       for (int c = 0; c < max_char; c++){
         if (Pb[0] == char(0)){
                Pb[0] = char(95);
             pblser[c]=Pb[c];
               return  pblser[max_char];
            };
            if (Pb[c] == char(32)){
                Pb[c] = char(95);
            }; 
         pblser[c] = Pb[c];
       };
      return  pblser[max_char];
     };
    
    char setPblser(string &Pb){         
      for (int c = 0; c < max_char; c++){
        if (Pb[0] == char(0)){
                Pb[0] = char(99);
             pblser[c]=Pb[c];
               return  pblser[max_char];
            };
            if (Pb[c] == char(34)){
                Pb[c] = char(99);
            }; 
         pblser[c] = Pb[c];
      };
     return  pblser[max_char];
    };
    
     string getPblser(){
       return  pblser;
     };

     double addCost(double C){
        cout << '\n'<< setw(30) << "Enter cost of book: $";
        while(!(cin >> C)){
         cout << '\n' << setw(42) << ">> Oops!numerical values Only!" << endl;
         cin.clear();
         cin.ignore(40 ,'\n');
         cout << '\n' <<  setw(27) << "Enter the cost: ";      
        };
        cost =C;
      return  cost;
    };
    
    double setCost(double C){
        cost = C;
      return  cost;
    };
    
     double getCost(){
       return  cost;
     };
        
     int addQuantity(int q){
        cout << '\n';
        cout << setw(30) << "Enter the quantity: ";
        while(!(cin >> q)){
         cout << setw(42) << ">> Oops! numerical values Only!" << endl;
         cin.clear();
         cin.ignore(40 ,'\n');
         cout << '\n' << setw(30) << "Enter the quantity: ";      
        };
        quantity = q;
      return quantity;
    };
    
    int setQuantity(int q){
        quantity = q;
      return quantity;
    };
    
     int getQuantity(){
        return quantity;
     };

   
     int buy(int q){
        while (quantity < max_char){
         try{
            int limit = max_char - quantity;
            cout << '\n';
            cout << setw(30) << "Enter the quantity: ";         
            while(!(cin >> q)){
             cout << setw(42) << ">> Oops! numerical values Only!" << endl;
             cin.clear();
             cin.ignore(40 ,'\n');
             cout << '\n' <<  setw(30) << "Enter the quantity: ";      
      };   
            if (q > limit){
              throw 19; 
        }
          }
          catch(int exc){
            cout << '\n';    
            cout << setw(44) << "< MAX. QUANTITY EXCEEDED! Error " << exc << " >" << endl;     
            q = max_char - quantity;
        cin.get();
             };
        
           if (quantity <= 40){
             quantity += q;
             cout << '\n' << setw(33) << "(Stock level updated!)\n";
             footer();  
         cin.get();  
             return quantity;
             exit;
           }
           else if (quantity > 40 && quantity < max_char){    
              cout << '\n';    
              cout << setw(36) << ">> Warning: HIGH quantity!"  << endl;
              quantity += q;
              cout << '\n' << setw(33) << "(Stock level updated!)\n";
              footer();    
          cin.get();    
              return quantity;   
              exit; 
           };
          };

          if (quantity >= max_char){
            cout << '\n';     
            cout << setw(35) << ">> MAX. QUANTITY REACHED!"  << endl;
            quantity = max_char;
        cin.get();    
            return 1;
          };

        return quantity;
      }; 
       
      int sell(int q){
       while(quantity > 0 && quantity <= max_char){
         try{
         cout << '\n';
    
          cout << setw(30) << "Enter the quantity: ";
          while(!(cin >> q)){
                 cout << setw(42) << ">> Oops! numerical values Only!" << endl;
                 cin.clear();
                 cin.ignore(40 ,'\n');
                 cout << '\n' << setw(30) << "Enter the quantity: ";      
            };    

     if (q > quantity){
          q = 0;    
              throw 81;
        }     
       
    if (q >= max_char){
              q = 0;
          throw 20;    
    }      
        }
    catch(int exc){
        cout << '\n';    
        cout << setw(39) << "< INVALID QUANTITY!! Error " << exc << " >" <<endl;        
    cin.get(); 
        return 1;
    };
        
    if (quantity >= 4){
            quantity -= q;
            cout << '\n' << setw(33) << "(Stock level updated!)\n";
        cin.get();
            footer();
            return quantity;
            exit;
    }
    else if (quantity < 4 && quantity >= 1){    
            cout << '\n';    
            cout << setw(35) << ">> Warning: LOW quantity!"  << endl;
            quantity -= q;   
            cout << '\n' << setw(33) << "(Stock level updated!)\n";
        cin.get();
            footer();
            return quantity;
            exit; 
    };
  };
        if (quantity <= 0){
            cout << '\n';     
            cout << setw(32) << ">> Title NOT available"  << endl;
            quantity = 0;
        cin.get();
            return 1;
         };
        return quantity;
      }; 


   friend int menu(int &c, int cho, signed char opt, book p[], book r[], string &bt, string &ba, string &bpb, double &bp, int &bq, ofstream &wf, ifstream &rf, fstream &uf);
       
   friend book DBload(int &c, book p[],ifstream &rf);
            
   friend book DBupdate(int &c, book p[],fstream &uf);
      
   friend book SellBuyBook(int&c, book p[], string &bt, string &ba, string &bpb, double &bp, int &bq, fstream &uf);
      
   friend book AddDelBook(int &c, signed char opt, book p[], string &bt, string &ba, string &bpb, double &bp, int &bq, ofstream &wf, fstream &uf);
   
   friend book addBook(int &c, signed char opt, book p[], string &bt, string &ba, string &bpb, double &bp, int &bq, ofstream &wf, fstream &uf);
      
   friend book delBook(int &c, book p[], string &s);
      
   friend book Bookedit(int &c, signed char opt, book p[], string &bt, string &ba, string &bpb, double &bp,ofstream &wf, fstream &uf);
        
   friend void load(int &c, book p[], ifstream &rf);
   
   friend book findId(int &c, book p[], book r[], ifstream &rf);
   
   friend book findTitle(book p[], book r[], string &s, ifstream &rf);
   
   friend book findAuthor(book p[], book r[], string &s, ifstream &rf);

   friend book findPblser(book p[], book r[], string &s, ifstream &rf);
   
   friend book searc(int &c, book p[], book r[], string &s, ifstream &rf);
    
   friend book initValues(book p[], string s);

};
// friend functions prototypes
int menu(int &c, int cho, signed char opt, book p[], book r[], string &bt, string &ba, string &bpb, double &bp, int &bq, ofstream &wf, ifstream &rf, fstream &uf); 

book addBook(int &c, signed char opt, book p[], string &bt, string &ba, string &bpb, double &bp, int &bq, ofstream &wf, fstream &uf);

book delBook(int &c, book p[], string &s);

book Bookedit(int &c, signed char opt, book p[], string &bt, string &ba, string &bpb, double &bp,ofstream &wf, fstream &uf);
    
book initValues(book p[], string s);

book DBload(int &c, book p[],ifstream &rf);
    
book SellBuyBook(int&c, book p[], string &bt, string &ba, string &bpb, double &bp, int &bq, fstream &uf);
    
book AddDelBook(int &c, signed char opt, book p[], string &bt, string &ba, string &bpb, double &bp, int &bq, ofstream &wf, fstream &uf);
    
book findId(int &c, book p[], book r[], ifstream &rf);

book findTitle(book p[], book r[], string &s, ifstream &rf);

book findAuthor(book p[], book r[], string &s, ifstream &rf);

book findPblser(book p[], book r[], string &s, ifstream &rf);

book searc(int &c, book p[], book r[], string &s, ifstream &rf);
    
book DBupdate(int &c, book p[],fstream &uf);

void load(int &c, book p[], ifstream &rf);


int main(){

 using namespace bookstore;
 
 book b[Capacity];
 book s[Capacity];
 
  ifstream rFile("booksDB.txt", ios::in);
 
  fstream uFile("booksDB.txt", ios::in | ios::out); 

  ofstream wFile("booksDB.txt", ios::out | ios::app);
 
  initValues(b,tat);
  DBload(counter,b,rFile);
  menu(counter,choice,option,b,s,tat,bab,xpb,p,qq,wFile,rFile,uFile);
   
  rFile.close();
  DBupdate(counter,b,uFile); 
  wFile.close();
  uFile.close();
  
  footer();
  cin.get();
    
 return 0;
}

void border(){
    cout << '\n';    
    cout << setw(11);
    for(int j = 0; j < 50; j++){
        cout << "+";
    };
    cout << '\n';
};

void header(){
    cout << '\n';
    cout << setw(59) << "____:: C++\'s BOOKSTORE MANAGER ::____";
};

void footer(){
    cout << '\n';
    cout <<setw(59) << "___________________" << endl;
    cout << setw(42) << "MADE WITH C++" << endl;
    cout << '\n';
};


book initValues(book p[], string s){
  book *Ptr = new book[Capacity];
    s = char(0);
    for (int i = 0; i < Capacity; i++){
        Ptr->setTitle(s);
        Ptr->setAuthor(s);
        Ptr->setPblser(s);
        Ptr->setCost(0.0);
        Ptr->setQuantity(0);
        Ptr++;
    };
    
   return *Ptr;
   delete[] Ptr;
};

book DBload(int &v, book p[],ifstream &ssf){
   
    while (ssf >> p->title >> p->author >> p-> pblser >> p->cost >> p->quantity){p++; v++;};
    
    return *p; 
};


book DBupdate(int &v, book p[], fstream &uf){
    int k = 0;
    while (k < v){
        uf << p->title << " " << p->author << " " << p-> pblser << " " << p->cost << " " << p->quantity << endl;
        p++; 
        k++;
    };
    return *p;
};


int menu(int &v, int cho, signed char opt, book p[], book r[], string &bt, string &ba, string &bpb, double &bp, int &bq, ofstream &wf, ifstream &ssf, fstream &uf){
    do{
    system("cls");
    header();
    
    cout << '\n';
    cout << '\n' << setw(34) << "[1] - Display Inventory\n" << endl;
    cout << setw(42) << "[2] - Add / Remove / Edit Title\n" << endl;
    cout << setw(33) << "[3] - Sell / Buy Title\n" << endl;
    cout << setw(23) << "[4] - Search\n" << endl;
    cout << setw(21) << "[5] - Exit\n" << endl;
    
    cout << '\n' << setw(28) << "Enter the option: ";
    cin >> opt;
 
    if (opt == '1'){
         load(v,p,ssf);
    }
    else if (opt == '2'){   
        AddDelBook(v, opt, p, bt, ba,bpb,bp, bq, wf, uf);
     }
     else if (opt == '3'){    
         SellBuyBook(v,p,bt,ba,bpb,bp,bq,uf);
         DBload(v,p,ssf);
     }
     else if (opt == '4'){    
         searc(v,p,r,bt,ssf);
     }
      else if (opt == '5'){   
         return 0;
     }
      else{  
         cout << '\n' << setw(34) << "> Ooops! Invalid option." << endl;
    };
    
    cout << '\n';
    cout << setw(46) << "Press Any Key to Back To MENU ";
    cout << '\n';
    cin >> opt;
    }while(opt != bookstore::qq);
 
};

book SellBuyBook(int&c, book p[], string &bt, string &ba, string &bpb, double &bp, int &bq, fstream &uf){
    system("cls");
    string btcpy;
    char choice;
    header();
    int X_id, x;
    cout << '\n';
    cout << '\n' << setw(24) << "Enter the Id: ";
    while(!(cin >> X_id)){
         cout << '\n' << setw(42) << ">> Ooops! Only mumerical values!" << endl;
         cin.clear();
         cin.ignore(40 ,'\n');
         cout << '\n' <<  setw(24) << "Enter the Id: ";      
        };
  
    cout << '\n';
    cout << '\n' << setw(26) << "(Searching for '"<< X_id <<"' on database...)\n" << endl;
    
    int count = 0;
    
    for(int i = 0; i < Capacity; i++){
      x = i + 1;
      if (X_id == x && X_id <= c){    
        count++;
        cout << '\n'<< setiosflags(ios::right);
        
        cout << setw(11) << "#" << i + 1;
        cout << '\n' << setw(16) << "Title:" << setw(2) << " " << p->getTitle() << endl;
         cout << setw(18) << "Author: " << p->getAuthor() << endl;
        cout << setw(21) << "Publisher: " << p->getPblser() << endl;
        cout << setw(17) << "Cost: " << setw(2) << "$" << p->getCost() << endl;
        cout << setw(20) << "Quantity: " << p->quantity << endl;
        border();
        cout << '\n';
        cout << setw(11) << "(" << count << " title found)" << endl;
        
    cout << '\n';
        cout << '\n' << setw(32) << "[1] Sell | [2] Buy: ";
        cout << '\n';
        cout << '\n' << setw(28) << "Enter the choice: ";
        cin >> choice;
        if (choice == '1'){
          p->sell(bq);
        }
        else if (choice == '2'){
             p->buy(bq);
        } 
        else{
               cout << '\n';
               cout << '\n' << setw(34) << "> Ooops! Invalid option." << endl;
           cin.get();    
        };
       return p[i];
      };
    p++;
  };
  cout << '\n';
  cout << '\n' << setw(37) << "(NO title found. All done.)" << endl;
     
   footer();
   cin.get();
  return *p;
};


book addBook(int &c, signed char opt, book p[], string &bt, string &ba, string &bpb, double &bp, int &bq, ofstream &wf, fstream &uf){
    system("cls");
    header();
    
    int cont = 0;
   
   
    for(int i = 0; i < c; i++){
        p++;
    };
     
    do{     
      cin.clear();
      cin.ignore(40, '\n');
      p->addTitle(bt);
      p->addAuthor(ba);
      p->addPblser(bpb);
      p->addCost(bp);
      p->addQuantity(bq);
        
      wf << p->title << " " << p->author << " "  << p-> pblser << " " << p-> cost << " " << p->quantity << endl;
      
      cont++;
      p++;
     
      cout << '\n';
      cout << '\n' << setw(46) << "< PRESS 'N' to ADD ANOTHER TITLE > ";
      cin >> opt;
     
    } while(opt == 'n' || opt == 'N'); 
    
    for(int i = 0; i < cont; i++){
        p--;
    };
    
    int idX = c;
    cout << '\n';
    cout << '\n' << setw(29) << "(Adding titles...)\n" << endl;
    
 
    for(int i = 0; i < cont; i++){
    
        cout << setiosflags(ios::right);
        
        cout << setw(15) << "#Id: " << idX + 1;
        cout << '\n' << setw(17) << "Title: " << " " << p->title << endl;
        cout << setw(18) << "Author: " << p->author << endl;
        cout << setw(21) << "Publisher: " << p-> pblser << endl;
        cout << setw(17) << "Cost: " << setw(2) << "$" << p-> cost << endl;
        cout << setw(20) << "Quantity: " << p->quantity << endl;
        border();
        idX++;
        p++;
    }; 
    cout << '\n';
    cout << setw(11) << "(" << cont << " title(s) added. All done.)" << endl;
    
    c += cont;
    
    footer();
    cin.get();  
    return p[c];
};

book delBook(int &v, book p[], string &C){
    system("cls");
    string strigcpy;
    header();
    int X_id, x;
    
    cout << '\n';
    cout << '\n' << setw(24) << "Enter the Id: ";
    while(!(cin >> X_id)){
         cout << '\n' << setw(42) << ">> Ooops! Only mumerical values!" << endl;
         cin.clear();
         cin.ignore(40 ,'\n');
         cout << '\n' <<  setw(24) << "Enter the Id: ";      
        };
  
    cout << '\n';
    cout << '\n' << setw(26) << "(Searching for '"<< X_id <<"' on database...)\n" << endl;
    
    int count = 0;
    
    for(int c = 0; c < Capacity; c++){
      x = c + 1;
        if (X_id == x && X_id <= v){    
        count++;
        cout << '\n';
        //sets text align to right
        cout << setiosflags(ios::right);
        cout << setw(11) << "#" << c + 1;
        cout << '\n' << setw(16) << "Title:" << setw(2) << " " << p->getTitle() << endl;
        cout << setw(18) << "Author: " << p->getAuthor() << endl;
        cout << setw(21) << "Publisher: " << p-> pblser << endl;
        cout << setw(17) << "Cost: " << setw(2) << "$" << p->getCost() << endl;
        cout << setw(20) << "Quantity: " << p->quantity << endl;
        border();
        cout << '\n';
        cout << '\n' << setw(30) << "(deleting title...)\n";
        
        C = "removed";
    
        p->setTitle(C);
        p->setAuthor(C);
        p->setPblser(C);
        p->setCost('\0');
        p->setQuantity('\0');
    
        cout << setw(36) << "(title deleted.)" << endl;
          
        footer();
        cin.get();
       return p[c];
      };
      p++;
     };
     
      cout << '\n';
      cout << setw(37) << "(NO title found. All done.)" << endl;
     
     footer();  
     cin.get();
     return *p;
    };
    
// edits title from database
book Bookedit(int &v, signed char ch, book p[], string &bt, string &ba, string &bpb, double &bp, ofstream &wf, fstream &uf){
    
    system("cls");
    string cpy;
    header();
    int X_id, x;
    
    cout << '\n' << '\n' << setw(24) << "Enter BookId: ";
    while(!(cin >> X_id)){
         cout << '\n' << setw(42) << ">> Oops! mumerical values Only!" << endl;
         cin.clear();
         cin.ignore(40 ,'\n');
         cout << '\n' <<  setw(24) << "Enter BookId: ";      
        };
  
    cout << '\n' << '\n' << setw(26) << "(Searching for '"<< X_id <<"' on database...\n)" << endl;
    signed char option;
    int Cnt = 0;
    
    for(int i = 0; i < Capacity; i++){
      x = i + 1;
        if (X_id == x && X_id <= v){    
        Cnt++;
        do{
          cout << '\n';
          cout << setiosflags(ios::right);
          cout << setw(11) << "#" << i + 1;
          cout << '\n' << setw(16) << "Title:" << setw(2) << " " << p->getTitle() << endl;
          cout << setw(18) << "Author: " << p->getAuthor() << endl;
          cout << setw(21) << "Publisher: " << p->pblser << endl;
          cout << setw(17) << "Cost: " << setw(2) << "$" << p->getCost() << endl;
          cout << setw(20) << "Quantity: " << p->quantity << endl;
          border();  
          cout << '\n';
          cout << setw(11) << "(" << Cnt << " title(s) found(ed).)" << endl;
        
        cout << '\n';
        cout << '\n' << setw(42) << "[1] Edit the Title \t[2] Edit the Author" << endl;
        cout << setw(45) << "[3] Edit the Publisher \t[4] Edit cost ";
        cout << '\n';
        cout << '\n' << setw(28) << "Enter the choice: ";
        cin >> ch;
    
    if (ch == '1'){
      cin.clear();
      cin.ignore(max_char, '\n');
      p->addTitle(bt);
      cout << '\n' << setw(48) << "(Title edited.)" << endl;
      unsigned char l = 'l';
      l = getchar();
    }
    else if(ch == '2'){
      cin.clear();
      cin.ignore(max_char, '\n');     
      p->addAuthor(ba);
      cout << '\n' << setw(49) << "(Author edited.)" << endl;
      unsigned char l = 'l';
      l = getchar();
    }
    else if (ch == '3'){
      cin.clear();
      cin.ignore(max_char, '\n');    
      p->addPblser(bpb);
      cout << '\n' << setw(48) << "(Title edited.)" << endl;
      unsigned char l = 'l';
      l = getchar();;    
    }
    else if (ch == '4'){
      p->addCost(bp);
      cout << '\n' << setw(48) << "(Cost edited.)" << endl;
      unsigned char l = 'l';
      l = getchar();    
    }
    else{
      cout << '\n';
      cout << '\n' << setw(34) << "> Ooops! Invalid option." << endl;
      cin.get();    
    };
    
    cout << '\n';
    cout << setw(44) << "< PRESS 'E' to KEEP EDITING > ";
    cin >> option;
    
    }while(option == 'e' || option == 'E');
          
       footer();
       return p[i];
      }; 
      p++;
     }; 
     
      cout << '\n';
      cout << setw(38) << "(title not found.)" << endl;
     
     footer();   
     cin.get(); 
     return *p;
    };
    
book AddDelBook(int &c, signed char ch, book p[], string &bt, string &ba, string &bpb, double &bp, int &bq, ofstream &wf, fstream &uf){
    system("cls");
    header();

    cout << '\n';
    cout << '\n' << setw(45) << "[1] - Add | [2] Remove | [3] Edit: ";
    cout << '\n';
    cout << '\n' << setw(28) << "Enter the choice: ";
    cin >> ch;
    
    if (ch == '1'){
      addBook(c, ch, p, bt, ba, bpb, bp, bq, wf, uf);
    }
    else if (ch == '2'){
      delBook(c, p, bt);
    }
    else if (ch == '3'){
      Bookedit(c, ch, p, bt, ba, bpb, bp, wf, uf);
    }
    else{
      cout << '\n';
          cout << '\n' << setw(34) << "> Ooops! Invalid option." << endl;
      cin.get();
    };
    
    return *p;
};


void load(int &v, book p[], ifstream &rf){  
    system("cls");
    header();

    cout << '\n'<< '\n' << setw(31) << "Loading database..." << endl;
    cout << '\n';
    for (int c = 0; c < v; c++){
        cout << setw(16) << "#Id: " << c + 1;
        cout << '\n' << setw(17) << "Title: " << p->title << endl;
        cout << setw(19) << "Name of Author: " << p->author << endl;
        cout << setw(21) << "Name of Publisher: " << p->pblser << endl;
        cout << setw(17) << "Cost: " << setw(2) << "$" << p-> cost << endl;
        cout << setw(20) << "Quantity: " << p->quantity << endl;
        border();
        p++;
    };
    cout << '\n';
    cout << setw(41) << "(Database successfully loaded!)" << endl;
    cout << setw(11) << "(" << v << " title(s) found(ed). All done.)" << endl;
    unsigned char l = 'l';
    l = getchar();
    footer();
};

book findId(int &c, book p[], book n[], ifstream &rf){
    system("cls");

    string strigcpy;
    header();
    cin.clear();
    cin.ignore(max_char,'\n');
    
    int X_id, x;
    
    cout << '\n';
    cout << '\n' << setw(24) << "Enter the Id: ";
    while(!(cin >> X_id)){
         cout << '\n' << setw(42) << ">> Ooops! Only mumerical values!" << endl;
         cin.clear();
         cin.ignore(40 ,'\n');
         cout << '\n' <<  setw(24) << "Enter the Id: ";      
        };
  
    cout << '\n';
    cout << '\n' << setw(26) << "(Searching for '"<< X_id <<"' on database...)\n" << endl;
    
    int count = 0;
    
    for(int i = 0; i < Capacity; i++){
      x = i + 1;
        if (X_id == x && X_id <= c){    
           string sTitle = p->getTitle();
           string sAuthor = p->getAuthor();
           string sPub = p->pblser;
           double sCost = p->getCost();
           int sQt = p->quantity;
          
           n->setTitle(sTitle);
           n->setAuthor(sAuthor);
           n->setPblser(sPub);
           n->setCost(sCost);
           n->setQuantity(sQt);
           
           n++;
           count++;
       };
       p++;
      };
          
    for(int i = 0; i < count; i++){
       n--;
     };
    
    if(count == 0){
      cout << '\n';
      cout << setw(37) << "(NO title found. All done.)" << endl;   
      footer();
      cin.get();
      return *p;
    }
    else{
                
    for(int i = 0; i < count; i++){
       cout << setiosflags(ios::right);
       cout << setw(11) << "#" << X_id;
       cout << '\n' << setw(16) << "Title:" << setw(2) << " " << n->getTitle() << endl;
       cout << setw(18) << "Author: " << n->getAuthor() << endl;
       cout << setw(21) << "Publisher: " << n->pblser << endl;
       cout << setw(17) << "Cost: " << setw(2) << "$" << n->getCost() << endl;
       cout << setw(20) << "Quantity: " << n->quantity << endl;
       border();
       n++;
     };
     cout << '\n';
     cout << setw(11) << "(" << count << " title(s) found(ed). All done.)\n";  
     footer(); 
     cin.get();
    };
  return *p;
};

// search by title
book findTitle(book p[], book n[], string &C, ifstream &rf){
    system("cls");
    int X_id[max_char];
    int j = 0;    

    string stringcpy;
    header();
    cin.clear();
    cin.ignore(max_char,'\n');
    cout << '\n';
    cout << '\n' << setw(34) << "Enter the title\'s name: ";
    getline(cin, C); stringcpy = C;
    for(int i = 0; i < max_char; i++){
        if (C[i] == char(32)){
           (C[i] = char(95));
        }; 
    };
    cout << '\n';
    cout << '\n' << setw(26) << "Searching for '"<< stringcpy <<"' on database...\n" << endl;
    int count = 0;
    for(int i = 0; i < Capacity; i++){
        if (C == p->title){
           X_id[j] = i+1;   
           string sAuthor = p->getAuthor();
           string sPub = p->pblser;
           double sCost = p->getCost();
           int sQt = p->quantity;
          
           n->setTitle(C);
           n->setAuthor(sAuthor);
           n->setPblser(sPub);
           n->setCost(sCost);
           n->setQuantity(sQt);
           
           n++;
       j++;
           count++;
       };
       p++;
      };
          
    for(int i = 0; i < count; i++){
       n--;
     };
    
    if(count == 0){
      cout << '\n';
      cout << setw(37) << "(NO title found. All done.)" << endl;   
      footer();
      cin.get();
      return *p;
    }
    else{
      
 
          
    for(int i = 0; i < count; i++){
    
       cout << setiosflags(ios::right);
       cout << setw(16) << "#Id: " << X_id[i];
       cout << '\n' << setw(16) << "Title:" << setw(2) << " " << n->getTitle() << endl;
       cout << setw(18) << "Author: " << n->getAuthor() << endl;
       cout << setw(21) << "Publisher: " << n->pblser << endl;
       cout << setw(17) << "Cost: " << setw(2) << "$" << n->getCost() << endl;
       cout << setw(20) << "Quantity: " << n->quantity << endl;
       border();
       n++;
     };
     cout << '\n';
     cout << setw(11) << "(" << count << " title(s) found(ed). All done.)\n";     
 
     footer();  
     cin.get();
    };
  return *p;
};

book findAuthor(book p[], book n[], string &C, ifstream &rf){
    system("cls");
    string strigcpy;

    int X_id[max_char];
    int j = 0;    

    header();
    cin.clear();
    cin.ignore(max_char,'\n');
    cout << '\n';
    cout << '\n' << setw(36) << "Enter the author\'s name: ";
    getline(cin, C); strigcpy = C;
    for(int i = 0; i < max_char; i++){
        if (C[i] == char(32)){
           (C[i] = char(95));
        }; 
    };
    cout << '\n';
    cout << '\n' << setw(26) << "(Searching for '"<< strigcpy <<"' on database...)\n" << endl;
    int count = 0;
    for(int i = 0; i < Capacity; i++){
        if (C == p->author){
       X_id[j] = i+1;          
           string sTitle = p->getTitle();
           string sPub = p->pblser;
           double sCost = p->getCost();
           int sQt = p->quantity;
          
           n->setTitle(sTitle);
           n->setAuthor(C);
           n->setPblser(sPub);
           n->setCost(sCost);
           n->setQuantity(sQt);
           
           n++;
           j++;
           count++;
       };
       p++;
      };
          
   
    for(int i = 0; i < count; i++){
       n--;
     };
    
    if(count == 0){
      cout << '\n';
      cout << setw(37) << "(NO title found.)" << endl;   
      footer();
      cin.get();
      return *p;
    }
    else{
      
    
           
    for(int i = 0; i < count; i++){
       cout << setiosflags(ios::right);
       cout << setw(15) << "#Id: " << X_id[i];
       cout << '\n' << setw(16) << "Title:" << setw(2) << " " << n->getTitle() << endl;
       cout << setw(18) << "Author: " << n->getAuthor() << endl;
       cout << setw(21) << "Publisher: " << n->pblser << endl;
       cout << setw(17) << "Cost: " << setw(2) << "$" << n->getCost() << endl;
       cout << setw(20) << "Quantity: " << n->quantity << endl;
       border();
       n++;
     };
     cout << '\n'<< setw(13) << "(" << count << " title(s) found(ed).)\n";    
  
     footer();      
     cin.get();
    };
  return *p;
};


book findPblser(book p[], book n[], string &C, ifstream &rf){
   
    system("cls");

    string strigcpy;

    int X_id[max_char];
    int j = 0;    

    header();
    cin.clear();
    cin.ignore(max_char,'\n');
    cout << '\n'<< '\n' << setw(40) << "Enter name of the Publisher: ";
    getline(cin, C); strigcpy = C;
    for(int i = 0; i < max_char; i++){
        if (C[i] == char(32)){
           (C[i] = char(95));
        }; 
    };
    cout << '\n';
    cout << '\n' << setw(26) << "Searching for '"<< strigcpy <<"' on database...\n" << endl;
    int count = 0;
    for(int i = 0; i < Capacity; i++){
        if (C == p->pblser){
       X_id[j] = i+1;          
           string sTitle = p->getTitle();
           string sAuthor = p->getAuthor();
           string sPub = p->pblser;
           double sCost = p->getCost();
           int sQt = p->quantity;
          
           n->setTitle(sTitle);
           n->setAuthor(sAuthor);
           n->setPblser(C);
           n->setCost(sCost);
           n->setQuantity(sQt);
           
           n++;
           j++;
           count++;
       };
       p++;
      };
          
 
    for(int i = 0; i < count; i++){
       n--;
     };
    
    if(count == 0){
      cout << '\n';
      cout << setw(37) << "(NO title found.)" << endl;   
      footer();
      cin.get();    
      return *p;
    }
    else{
           
    for(int i = 0; i < count; i++){
       cout << setiosflags(ios::right);
       cout << setw(15) << "#Id: " << X_id[i];
       cout << '\n' << setw(16) << "Title:" << setw(2) << " " << n->getTitle() << endl;
       cout << setw(18) << "Author: " << n->getAuthor() << endl;
       cout << setw(21) << "Publisher: " << n->pblser << endl;
       cout << setw(17) << "Cost: " << setw(2) << "$" << n->getCost() << endl;
       cout << setw(20) << "Quantity: " << n->quantity << endl;
       border();
       n++;
     };
     cout << '\n';
     cout << setw(11) << "(" << count << " title(s) found(ed).)\n";    
  
     footer();      
     cin.get();
    };
  return *p;
};
book searc(int &v, book p[], book r[], string &s, ifstream &ssf){
    DBload(v, p, ssf);
    system("cls");
    header();
    char num;
    cout << '\n' << '\n' << setw(25) << "Search using: \n";
    cout << '\n' << setw(30) << "[1] Book Id \t[3] Book Author";
    cout << '\n';
    cout << '\n' << setw(35) << "[2] Book Title \t[4] Book Publisher";
    cout << '\n';
    cout << '\n' << setw(30) << "Enter your choice: ";
    cin >> num;
    if (num== '1'){
       findId(v, p,r, ssf);
    }
    else if (num == '2'){ 
       findTitle(p, r, s, ssf);
    }
    else if (num == '3'){
        findAuthor(p, r, s, ssf);
    }
    else if (num == '4'){
        findPblser(p, r, s, ssf);
    }
    else{
      cout << '\n';
      cout << '\n' << setw(35) << "> Ooops! Invalid option." << endl;
    };   
  return *p;
};
