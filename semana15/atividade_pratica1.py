class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def count_nodes(root):
    if root is None:
        return 0
    return 1 + count_nodes(root.left) + count_nodes(root.right)


def sum_nodes(root):
    if root is None:
        return 0
    return root.value + sum_nodes(root.left) + sum_nodes(root.right)


def tree_height(root):
    if root is None:
        return 0
    return 1 + max(tree_height(root.left), tree_height(root.right))


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
