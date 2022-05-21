class Solution:
    def match(self, opening: str, closing: str) -> bool:
        if (opening == "("):
            if (closing == ")"):
                return True
            else: 
                return False
        
        elif (opening == "{"):
            if (closing == "}"):
                return True
            else:
                return False
        
        elif (opening == "["):
            if (closing == "]"):
                return True
            else:
                return False
        
    
    def isOpening(self, s: str) -> bool:
        if (s == "{" or s == "(" or s == "["):
            return True
        else:
            return False
    
    
    def isValid(self, s: str) -> bool:
        if (len(s) % 2 != 0):
            return False
        
        pstack = []
        
        for p in s:
            if (self.isOpening(p) == True):
                pstack.append(p)
                continue
                
            if (len(pstack) == 0):
                # Return false since the stack cannot be empty if a closing bracket is read
                return False 
            else:
                if (self.match(pstack.pop(), p) == False):
                    return False
        
        if (len(pstack) != 0):
            return False
        return True
