import time
def merge(data):

   if len(data)== 1 or len(data)==0:
      return data
   else:
      fst = []
      data[:len(data)//2].append(fst)
      snd = []
      data[len(data)//2 : len(data)-1].append(snd)
      res=[]
      fi = 0
      si = 0
      while fi in fst and si in snd :
         if fst[fi] < snd[si]:
            res.append(fst[fi])
            fi+=1
         else:
            res.append(snd[si])
            si+=1
      if fi in fst:
         fst.append(fi) and res.append(fst)
      else:
         res.append(si) and res.append(snd)
      return res

print(merge([5,2,4,1,3]))


start = time.process_time(); end = time.process_time()



duration = round((end - start) * 1000000)
print(merge([5,2,4,1,3]))
print(time.process_time())
