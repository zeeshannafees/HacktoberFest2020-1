import speech_recognition as sr
r = sr.Recognizer()
with sr.Microphone() as source:
    r.adjust_for_ambient_noise(source)
    print("Speak")
    audio = r.listen(source)
    print("Recognising...")
    
    try:
        text = r.recognize_google(audio)
        print(": {}".format(text))
    except:
        print("Error")
with open("recorded.wav","wb") as f:
    f.write(audio.get_wav_data())