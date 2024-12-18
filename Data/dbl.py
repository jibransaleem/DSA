class Node:
    def __init__(self, data):
        # Initialize the node with data and set the left and right pointers to None
        self.right = None
        self.left = None
        self.data = data

class DL:
    def __init__(self):
        # Initialize the doubly linked list with an empty head and size 0
        self.head = None
        self.size = 0

    def insert_head(self, data):
        # Insert a node at the beginning of the list
        node = Node(data)
        self.size += 1
        if self.head is None:
            # If the list is empty, set the head to the new node
            self.head = node
        else:
            # If the list is not empty, adjust the pointers to insert the node at the head
            node.right = self.head
            self.head.left = node
            self.head = node
        return

    def append(self, data):
        # Append a node at the end of the list
        self.size += 1
        node = Node(data)
        if self.head is None:
            # If the list is empty, insert the node at the head
            self.insert_head(data)
            return
        head = self.head
        # Traverse to the last node
        while head.right is not None:
            head = head.right
        # Insert the new node at the end
        head.right = node
        node.left = head

    def delete(self, pos):
        # Delete a node at a specific position
        if pos == 0:
            # If the node to be deleted is the head
            self.head = self.head.right
            if self.head:
                self.head.left = None
            self.size -= 1
            return
        head = self.head
        if pos == self.size - 1:
            # If the node to be deleted is the last node
            while head.right is not None:
                head = head.right
            head.left.right = None  # Remove the last node
            self.size -= 1
            return
        index = 0
        # Traverse to the node just before the one to be deleted
        while index + 1 != pos:
            head = head.right
            index += 1
        # Remove the node from the middle
        head.right = head.right.right
        if head.right:
            head.right.left = head
        self.size -= 1
        return
    def Reverse(self):
        temp = self.head
        while temp is not None:
            demo =  temp.left
            temp.left = temp.right
            temp.right = demo
            new_head = temp
            temp = temp.left
        self.head = new_head
            

    def display(self):
        # Display the elements of the list
        head = self.head
        while head is not None:
            # Print the node's data, and use " < - > " to separate the nodes
            print(head.data, end=" < - > " if head.right else "")
            head = head.right
        print()  # To move to the next line after the list is printed
