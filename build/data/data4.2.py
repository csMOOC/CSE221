data = 'a'*1024 # 1kb

for i in range(10):
    path = str(4*(2**i)) + "KB.txt"
    f = open(path,"w")
    for j in range(4*(2**i)):
        f.write(data)
    f.close()
