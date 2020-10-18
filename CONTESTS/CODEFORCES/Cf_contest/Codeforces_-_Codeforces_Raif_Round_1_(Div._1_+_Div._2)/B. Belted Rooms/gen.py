import random

n=random.randint(2,8)
print(n)
str = ""
for i in range(n):
        x=random.randint(1,3)
        
        if(x==1):
                str =str+"-"
        elif(x==2):
                str =str+">"
        elif(x==3):
                str =str+"<"
print(str)