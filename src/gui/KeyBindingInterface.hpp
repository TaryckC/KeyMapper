#pragma once

#include <QMainWindow>

class KeyBindingInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit KeyBindingInterface(QWidget *parent = nullptr);
    ~KeyBindingInterface();

    void initialize();

private:
    void onLoadClicked();
    void onSaveClicked();
    void onResetClicked();
};