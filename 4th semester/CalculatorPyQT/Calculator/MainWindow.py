from PyQt6 import uic
from PyQt6.QtWidgets import QApplication
from PyQt6 import QtCore

Form, Window=uic.loadUiType("mainwindow.ui")
app = QApplication([])
window=Window()
form = Form()
form.setupUi(window)
window.show()


number_first=0
def digit_numbers():
    button = window.sender()
    if form.result_view.text().find('.')>=0 and button.text()=='0':
        s=form.result_view.text()+button.text()
    else:
        number = float(form.result_view.text()+button.text())
        s="{:}".format(int(number)if int(number)==number else float(number))
    form.result_view.setText(s)

form.pushButton_0.clicked.connect(digit_numbers)
form.pushButton_1.clicked.connect(digit_numbers)
form.pushButton_2.clicked.connect(digit_numbers)
form.pushButton_3.clicked.connect(digit_numbers)
form.pushButton_4.clicked.connect(digit_numbers)
form.pushButton_5.clicked.connect(digit_numbers)
form.pushButton_6.clicked.connect(digit_numbers)
form.pushButton_7.clicked.connect(digit_numbers)
form.pushButton_8.clicked.connect(digit_numbers)
form.pushButton_9.clicked.connect(digit_numbers)

def on_pushButton_dot_clicked():
    s=form.result_view.text()
    if s.find('.')<0:
        form.result_view.setText(s+'.')

form.pushButton_dot.clicked.connect(on_pushButton_dot_clicked)

def operation():
    button = window.sender()
    if(button.text()=='+/-'):
        number=float(form.result_view.text())
        number*=-1
        s="{:}".format(int(number)if int(number)==number else float(number))
        form.result_view.setText(s)
    if(button.text()=="AC"):
        number=0
        form.pushButton_plus.setChecked(False)
        form.pushButton_minus.setChecked(False)
        form.pushButton_times.setChecked(False)
        form.pushButton_demiter.setChecked(False)  
        form.result_view.setText(str(number))
    if(button.text()=="%"):
        number=float(form.result_view.text())
        number*=0.01
        s="{:}".format(int(number)if int(number)==number else float(number))
        form.result_view.setText(s)

form.pushButton_plusminus.clicked.connect(operation)
form.pushButton_AC.clicked.connect(operation)
form.pushButton_procent.clicked.connect(operation)

def math_operation():
    global number_first
    button=window.sender()
    button.setChecked(True)
    number_first=float(form.result_view.text())
    form.result_view.setText('0')

def on_pushButton_answer_clicked():
    global number_first
    number_second=float(form.result_view.text())
    res=0

    if form.pushButton_plus.isChecked():
        res = number_first+number_second
        form.pushButton_plus.setChecked(False)     

    if form.pushButton_minus.isChecked():
        res = number_first-number_second
        form.pushButton_minus.setChecked(False)
    
    if form.pushButton_demiter.isChecked():
        if(number_second == 0):
            res = form.result_view.setText('0')
        else:
            res = number_first/number_second
            form.pushButton_demiter.setChecked(False)

    if form.pushButton_times.isChecked():
        res = number_first*number_second
        form.pushButton_times.setChecked(False)

    s="{:}".format(int(res)if int(res)==res else float(res))
    form.result_view.setText(s)
        

form.pushButton_plus.setCheckable(True)
form.pushButton_minus.setCheckable(True)
form.pushButton_times.setCheckable(True)
form.pushButton_demiter.setCheckable(True)

form.pushButton_plus.clicked.connect(math_operation)
form.pushButton_minus.clicked.connect(math_operation)
form.pushButton_times.clicked.connect(math_operation)
form.pushButton_demiter.clicked.connect(math_operation)
form.pushButton_answer.clicked.connect(on_pushButton_answer_clicked)

app.exec()