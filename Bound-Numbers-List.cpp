#include <iostream>

#include <algorithm>

using namespace std;

// Define the basic unit Element which has data and a pointer to the next Element.
struct Element {
    int data; // Data part of the element.
    Element * following; // Pointer to the next element.
};

// Define a class for the list that bounds the number to a certain limit.
class BoundNumbersList {
    private: int limit; // The upper limit for values in the list.
    Element * start; // Pointer to the first element in the list.

    public:
        // Constructor to initialize the list with a given limit.
        BoundNumbersList(int limitFromUser);

    // Destructor to free up the memory allocated for the list.
    ~BoundNumbersList();

    // Function to insert an element to the front of the list.
    bool insertElement(int value);

    // Function to insert an element at a specific position in the list.
    bool insertPosition(int value, int position);

    // Function to delete the front element of the list.
    bool deleteFrontList();

    // Function to delete an element at a specific position.
    bool deleteElement(int position);

    // Function to display the list (seems to be missing its implementation).
    void displayBound();

    // Getter for the limit value.
    int getLimit() {
        return limit;
    }

    // Pointer to the next BoundNumbersList object.
    BoundNumbersList * following;

    // Getter for the start of the list.
    Element * getStart() {
        return start;
    }
};

// Constructor implementation.
BoundNumbersList::BoundNumbersList(int limitFromUser) {
    limit = limitFromUser;
    start = nullptr; // Initialize start as null.
    following = nullptr; // Initialize the following pointer as null.
}

// Destructor implementation.
BoundNumbersList::~BoundNumbersList() {
    // Delete all elements from the list.
    while (start != nullptr) {
        Element * temp = start;
        start = start -> following;
        delete temp;
    }
}



bool BoundNumbersList::deleteFrontList() {
    if (start == nullptr) {
        // If the list is empty, nothing to delete.
        return false;
    } else {
        // Save the pointer to the first element.
        Element * temp = start;
        // Move the start pointer to the next element.
        start = start -> following;
        // Delete the saved first element.
        delete temp;
        return true;
    }
}

// Function to find a BoundNumbersList with a specific limit.
BoundNumbersList * findListByLimit(BoundNumbersList * initialList, int providedLimit) {
    BoundNumbersList * activeList = initialList;
    while (activeList != nullptr) {
        if (activeList -> getLimit() == providedLimit) {
            return activeList;
        }
        activeList = activeList -> following;
    }
    return nullptr; // Return null if list with provided limit is not found.
}

bool BoundNumbersList::insertElement(int value) {
    if (value > limit) {
        cout << "Value surpasses the limit and cannot be added." << endl;
        return false;
    } else {
        Element * newElement = new Element;
        newElement -> data = value;
        newElement -> following = start; // New element points to the previous start.
        start = newElement; // Update start to point to the new element.
        return true;
    }
}

bool BoundNumbersList::insertPosition(int value, int position) {
    if (position < 1) {
        cout << "Enter a positive integer for the position.";
        return false;
    }

    Element * newElement = new Element;
    newElement -> data = value;

    // If inserting at the first position or list is empty.
    if (position == 1 || start == nullptr) {
        newElement -> following = start;
        start = newElement;
        return true;
    }

    Element * current = start;
    int currentPos = 1;

    // Traverse the list to find the correct position or end of the list.
    while ((currentPos < (position - 1)) && (current -> following != nullptr)) {
        current = current -> following;
        currentPos++;
        if (current -> following == nullptr) {
            cout << "Specified position exceeds list length. Value inserted at the end instead." << endl;
        }
    }

    // Insert the new element.
    newElement -> following = current -> following;
    current -> following = newElement;

    return true;
}

