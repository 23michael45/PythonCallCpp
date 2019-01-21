import pym
import cv2
import numpy as np

def GetImage(fn):
    im = pym.GetImage(fn)
    return np.array(im, copy=False)


v = pym.addnum(4,5)
print(v)

img = GetImage('1.jpg')
print(img.size)

cv2.imshow('img',img)
cv2.waitKey(0)

print(v)