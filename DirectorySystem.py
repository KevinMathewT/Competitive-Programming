import os
import shutil
import matplotlib.pyplot as plt; plt.rcdefaults()
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import time

def calculate_size(start_path):
    total_size = 0

    for dirpath, dirnames, filenames in os.walk(start_path):
        for f in filenames:
            fp = os.path.join(dirpath, f)
            total_size += os.path.getsize(fp)
    if total_size>0:
        return total_size
    else:
        return os.path.getsize(start_path)

def get_filename_and_size(link):
    for files in os.listdir(link):
        path=link+'\\'+files
        size=calculate_size(path)
        arr.append(size/(1024*1024))

def calculate_percentage(link):
    total=sum(arr)
    for i in arr:
        perc.append((i/total)*100)

def display_stats(link):
    get_filename_and_size(link)
    calculate_percentage(link)
    labels = os.listdir(link)
    print('Total space occupied by directory(in MB) :',sum(arr))
    df=pd.DataFrame({'Perc(%)':perc,'Size(in MB) ':arr,'File':labels})
    df1=df.sort_values(by=['Perc(%)'],ascending=False)

    time.sleep(1)
    print(df1)
    
    for i in range(0,len(arr)-1):
        for j in range (i+1,len(arr)):
            if arr[i]>arr[j]:
                temp=arr[i]
                arr[i]=arr[j]
                arr[j]=temp
                temp1=labels[i]
                labels[i]=labels[j]
                labels[j]=temp1

    if len(os.listdir(link))>10:
        header=labels[len(labels)-10:len(labels)]
        val=arr[len(arr)-10:len(arr)]
    else:
        header=labels[0:len(labels)]
        val=arr[0:len(arr)]
    y_pos = np.arange(len(header))
    plt.barh(y_pos,val, align='center', alpha=0.6,color='red')
    plt.yticks(y_pos,header)
    plt.xlabel('Disk space used in MB')
    plt.ylabel('File Name')
    plt.title('Directory Space Usage Analysis\nShowing the files that occupy the most space')
    time.sleep(1)
    plt.show()


dirpath=input('enter the path of directory')
dirpath.replace(':\\',':\\\\')
if os.path.exists(dirpath) is False:
    print('incorrect directory path')
else:
    path = dirpath
    arr = []
    perc = []
    if os.listdir(path) == []:
        print('Empty directory')
    else:
        display_stats(path)
        for i in range(1, 1000):
            print('Press 1 to go to child directory')
            print('Press 2 to go to parent directory')
            print('Press 3 to delete a subdirectory within current directory')
            print('Press 4 to delete a file within current directory')
            print('Press 5 to exit')
            time.sleep(2)
            op=input('enter your choice:')
            if op=='1':
                ch=input('enter the folder name:')
                if os.path.exists(path+'\\'+ch) is False:
                    print('Incorrect folder name')
                else:
                    path=path+'\\'+ch
                    arr=[]
                    perc=[]
                    if os.listdir(path)==[]:
                        print('Empty directory')
                    else:
                        display_stats(path)
            elif op=='2':
                path=path[:path.rfind('\\')]
                arr=[]
                perc=[]
                display_stats(path)
            elif op=='3':
                subdir_name=input('enter the name of subdirectory to be deleted:')
                if os.path.exists(path+'\\'+subdir_name) is False:
                    print('incorrect subdirectory name')
                else:
                    shutil.rmtree(path+'\\'+subdir_name)
                    arr=[]
                    perc=[]
                    display_stats(path)
            elif op=='4':
                file_name=input('enter the name of file to be deleted:')
                if os.path.exists(path+'\\'+file_name) is False:
                    print('incorrect file name')
                else:
                    os.remove(path+'\\'+file_name)
                    arr=[]
                    perc=[]
                    display_stats(path)
            elif op=='5':
                print('Thank you')
                break
            else:
                print('Wrong choice entered')