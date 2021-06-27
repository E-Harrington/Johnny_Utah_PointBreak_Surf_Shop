/*******************************************************************************
Week05 Programming Assignment
Eric Harrington

***********************Before main()********************************************
1: Declare prototype functions

***********************Within main()*********************************************
2: Declare 3 const doubles for board prices

3: Declare char variable userInput, which will be used as a sentinel variable; 
   initialize it to a character that is not 'Q'

4: Declare 3 int variables to keep track of the number of small, medium, and large
   surfboards that have been purchased

5: Set up a while loop that runs while char userInput does not equal "q" and place
   a prompt for user input at beginning of while loop; after the cin statement,
   set the char sentinel to uppercase using toupper()

6: Set up an "if...else-if" structure that calls functions if the user enters
   the corresponding character; for now, just set up the conditions

**************************After main()*******************************************
7: Define ShowTitle() by declaring and initializing a string variable for the
   title and an int variable for the program width, and use these variables to
   help format cout statements

8: Define Show usage via a series of cout statements that match assignment example

9: Define MakePurchase() using reference variables, and within function declare
   and initialize an int variable and a char variable that will be assigned to
   the user's input for board quantity and board type; set up a while loop to correct
   invalid user input; use if statements to update corresponding board total based
   on successful user input

10: Define DisplayPurchase() using an if-else statement; the if statement should check
   whether any of the board quantities is greater than zero; if any are, then use if
   statements to check each board total and display that board's total if the board total
   is greater than zero; within the else statement, use cout to display that no purchases
   have been made;


11: Define DisplayTotal(): use "cout << fixed << setprecision(2) << showpoint" to format
    output for displaying money; declare a double variable totalSales to track the total
    amount of money earned from board sales and initialize it to zero; set up an if-else
    statement; the if statement should check whether any of the board quantities is greater
    than zero; if any are, then use if statements to check each boards quantity and display
    the quantity of that board; last, assign the value of the totalSales variable to the 
    sum of the quantity of boards times their prices;

12: Define ClosingMessage() using a cout statement and iomanip's system("pause") function

***********************Within main()*********************************************
13: Now that functions are defined, call them within their respective if or if-else
    statement using the appropriate variables as arguments; also, call ClosingMessage()
    outside of any if or if-else statement

*******************************************************************************/

#include<iostream>
#include<iomanip>
#include<string>
#include<cctype>

using namespace std;


//Step 1
/***********************************Prototypes***********************************************/

//A function to display the title of the program
void ShowTitle();

//A function to show the user how to use the program
void ShowUsage();

//A function to sell surfboards
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge);

//A function to show the number of surfboards of each size sold
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);

//A Function to show the total amount of money made
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const double, const double, const double);

//A function to display closing message
void ClosingMessage();

/********************************************************************************************/

int main()
{
    //Step2
    const double SMALL_BOARD_PRICE = 175.00;
    const double MEDIUM_BOARD_PRICE = 190.00;
    const double LARGE_BOARD_PRICE = 200.00;

    //Step 3
    char userInput = 'y';

    //Step 4
    int iTotalSmall = 0;
    int iTotalMedium = 0;
    int iTotalLarge = 0;

    ShowTitle();

    cout << endl << endl;

    ShowUsage();

    //Step 5
    while (userInput != 'Q')
    {
        cout << "Please enter selection: ";
        cin >> userInput;
        userInput = toupper(userInput);

        //Step 6
        if (userInput == 'S')
            ShowUsage();//Step 13

        else if (userInput == 'P')
            MakePurchase(iTotalSmall, iTotalMedium, iTotalLarge);//Step 13

        else if (userInput == 'C')
            DisplayPurchase(iTotalSmall, iTotalMedium, iTotalLarge);//Step 13

        else if (userInput == 'T')
            DisplayTotal(iTotalSmall, iTotalMedium, iTotalLarge, SMALL_BOARD_PRICE, MEDIUM_BOARD_PRICE, LARGE_BOARD_PRICE);//Step 13
    }

    ClosingMessage();//Step 13

    return 0;
}


