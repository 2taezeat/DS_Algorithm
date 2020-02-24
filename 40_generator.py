def prime_number_generator(start,stop):
    for i in range(start,stop+1):
        p = 1

        for j in range(2,i):    
            if i % j == 0 :
                p = 0
                break
        
        if p == 1:
            yield i


start, stop = map(int, input().split())
 
g = prime_number_generator(start, stop)
print(type(g))

for i in g:
    print(i, end=' ')