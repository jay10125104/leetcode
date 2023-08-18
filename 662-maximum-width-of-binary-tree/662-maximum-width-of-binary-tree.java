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
    class Pair{
        TreeNode node;
        int level;
        Pair(TreeNode node, int level){
            this.node = node;
            this.level = level;
        }
    }
    public int widthOfBinaryTree(TreeNode root) {
        if(root == null) return 0;
        
        Queue<Pair> que = new ArrayDeque<>();
        
        que.add(new Pair(root, 1));
        int maxWidth = 0;
        
        while(que.size() > 0){
            int size = que.size();
            int start = que.peek().level;
            // System.out.println(start);
            while(size-- > 0){
                Pair curr = que.remove();

                if(curr.node.left != null){
                    que.add(new Pair(curr.node.left, 2*(curr.level - start)+ 1));
                }
                if(curr.node.right != null){
                    que.add(new Pair(curr.node.right, 2*(curr.level - start) + 2));
                }   
                maxWidth = Math.max(maxWidth, curr.level - start + 1);
            } 
        }
        
        return maxWidth;
    }
}