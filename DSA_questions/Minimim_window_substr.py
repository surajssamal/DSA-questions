def Minwindow( s, t):
    if t=="":
        return ""
    #taking the t map 
    t_map,s_map ={},{}
    for c in t:
        t_map[c]=1+t_map.get(c,0);

    result =[-1,-1]
    min_lenth = float("infinity")
    have =0
    need =len(t_map)
    left =0
    for right in range(len(s)):
        c =s[right]
        s_map[c]=1+s_map.get(c,0)
        if c in t_map and s_map[c]== t_map[c] :
            have+=1
        while have==need:
            if (right-left+1)<min_lenth:
                min_lenth=right-left+1
                result=[left,right]
            k =s[left]
            s_map[k]-=1
            if k in t_map and s_map[k]<t_map[k]:
                have-=1
            left+=1
    l,r=result
    return s[l:r+1]




s ="OUZODYXAZV"
t ="XYZ"
print(Minwindow(s,t))