bool BoundNumbersList::deleteElement(int position) {
    // Check if position is valid (greater than or equal to 1).
    if (position >= 1) {
        // If it's not the first position.
        if (position != 1) {
            Element * current = start; // Pointer to traverse the list.
            Element * prev = nullptr; // Pointer to the previous element.
            int currentPos = 1;

            // Traverse the list until the specified position or end of the list.
            while (current != nullptr && currentPos < position) {
                prev = current; // Move the previous pointer.
                current = current -> following; // Move to the next element.
                currentPos++;
            }

            // If we found the element at the specified position.
            if (current != nullptr) {
                // Delete the element and adjust the pointers.
                prev -> following = current -> following;
                delete current;
                return true;
            }
            // Element not found at the specified position.
            return false;
        }
        // If it's the first position, use the deleteFrontList function.
        return deleteFrontList();
    }
    // Position is not valid.
    return false;
}

void BoundNumbersList::displayBound() {
    Element * current = start; // Pointer to traverse the list.

    // Traverse and print all elements in the list.
    while (current != nullptr) {
        cout << current -> data << " ";
        current = current -> following;
    }
    cout << endl;
}

int main() {
    // Initial and final pointers to track the BoundNumbersList objects.
    BoundNumbersList * initialList = nullptr;
    BoundNumbersList * finalList = nullptr;

    // Infinite loop for the menu-driven system.
    while (true) {
        int choice;
        cout << "\n--- Menu ---" << endl;
        cout << "Note: Index starts from 1." << endl;
        // Display the menu options to the user.
        cout << "1. Create new list" << endl;
        cout << "2. Add value to list" << endl;
        cout << "3. Remove front from list" << endl;
        cout << "4. Remove item from list" << endl;
        cout << "5. Merge two lists (no duplicates)" << endl;
        cout << "6. Show limit value for each list" << endl;
        cout << "7. Show all items in a specific list" << endl;
        cout << "8. Exit\n" << endl;
        cout << "Choice: ";
        cin >> choice;

        // Process the user's choice.
        switch (choice) {
        case 1: {
            int limit;
            cout << "Enter the limit value for the new list: ";
            cin >> limit;
            bool isUnique = true;
            BoundNumbersList * activeList = initialList;

            // Check if a list with the same limit already exists.
            while (activeList != nullptr) {
                if (activeList -> getLimit() == limit) {
                    cout << "A list already exists with that limit value. Please select a different, unique limit." << endl;
                    isUnique = false;
                    break;
                }
                activeList = activeList -> following;
            }

            // If the limit is unique, create a new list.
            if (isUnique) {
                BoundNumbersList * newList = new BoundNumbersList(limit);
                if (finalList != nullptr) {
                    finalList -> following = newList;
                }
                finalList = newList;
                if (initialList == nullptr) {
                    initialList = newList;
                }
                cout << "Created a new list with limit value " << limit << endl;
            }
            break;
        }
        case 2: {
            int limit, value;
            cout << "Enter the limit value: ";
            cin >> limit;

            BoundNumbersList * activeList = initialList;
            BoundNumbersList * targetList = nullptr;

            // Find the list with the specified limit.
            while (activeList != nullptr) {
                if (activeList -> getLimit() == limit) {
                    targetList = activeList;
                    break;
                }
                activeList = activeList -> following;
            }

            if (targetList == nullptr) {
                cout << "No list exists with this limit value." << endl;
                break;
            } else {
                cout << "\n--- Options ---" << endl;
                cout << "1. Insert at the Front" << endl;
                cout << "2. Insert at a specific position" << endl;
                cout << "Choice: ";
                int insertChoice;
                cin >> insertChoice;

                // Process the insertion choice.
                if (insertChoice == 1) {
                    cout << "\nValue to insert at the Front: ";
                    cin >> value;
                    if (targetList -> insertElement(value)) {
                        cout << "Value added to the Front successfully." << endl;
                    } else {
                        cout << "Insertion failed. Try again." << endl;
                    }
                } else if (insertChoice == 2) {
                    int position;
                    cout << "\nPosition for insertion: ";
                    cin >> position;

                    if (position < 1) {
                        cout << "Invalid position. Use a positive integer." << endl;
                    } else {
                        cout << "Enter a value to insert: ";
                        cin >> value;

                        if (targetList -> insertPosition(value, position)) {
                            cout << "Insertion successful.\n" << endl;
                        } else {
                            cout << "Insertion failed.\n" << endl;
                        }
                    }
                } else {
                    cout << "Invalid option. Choose again." << endl;
                }
                break;
            }
        }
        case 3: {
            // Delete the front list.
            if (initialList == nullptr) {
                cout << "List is empty. Nothing to remove." << endl;
            } else {
                BoundNumbersList * temp = initialList;
                initialList = initialList -> following;
                delete temp;
                cout << "Removed the Front of the list." << endl;
            }
            break;
        }
        case 4: {
            // Delete an element from a list specified by its limit.
            int limit;
            cout << "Enter the limit value of the list to delete: ";
            cin >> limit;

            BoundNumbersList * targetList = findListByLimit(initialList, limit);

            if (targetList != nullptr) {
                int position;
                cout << "Specify the item's index to delete: ";
                cin >> position;

                if (position < 1) {
                    cout << "Error: Use a positive index value." << endl;
                } else {
                    if (targetList -> deleteElement(position)) {
                        cout << "Item at position " << position << " removed from the list with limit " << limit << "." << endl;
                    } else {
                        cout << "Error: Index exceeds list's item count." << endl;
                    }
                }
            } else {
                cout << "No list found with the given limit value." << endl;
            }
            break;
        }
        case 5: {
            // Merge two lists.
            int limit1, limit2;
            cout << "Enter the limit of the first list to merge: ";
            cin >> limit1;
            cout << "Enter the limit of the second list to merge: ";
            cin >> limit2;

            BoundNumbersList * list1 = findListByLimit(initialList, limit1);
            BoundNumbersList * list2 = findListByLimit(initialList, limit2);

            if (list1 == nullptr || list2 == nullptr) {
                cout << "One or both of the specified lists do not exist." << endl;
            } else {
                int mergedBound = max(list1 -> getLimit(), list2 -> getLimit());
                BoundNumbersList * mergedList = new BoundNumbersList(mergedBound);

                // Merge the elements from the two lists.
                Element * current1 = list1 -> getStart();
                while (current1 != nullptr) {
                    mergedList -> insertElement(current1 -> data);
                    current1 = current1 -> following;
                }

                Element * current2 = list2 -> getStart();
                while (current2 != nullptr) {
                    mergedList -> insertElement(current2 -> data);
                    current2 = current2 -> following;
                }

                if (finalList != nullptr) {
                    finalList -> following = mergedList;
                }
                finalList = mergedList;
                if (initialList == nullptr) {
                    initialList = mergedList;
                }

                cout << "Successfully merged lists with limit values " << limit1 << " and " << limit2 << "." << endl;

                delete list1;
                delete list2;
            }
            break;
        }
        case 6: {
            // Display the limit of each list.
            BoundNumbersList * activeList = initialList;

            if (activeList == nullptr) {
                cout << "No lists found." << endl;
            } else {
                cout << "Bound values of stored lists:" << endl;
                int temp_index = 1;
                while (activeList != nullptr) {
                    cout << "List " << temp_index << ", Bound value: " << activeList -> getLimit() << endl;
                    temp_index++;
                    activeList = activeList -> following;
                }
            }
            break;
        }
        case 7: {
            // Display the elements of a list specified by its limit.
            int _limit;
            cout << "Specify the limit value to view the list's items: ";
            cin >> _limit;

            BoundNumbersList * targetList = findListByLimit(initialList, _limit);

            if (targetList == nullptr) {
                cout << "There's no list with the given limit value." << endl;
            } else {
                cout << "Displaying items for the list with limit " << _limit << ":\n";
                targetList -> displayBound();
            }
            break;
        }
        case 8:
            // Exit the program.
            exit(1);
            break;
        default:
            // Handle invalid choice.
            cout << "Invalid input" << endl;
            break;
        }
    }

    return 0;
}
