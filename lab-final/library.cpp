/*
A program for library management
--features--
add, remove books
keep track of book borrowed
*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
//sstream -> isstringstream

using namespace std;

class Library {
public:
  //varriables to store username and passwords for both admin and member
  string adminUsername;
  string memberUsername;
  string adminPass;
  string memberPass;

  void mainMenu() {
    cout << "\n\n";
    cout << "\t\t\t\t********************************************\n";
    cout << "\t\t\t\t*                                          *\n";
    cout << "\t\t\t\t*       Welcome to the Library System      *\n";
    cout << "\t\t\t\t*                                          *\n";
    cout << "\t\t\t\t********************************************\n";
    cout << "\t\t\t\t--------------------------------------------\n";
    cout << "\t\t\t\t|              1) Admin                    |\n";
    cout << "\t\t\t\t|              2) User                     |\n";
    cout << "\t\t\t\t|              3) Exit                     |\n";
    cout << "\t\t\t\t--------------------------------------------\n";
  };

  void adminMenu() {
    cout << "\n\n";
    cout << "\t\t\t\t********************************************\n";
    cout << "\t\t\t\t*              Admin Menu                  *\n";
    cout << "\t\t\t\t********************************************\n";
    cout << "\t\t\t\tEnter your username: ";
    cin >> adminUsername;
    cout << "\t\t\t\tEnter your password: ";
    cin >> adminPass;
  }

  void memberMenu() {
    cout << "\n\n";
    cout << "\t\t\t\t********************************************\n";
    cout << "\t\t\t\t*              Member Menu                 *\n";
    cout << "\t\t\t\t********************************************\n";
    cout << "\t\t\t\tEnter your username: ";
    cin >> memberUsername;
    cout << "\t\t\t\tEnter your password: ";
    cin >> memberPass;
  }

  void adminOptions() {
    cout << "\n\n";
    cout << "\t\t\t\t================ Admin Options ================\n";
    cout << "\t\t\t\t|  1. Add a Book                               |\n";
    cout << "\t\t\t\t|  2. Remove a Book                            |\n";
    cout << "\t\t\t\t|  3. Show Available Books                     |\n";
    cout << "\t\t\t\t|  4. Exit Menu                                |\n";
    cout << "\t\t\t\t================================================\n";
  }

  void memberOptions() {
    cout << "\n\n";
    cout << "\t\t\t\t================ Member Options ================\n";
    cout << "\t\t\t\t|  1. Borrow a Book                            |\n";
    cout << "\t\t\t\t|  2. Show Available Books                     |\n";
    cout << "\t\t\t\t|  3. View Borrowed Books                      |\n";
    cout << "\t\t\t\t|  4. Return Book                              |\n";
    cout << "\t\t\t\t|  5. Exit Menu                                |\n";
    cout << "\t\t\t\t================================================\n";
  }

  //adds book to the book-database.txt along with its ID
  //also adds the book default status as available 
  void addBook() {
    string book_name;
    string book_id;
    string status = "[Available]";
    //output stream class to write on file
    ofstream book_database("book-database.txt", ios::app);


    //cin.ignore() is ignoring the one character, here it is ignoring new line (\n)
    //in previous operations, there is a new character left, so it ignores that and makes sure that it doesn't interfer
    cin.ignore();
    cout << "\t\t\t\tEnter the book id: ";
    getline(cin, book_id);
    // cin.ignore();
    cout << "\t\t\t\tEnter the book name: ";
    getline(cin, book_name);

    //replaces spaces between book name with underscores so, it is easier to read from it later
    for (char &c : book_name) {
      if (c == ' ') c = '_';
    }

    //<< -> insertion operator 
    //>> -> extraction operator 
    book_database << book_id << " " << book_name << " " << status << endl;
    book_database.close();
    cout << "\t\t\t\tBook added successfully!\n";
  }



  //removes books using book ID
  void removeBook() {
    string bookIdToRemove;
    ifstream databaseInputStream("book-database.txt");
    ofstream databaseOutputStream("temp.txt");


    //cin.ignore() is ignoring the one character, here it is ignoring new line (\n)
    //cin.ignore() ensures that leftovers character like \n don't interfere with the cin or getline()
    cin.ignore();
    cout << "\t\t\t\tEnter the ID of the book you want to remove: ";
    getline(cin, bookIdToRemove);

    string currentLine;
    bool bookFound = false;

    //reads one line from the file and stores it in currentLine
    while (getline(databaseInputStream, currentLine)) {
      //here isstringstream is used to split and extract individual components 
      //like book id, book name, status 
      istringstream iss(currentLine);
      string currentBookId;
      string currentBookName;
      string currentStatus;

      iss >> currentBookId >> currentBookName >> currentStatus;
      //iss splits currentLine string into components   using extraction operator
      //takes the space separated parts in and puts it in currentBookId, currentBookName, and  currentStatus

      if (currentBookId == bookIdToRemove) {
        bookFound = true;
        cout << "\t\t\t\tBook removed successfully!\n";
      } else {
        databaseOutputStream << currentLine << endl;
      }
    }

    if (!bookFound) {
      cout << "\t\t\t\tBook not found!\n";
    }

    databaseInputStream.close();
    databaseOutputStream.close();
    remove("book-database.txt");
    rename("temp.txt", "book-database.txt");
  }

  //function to borrow book using the book id
  //check if the book is borrowed by looking for the [Borrowed] status 
  //
  void borrowBook() {
    string bookIdToBorrow;
    ifstream databaseInputStream("book-database.txt");
    ofstream databaseOutputStream("temp.txt");


    //cin.ignore() is ignoring the one leftover character, here it is ignoring new line (\n)
    cin.ignore();
    cout << "\t\t\t\tEnter the ID of the book you want to borrow: ";
    cin >> bookIdToBorrow;
    string currentLine;
    bool bookFound = false;

    //while loop continues until all the line from the files are read
    while (getline(databaseInputStream, currentLine)) {
      istringstream iss(currentLine);
      string currentBookId, currentBookName, currentStatus;

      iss >> currentBookId >> currentBookName >> currentStatus;

      if (currentBookId == bookIdToBorrow) {
        if (currentStatus == "[Borrowed]") {
          cout << "\t\t\t\tBook is already borrowed!\n";
          databaseOutputStream << currentLine << endl;
        } else {
          bookFound = true;
          databaseOutputStream << currentBookId << " " << currentBookName << " [Borrowed]" << endl;
          cout << "\t\t\t\tBook borrowed successfully!\n";
        }
      } else {
        databaseOutputStream << currentLine << endl;
      }
    }

    if (!bookFound) {
      cout << "\t\t\t\tBook not found!\n";
    }

    databaseInputStream.close();
    databaseOutputStream.close();
    remove("book-database.txt");
    rename("temp.txt", "book-database.txt");
  }


  //function to return book from the book-database.txt that are listes as borrowed
  //asks the user for book id to return 
  //check if the current status is borrowed than changes it to Available
  void returnBook() {
    string bookIdToReturn;
    ifstream databaseInputStream("book-database.txt");
    ofstream databaseOutputStream("temp.txt");

    //cin.ignore() is ignoring the one character, here it is ignoring new line (\n)
    cin.ignore();
    cout << "\t\t\t\tEnter the ID of the book you want to return: ";
    getline(cin, bookIdToReturn);
    //getline takes all the input a single line

    string currentLine;
    bool bookFound = false;

    while (getline(databaseInputStream, currentLine)) {
      istringstream iss(currentLine);
      string currentBookId, currentBookName, currentStatus;

      iss >> currentBookId >> currentBookName >> currentStatus;

      if (currentBookId == bookIdToReturn) {
        if (currentStatus == "[Available]") {
          cout << "\t\t\t\tThis book wasn't borrowed!\n";
          databaseOutputStream << currentLine << endl;
        } else {
          bookFound = true;
          databaseOutputStream << currentBookId << " " << currentBookName << " [Available]" << endl;
          cout << "\t\t\t\tBook returned successfully!\n";
        }
      } else {
        databaseOutputStream << currentLine << endl;
      }
    }

    if (!bookFound) {
      cout << "\t\t\t\tBook not found!\n";
    }

    databaseInputStream.close();
    databaseOutputStream.close();
    remove("book-database.txt");
    rename("temp.txt", "book-database.txt");
  }


  //function to view borrowed book
  //while loops through the every line at book-database.txt till it finds currentStatus as "Borrowed"
void viewBorrowedBooks() {
  ifstream databaseInputStream("book-database.txt");

  cout << "\n\t\t\t\t=============================\n";
  cout << "\t\t\t\t  Borrowed Books\n";
  cout << "\t\t\t\t=============================\n\n";

  string currentBookId, currentBookName, currentStatus;
  int count = 1;
  while (databaseInputStream >> currentBookId >> currentBookName >> currentStatus) {
    if (currentStatus == "[Borrowed]") {

      //&c is refrence to each character in the currentBookName
      //if statement checks if the current character is true and is true than replaces with underscore
      
      for (char &c : currentBookName) {
        if (c == '_') c = ' ';
      }
      //this is just for numbering borrowed books
      cout << "\t\t\t\t" << count << ". ID: " << currentBookId << " - " << currentBookName << endl;
      count++;
    }
  }

  databaseInputStream.close();
}


  //shows available books 
  //
  void showAvailableShowBooks() {
    string listName;
    ifstream bookDatabase("book-database.txt");
    cout << "\t\t\t\t--------------------------------------------\n";
    cout << "\t\t\t\t|          Available Books List            |\n";

    while (getline(bookDatabase, listName)) {
      //for each character in the listName it looks for spaces and when there is a space it replaces with underscore 
      for (char &c : listName) {
        if (c == '_') c = ' ';
      }
      cout << "\t\t\t\t* " << listName << "\n";
    }

    cout << "\t\t\t\t--------------------------------------------\n";
    bookDatabase.close();
  }
};


int main() {
  //total of three types of menus are called in the int main() 
  //usign dot notation, most of them are put in do while loop
  //switch case to run, different function according to user choice
  Library library;
  int choice;

  do {
    library.mainMenu();
    cout << "\t\t\t\tEnter your choice: ";
    cin >> choice;
    switch (choice) {
      case 1:
        library.adminMenu();
        if (library.adminUsername == "admin" && library.adminPass == "pass") {
          int adminChoice;
          do {
            library.adminOptions();
            cout << "\t\t\t\tEnter your choice: ";
            cin >> adminChoice;
            switch (adminChoice) {
              case 1:
                library.addBook();
                break;

              case 2:
                library.removeBook();
                break;

              case 3:
                library.showAvailableShowBooks();
                break;

              case 4:
                cout << "\t\t\t\tExiting admin menu!\n";
                break;

              default:
                cout << "\t\t\t\tINVALID OPTION\n";
                break;
            }
          } while (adminChoice != 4);
        } else {
          cout << "\t\t\t\tWrong username or password!!!\n";
        }
        break;
      case 2:
        library.memberMenu();
        if (library.memberUsername == "member" && library.memberPass == "pass") {
          int memberChoice;
          do {
            library.memberOptions();
            cout << "\t\t\t\tEnter your choice: ";
            cin >> memberChoice;

            switch (memberChoice) {
              case 1:
                library.borrowBook();
                break;

              case 2:
                library.showAvailableShowBooks();
                break;

              case 3:
                library.viewBorrowedBooks();
                break;
              case 4:
                library.returnBook();
                break;
              case 5:
                cout << "\t\t\t\tExiting Menu!!!";
                break;
              case 6: 
                cout << "\t\t\t\tInvalid Choice!";
                break;
            }
          }  while(memberChoice != 5); 
        } else {
          cout << "\t\t\t\tWrong username or password!!!\n";
        }
        break;
      case 3:
        cout << "\t\t\t\tExiting program!\n";
        break;
      default:
        cout << "\t\t\t\tINVALID OPTION\n";
        break;
    }
  } while (choice != 3);

  return 0;
}
