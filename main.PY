class Node:
    def __init__(self, key, value):
        self.key = key
        self.val = value
        self.prev = None
        self.next = None


class LRU:
    def __init__(self, capacity):
        self.capacity = capacity
        self.hash = dict()
        self.head = Node(0, 0)
        self.tail = Node(0, 0)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.get_requests = 0
        self.misses = 0

    def get(self, key):
        self.get_requests += 1
        if key in self.hash:
            n = self.hash[key]
            self.remove(n)
            self.add(n)
            return n.val
        else:
            self.misses += 1
            return -1

    def put(self, key, value):
        if key in self.hash:
            self.remove(self.hash[key])
        else:
            if len(self.hash) >= self.capacity:
                lru = self.head.next
                self.remove(lru)
                del self.hash[lru.key]
        new_node = Node(key, value)
        self.add(new_node)
        self.hash[key] = new_node

    def remove(self, node):
        p = node.prev
        n = node.next
        p.next = n
        n.prev = p

    def add(self, node):
        p = self.tail.prev
        p.next = node
        self.tail.prev = node
        node.prev = p
        node.next = self.tail
    def miss_rate(self):
        total_requests = self.get_requests   
        if total_requests == 0:
            return 100
        return (self.misses / total_requests) * 100

