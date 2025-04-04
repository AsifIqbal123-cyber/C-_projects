#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Book{
 public:
    int id;
    string title;
    string author;
    bool status;
        Book(int id, string title, string author){
            this->id = id;
            this->title = title;
            this-> author = author;
            this->status = false;
        }
};

class Library {
    public:
        vector<Book> library;

    void book_add(int id, string title, string author){
        library.push_back(Book(id,title,author));
        cout<<"Book added\n";
    }

    void display_book(){
        for(auto &book : library){
            cout<< "\nBook I.D: "<< book.id;
            cout<< "\nBook title: "<< book.title;
            cout<< "\nBook author: "<< book.author;
            cout<< (book.status?"\nissued":"\nAvailable");
            cout << endl;
        }
    }

    void isissued(int id){
        for(auto &book : library){
            if(book.id==id){
                if(!book.status){
                    book.status=true;
                    cout<<"Book is issued\n";
                } else {
                    cout<<"Book is already issued\n";
                }
                return;
            }
        }
    }


    void returnbook(int id){
        for(auto &book: library){
            if(book.id==id){
                if(book.status){
                    book.status=false;
                    cout<<"Book is returned\n";
                }else{
                    cout<<"Book is not issued\n";
                }
                return;
            }
        }
        cout <<"Book not found.\n";
    }

};

int main(){
    Library lib;
    int choice;
    while(choice!=5){
    cout<<"\nMenu\n";
    cout<<"1.Add a book\n";
    cout<<"2.Display library\n";
    cout<<"3.Issue a book\n";
    cout<<"4.Return a book\n";
    cout<<"5.Exit()\n";
    cin>>choice;

    int id;
    string title;
    string author;

    switch(choice){
        case 1:
         
            cout<<"Add a book \n";
            cout<< "Give an id ";
            cin>>id;
            cout<< "Give a title ";
            cin>>title;
            cout<< "Give an author ";
            cin>>author;
            lib.book_add(id, title, author);
            break;
        case 2: 
            lib.display_book();
            break;
        case 3:
            cout<<"Enter book id";
            cin>>id;
            lib.isissued(id);
            break;
        case 4:
            cout<<"Enter book id";
            cin>>id;
            lib.returnbook(id);
            break;
        case 5:
            cout<<"Exiting....\n";
            break;
        default:
            cout<<"Invalid choice! Try again.\n";
    }
}
}