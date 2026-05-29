Python 3.10.5 (tags/v3.10.5:f377153, Jun  6 2022, 16:14:13) [MSC v.1929 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
def remove_dups(data,value):
    res = []
    if len(data)!=0:
        fresh=data[0]
        i=1
        while i < len(data):
            if data[i]!=fresh:
                res.append(fresh)
                fresh=data[i]
                i+=1
                
        res.append(fresh)
    return res 
