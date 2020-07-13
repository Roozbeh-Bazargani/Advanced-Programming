#include "notepad.h"
#include "ui_notepad.h"
#include<fstream>
#include"qfiledialog.h"
#include<sstream>
#include<string>
#include<iostream>
#include"QMessageBox"
#include<QDebug>


Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);
    on_actionnew_tab_triggered();
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::on_actionSave_triggered()
{
    // path
    QString save_as_path {QFileDialog::getSaveFileName(this, tr("select a directory"))};
    if(path[ui->tabWidget->currentIndex()] == "")
    {
        path[ui->tabWidget->currentIndex()] = save_as_path;
        QDir npath{path[ui->tabWidget->currentIndex()]};
        name[ui->tabWidget->currentIndex()] = npath.dirName();
        ui->label->setText(name[ui->tabWidget->currentIndex()]);
        npath.cdUp();
        up_path[ui->tabWidget->currentIndex()] = npath.path();
        //isFile[ui->tabWidget->currentIndex()] = true;
        //tree_view(true, path[ui->tabWidget->currentIndex()], up_path[ui->tabWidget->currentIndex()], name[ui->tabWidget->currentIndex()]);
    }
    std::ofstream ofile{save_as_path.toStdString()};
    QTextEdit* tmp = reinterpret_cast<QTextEdit*>(ui->tabWidget->currentWidget());
    ofile << tmp->toPlainText().toStdString();
    ofile.close();
}

void Notepad::on_actionLoad_triggered()
{
    // path
    int num{ui->tabWidget->currentIndex()};
    path[num] = {QFileDialog::getOpenFileName(this, tr("Select a file"),tr("")
                                                     ,tr("Text Files (*.txt);;Source Files (*cpp),(*h)"))};
    QDir dir{path[num]};
    name[num] = dir.dirName();
    ui->tabWidget->setTabText(num,name[num]);
    std::vector<QString> find{};
    find.push_back(".");
    int64_t x{std::find_end(name[num].begin(),name[num].end(),find.begin(),find.end()) - name[num].begin()};
    std::string lab{name[num].toStdString().substr(x + 1,name[num].size() - x - 1)};
    ui->label_2->setText(QString::fromStdString(lab));
    dir.cdUp();
    up_path[num] = {dir.absolutePath()};
    std::ifstream iFile{path[num].toStdString()};
    if(!iFile) {
        QMessageBox::critical(this, "ERROR" , "Are you kidding?");
        return;
    }
    std::stringstream ss{};
    ss << iFile.rdbuf();
    iFile.close();
    QTextEdit* editor = reinterpret_cast<QTextEdit*>(ui->tabWidget->currentWidget());
    editor->setText(QString::fromStdString(ss.str()));
    model = new QFileSystemModel();
    model->setReadOnly(true);
    model->setRootPath(path[num]);
    ui->treeView->setModel(model);
    QModelIndex index = model->index(up_path[num]);
    ui->treeView->setRootIndex(index);
}

void Notepad::on_actionnew_tab_triggered()
{
    QTextEdit* editor = new QTextEdit();
    ui->tabWidget->addTab(editor,"New tab");
    path.push_back("");
    up_path.push_back("");
    name.push_back("");
}
