/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int findBottomLeftValue(TreeNode root) {
        Queue<TreeNode> myQueue = new LinkedList<>();
        myQueue.add(root);
        while(!myQueue.isEmpty()){
            root = myQueue.poll();
            if (root.right != null) myQueue.add(root.right);
            if (root.left != null) myQueue.add(root.left);
           
        }
        return root.val;
        
    }
}