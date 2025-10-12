class solution:
    def Generate_parenthesis(self,n):
        res =[]
        
        def is_valid(s):
            open_brackets =0
            for c in s:
                open_brackets+=1 if c=='(' else -1
                if open_brackets<0:
                    return False
            return not open_brackets
        def appending_res(s):

            if len(s)==2*n:
                if is_valid(s):
                  res.append(s)
                return
            appending_res(s+'(')
            appending_res(s+')')
        appending_res("")
        return res
    def Backtracking(self,n):
        stack =[]
        result =[]
        def generate_param(openN,closeN):
            if openN==closeN==n:
                result.append("".join(stack))
                return  
            if openN<n:
                stack.append("(")
                generate_param(openN+1,closeN)
                stack.pop()
            if closeN<openN:
                stack.append(")")
                generate_param(openN,closeN+1)
                stack.pop()
        generate_param(0,0)
        return result
n = int(input("the number of paranthesis :- "))
K=solution()
print(K.Backtracking(n))