/***************************************************************Function Definitions**************************************************************************************/

//Step 7
void ShowTitle()
{
    const string TITLE = "Welcome to my Johnny Utah's PointBreak Surf Shop";
    unsigned __int64 progWidth = 60;
    cout << setfill('*');

    cout << setw(progWidth) << " " << endl;

    cout << setw(progWidth / 2 + TITLE.length() / 2) << TITLE
        << setw(progWidth - (progWidth / 2 + TITLE.length() / 2)) << " " << endl;

    cout << setw(progWidth) << " " << endl;

}

//Step 8
void ShowUsage()
{
    cout << endl << "To show program usage 'S'" << endl;
    cout << "To purchase a surfboard press 'P'" << endl;
    cout << "To display current purchases press 'C'" << endl;
    cout << "To display total amount due press 'T'" << endl;
    cout << "To quit the program press 'Q'" << endl << endl;
}

//Step 9
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)
{
    int boardSelectionQuantity = 0;
    char boardSelectionSize = ' ';

    cout << "Please enter the quantity and type (S=small, M=medium, L=large)"
        << " of surfboard you \nwould like to purchase: ";
    cin >> boardSelectionQuantity >> boardSelectionSize;

    while (!cin)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << endl << "Invalid input:" << endl;
        cout << "Please enter the quantity and type (S=small, M=medium, L=large)"
            << " of surfboard you \nwould like to purchase: ";
        cin >> boardSelectionQuantity >> boardSelectionSize;
    }

    boardSelectionSize = toupper(boardSelectionSize);

    if (boardSelectionSize == 'S')
        iTotalSmall += boardSelectionQuantity;

    else if (boardSelectionSize == 'M')
        iTotalMedium += boardSelectionQuantity;

    else if (boardSelectionSize == 'L')
        iTotalLarge += boardSelectionQuantity;

    cout << endl << endl;

}

//Step 10
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
    if (iTotalSmall > 0 || iTotalMedium > 0 || iTotalLarge > 0)
    {
        if (iTotalSmall > 0)
            cout << "The total number of small surfboards is " << iTotalSmall << endl;

        if (iTotalMedium > 0)
            cout << "The total number of medium surfboards is " << iTotalMedium << endl;

        if (iTotalLarge > 0)
            cout << "The total number of large surfboards is " << iTotalLarge << endl;

        if (iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0)
            cout << "No purchases made yet." << endl;

        cout << endl;
    }
    else
        cout << "No purchases made yet." << endl << endl;

}

//Step 11
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const double smallPrice, const double mediumPrice, const double largePrice)
{
    cout << fixed << setprecision(2) << showpoint;
    double total = 0;

    if (iTotalSmall > 0 || iTotalMedium > 0 || iTotalLarge > 0)

    {
        if (iTotalSmall > 0)
        {
            cout << "The total number of small surfboards is " << iTotalSmall
                << " at a total of $" << iTotalSmall * smallPrice << endl;
        }

        if (iTotalMedium > 0)
        {
            cout << "The total number of medium surfboards is " << iTotalMedium
                << " at a total of $" << iTotalMedium * mediumPrice << endl;
        }

        if (iTotalLarge > 0)
        {
            cout << "The total number of large surfboards is " << iTotalLarge
                << " at a total of $" << iTotalLarge * largePrice << endl;
        }

        total = iTotalSmall * smallPrice + iTotalMedium * mediumPrice + iTotalLarge * largePrice;
        cout << "Amount due: $" << total << endl << endl;
    }
    else
        cout << "No purchases made yet." << endl << endl;


}

//Step 12
void ClosingMessage()
{
    cout << "Thank you" << endl;
    system("pause");
}

/*************************************************************************************************************************************************************************/