# By NANDAN CHUPA 

class Solution:
    def largestPalindromic(self, num: str) -> str:
        res=sorted(num,reverse=True)
        #print(res)
        s=''
        z=''
        i=0
        while i<len(res):
            if i<len(res)-1:
                if res[i]==res[i+1]:
                    if res[i]=='0' and s=='':
                        i+=1
                        continue
                    s=s+res[i]
                    i+=1
                else :
                    if z=='':
                        z=res[i]
            else:
                if z=='':
                    z=res[i]
            i+=1
                    
            # print(i,"   ")
                
        return s+z+s[::-1]