#include <iostream>

#ifndef GRAPH_H
#define GRAPH_H
	
namespace Graph {

	class Node {
		public:
			// node constructors
			Node(const char letter): room(letter), northLink(nullptr), 
				southLink(nullptr), eastLink(nullptr), westLink(nullptr) { };

			Node(const char letter, Node *north, Node *south, Node *east, 
				Node *west): room(letter), northLink(north), southLink(south),
				eastLink(east), westLink(west) { };

			/*
				Accessor Functions
			*/

			// return user's current room
			const char getRoom() const { return room; }

			// print available directions for user
			void getDirections() { 
				if(northLink->getRoom() != '0')
					std::cout << "North: " << northLink->room << std::endl;
				if(southLink->getRoom() != '0')
					std::cout << "South: " << southLink->room << std::endl;
				if(eastLink->getRoom() != '0')
					std::cout << "East: " << eastLink->room << std::endl;
				if(westLink->getRoom() != '0')
					std::cout << "West: " << westLink->room << std::endl;
			}

			//gets northLink of current node
			Node* getNorthLink() {
				return northLink;
			}

			// gets southLink of current node
			Node* getSouthLink() {
				return southLink;
			}

			// gets eastLink of current node
			Node* getEastLink() {
				return eastLink;
			}

			// gets westLink of current node
			Node* getWestLink() {
				return westLink;
			}

			/*
				Mutator Functions
			*/

			// sets the links of the current intersection node simulataneously
			// then sets the links of the new links to null
			void setLinks(Node *north, Node *south, Node *east, Node *west) {
				northLink = north;
				southLink = south;
				eastLink = east;
				westLink = west;
			}

			//sets northLink of current node
			void setNorthLink(Node *north) {
				northLink = north;
			}

			// sets southLink of current node
			void setSouthLink(Node *south) {
				southLink = south;
			}

			// sets eastLink of current node
			void setEastLink(Node *east) {
				eastLink = east;
			}

			// set westLink of current node
			void setWestLink(Node *west) {
				westLink = west;
			}

			// moves user to new room after selecting a direction
			// by return pointer to the selected room
			Node* moveRoom(char direction) const { 
				if(direction == northLink->room)
					return northLink;
				else if(direction == southLink->room)
					return southLink;
				else if(direction == eastLink->room)
					return eastLink;
				else if(direction == westLink->room)
					return westLink;
				else
					return nullptr;
			}


		private:
			Node *northLink, *southLink, *eastLink, *westLink;
			char room;
	};

	// initialze the graph after having been passed the head
	// which will contain the letter A
	void initGraph(Node *head);

}

#endif
