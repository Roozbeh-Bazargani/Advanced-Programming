import sys
from PyQt5 import uic
from PyQt5.QtWidgets import QApplication , QMainWindow, QVBoxLayout, QFileDialog
import os
import xlsxwriter
from xlrd import open_workbook
import numpy as np
from matplotlib.figure import Figure
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.backends.backend_qt5agg import NavigationToolbar2QT as NavigationToolbar


# open ui
Form = uic.loadUiType(os.path.join(os.getcwd(),'gui.ui'))[0]

# write xlsx
workbook = xlsxwriter.Workbook('data.xlsx')
worksheet = workbook.add_worksheet()

# filling columns
for r in range (0,100):
    s = np.random.normal(1,4,None)
    worksheet.write(r, 0, s)
    num = np.linspace(-5,5,100)
    worksheet.write(r, 1, num[r])

# window class
class IntroWindow(Form,QMainWindow):
    def __init__(self):
        xlsxfile = None
        Form.__init__(self)
        QMainWindow.__init__(self)
        self.setupUi(self)
        # figure
        self.fig = Figure()
        self.ax = self.fig.add_axes([0.05, 0.05, 0.9, 0.9])
        self.axis_plot()
        self.canvas = FigureCanvas(self.fig)
        self.navi = NavigationToolbar(self.canvas, self)

        l = QVBoxLayout(self.matplotlib_widget)
        l.addWidget(self.canvas)
        l.addWidget(self.navi)
        # pushButtons clicked
        self.pushButton_Add.clicked.connect(self.Add)
        self.pushButton_Clear.clicked.connect(self.Clear)
        self.pushButton_ReadExcel.clicked.connect(self.ReadExcel)
        self.pushButton_Plot.clicked.connect(self.Plot)
    # add point
    def Add(self):
        x = self.doubleSpinBox_X.value()
        y = self.doubleSpinBox_Y.value()
        self.point = self.ax.plot(x, y, 'ro', linewidth=5.0)
        self.fig.canvas.draw()
    # clear points
    def Clear(self):
        self.ax.cla()
        self.axis_plot()
        self.fig.canvas.draw()
    # read excel file
    def ReadExcel(self):
        self.xlsxfile = QFileDialog.getOpenFileName(self, 'Open file', __file__, "Excel Files(*.xlsx)")
    # plot excel file
    def Plot(self):
        if self.xlsxfile:
            excel = open_workbook(str(self.xlsxfile[0]))
            sheet = excel.sheet_by_index(0)
            first_row = []
            for i in range(0, 100):
                self.ax.plot(sheet.cell_value(i, 1), sheet.cell_value(i, 0), 'ro')
            self.fig.canvas.draw()
        else:
            print('Error! : No excel file is open!')
    # plot axis of figure
    def axis_plot(self):
        # Major ticks every 20, minor ticks every 5
        major_ticks = np.arange(-15, 15.1, 3)
        minor_ticks = np.arange(-15, 15.1, 1)
        self.ax.set_xticks(major_ticks)
        self.ax.set_xticks(minor_ticks, minor=True)
        self.ax.set_yticks(major_ticks)
        self.ax.set_yticks(minor_ticks, minor=True)
        # And grid
        self.ax.grid(which='both')
        self.ax.grid(which='minor', alpha=0.1)
        self.ax.grid(which='major', alpha=0.25)
        self.ax.set_ylim(ymin=-15, ymax=15.1)
        self.ax.set_xlim(xmin=-15, xmax=15.1)

# show and close window
app = QApplication(sys.argv)

w = IntroWindow()
w.show()
workbook.close()
sys.exit(app.exec())