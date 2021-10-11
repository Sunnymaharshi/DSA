n=int(input())
def ch():
    if d["1"]>0 and d["2"]>0 and d["3"]>0:
        return True
    return False
for _ in range(n):
    s=input()
    d={}
    d["1"]=0
    d["2"]=0
    d["3"]=0
    l=0
    r=0
    ans=1000000
    while(r<len(s)):
        d[s[r]]+=1
        while(ch()):
            ans=min(r-l+1,ans)
            d[s[l]]-=1
            l+=1
            
        r+=1
    if ans==1000000:
        print(0)
    else:
        print(ans)