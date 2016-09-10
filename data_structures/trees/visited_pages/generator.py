# generate log files with timestamp and random selected website name
# timestamps are guaranteed to be incrementing. 

import random
import time
from time import sleep 

def getrandompage(): 
    pages = ['google',
             'yahoo',
             'bing',
             'apple',
             'snapchat',
             'facebook',
             'amazon',
             'nvidia',
             'intel',
             'cnn',
             'nytimes',
             'cnbc']

    return random.choice(pages)

def main(): 
    f = open("pages.log", 'w')
    for num in range(1, 1000): 
        f.write(str(int(time.time()*1000)))
        f.write(" ")
        f.write(getrandompage())
        f.write('\n')
        sleep(0.005) 
    f.close()

if __name__ == "__main__": 
    main()
