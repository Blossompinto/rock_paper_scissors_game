#include <iostream>
#include <cstdlib>
#include <ctime>

//prints the game rules
void printRules(){
   std::cout << "Basic Rules: type in R for rock, P for paper or S for scissors to play. To end the game type x" << std::endl;
    std::cout << "Rules of the game: rock beats scissors, scissors beat paper, and paper beats rock" << std::endl; 
}

//checks to see if the user input is a valid play
bool isValid (char c){
    switch(c){
        case 's':
        return true;
        break;
        case 'r':
        return true;
        break;
        case 'p':
        return true;
        break;
        case 'x':
        return true;
        break;
        case 'S':
        return true;
        break;
        case 'R':
        return true;
        break;
        case 'P':
        return true;
        break;
        case 'X':
        return true;
        break;
    }
    return false;
}

//generates the move for the computer based on the random number 
char play(int num){
   if(num == 0){
       return 'r';
   }
   else if(num == 1){
       return 'p';
   }
   return 's';
}

// determines the winner of each round
void winner(char user, char comp){
    if(user == comp){
        std::cout << "It's a tie!" << std::endl;
    }
    else if((comp == 'r' && user == 's') || (comp == 'r' && user == 'S')){
         std::cout << "Computer wins! :P" << std::endl;
    }
    else if((comp == 's' && user == 'p') || (comp == 's' && user == 'P')){
        std::cout << "Computer wins! :P" << std::endl;
    }
    else if((comp == 'p' && user == 'r') || (comp == 'p' && user == 'R')){
        std::cout << "Computer wins! :P" << std::endl;
    }
    else{
        std::cout << "You win!" << std::endl;
    }
}

int main() {
    //sets the seed to generate a random number
    srand(static_cast<unsigned int>(time(NULL)));
    printRules();
    char input;
    std::cin >> input;
    //keep the game going until the user decides to end the game
    while(input != 'x' || input != 'X'){
    //calls the function to print rules of the game
        std::cin >> input;
        bool valid = isValid(input);
        //checks if the input is a valid play
        if(valid){
            //generate a random number
            int random_number = rand() % (3);
            //call the play funtion to play for the computer
            char c = play(random_number);
            winner(input, c);
            }
            else {
                std::cout << "Invalid input enter r,s,p, or x" << std::endl;
            }
    }
}
