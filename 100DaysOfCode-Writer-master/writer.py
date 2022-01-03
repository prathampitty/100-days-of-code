import webbrowser
import os
import datetime
import time
import pyperclip
import urllib.parse
from os import system, name
from colorama import Fore
from colorama import Style
# from rich.console import Console
# console = Console()

def progressBar(current, total, barLength = 20):
    percent = float(current) * 100 / total
    arrow   = '-' * int(percent/100 * barLength - 1) + '>'
    spaces  = ' ' * (barLength - len(arrow))

    print('Progress: [%s%s] %d %%' % (arrow, spaces, percent), end='\r')

def retDateStr():
    dt = str(datetime.datetime.now())
    lst = {'01':'January',
    '02': 'February',
    '03': 'March',
    '04': 'April',
    '05': 'May',
    '06': 'June',
    '07': 'July',
    '08': 'August',
    '09': 'September',
    '10': 'October',
    '11': 'November',
    '12': 'December'}
    
    date = dt[8:10]
    month = dt[5:7]
    yr = dt[0:4]

    date_formatted = '{} {}, {}'.format(lst[str(month)], date, yr)
    return (str(date_formatted))

txt = """#100DaysOfCode
🗓 DAY {} of 100: {}

✔ Progress: {}

🧠 Thoughts: {}

🔗 Link: {}"""

def inp():
    DAY = input("> Enter Day Number: ")
    DATE = retDateStr()
    Progress = input("> Enter Progress: ")
    Thoughts = input("> Enter Thoughts: ")
    Link = input("> Enter Link: ")

    txt_fin = txt.format(DAY, DATE, Progress, Thoughts, Link)

    return txt_fin

def tweet(txt):
    txt = urllib.parse.quote(txt)
    pre="https://twitter.com/intent/tweet?text={}".format(txt)
    webbrowser.open(pre)

def clear():
  
    # for windows
    if name == 'nt':
        _ = system('cls')
  
    # for mac and linux(here, os.name is 'posix')
    else:
        _ = system('clear')

clear()
#exp = Final export
exp = inp()
print(f"\n{Fore.RED}Final Text:\n{Fore.GREEN}"+exp+f"{Style.RESET_ALL}")

flag = 0
#Copy Final Export to Clipboard
while (flag==0): 
    twt = input(f"\n{Fore.RED}Copy Text to Clipboard? [Y/n] {Style.RESET_ALL}")
    if((twt=='Y') | (twt=='y') | (twt=='N') | (twt=='n') | (twt=='')):
        if ((twt == 'Y')|(twt == 'y')|(twt=='')):
            pyperclip.copy(exp)
            print (f"\n{Fore.GREEN}Text Copied!\n{Style.RESET_ALL}Paste Anywhere.")
            flag=1
        elif((twt == 'N') | (twt == 'n')):
            flag=1


#Tweet[Y/n]?
flag = 0
while (flag==0): 
    twt = input(f"\n{Fore.RED}Open new Tweet? [Y/n] {Style.RESET_ALL}")
    if((twt=='Y') | (twt=='y') | (twt=='N') | (twt=='n') | (twt=='')):
        if ((twt == 'Y')|(twt == 'y')|(twt=='')):
            print(f"{Fore.GREEN}Opening new Tweet.{Style.RESET_ALL}")
            time.sleep(1)
            tweet(exp)
            flag=1
        elif((twt == 'N') | (twt == 'n')):
            flag=1
