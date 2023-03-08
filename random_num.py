import random
import time
f = open("./datasets/data2.txt", "a")
#f = open("./data.txt", "a")
numbers = []
prev_num = random.uniform(10000000, 9999990)
#prev_num = random.uniform(0, 20)
random.seed(time.time())

for i in range(1000000):
    new_num = prev_num - random.uniform(1, 10)
    f.write(str(round(new_num, 3)))
    f.write(" ")
    numbers.append(round(new_num, 3))
    prev_num = new_num

#print(numbers)


# f = open(".\Folder\data10.txt", "a")
# f.write("Now the file has more content!")
# f.close()

# f = open(".\Folder\data10.txt", "r")
# print(f.read())