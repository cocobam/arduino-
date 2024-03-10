import tkinter
import webbrowser


urL='http://172.20.10.2/phpmyadmin/'
urL2='http://172.20.10.2:1880/ui'
urL3='http://172.20.10.2:1880'
def database():
    webbrowser.get('windows-default').open_new(urL)
def ui():
    webbrowser.get('windows-default').open_new(urL2)
def nodered():
    webbrowser.get('windows-default').open_new(urL3)
Tkwindow = tkinter.Tk()
Tkwindow.title("聲音監測")
Tkwindow.minsize(200,200)
bta = tkinter.Button(Tkwindow,
                     anchor=tkinter.S,
                     text="資料庫",
                     width=10,
                     height=1,
                     command=database)
bta.pack() 
btb = tkinter.Button(Tkwindow,
                     anchor=tkinter.S,
                     text="Ui",
                     width=10,
                     height=1,
                     command=ui)
btb.pack() 
btc = tkinter.Button(Tkwindow,
                     anchor=tkinter.S,
                     text="node red",
                     width=10,
                     height=1,
                     command=nodered)
btc.pack() 
   
        
Tkwindow.mainloop()
    