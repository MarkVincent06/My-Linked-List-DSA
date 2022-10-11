#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Node* head; // global variable, can be accessed anywhere

// creates a new node
Node* getNode(int pValue) {
    Node* newNode = new Node();
    newNode->data = pValue;
    newNode->next = head;

    return newNode;
}

// This inserts the node at the beginning
void insertNodeAtBeginning(int pValue) {
    Node* newNode = getNode(pValue);
    head = newNode;
}

void insertNodeAtMiddle(int pValue) {
    Node* newNode = getNode(pValue);

    if(head == NULL) {
        head = newNode;
    } else {
        Node* middle = head;
        int length = 0;

        while(middle->next != NULL) {
            length++;
            middle = middle->next;
        }

        int count = ((length % 2) == 0) ? (length / 2) : (length + 1) / 2;

        middle = head;

        while(count-- > 1) {
            middle = middle->next;
        }

        newNode->next = middle->next;
        middle->next = newNode;
    }
}

// This inserts the node at the end
void insertNodeAtEnd(int pValue) {
    Node* newNode = getNode(pValue);
    newNode->next = NULL;

    Node* last = head;
    
    if(last != NULL) {
        while(last->next != NULL) {
            last = last->next;
        }

        last->next = newNode;
    } else {
        head = newNode;
    }
}

// This will delete the node at the beginning
void deleteNodeAtBeginning() {
    if(head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        cout << "The list is empty." << endl;
    }
}

// This will delete the node at the middle
void deleteNodeAtMiddle() {
    int count = 0;
    Node* temp = head;
    
    while(temp != NULL) {
        temp = temp->next;
        count++;
    }
    // cout << "The number of nodes is " << count << endl;
    if(head == NULL) {
        head = NULL;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
    }

    Node* copyHead = head;
    int middle = count / 2 ;    

    while(middle-- > 1) {
        copyHead = copyHead->next;
    }

    copyHead->next = copyHead->next->next;
}

// this will delete the node at the end
void deleteNodeAtEnd() {  
    if (head == NULL)
        head = NULL;
 
    if (head->next == NULL) {
        delete head;
        head = NULL;
    }

    Node* secondLastNode = head;
    while(secondLastNode->next->next != NULL) {
        secondLastNode = secondLastNode->next;
    }

    delete secondLastNode->next;
    secondLastNode->next = NULL;

}

void printNode(char input) {
    Node* temp = head;

        if(input == '1') cout << "\nAfter inserting at the start, the updated linked list are: \n";    
        else if (input == '2') cout << "\nAfter inserting at the middle, the updated linked list are: \n"; 
        else if (input == '3') cout << "\nAfter inserting at the end, the updated linked list are: \n"; 
        else if (input == '4') cout << "\nAfter deleting at the start, the updated linked list are: \n"; 
        else if (input == '5') cout << "\nAfter deleting at the middle, the updated linked list are: \n"; 
        else if (input == '6') cout << "\nAfter deleting at the end, the updated linked list are: \n";
        else cout << "\nThe current linked list are: \n";

        while(temp != NULL) {
            if(temp->next != NULL) {
                cout << temp->data << " -> ";
            } else {
                cout << temp->data << " -> NULL";
            }
            temp = temp->next;
        }
        cout << "\n";
}

int main() {
    head = NULL; // empty list
    int noOfNodes, value;

    cout << "Input the number of nodes: ";
    cin >> noOfNodes;

    cout << endl;
    for(int i=1; i<=noOfNodes; i++) {
        cout << "Input data for node " << i << ": ";
        cin >> value;
        insertNodeAtBeginning(value);
    }   

    if(head == NULL) {
        cout << "The list is empty." << endl;
    } else {
        Node* temp = head;

        cout << "\nThe linked list are: ";    
        while(temp != NULL) {
            if(temp->next != NULL) {
                cout << temp->data << " -> ";
            } else {
                cout << temp->data << " -> NULL";
            }
            temp = temp->next;
        }
        cout << "\n";
    }

    char choice;

    cout << "\nDo you want to insert an operation in the linked list above (y or n)? ";
    while(true) {
        cin >> choice;
        if(choice == 'y') {
            break;
        } else if(choice == 'n') {
            return 1;
        } else {
            cout << "Invalid choice!" << endl;
            cout << "Insert an operation in the linked list above (y or n)? ";
        }
    }
    
    cout << "\n(1) Insert a new node at the start" << endl;
    cout << "(2) Insert a new node at the middle" << endl;
    cout << "(3) Insert a new node at the end" << endl;
    cout << "(4) Delete a node at the front" << endl;
    cout << "(5) Delete a node at the middle" << endl;
    cout << "(6) Delete a node at the end" << endl;

    int data;
    char input;
    bool breakLoop = false;

    cout << "\nSelect an operation to be used based on the list above (1-6): ";
    while(!breakLoop) {
        cin >> input;
        switch(input) {
            case '1':
                printNode('0');
                cout << "Input data for the first node: ";
                cin >> data;
                insertNodeAtBeginning(data);
                printNode('1');
                breakLoop = true;
                break;
            case '2':
                printNode('0');
                cout << "Input data for the middle node: ";
                cin >> data;
                insertNodeAtMiddle(data);
                printNode('2');
                breakLoop = true;
                break;
            case '3':
                printNode('0');
                cout << "Input data for the end node: ";
                cin >> data;
                insertNodeAtEnd(data);
                printNode('3');
                breakLoop = true;
                break;
            case '4':
                printNode('0');
                deleteNodeAtBeginning();
                printNode('4');
                breakLoop = true;
                break;
            case '5':
                printNode('0');
                deleteNodeAtMiddle();
                printNode('5');
                breakLoop = true;
                break;
            case '6':
                printNode('0');
                deleteNodeAtEnd();
                printNode('6');
                breakLoop = true;
                break;
            default: 
                cout << "Ivalid input!" << endl;
                cout << "Please select an operation between {1-6} based on the list above: ";
               break;
        }
    }
    
    cout << "\nSuccess :)" << endl;
    return 0;
}