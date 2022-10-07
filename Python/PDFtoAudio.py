#!/usr/bin/python3
# importing the modules
# usage PDFtoAudio.py {pdf file name} {page number to start from}

import PyPDF2
import pyttsx3
from sys import argv

# path of the PDF file
path = open(argv[1],'rb')
# creating a PdfFileReader object
pdfReader = PyPDF2.PdfFileReader(path)

# the page with which you want to start
# this will read the page of 25th page.
from_page = pdfReader.getPage(int(argv[2]))

# extracting the text from the PDF
text = from_page.extractText()

# reading the text
speak = pyttsx3.init()
speak.say(text)
speak.runAndWait()
