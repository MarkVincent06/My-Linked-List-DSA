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

// This prints the node(s)
void printNode() {
    Node* temp = head;

    if(temp == NULL) {
        cout << "\t\tThe List for now is empty." << endl;
    } else {
         cout << "\t\tThe Linked List is/are: ";
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
}


int main() {
    head = NULL; // empty list


    // cout << endl;
    // for(int i=1; i<=noOfNodes; i++) {
    //     cout << "Input data for node " << i << ": ";
    //     cin >> value;
    //     insertNodeAtBeginning(value);
    //     PrintNode();
    // }

    // cout << "Input the number of nodes: ";
    // int n, value;
    // cin >> n;


    // deleteNodeAtEnd();
    // PrintNode();



    return 0;
}