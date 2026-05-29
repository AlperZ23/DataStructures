import time
def bubble(data):
    res = data
    ui = len(res) - 1

    while ui > 0:
        si = 0
        i = 0
        while i < ui:
            if res[i] > res[i + 1]:
                res[i], res[i + 1] = res[i + 1], res[i]
                si = i
            i += 1

        ui = si
    
    return res



start = time.process_time(); end = time.process_time()



duration = round((end - start) * 1000000)
print((bubble([5,4,1,7,2,6,2])))
print(time.process_time())
