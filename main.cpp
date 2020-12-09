#include <iostream>
#include <vector>
#include <ctime>

int main() {
    srand(time(nullptr));
    //Objects Input
    int playersNumber, objectsNumber = 3;
    std::cout << std::endl << "Enter a number of players: " << std::endl;
    std::cin >> playersNumber;
    std::cout << std::endl << "Enter an odd number of objects: " << std::endl;
    while (true)
    {
        std::cin >> objectsNumber;
        if (objectsNumber % 2 == 1)
        {
            break;
        }
        std::cout << "You chose an even number, try again" << std::endl;
    }

    //Vector of players
    std::vector <int> players(playersNumber);
    players[0] = 1;
    for(int i = 1; i < players.size(); i++)
    {
        players[i] = players[i-1] + 1;
    }

    int temp1, temp2;
    while (players.size()-1)
    {
        for (int i = 1; i < players.size(); i++)
        {
            //Random Object
            temp1 = rand() % objectsNumber + 1;
            std::cout << "Player " << players[i-1] << " chose " << temp1 << std::endl;
            temp2 = rand() % objectsNumber + 1;
            std::cout << "Player " << players[i] << " chose " << temp2 << std::endl;

            //DRAW
            if (temp1 == temp2)
            {
                std::cout << "It's a draw between player " << players[i-1] << " and " << players[i] << std::endl;
                continue;
            }

            //If they differ by 1
            if (temp1 - 1 == temp2 || temp1 - 1 + objectsNumber == temp2) //%
            {
                std::cout << "Player " << players[i] << " has won this round" << std::endl;
                std::rotate(players.begin(), players.begin() + i, players.end());
                players.pop_back();
                continue;
            }
            if (temp2-1 == temp1 || temp2 - 1 + objectsNumber == temp1)
            {
                std::cout << "Player " << players[i-1] << " has won this round" << std::endl;
                std::rotate(players.begin(), players.begin() + i + 1, players.end());
                players.pop_back();
                continue;
            }

            //Fight calculation
            //temp1 = (temp1-1)/2;
            //temp2 = (temp2-1)/2;
            if (temp1 >= ( (objectsNumber - 1 ) / 2 + temp2) || temp1 <= (( (objectsNumber)-1 ) / 2 + temp2) % objectsNumber && temp2 > temp1 || //<
            temp1 >= (( (objectsNumber)-1 ) / 2 + temp2) % objectsNumber && temp2 < temp1) //Errors
            {
                std::cout << "Player " << players[i] << " has won this round" << std::endl;
                std::rotate(players.begin(), players.begin() + i, players.end());
                players.pop_back();
                continue;
            }
            else
            {
                if (temp2 >= ( (objectsNumber - 1 ) / 2 + temp1) || temp2 <= ( (objectsNumber - 1 ) / 2 + temp1) % objectsNumber && temp1 > temp2 ||
                        temp2 >= (( (objectsNumber)-1 ) / 2 + temp1) % objectsNumber && temp1 < temp2) //Errors
                {
                    std::cout << "Player " << players[i-1] << " has won this round" << std::endl;
                    std::rotate(players.begin(),players.begin() + i + 1, players.end());
                    players.pop_back();
                    continue;
                }
            }
            std::rotate(players.begin(),players.begin() + i, players.end());
        }
    }

    std::cout << "Player " << players[0] << " has won!";

    return 0;
}
