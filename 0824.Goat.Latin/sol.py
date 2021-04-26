class Solution:
    def toGoatLatin(self, S: str) -> str:
        words = S.split(' ')
        relt = []
        vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        for i, w in enumerate(words, start=1):
            newW = ""
            if w[0] in vowels:
                newW = w + "ma"
            else:
                newW = w[1:] + w[0] + "ma"
                
            for j in range(i):
                newW += "a"
            
            relt.append(newW)
        return " ".join(relt)
