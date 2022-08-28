class Solution {
    public String removeStars(String s) 
    {
        Stack<Character> stack = new Stack< Character>();
        for(int i=0;i<s.length();i++)
        {
            char ch=s.charAt(i);
            if(ch=='*')
            {
                //System.out.println(stack.pop());
                stack.pop();
            }
            else if(ch>='a' && ch<='z')
            {
                stack.push(s.charAt(i));
            }
        }
        String ans="";
        //System.out.println(stack);
        while(!(stack.isEmpty()))
        {
            ans=stack.pop()+ans;
        }
        return ans;
    }
        
}