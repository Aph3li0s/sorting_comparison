import random
import time
prev_num = 0
def inc():
    prev_num = random.uniform(0, 20)
    for i in range(1000000):
        new_num = prev_num + random.uniform(1, 10)
        f.write(str(round(new_num, 3)))
        f.write(" ")
        prev_num = new_num
def dec():
    prev_num = random.uniform(10000000, 9999990)    
    for i in range(1000000):
        new_num = prev_num - random.uniform(1, 10)
        f.write(str(round(new_num, 3)))
        f.write(" ")
        prev_num = new_num
        
        
for i in range (10):
    f = open("./datasets/data" + str(i+1) + ".txt", "a")
    f.truncate(0)
    random.seed(time.time())
    if (i == 0):
        inc()
    if (i == 1):
        dec()
    else:
        for i in range(1000000):
            num = random.uniform(0, 100000000) 
            f.write(str(round(num, 3)))
            f.write(" ")
               



