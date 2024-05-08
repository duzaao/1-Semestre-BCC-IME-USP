def duplicate_encode(word):
    i = int(0)
    S = str[len(word)]
    
    while i< len(word):
        j= int (i)
        S[i] = '('
        
        while j < len(word):
            
            if word[i] == word[j]:
                S[i] = ')'
                S[j] = ')'
    i= i+1      
    return S

    print(duplicate_encode("hello"))