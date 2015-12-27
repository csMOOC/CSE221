data = "a"*1024*1024

path = "3000MB.txt"

f = open(path,"w")

for i in range(3000):
    f.write(data)
f.close()
