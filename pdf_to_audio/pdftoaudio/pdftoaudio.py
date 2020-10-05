#importing required module
import PyPDF2
from gtts import gTTS
import os
from tkinter import Tk
from tkinter.filedialog import askopenfilename
import pygame, sys
from pygame.locals import *
pygame.init()
basicFont = pygame.font.SysFont(None, 48)
text = basicFont.render('Hello world!', True, WHITE, BLUE)
print("converting.......")
Tk().withdraw() # we don't want a full GUI, so keep the root window from appearing
filename = askopenfilename()
print(os.path.basename(filename))
#create a file obj and open in read binary mode
with  open(filename,'rb') as pdfFileObj:     #'rb' for read binary mode
    pdfReader = PyPDF2.PdfFileReader(pdfFileObj)
    print((pdfReader.numPages))
    for i in range(0,pg):
        pageObj = pdfReader.getPage(i)
        finalDoc += (" " + pageObj.extractText().strip())
#close
    pdfFileObj.close()
#set language
    lang='en'
#passing the text and slow=false bcz i want the audio have a high  speed
    myobj=gTTS(text=p,lang=lang,slow=False)
#save it in mp3 file
    myobj.save("audio.mp3")
#run it
    os.system("mpg321 audio.mp3")
    '''quit='r'
    while(quit !='q'):
        quit=input("enter q  to exit:")'''
while True:

    for event in pygame.event.get():

        if event.type == QUIT:
            pygame.quit()
            sys.exit()
