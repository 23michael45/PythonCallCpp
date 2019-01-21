import pym
import cv2
import numpy as np

# def GetImage(fn):
#     im = pym.GetImage(fn)
#     return np.array(im, copy=False)


v = pym.addnum(4,5)
print(v)

img = pym.GetImage('1.jpg')
print(img.size)

size = pym.SetImage(img)
print(size)


cv2.imshow('img',img)
cv2.waitKey(0)

print(v)

def test_pet():
    my_dog = pym.Pet('Pluto', 5)
    print(my_dog.get_name())
    print(my_dog.get_hunger())
    my_dog.go_for_a_walk()
    print(my_dog.get_hunger())

test_pet()