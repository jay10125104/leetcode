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
        int xlevel;
        int ylevel;
        Pair(TreeNode node, int xlevel, int ylevel){
            this.node = node;
            this.xlevel = xlevel;
            this.ylevel = ylevel;
        }
    }
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<List<Integer>> list = new ArrayList<>();
        
        int[] width = new int[2];
        // System.out.println(Arrays.toString(width));
        calcWidth(root, 0, width);
        
        for(int i = width[0]; i <= width[1]; i++){
            list.add(new ArrayList<>());
        }
        
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> {
            if(a.ylevel == b.ylevel){
                return a.node.val - b.node.val;  
            }
            return a.ylevel - b.ylevel;
        });
        // System.out.println(list);
        pq.add(new Pair(root, Math.abs(width[0]), 0));
        
        while(pq.size() > 0){
            Pair currPair = pq.remove();
            TreeNode curr = currPair.node;
            
            list.get(currPair.xlevel).add(curr.val);
            
            if(curr.left != null){
                pq.add(new Pair(curr.left, currPair.xlevel - 1, currPair.ylevel + 1));
            }
            
            if(curr.right != null){
                pq.add(new Pair(curr.right, currPair.xlevel + 1, currPair.ylevel + 1));
            }
        }
        
        
        return list;
    }
    
    private void calcWidth(TreeNode root, int level, int[] width){
        if(root == null){
            return;
        }
        // System.out.println(level);
        
        width[0] = Math.min(width[0], level);
        width[1] = Math.max(width[1], level);
        
        calcWidth(root.left, level - 1, width);
        calcWidth(root.right, level + 1, width);
        
    }
}
