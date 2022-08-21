// By Nandan Chupa 
class Solution {
    public int minNumberOfHours(int initialEnergy, int initialExperience, int[] energy, int[] experience) 
    {
        int c=0;
        int sum=0;
        for(int i=0; i<energy.length;i++)
        {
            sum+=energy[i];
            if(initialExperience<=experience[i])
            {
                c+=experience[i]-initialExperience +1;
                initialExperience=experience[i]+1;
            }
            
            if(initialExperience>experience[i])
                initialExperience+=experience[i];
            
            System.out.println("IE ="+initialExperience);
            System.out.println("C ="+c);
        }
        //System.out.println("sum ="+sum);
        if(sum>=initialEnergy)
            c+=sum-initialEnergy+1;
        
        return c;    
    }
}