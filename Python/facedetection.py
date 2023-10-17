import cv2
import sys

faceCascade=cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
videoCapture=cv2.VideoCapture(0)
imageCounter=0

while True:
    ret, Frame = videoCapture.read()
    gray= cv2.cvtColor(Frame, cv2.COLOR_BGR2GRAY)
    k = cv2.waitKey(1)
    faces = faceCascade.detectMultiScale(
        gray,
        scaleFactor=1.5,
        minNeighbors=5,
        minSize=(30,30),
        flags=cv2.CASCADE_SCALE_IMAGE
     )

    for (x, y, w, h) in faces:
         cv2.rectangle(Frame, (x,y), (x+w, y+h), (255,255,0), 2)

         cv2.imshow('FaceDetection', Frame)

         if k%256 == 27:
             break
         elif k%256 == 32:
                imageName= "facedetect_webcam_{}.png".format(imageCounter)
                cv2.imwrite(imageName, Frame)
                print("{} written!".format(imageName))
                imageCounter +=1

videoCapture.release()
cv2.destroyAllWindows()