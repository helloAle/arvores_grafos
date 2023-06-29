from collections import deque

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def count_nodes(root):
    if root is None:
        return 0
    
    count = 0
    queue = deque()
    queue.append(root)

    while queue:
        node = queue.popleft()
        count += 1

        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)
    
    return count


def sum_nodes(root):
    if root is None:
        return 0
    
    total_sum = 0
    queue = deque()
    queue.append(root)

    while queue:
        node = queue.popleft()
        total_sum += node.value

        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)
    
    return total_sum


def tree_height(root):
    if root is None:
        return 0
    
    height = 0
    queue = deque()
    queue.append(root)

    while queue:
        level_size = len(queue)

        for _ in range(level_size):
            node = queue.popleft()

            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        height += 1
    
    return height


# Exemplo de uso
# Construindo uma árvore binária
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)

print("Número de nós:", count_nodes(root))
print("Soma dos nós:", sum_nodes(root))
print("Altura da árvore:", tree_height(root))
