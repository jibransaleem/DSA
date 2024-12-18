class Node:
    def __init__(self, data):
        self.next = None
        self.data = data

class LL:
    def __init__(self):
        self.head = None
        self.leng = 0  # Renamed to 'leng' to avoid conflict
    def leng(self):  # This remains your method
        return self.leng

    def insert_head(self, data):
        self.leng += 1  # Updated to 'self.leng'
        node = Node(data)
        if self.head is None:
            self.head = node
            return
        node.next = self.head
        self.head = node

    def append(self, data):
        node = Node(data)
        self.leng += 1  # Updated to 'self.leng'
        if self.head is None:
            self.insert_head(data)
            return
        head = self.head
        while head.next is not None:  # Fixed condition to traverse correctly
            head = head.next
        head.next = node

    def insert(self,pos,data):
        node =  Node(data)
        head = self.head
        if pos == 0:
            self.insert_head(data)
            return
        index = 0 
        while(index+1 != pos):
            index+=1
            head = head.next 
        node.next = head.next
        head.next = node
        return
    def delete_head(self):
        head = self.head
        if head:
            head.next = head.next.next 
            self.head = head.next
        return
    def delete_tail(self):
        head = self.head
        if head:
            while(head.next):
                head = head.next 
            head.next = None
        return
    def delete_pos(self,pos):
        head = self.head
        if head is None :
            return
        if pos == self.leng:
            self.delete_tail()
            return
        if pos == 0 :
            self.delete_head()
            return
        index = 0  
        while(index+1!=pos):
            head = head.next 
            index +=1
        head.next = head.next.next 
    def search(self,data):
        head = self.head
        if self.head is None:
            return
        pos =  0
        while(head.data != data):
            head=head.next
            pos+=1
        return pos
    def display(self):
        head = self.head
        while head.next:
            print(head.data,end=" -> ")
            head = head.next
        print(head.data)
