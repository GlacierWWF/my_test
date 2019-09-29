absdiff 获取差分图 就是将两幅图像作差

cv2.absdiff(src1,src2,[dst])

src1 The ﬁrst source array

src2 The second source array 
dst The destination array

The function calculates absolute difference between two arrays. 
dst(i)c = |src1(I)c − src2(I)c|
