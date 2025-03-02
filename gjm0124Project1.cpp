//People that helped make this project - Ryan Griffin rcg0149 RyanGriffin3@my.unt.edu


#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

int main(){

    //Initialize variables
    int points = 100;
    int rand1;
    int rand2;
    string userName;
    int getOper;
    int counter = 0;
    int correct_answer = 0;
    bool playAgain = true;
    char YON = ' ';
    bool choice;
    int i;

    enum OPERATION{ADD = 1,SUBTRACT = 2, DISPLAY = 3, GIVEUP = 4, EXIT = 5};
    OPERATION operation;

    srand(time(0)); // declaring the seed for the random number generator

    string caption = "+-------------------------------------------------------+\n"
                    "|\tComputer Science and Engineering\t\t|\n"
                    "|\tCSCE 1030 - Computer Science I\t\t\t|\n"
                    "|\tGael Mendez  gjm0124 gaelmendez@my.unt.edu\t|\n"
                    "--------------------------------------------------------+\n";

    cout << caption << endl;

    do
    {
 
        choice = true;

        cout << "Enter your name: ";
        getline(cin, userName);

        for (i = 0; i < userName.size(); ++i)
        {
            if (!(isalpha(userName.at(i)) || isspace(userName.at(i)))) // checks each string and make sure there is only alphabet letters or spaces
            {
                choice = false; // if its false break out of the loop
                break;
            }
        }

        if (!(choice)) // if false we will output the message
        {
            cout << "Your name can only have alphabets or spaces. Enter again." << endl; // if its false you must keep on entering until its true
        }

    } while (!choice);

    bool word = true; // check every first word that the user enters
    for (i = 0; i < userName.size(); ++i)
    {
        if (isalpha(userName.at(i)))
        {
            if (word)
            {
                userName.at(i) = toupper(userName.at(i)); // makes sure the first letter of each word will be capitalized
                word = false;
            }
            else
            {
                userName.at(i) = tolower(userName.at(i)); // the rest of the remaining letters will be lowercase
            }
        }
        else
        {
            word = true;
        }
    }
    cout << "Welcome " << userName << endl;

    do
    {
        rand1 = rand() % (150 - 100 + 1) + 100; // generating the random numbers for both variables
        rand2 = rand() % (150 - 100 + 1) + 100;
    } while (rand1 >= rand2);

    cout << "Your two random numbers have been generated " << endl;

    

    

    //Making a multistring output to the screen
    string OperationMultiString = "\n1.ADD\n"
                            "2.Subtract\n"
                            "3.DISPLAY\n"
                            "4.GIVEUP\n"
                            "5.EXIT\n";

  do{                         
        cout << OperationMultiString << endl;

        cout << "Enter your choice: ";
        cin >> getOper;

        operation = static_cast<OPERATION>(getOper);


        // Making a switch case to be able to calculate the different options that there are.
        switch(operation){

            // Adds the two random numbers and checks if the user guess is an absolute difference less than 5
            case ADD:
            int guessSum;
            
            cout << "Enter your guess sum: ";
            cin >> guessSum;

            correct_answer = rand1 + rand2;

            if (fabs(correct_answer - guessSum) <= 5){
                points += 5;

                cout << "Your guess was close enough. You win. Your updated points are: " << points << endl;
                cout << "Do you want to restart the game? Y/N: ";
                cin >> YON;

                if(toupper(YON) == 'Y'){
                    playAgain = true;
                    cout << " Your two numbers have been generated." << endl;
                }else if (toupper(YON) == 'N'){
                    
                    cout << "Your final points are: " << points << endl;
                    cout << "Goodbye, " << userName << endl;
                    playAgain = false;
                    
                }
                
            }else{
                cout << "Wrong guess" << endl;
                points--;
                cout << "Your updated points are: " << points << "\n" << endl;         
            }
            break;
            // Subtracts the two random numbers and checks if the user guess is an absolute difference less than 5
            case SUBTRACT:
                int guessDiff;
                cout << "Enter your guess diference: ";
                cin >> guessDiff;

                correct_answer = rand1 - rand2;

                if(fabs(correct_answer - guessDiff) <= 5){
                    points += 5;

                    cout << "Your guess was close enough. You win. Your updated points are: " << points << endl;
                    cout << "Do you want to restart the game? Y/N: ";
                    cin >> YON;

                    if(toupper(YON) == 'Y'){
                        playAgain = true;
                        cout << " Your two numbers have been generated." << endl;
                    }else if (toupper(YON) == 'N'){
                        
                        cout << "Your final points are: " << points << endl;
                        cout << "Goodbye, " << userName << endl;
                        playAgain = false;
                    }
                }else{
                    cout << "Wrong guess" << endl;
                    points--;
                    cout << "Your updated points are: " << points << "\n" << endl; 
                }

            break;

                /*
                Displays the first random number and if he asks again we tell the user that he or she already
                has displayed the first number, then print the first number agan

                */ 

            case DISPLAY:
                if(counter == 0){
                    points -= 3;
                    cout << "Your final points are: " << points << endl;
                    cout << "The first random number is: " << rand1 << endl;
                    
                }else{
                    cout << "You have already displayed the first number." << endl;
                    cout << "The first random number is: " << rand1 << endl;
                }
                counter++;
                break;

                /*
                The user gives up and is being promted if he wants to play again.
                */

            case GIVEUP:

                cout << "Do you want to restart the game? Y/N: ";
                cin >> YON;

                if(toupper(YON) == 'Y'){
                    playAgain = true;
                    cout << " Your two numbers have been generated." << endl;
                }else if (toupper(YON) == 'N'){
                    
                    cout << "Your final points are: " << points << endl;
                    cout << "Goodbye, " << userName << endl;
                    playAgain = false;
                }

            break;

            // If the user tries to exit the program, the final points are displayed and the program ends.

            case EXIT:
                cout << "Your final points are: " << points << endl;
                cout << "Goodbye, " << userName << endl;
                playAgain = false;
            break;
            default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    }while(playAgain);

    return 0;    
    }
    