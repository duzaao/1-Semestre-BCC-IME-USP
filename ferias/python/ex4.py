def find_it(seq):
    seq = seq.sort
    i = int(1)
    impar = int(0)
    
    while i< len(seq):
        if seq[i-1] == seq [i]:
            impar += 1
        elif impar != 0:
            if impar%2 != 0:
                return seq[i-1]
            else:
                impar = 0
        i += 1
    return None


print(find_it([20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5]))