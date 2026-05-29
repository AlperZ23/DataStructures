Python 3.10.5 (tags/v3.10.5:f377153, Jun  6 2022, 16:14:13) [MSC v.1929 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
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