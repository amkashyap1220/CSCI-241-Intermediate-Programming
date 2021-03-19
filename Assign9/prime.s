10  rem 
11  rem  test x to see if it is prime
12  rem 
20  input x
30  data 100
40  rem
41  rem   prime numbers must be greater than 1
42  rem
50  if x < 2 goto 160
60  rem
61  rem   need only check divisors 
62  rem   from 2 through x/2
63  rem
70  let h = x/2
80  let d = 2
90  rem
91  rem   top of loop
92  rem
100 if d > h goto 190
110 rem
111 rem   y will equal x iff d evenly divides x
112 rem
120 let y = d*(x / d)
130 if x == y goto 160
140 let d = d + 1
150 goto 90
160 rem
161 rem   x is not prime
162 rem 
170 print -1 
180 end
190 rem 
191 rem   x is prime
192 rem
200 print 1 
210 end
