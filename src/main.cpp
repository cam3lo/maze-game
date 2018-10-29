/* 
	Program that implements a graph to be interpreted as a maze
	using instances of a Node class.
	Author: jese camilo
*/
#include <iostream>
#include "node.h"

using namespace Graph;

int main() {
	Node *entrance = new Node('A');
	Node *currentPosition = entrance;
	char direction;

	Graph::initGraph(entrance); // initialize the maze
	std::cout << "You are in room " << currentPosition->getRoom()
			  << " of the maze." << std::endl;

	std::cout << "You can go " << std::endl;
	std::cout << "----------" << std::endl;
	currentPosition->getDirections();

	do {
		std::cout << "Choose your path (q to quit): ";
		std::cin >> direction;
		if(direction == '0')
			std::cout << "Invalid choice." << std::endl;
		else if(direction == 'q')
			break; 
        else if(currentPosition->getRoom() == 'L') {
			std::cout << "Congrats! You solved the maze!";
			break;
		}
		else {
			currentPosition = currentPosition->moveRoom(direction);
			std::cout << "You can go " << std::endl;
			std::cout << "----------" << std::endl;
			currentPosition->getDirections();
		}
	} while(direction != 'q');

	return 0;
}
