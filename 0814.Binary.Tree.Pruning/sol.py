class Solution:
    def pruneTree(self, root: TreeNode) -> TreeNode:
        
        if (root.left):
            if (not self.hasContain(root.left)):
                root.left = None
                
        if (root.right):
            if (not self.hasContain(root.right)):
                root.right = None
            
            
        if (root.left):
            root.left = self.pruneTree(root.left)
        
        if (root.right):
            root.right = self.pruneTree(root.right)
        
        return root
    
    def hasContain(self, node: TreeNode):
        if (node.left == None and node.right == None) :
            return (node.val == 1)
        elif (node.left != None and node.right != None) :
            return self.hasContain(node.left) or self.hasContain(node.right)
        elif (node.left != None and node.right == None) :
            return self.hasContain(node.left)
        elif (node.left == None and node.right != None) :
            return self.hasContain(node.right)
