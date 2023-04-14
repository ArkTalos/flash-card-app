// Capstone Project: Flashcard App
// Written by: Jarratt Schleehauf
// This is the source file for the flashcard program.
// This Program will allow a user to create decks of flashcards,
// and study those decks.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void mainMenu();
void readDecksMessage(string deckNamesArray[]);
void readDeck(string deckArrayNum[][2]);
void userSelectsDeck(int deckSelected, string deckOne[][2], string deckTwo[][2], string deckThree[][2]);

int main()
{

   // Variable declarations:

   int choice;
   int totalNumCards;
   const int numDecks = 3;
   ifstream inFile;
   ofstream outFile;
   string deckNameArray[numDecks];
   int deckSelected;
   string deckOne[4][2];
   string deckTwo[4][2];
   string deckThree[4][2];
   string deckName;

   // declare the number of Decks that can be made. Start with a small number and will develop the program to extend the number of possible decks.
   const int deckArraySize = 3;

   string deckArray[deckArraySize]; //This array will hold the user defined names for each deck.
   string fileName = "cardDecks.txt"; //specifies the file for reading and writing.

   do
   {
      //Calls the main menu function as defined outside of main.

      mainMenu();
      cin >> choice;
      cout << endl;

      //selection structure that will allow the user to choose what to do from the main menu or quit the program.
      switch (choice)
      {
      case 1:
      {
         // This case allows the user to pick from available decks to study.
 // open the file to read the available string arrays which represent each deck and display the available decks.
         inFile.open(fileName);
         if (!inFile)
         {
            cout << "There are no decks to study.Please create a new deck." << endl;
            break;
         }
         else

            cout << "Choose a number from the following decks: " << endl;
         // Code for reading from the cardDecks.txt file to list available decks to choose from.
         cin.get(); // discards newline character so getline function will work.
         int x = 0;
         while (inFile)
         {
            getline(inFile, deckNameArray[x]);

            for (int i = 0; i < 4; i++)
               for (int j = 0; j < 2; j++)
               {
                  if (x == 0)
                     getline(inFile, deckOne[i][j]);
                  else if (x == 1)
                     getline(inFile, deckTwo[i][j]);
                  else if (x == 2)
                     getline(inFile, deckThree[i][j]);
                  else
                     break;
               }
            x++;

         }


         readDecksMessage(deckNameArray);

         cin >> deckSelected;

         userSelectsDeck(deckSelected, deckOne, deckTwo, deckThree);
         break;
      }
      case 2:
         // open the deck text file to create a new string array / new deck.
      {
         outFile.open(fileName, ios::app);
         if (outFile.is_open())  // Test to make sure open operation successful.

            // code to create a string array


            string deckName;
         cout << "What is the name of the deck?" << endl;
         cin >> deckName;


         cout << "The name of the Deck is: " << deckName << endl;
         cout << "This deck can have a maximum of 5 cards. \n"
            "If more cards are needed, create another deck.\n"
            "How many cards are in this deck? ";
         cin >> totalNumCards;
         outFile << deckName << endl;
         cin.get();
         // The following code will create a deck of 4 rows and 2 columns.
         // Each column represents the front and back of each card.
                   // The user will enter what they want to be displayed for the front
                   // and then the back side of the card.


         string deckName[4][2];
         for (int i = 0; i < totalNumCards && i < 4; i++)
         {
            for (int j = 0; j < 2; j++)
            {
               if (j == 0)
               {
                  cout << "Front of Card" << endl;
                  getline(cin, deckName[i][j]);
                  outFile << deckName[i][j] << endl;
               }
               else
               {
                  cout << "Back of Card" << endl;
                  getline(cin, deckName[i][j]);
                  outFile << deckName[i][j] << endl;
               }
            }
         }
         cout << "You have finished creating " << deckName << ".\nYou will be returned to the main menu." << endl;

      }
      break;
      case 3:
         // Allows the user to choose a deck to edit.
         inFile.open(fileName, ios::app);
         if (!inFile)
         {
            cout << "There are no decks to study.Please create a new deck." << endl;
            break;
         }
         else

            cout << "Choose from the following decks: " << endl;
         // Write Code for reading from the cardDecks.txt file to list available decks to choose from.
         readDecksMessage(deckNameArray);

      case 4:
         // Allows the user to delete an existing deck.
         inFile.open(fileName);

         if (inFile.is_open())  // Test to make sure open operation successful.
         {
            if (!inFile)
            {
               cout << "There are no decks to study.Please create a new deck." << endl;
               break;
            }


            else

               cout << "Choose from the following decks: " << endl;
            // Write Code for reading from the cardDecks.txt file to list available decks to choose from.

            readDecksMessage(deckNameArray);

         }
      case 99:
         break;

      default:
         cout << "Invalid Input." << endl;






      }
   } while (choice != 99);
   return 0;
}


// Function that shows the starting menu of the application and shows the options for the user to choose.
void mainMenu()
{
   cout << "Welcome to the FlashCard Study App!" << endl;
   cout << "***********************************" << endl;
   cout << "Please Choose from the Following Options:" << endl;
   cout << " 1: Study an Available Deck" << endl;
   cout << " 2: Create a New Deck" << endl;
   cout << " 3: Edit an Existing Deck" << endl;
   cout << " 4: Delete a Deck" << endl;
   cout << "99: Exit and Close App" << endl;
}

// Function that reads a message to user of the available decks.
void readDecksMessage(string deckArrays[])
{
   cout << "The available decks are: " << endl
      << "1: " << deckArrays[0] << endl
      << "2: " << deckArrays[1] << endl
      << "3: " << deckArrays[2] << endl
      << "99 to return to main menu." << endl;
}

// Function that reads the deck chosen by user.
void readDeck(string deckArray[][2])
{
   cout << "press any key to see next card" << endl;
   for (int i = 0; i < 4; i++)
      for (int j = 0; j < 2; j++)
         cout << deckArray[i][j] << endl;
   cin.get();
   getchar();

}


// Function that matches the number selection for the deck chosen by the user.
void userSelectsDeck(int deckSelected, string deckOne[][2], string deckTwo[][2], string deckThree[][2])
{
   switch (deckSelected)
   {
   case 1:
      readDeck(deckOne);
      cout << "End of Deck." << endl;

   case 2:
      readDeck(deckTwo);
      cout << "End of Deck." << endl;
   case 3:
      readDeck(deckThree);
      cout << "End of Deck." << endl;
   case 99:
      break;

   default:
      cout << "Choose a number 1-3. Or 99 to exit. " << endl;

   }
}
