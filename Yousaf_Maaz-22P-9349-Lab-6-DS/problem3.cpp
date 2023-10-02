// Linked List-based Stack:

// Dynamic Size: Linked lists can easily accommodate a dynamic number of text states. As users edit text, the number of states may vary, and linked lists handle this flexibility well.

// Memory Efficiency: Linked lists can be memory-efficient if implemented properly. They allocate memory for each state only when needed, reducing overall memory consumption.

// Ease of Insertion and Deletion: Adding or removing states (undo/redo) is efficient in a linked list. You can insert a new state into the list or remove the last state without shifting a large portion of memory.

// Scalability: If your application might need to handle a large number of undo/redo states, a linked list can scale well without much impact on performance.

// Complex Operations: If you foresee complex operations during undo/redo, such as merging or splitting states, a linked list can make these operations more manageable.