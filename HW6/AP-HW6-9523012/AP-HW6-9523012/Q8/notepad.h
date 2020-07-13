#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QFileSystemModel>
#include<vector>

namespace Ui {
class Notepad;
}

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = 0);
    QFileSystemModel* model;
    ~Notepad();

private slots: // functions
    void on_actionSave_triggered();

    void on_actionLoad_triggered();

    void on_actionnew_tab_triggered();

private:
    Ui::Notepad *ui;
    std::vector<QString> up_path;
    std::vector<QString> path;
    std::vector<QString> name;
};

#endif // NOTEPAD_H
