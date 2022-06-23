from doctest import DocFileSuite
from os import terminal_size
from pickle import TRUE
from sys import stdin

def get_data(word):
    uno = ["B","F","P","V"]
    dos = ["C", "G", "J", "K", "Q", "S", "X", "Z"]
    tres =["D","T"]
    cua = ["L"]
    cin = ["M","N"]
    sei = ["R"]
    un = ["A", "E", "I", "O", "U", "H", "W", "Y"]
    w = list(word)
    sc = str()
    past_co = 0
    bandera = 1
    for pal in w:
        if bandera == 0:
            if (pal in uno):
                sc = sc + "1"
                past_co = 1
                bandera = 1
            if (pal in dos):
                sc = sc + "2"
                past_co = 2
                bandera = 1
            if (pal in tres):
                sc = sc + "3"
                past_co = 3
                bandera = 1
            if (pal in cua):
                sc = sc + "4"
                past_co = 4
                bandera = 1
            if (pal in cin):
                sc = sc + "5"
                past_co = 5
                bandera = 1
            if (pal in sei):
                sc = sc + "6"
                past_co = 6
                bandera = 1
        else:
            if (pal in uno and past_co != 1):
                sc = sc + "1"
                past_co = 1
            if (pal in dos and past_co != 2):
                sc = sc + "2"
                past_co = 2
            if (pal in tres and past_co != 3):
                sc = sc + "3"
                past_co = 3
            if (pal in cua and past_co != 4):
                sc = sc + "4"
                past_co = 4
            if (pal in cin and past_co != 5):
                sc = sc + "5"
                past_co = 5
            if (pal in sei and past_co != 6):
                sc = sc + "6"
                past_co = 6
        if pal in un:
            bandera = 0    
    return int(sc)

def main():
    while True:    
      try:
        word = stdin.readline()
        if word == "":
          break;
        print(word)
        
      except:
        break;  
    

main()