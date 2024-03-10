import serial
import sys
import pymysql
import time
import re
import tkinter
from time import sleep

COM_PORT = 'COM4'
BAUD_RATES = 115200
ser = serial.Serial(COM_PORT,BAUD_RATES)
Sounddata=''


data = ""
condition = False


def dataupload():
    Arduino_cmd='a'
    cmd=Arduino_cmd.encode('utf-8')
    SerialWrite(cmd)
    condition = False
    try:
       db = pymysql.connect(host="192.168.137.1",user="kokonum",password="ilovevul3a94lkk",db="kokonum")
       cursor1 = db.cursor()
       while True:
          while ser.in_waiting:
             try:
                msg = ser.readline().decode()
                if(msg == ''):
                   continue
                else:
                    print('msg={}'.format(msg))
                    msg_data=re.split(',|:',msg)
    
                    if("聲音數據" in str(msg_data[0])) :
                      Sounddata=msg_data[1].replace(r"\r\n",'')

                      cursor1.execute('INSERT INTO `dht` ( `Sound` ) VALUES ( %s )'%( Sounddata ))
    
                      db.commit()
    
                    else:
                      continue
                    print("上傳完成")
                    time.sleep(1)
             except OSError as er:
                db.rollback()
                db.close()
                print(er)
    
    except OSError as er:
       db.rollback()
       db.close()
       print(er)
    
    except KeyboardInterrupt:
       ser.close()
       db.close()
       print('關閉!!')
     
        
     
        
def SerialWrite(command):
    ser.write(command)
    rv = ser.readline()
    
    print(rv.decode("utf-8"))
    data = rv.decode("utf-8")
    print(data)
    sleep(1)
    ser.flushInput()
    
       
       
       

  

Tkwindow = tkinter.Tk()
Tkwindow.title("聲音監測")
Tkwindow.minsize(600,400)
bta = tkinter.Button(Tkwindow,
                     anchor=tkinter.S,
                     text="數據上傳",
                     width=10,
                     height=1,
                     command=dataupload)
bta.pack() 
   
        
Tkwindow.mainloop()
    
    
    
    
    
    
    
    
    
    
    
    
    


