#include "KeyBindingInterface.hpp"
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QDebug>

/* TODO prochaine fois :
    -
    -
*/

// TODO : Idée version 2 : Mettre la possibilité de pas seuelemnt bindé des touches entre elles
// TODO : de binder des actions automatisées à des touches de manière transparente ex : key -> path to action (executable)

KeyBindingInterface::KeyBindingInterface(QWidget *parent) : QMainWindow(parent)
{
    initialize();
}

KeyBindingInterface::~KeyBindingInterface() = default;

void KeyBindingInterface::initialize()
{
    setWindowTitle("KeyMapper");
    resize(800, 600);

    // Principal interface's layout
    QVBoxLayout *mainLayout = new QVBoxLayout();

    /* --- --- --- --- --- --- --- --- ---
    Main buttons layout : Load - Save - Reset
    --- --- --- --- --- --- --- --- --- */
    QHBoxLayout *mainButtonsLayout = new QHBoxLayout();

    QPushButton *loadButton = new QPushButton("Load bindings", this);
    QPushButton *saveButton = new QPushButton("Save bindings", this);
    QPushButton *resetButton = new QPushButton("Reset bindings", this);

    mainButtonsLayout->addWidget(loadButton);
    mainButtonsLayout->addWidget(saveButton);
    mainButtonsLayout->addWidget(resetButton);

    connect(loadButton, &QPushButton::clicked, this, &KeyBindingInterface::onLoadClicked);
    connect(saveButton, &QPushButton::clicked, this, &KeyBindingInterface::onSaveClicked);
    connect(resetButton, &QPushButton::clicked, this, &KeyBindingInterface::onResetClicked);

    /* --- --- --- --- --- --- --- --- ---
    Main Secondary layout (composed) :
        Clickable area : Action - "is binded to" - Bind (default value = Empty - "is binded to" - Empty)
        Buttons : Add Binding - Remove Binding
    --- --- --- --- --- --- --- --- --- */
    // First Layout
    QPushButton *bindLabel = new QPushButton("Empty");
    bindLabel->setFlat(true);
    bindLabel->setStyleSheet(
        "QPushButton { background-color: #d3d3d3; border: none; border-radius: 5px; padding: 4px 4px; text-align: left; }"
        "QPushButton:hover { background-color: #bcbcbc; }");

    QLabel *isBindedToLabel = new QLabel(" is binded to ");

    QPushButton *actionLabel = new QPushButton("Empty");
    actionLabel->setFlat(true);
    actionLabel->setStyleSheet(
        "QPushButton { background-color: #d3d3d3; border: none; border-radius: 5px; padding: 4px 2px; text-align: left; }"
        "QPushButton:hover { background-color: #bcbcbc; }");

    QHBoxLayout *secondaryFirstLayout = new QHBoxLayout();

    secondaryFirstLayout->addWidget(bindLabel);
    secondaryFirstLayout->addWidget(isBindedToLabel);
    secondaryFirstLayout->addWidget(actionLabel);

    // Secondary Layout
    QPushButton *addBinding = new QPushButton("Add", this);
    QPushButton *removeBinding = new QPushButton("Remove", this);

    QHBoxLayout *secondarySecondaryLayout = new QHBoxLayout();

    secondarySecondaryLayout->addWidget(addBinding);
    secondarySecondaryLayout->addWidget(removeBinding);

    // Main Secondary Layout composition

    QHBoxLayout *mainSecondaryLayout = new QHBoxLayout();
    mainSecondaryLayout->addLayout(secondaryFirstLayout);
    mainSecondaryLayout->addLayout(secondarySecondaryLayout);

    // Main Layout
    mainLayout->addLayout(mainButtonsLayout);
    mainLayout->addLayout(mainSecondaryLayout);
    mainLayout->addStretch(); // 🔒 pousse le contenu vers le haut

    QWidget *central = new QWidget(this);
    setCentralWidget(central);
    central->setLayout(mainLayout);
}

void KeyBindingInterface::onLoadClicked()
{
    qDebug("Load clicked");
}

void KeyBindingInterface::onSaveClicked()
{
    qDebug("Save clicked");
}

void KeyBindingInterface::onResetClicked()
{
    qDebug("Reset clicked");
}