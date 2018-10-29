#include "node.h"

namespace Graph {

	void initGraph(Node *head) {
		Node *current = head; // current->A
		Node *intersection = head;
		// head will point to letter A initially
		// take care of links in each direction for each intersectio
		current->setLinks(new Node('0', nullptr, current, nullptr, nullptr),
							 new Node('E', current, nullptr, nullptr, nullptr), 
							 new Node('B', nullptr, nullptr, nullptr, current),
							 new Node('0', nullptr, nullptr, current, nullptr));

		current = current->getSouthLink(); // current->E
		current->setSouthLink(new Node('I', current, nullptr, nullptr, nullptr));
		current->setEastLink(new Node('0', nullptr, nullptr, nullptr, current));
		current->setWestLink(new Node('0', nullptr, nullptr, current, nullptr));
		
		current = current->getSouthLink(); // current->I
		current->setEastLink(new Node('J', nullptr, nullptr, nullptr, current));
        current->setWestLink(new Node('0', nullptr, nullptr, current, nullptr));
        current->setSouthLink(new Node('0', current, nullptr, nullptr, nullptr));

        current = current->getEastLink(); // current->J
		current->setSouthLink(new Node('0', current, nullptr, nullptr, nullptr));
		current->setEastLink(new Node('0', nullptr, nullptr, nullptr, current));
        current->setNorthLink(new Node('0', nullptr, current, nullptr, nullptr));

		current = intersection; // current->A
		current = current->getEastLink(); // current->B
        current->setNorthLink(new Node('0', nullptr, current, nullptr, nullptr));
		current->setSouthLink(new Node('F', current, nullptr, nullptr, nullptr));
		current->setEastLink(new Node('0', nullptr, nullptr, nullptr, current));

		current = current->getSouthLink(); // current->F
		current->setSouthLink(new Node('0', current, nullptr, nullptr, nullptr));
		current->setEastLink(new Node('G', nullptr, nullptr, nullptr, current));
		current->setWestLink(new Node('0', nullptr, nullptr, current, nullptr));

		current = current->getEastLink(); // current->G
		intersection = current; // at position G
		current->setNorthLink(new Node('C' , nullptr, current, nullptr, nullptr));
		current->setSouthLink(new Node('K' , current, nullptr, nullptr, nullptr));
		current->setEastLink(new Node('H' , nullptr, nullptr, nullptr, current));

		current = current->getNorthLink(); // current->C
		current->setNorthLink(new Node('0', nullptr, current, nullptr, nullptr));
		current->setEastLink(new Node('D', nullptr, nullptr, nullptr, current));
		current->setWestLink(new Node('0', nullptr, nullptr, nullptr, nullptr));

        current = current->getEastLink();
		current->setSouthLink(new Node('0', current, nullptr, nullptr, nullptr));
		current->setEastLink(new Node('0', nullptr, nullptr, nullptr, current));
        current->setNorthLink(new Node('0', nullptr, current, nullptr, nullptr));

		current = intersection; // current->G
		current = current->getEastLink(); // current->H
        current->setNorthLink(new Node('0', nullptr, current, nullptr, nullptr));
        current->setEastLink(new Node('0', nullptr, nullptr, nullptr, current));
		current->setSouthLink(new Node('L' , current, nullptr, nullptr, nullptr));

        current = current->getSouthLink(); // current->L
        current->setSouthLink(new Node('0', current, nullptr, nullptr, nullptr));
        current->setEastLink(new Node('0', nullptr, nullptr, nullptr, current));
        current->setWestLink(new Node('0', nullptr, nullptr, current, nullptr));

        current = intersection; // current->G
        current = current->getSouthLink(); // current->K
        current->setSouthLink(new Node('0', current, nullptr, nullptr, nullptr));
        current->setEastLink(new Node('0', nullptr, nullptr, nullptr, current));
        current->setWestLink(new Node('0', nullptr, nullptr, current, nullptr));

	}

}
