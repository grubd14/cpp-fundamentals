/*
A program for library management
--features--
add, remove and search for books
keep track of borrowers and duet dates
implement a system for calculating fines
*/

#include <iostream> 
#include <fstream>
#include <string>

using namespace std;

class Library {
public:
  string adminUsername;
  string memberUsername;
  string adminPass;
  string memberPass;

  void mainMenu() {
    cout << "\t1)Admin\n";
    cout << "\t2)User\n"; 
  };

  void adminMenu() {
    cout << "\tAdmin Menu\n";
    cout << "\tEnter your username: ";
    cin >> adminUsername;
    cout << "\tEnter your password: ";
    cin >> adminPass;
  }

  void memberMenu() {
    cout << "\tMember Menu\n";
    cout << "\tEnter your username: ";
    cin >> memberUsername;
    cout << "\tEnter your password: ";
    cin >> memberPass;
  }

  void adminOptions() {
    cout << "\t1.Add a book\n";
    cout << "\t2.Remove a book\n";
    cout << "\t3.Show Available books\n";
    cout << "\t4.Exit Menu";
  }

  void memberOptions() {
    cout << "\t1.Add a book\n";
    cout << "\t2.Search a book\n";
    cout << "\t3.Borrow a book\n";
  }



  void addBook() {
    string book_name;
    ofstream book_database("book-database.txt", ios::app);

    cin.ignore();
    cout << "\tEnter the book name: ";
    getline(cin, book_name);

    book_database << book_name << endl;
    book_database.close();
  }

  void removeBook() {
    string bookNameToRemove;
    string currentBookName;
    ifstream databaseInputStream("book-database.txt");
    ofstream databaseOutputStream("temp.txt");

    cout << "Enter the name of book you want to remove: ";
    getline(cin, bookNameToRemove);

    while (databaseInputStream >> currentBookName) {
      if (currentBookName != bookNameToRemove) {
        databaseOutputStream << currentBookName << '\n';
      }
    }

    databaseInputStream.close();
    databaseOutputStream.close();
  }

  void showAvailableShowBooks() {
    //will store string from the file read to this string
    
    string listName;
    ifstream bookDatabase("book-database.txt");
    while (!bookDatabase.eof()) {
      getline(bookDatabase, listName);

      cout << "\t" << listName << "\n" << endl;
    }

    bookDatabase.close();
  }

  //TO-DO
  //implement feature to borrow the book 
  //remove the name to be borrowed from the books-database.txt
  //copy the book name to borrowed_books.txt 


};

int main() {
  Library library;

  library.mainMenu();
  int choice;

  cout << "\tEnter your choice: ";
  cin >> choice;
  switch (choice) {
    case 1:
      library.adminMenu();
      break;
    case 2:
      library.memberMenu();
      break;
  }


  if (library.adminUsername == "admin" && library.adminPass == "pass") {
    do {
      library.adminOptions();
      cout << "\tEnter your choice: ";
      int choice;
      cin >> choice;
      switch (choice) {
        case 1:
          library.addBook();
          break;

        case 2:
          library.removeBook();
          break;

        case 3:
          cout << "\tAll the available books";
          library.showAvailableShowBooks();
          break;
        case 4:
          cout << "\tExiting admin menu!\n";
          library.mainMenu();
          break;
        default:  
          cout << "\tINVALID OPTION\n";
          break;
      } 
    } while (choice != 3);
  } else if (library.memberUsername == "member" && library.memberPass == "pass") {
    library.memberOptions();
    cout << "\tEnter your choice: ";
    int choice;
    cin >> choice;

    switch (choice) {
      case 1:
        library.addBook();
        break;
    }
  } else {
    cout << "\tWrong username or password!!! ";
  }
}

