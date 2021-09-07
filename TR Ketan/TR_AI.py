import cv2 #pip install opencv-python #conda install -c conda-forge opencv
import matplotlib.pyplot as plt #pip install matplotlib

config_file = 'ssd_mobilenet_v3_large_coco_2020_01_14.pbtxt'
frozen_model = 'frozen_inference_graph.pb'

model = cv2.dnn_DetectionModel(config_file, frozen_model)

ClassLabels = []
file_name = 'labels.txt'
with open(file_name,'rt') as fpt:
    ClassLabels = fpt.read().rstrip('\n').split('\n')
    
model.setInputSize(320,320)
model.setInputScale(1.0/127.5)
model.setInputMean((127.5,127.5,127.5))
model.setInputSwapRB(True)
    
img = cv2.imread('car.jpeg')

Classindex, confidence, bbox = model.detect(img,confThreshold=0.5)

font_scale = 3
font = cv2.FONT_HERSHEY_COMPLEX_SMALL
for ClassInd, conf, boxes in zip(Classindex.flatten(), confidence.flatten(), bbox):
    cv2.rectangle(img, boxes, (0, 0, 255), 2)
    cv2.putText(img, ClassLabels[ClassInd-1],(boxes[0]+10,boxes[1]+40), font, fontScale=font_scale, color=(0, 0, 0), thickness=3 )
    
plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
