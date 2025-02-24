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
    int rand1 = 150;
    int rand2 = 300;
    string userName;
    int getOper;
    int counter = 0;
    int correct_answer = 0;
    bool playAgain = true;
    char YON = ' ';


    enum OPERATION{ADD = 1,SUBTRACT = 2, DISPLAY = 3, GIVEUP = 4, EXIT = 5};
    OPERATION operation;

    cout << "Enter your name: ";
    getline(cin, userName);

    

    //Making a multistring output to the screen
    string OperationMultiString = "1.ADD\n"
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
                cout << " Enter your guess diference: ";
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
                }

            break;
                /*
                Displays the first random number and if he asks again we tell the user that he or she already
                has displayed the first number, then print the first number agan

                */ 

            case DISPLAY:
                if(counter == 0){
                    cout << "The first random number is: " << rand1 << endl;
                    points -= 3;
                }else{
                    cout << "You have already displayed the first number." << endl;
                    cout << "The first random number is: " << rand1 << endl;
                }
                counter++;
                break;

            case GIVEUP:
            break;
            case EXIT:
                cout << "Your final points are: " << points << endl;
                cout << "Goodbye, " << userName << endl;
                playAgain = false;
            break;

    }
    }while(playAgain);

    return 0;    
}

