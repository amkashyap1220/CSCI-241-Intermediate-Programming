10 rem sum 1 to x
15 input x
20 data 10
25 if x <= -1 goto 60
30 rem add x to total
35 let t = t + x
40 let x = x - 1
45 rem loop x
50 goto 25
55 rem output result
60 print t
99 end
