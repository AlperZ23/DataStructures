Python 3.9.13 (tags/v3.9.13:6de2ca5, May 17 2022, 16:36:42) [MSC v.1929 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> 
=========== RESTART: C:\Users\Alper\Desktop\Module 1 week 2\search.py ==========
>>> import search
search.linear([4, 2, 3, 2], 2)
search.linear([4, 2, 3, 2], 5)
search.linear(["a", "short", "sentence"], "sentence")
search.linear(["a", "short", "sentence"], 2)
SyntaxError: multiple statements found while compiling a single statement
>>> import search
search.linear([4, 2, 3, 2], 2)

SyntaxError: multiple statements found while compiling a single statement
>>> 

search.linear([4, 2, 3, 2], 2)
Traceback (most recent call last):
  File "<pyshell#2>", line 3, in <module>
    search.linear([4, 2, 3, 2], 2)
NameError: name 'search' is not defined
>>> import search
>>> search.linear([4, 2, 3, 2], 2)
1
>>> 
>>> 
>>> 
>>> search.linear([4, 2, 3, 2], 5)
-1
>>> search.linear(["a", "short", "sentence"], "sentence")
2
>>> search.linear(["a", "short", "sentence"], 2)
-1
>>> 